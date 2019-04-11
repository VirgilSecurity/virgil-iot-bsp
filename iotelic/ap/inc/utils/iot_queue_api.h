/****************************************************************************

Copyright(c) 2016 by IoTelic Technologies. ALL RIGHTS RESERVED.

This Information is proprietary to IoTelic Technologies and MAY NOT
be copied by any method or incorporated into another program without
the express written consent of Iotelic. This Information or any portion
thereof remains the property of Iotelic. The Information contained herein
is believed to be accurate and Iotelic assumes no responsibility or
liability for its use in any way and conveys no license or title under
any patent or copyright and makes no representation or warranty that this
Information is free from patent or copyright infringement.

****************************************************************************/

#ifndef IOT_QUEUE_API_H
#define IOT_QUEUE_API_H

/* os shim includes */
#include "os_types_api.h"
#include "os_lock_api.h"

/** \defgroup MISC_APIs MISC APIs
 *  @brief MISC APIs
 *
 *
 */

/** @addtogroup MISC_APIs
 * @{
 *
 */


/*
 * These are non-NULL pointers that will result in memory access error.
 * Use those definitions to identify such access for linked list.
 */
#define IOT_LIST_POISON1    ((void *)0xD1010101)
#define IOT_LIST_POISON2    ((void *)0xD2020202)


/* list head to link objects into double linked list */
typedef struct _iot_list_head {
    struct _iot_list_head   *next;
    struct _iot_list_head   *prev;
} iot_list_head_t;

/* message entry */
typedef struct _iot_msg_entry {
    /* pointer to next entry */
    struct _iot_msg_entry *next;
} iot_msg_entry_t;

/* message queque */
typedef struct _iot_msg_queue {
    /* pointer to the first message in the queue */
    iot_msg_entry_t *head;
    /* pointer to the last message in the queue */
    iot_msg_entry_t *tail;
    /* number of messages in the list */
    uint32_t        cnt;
    /* lock to protect access to the message queue */
    os_mutex_h      lock;
} iot_msg_queue_t;

/**
 * @brief iot_list_entry() - get the struct for this entry
 * @param ptr:        the &struct list_head pointer.
 * @param type:       the type of the struct embedded in.
 * @param member:     the name of the list_head within the struct.
 *
 * @return            NULL -- if the field is invalid
 * @return            otherwise -- pointer to specific field
 */
#define iot_list_entry(ptr, type, member) \
    container_of(ptr, type, member)

/**
 * @brief iot_list_for_each() - iterate over a list
 * @param pos:      the &struct list_head to use as a loop counter
 * @param head:     the head for the list.
 */
#define iot_list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

 /**
 * @brief iot_list_for_each_rves() - iterate over a list reversely
 * @param pos:      the &struct list_head to use as a loop counter
 * @param head:     the head for the list.
 */
#define iot_list_for_each_rves(pos, head) \
    for (pos = (head)->prev; pos != (head); pos = pos->prev)

/**
 * @brief iot_list_for_each_safe() - iterate over a list safe against removal of
 *                                   list entry
 * @param pos:      the &struct list_head to use as a loop counter
 * @param n:        another &struct list_head to use as temporary storage
 * @param head:     the head for the list
 */
#define iot_list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); \
        pos = n, n = pos->next)

/**
 * @brief iot_list_init() - init the specified list head
 * @param head:     list head to be init
 */
static inline void iot_list_init(iot_list_head_t *head)
{
    head->next = head;
    head->prev = head;
}

/**
 * @brief iot_list_add() - add a new entry after the specified head
 * @param new:  new entry to be added
 * @param head: list head to add it after
 */
static inline void iot_list_add(iot_list_head_t *new, iot_list_head_t *head)
{
    head->next->prev = new;
    new->next = head->next;
    head->next = new;
    new->prev = head;
}

/**
 * @brief iot_list_add_tail() - add a new entry before the specified head
 * @param new:  new entry to be added
 * @param head: list head to add it before
 */
static inline void iot_list_add_prev(iot_list_head_t *new,
    iot_list_head_t *head)
{
    head->prev->next = new;
    new->prev = head->prev;
    head->prev = new;
    new->next = head;
}

/**
 * @brief iot_list_del() - deletes entry from list
 * @param entry: the element to be deleted from the list
 */
static inline void iot_list_del(iot_list_head_t *entry)
{
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
    entry->next = IOT_LIST_POISON1;
    entry->prev = IOT_LIST_POISON2;
}

/**
 * @brief iot_list_empty() - tests whether a list is empty
 * @param head:     the list to test.
 *
 * @return          0 - for non empty case
 * @return          1 - for empty case
 */
static inline uint32_t iot_list_empty(iot_list_head_t *head)
{
    return ((head->next == head) && (head->prev == head));
}

/**
 * @brief iot_msg_entry_init() - init message entry
 * @param entry:      message entry to be init
 */
static inline void iot_msg_entry_init(iot_msg_entry_t *entry)
{
    entry->next = NULL;
}

/**
 * @brief iot_msg_queue_init() - init message queue
 * @param queue:      message queue to be init
 *
 * @return          0 -- for success case
 * @return          otherwise -- error code
 */
uint32_t iot_msg_queue_init(iot_msg_queue_t *queue);

/**
 * @brief iot_msg_queue_deinit() - deinit message queue
 * @param queue:    message queue to be deinit
 */
void iot_msg_queue_deinit(iot_msg_queue_t *queue);

/**
 * @brief iot_msg_queue_put() - enqueue message into the end of the queue
 * @param queue:    message queue
 * @param msg:      message to be enqueued
 */
void iot_msg_queue_put(iot_msg_queue_t *queue, iot_msg_entry_t *msg);

/**
 * @brief iot_msg_queue_get() - dequeue message from the head of the queue
 * @param queue:      message queue
 *
 * @return          NULL -- for queue empty case
 * @return          otherwise -- for message dequeued
 */
iot_msg_entry_t *iot_msg_queue_get(iot_msg_queue_t *queue);

/* @brief message queue loop callback definition
 * @param msg: message to be checked
 * @param param: same as the value whill invoke iot_msg_queue_loop
 *
 * @retval  1 - if the message is deleted
 *          0 - otherwise
 */
typedef uint32_t (*iot_msg_queue_loop_func_t)(iot_msg_entry_t *msg,
    void *param);

/**
 * @brief iot_msg_queue_loop() - loop message from the head of the queue
 * @param queue:    message queue to be looped
 * @param func:     callback to check each message
 * @param param:    parameter to be passed to the callback
 */
void iot_msg_queue_loop(iot_msg_queue_t *queue, iot_msg_queue_loop_func_t func,
    void *param);

/**
  * @}
  */


#endif /* IOT_QUEUE_API_H */