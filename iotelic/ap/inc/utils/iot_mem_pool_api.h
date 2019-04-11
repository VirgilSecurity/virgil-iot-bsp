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
/* This is file is modified for embeded use, as the memory is limited, the
 * macro define version inlined would take IRAM for every instance, so we
 * change it to the function version
 */

#ifndef IOT_MEM_POOL_API_H
#define IOT_MEM_POOL_API_H

/* os shim includes */
#include "os_types_api.h"
#include "os_lock_api.h"

/* common includes */
#include "iot_module_api.h"

/** \defgroup MISC_APIs MISC APIs
 *  @brief MISC APIs
 *
 *
 */

/** @addtogroup MISC_APIs
 * @{
 *
 */

typedef union _iot_mem_pool_entry {
    union _iot_mem_pool_entry *next;
    uint32_t data; /* just take the same size of a pointer for place holder */
} iot_mem_pool_entry_t;

typedef struct _mem_pool {
    iot_mem_pool_entry_t *entries;
    iot_mem_pool_entry_t *head;
    uint32_t num;
    uint32_t free_num;
    uint32_t align_block_word_size;
    os_mutex_h pool_mutex;
} iot_mem_pool_t;

/**
 * @brief iot_mem_pool_new() - create a memory pool structure
 * @param m_id:         module's id request
 * @param block_num:    how many blocks can be used max
 * @param block_size:   sizeof(block)
 * @param pool_ptr:     allocated start pointer for the pool if successful
 *
 * @return              0 -- for success
 * @return              otherwise -- for error
 */
uint32_t iot_mem_pool_new(module_id_t m_id,
    uint32_t block_num, uint32_t block_size, iot_mem_pool_t **pool_ptr);

/**
 * @brief iot_mem_pool_init() - init an exist memory pool structure
 * @param block_num:    how many blocks can be used max
 * @param block_size:   sizeof(block)
 * @param pool_ptr:     allocated start pointer for the pool if successful
 *
 * @return              0 -- for success
 * @return              otherwise -- for error
 */
uint32_t iot_mem_pool_init(module_id_t m_id,
    uint32_t block_num, uint32_t block_size, iot_mem_pool_t *pool_ptr);

/**
 * @brief iot_mem_pool_destroy() - destroy the pool
 * NB: not support right now, for fast allocate and recall without memory frag
 * we don't free the pool normally
 * @param pool_ptr:     allocated start pointer for the pool if successful
 *
 * @return              0 -- for success
 * @return              otherwise -- for error
 */
uint32_t iot_mem_pool_destroy(iot_mem_pool_t *pool_ptr);

/**
 * @brief iot_mem_pool_alloc_with_reserve() - alloc a block from the mem pool
 *                  with at least reserved free blocks in the mem pool.
 * @param pool_ptr:     mem pool pointer
 * @param reserved:     reserved free blocks required after this allocation, if
 *              the reserved free blocks not enough, the request will be failed.
 *
 * @return              NULL -- for error case
 * @return              otherwise -- return the block address
 */
void *iot_mem_pool_alloc_with_reserve(iot_mem_pool_t *pool_ptr,
    uint32_t reserved);

/**
 * @brief iot_mem_pool_alloc() - alloc a block from the mem pool.
 * @param pool_ptr:     mem pool pointer
 *
 * @return              NULL -- for error case
 * @return              otherwise -- return the block address
 */
#define iot_mem_pool_alloc(pool_ptr) \
    iot_mem_pool_alloc_with_reserve(pool_ptr, 0)

/**
 * @brief iot_mem_pool_force_free() - return the data to the mem pool by search
 * @param data:     the address for the block allocated by iot_mem_pool_alloc()
 * @param pool_ptr: mem pool pointer
 *
 * @return              0 -- for success
 * @return              otherwise -- for error
 */
uint32_t iot_mem_pool_force_free(iot_mem_pool_t *pool_ptr, void *data);

/**
 * @brief iot_mem_pool_free() - return the data to the mem pool
 * @param data:     the address for the block allocated by iot_mem_pool_alloc()
 * @param pool_ptr: mem pool pointer
 *
 * @return              0 -- for success
 * @return              otherwise -- for error
 */
uint32_t iot_mem_pool_free(iot_mem_pool_t *pool_ptr, void *data);


/**
 * @brief iot_mem_pool_get_freenum() - return the free num of the mem pool
 * @param pool_ptr:     mem pool pointer
 *
 * @return              the free number
 */
uint32_t iot_mem_pool_get_freenum(iot_mem_pool_t *pool_ptr);


/**
  * @}
  */


#endif /* IOT_MEM_POOL_API_H */
