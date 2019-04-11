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

#ifndef IOT_TASK_API_H
#define IOT_TASK_API_H

/* os shim includes */
#include "os_types_api.h"
#include "os_task_api.h"

/* common includes */
#include "iot_queue_api.h"

/** \defgroup MISC_APIs MISC APIs
 *  @brief MISC APIs
 *
 *
 */

/** @addtogroup MISC_APIs
 * @{
 *
 */

/* define maximum number of queues supported */
#define IOT_TASK_QUEUE_CNT_MAX      4

#define IOT_TASK_MSG_ID_ALL     0xFFFF

/* task message */
typedef struct _iot_task_msg {
    /* link of the message queue */
    iot_msg_entry_t link;
    /* message type */
    uint16_t        type;
    /* message id */
    uint16_t        id;
} iot_task_msg_t;

typedef void *iot_task_h;

/**
 * @brief (*iot_task_event_func_t)() - function callback to handle task events
 * @param task_h:     iot task handle of the message
 * @param events:     task events
 */
typedef void (*iot_task_event_func_t)(iot_task_h task_h,
    uint32_t events);

/**
 * @brief (*iot_task_msg_execute_func_t)() - function callback to handle msg executing case
 * @param task_h:     iot task handle of the message
 * @param msg:        pointer to message to be executed
 */
typedef void (*iot_task_msg_execute_func_t)(iot_task_h task_h,
    iot_task_msg_t *msg);

/**
 * @brief (*iot_task_msg_cancel_func_t)() -- function callback to handle msg canceling case
 * @param task_h:     iot task handle of the message
 * @param msg:        pointer to message to be canceled
 */
typedef void (*iot_task_msg_cancel_func_t)(iot_task_h task_h,
    iot_task_msg_t *msg);

/* task message queue configuration */
typedef struct _iot_task_msg_queue_config {
    /* assgined quota of the queue. if quota is 0, it means quota feature
     * disabled for this queue. quota queue rule:
     * 1. task handle quota disabled queues first
     * 2. then task handle quota available queues
     * 3. task handle quota exhausted queues last
     * 4. once quota of all quota enabled queues exhausted, quota will be
     *    reassigned to each quota enabled queue.
     */
    uint8_t         quota;
} iot_task_msg_queue_config_t;

/* task configuration */
typedef struct _iot_task_config {
    /* task stack size, set to 0 to use default stack size. unit is 4 bytes. */
    uint32_t                        stack_size;
    /* task priority */
    uint8_t                         task_prio;
    /* task message size */
    uint8_t                         msg_size;
    /* task message count */
    uint8_t                         msg_cnt;
    /* task message queue count, should be less than IOT_TASK_QUEUE_CNT_MAX */
    uint8_t                         queue_cnt;
    /* configuration of each queue. the lower the index, the higher the priority
     * of the queue. Higer priority queues fall into the same quota rule will
     * be executed first.
     */
    iot_task_msg_queue_config_t     queue_cfg[IOT_TASK_QUEUE_CNT_MAX];
    /* function pointer to handle task events */
    iot_task_event_func_t           task_event_func;
    /* function pointer to handle message executing */
    iot_task_msg_execute_func_t     msg_exe_func;
    /* function pointer to handle message canceling */
    iot_task_msg_cancel_func_t      msg_cancel_func;
} iot_task_config_t;

/**
 * @brief iot_task_create_with_name() - create a message driven based task
 *                          context. the task handles messages delivered to it.
 * @param module: the id of the module to create the task. For debug purpose.
 * @param cfg:    pointer of the task configuration
 * @param name:   task name string
 *
 * @return          NULL -- for failure case
 * @return          otherwise -- iot task message
 */
iot_task_h iot_task_create_with_name(module_id_t module,
    iot_task_config_t *cfg, const char *name);

/**
 * @brief iot_task_create() - create a message driven based task context.
 *                     the task handles messages delivered to it.
 * @param module: the id of the module to create the task. For debug purpose.
 * @param cfg:    pointer of the task configuration
 *
 * @return          NULL -- for failure case
 * @return          otherwise -- iot task message
 */
#define iot_task_create(module, cfg) \
    iot_task_create_with_name(module, cfg, __FUNCTION__)

/**
 * @brief iot_task_delete() - delete a message driven based task context.
 * @param task_h:   iot task handle
 */
void iot_task_delete(iot_task_h task_h);

/**
 * @brief iot_task_alloc_msg_with_reserved() - allocate task message to be
 *                                      delivered to a specified iot task with
 *                                      reserved free messages in the queue.
 * @param task_h:   iot task handle
 * @param reserved: reserved free messages required after this allocation,
 *                  if the reserved free messages not enough, the request will
 *                  be failed.
 *
 * @return          NULL -- for failure case
 * @return          otherwise -- iot task message
 */
iot_task_msg_t *iot_task_alloc_msg_with_reserved(iot_task_h task_h,
    uint32_t reserved);

/**
 * @brief iot_task_alloc_msg() - allocate task message to be delivered to
 *                        a specified iot task.
 * @param task_h:   iot task handle
 *
 * @return          NULL -- for failure case
 * @return          otherwise -- iot task message
 */
#define iot_task_alloc_msg(task_h) \
    iot_task_alloc_msg_with_reserved(task_h, 0)

/**
 * @brief iot_task_free_msg() - free task message to be delivered to a specified
 *                              iot task.
 * @param task_h:   iot task handle
 * @param msg:      pointer to the task message to be freed
 */
void iot_task_free_msg(iot_task_h task_h, iot_task_msg_t *msg);

/**
 * @brief iot_task_queue_msg() - queue task message to the queue of a specified
 *                          iot task.
 * @param task_h:   iot task handle
 * @param msg:      pointer to the task message to be queued
 * @param prio:     priority of the queue to be queued. The lower the number,
 *                  the higher the priority. max priority is same as the number
 *                  of queues configured while creating the iot task.
 */
void iot_task_queue_msg(iot_task_h task_h, iot_task_msg_t *msg, uint8_t prio);

/**
 * @brief iot_task_clean_msg() - clean up specified messages of a specified
 * @param task_h:   iot task handle
 * @param type:     type of the messages to be canceled
 * @param id:       id of messages to be canceled, can set 0xffff to delete
 *                  all of id.
 */
void iot_task_clean_msg(iot_task_h task_h, uint16_t type, uint16_t id);

/**
 * @brief iot_task_get_os_task_h() - convert iot task handle to os task handle
 * @param task_h:   iot task handle
 *
 * @return          os task handle
 */
os_task_h iot_task_get_os_task_h(iot_task_h task_h);

/**
  * @}
  */
#endif /* IOT_TASK_API_H */
