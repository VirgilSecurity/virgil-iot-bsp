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

#ifndef IOT_ADDR_HASH_TABLE_API_H
#define IOT_ADDR_HASH_TABLE_API_H

/* os shim includes */
#include "os_types_api.h"

/* common includes */
#include "iot_utils_api.h"

/** \defgroup MISC_APIs MISC APIs
 *  @brief MISC APIs
 *
 *
 */

/** @addtogroup MISC_APIs
 * @{
 *
 */


/* iot mac address hash table entry */
typedef struct _iot_addr_hash_entry {
    struct _iot_addr_hash_entry *next;
    /* mac address of the meter */
    uint8_t             addr[IOT_MAC_ADDR_LEN];
} iot_addr_hash_entry_t;

/* iot mac address hash table handle */
typedef void *iot_addr_hash_table_h;

/* @brief mac address hash table loop callback definition
 * @param entry:    hash table entry to be checked
 * @param param:    same as the value whill invoke iot_addr_hash_table_loop
 */
typedef void (*iot_addr_hash_loop_func_t)(iot_addr_hash_entry_t *entry,
    void *param);

/**
 * @brief iot_addr_hash_table_create() - create a iot mac address table
 * @param module:      id of the module calling this function
 * @param entry_cnt:   number of entries supported
 * @param entry_size:  memory size of each entry
 * @param table_size:  hash table size. The size is an exponent for 2. so if
 *                     this value is 3, than the actual table size will be 8.
 *                     The larger the table, the smaller the possibilty to hit
 *                     hash key conflict.
 *
 * @return              NULL - for failure case
 * @return              otherwise - iot mac address hash table handle
 */
iot_addr_hash_table_h iot_addr_hash_table_create(module_id_t module,
    uint16_t entry_cnt, uint16_t entry_size, uint16_t table_size);

/**
 * @brief iot_addr_hash_table_delete() - delete a iot mac address table
 * @param handle:   iot mac address table handle
 */
void iot_addr_hash_table_delete(iot_addr_hash_table_h handle);

/**
 * @brief iot_addr_hash_table_add() - add an entry into the hash table
 * @param handle:   iot mac address table handle
 * @param entry:    the entry to be added
 *
 * @return          0 -- for success case
 * @return          otherwise -- error code
 */
uint32_t iot_addr_hash_table_add(iot_addr_hash_table_h handle,
    iot_addr_hash_entry_t *entry);

/**
 * @brief iot_addr_hash_table_remove() - remove an entry from the hash table
 * @param handle:   iot mac address table handle
 * @param entry:    the entry to be removed
 */
void iot_addr_hash_table_remove(iot_addr_hash_table_h handle,
    iot_addr_hash_entry_t *entry);

/**
 * @brief iot_addr_hash_table_find() - find an entry in the specified hash table
 * @param handle:   iot mac address table handle
 * @param addr:     iot mac address of the entry to be searched
 *
 * @return          NULL -- for failure case
 * @return          otherwise -- pointer to mac address entry
 */
iot_addr_hash_entry_t *iot_addr_hash_table_find(iot_addr_hash_table_h handle,
    uint8_t* addr);

/**
 * @brief iot_addr_hash_table_loop() - loop hash table entry
 * @param handle:   iot mac address table handle to be looped
 * @param func:     callback to check each hash table entry
 * @param param:    parameter to be passed to the callback
 */
void iot_addr_hash_table_loop(iot_addr_hash_table_h handle,
    iot_addr_hash_loop_func_t func, void *param);

/**
 * @brief iot_addr_hash_table_alloc() - allocate an free entry from the hash
 *                                      table.
 * @param handle:   iot mac address table handle
 *
 * @return          NULL -- for failure case
 * @return          otherwise -- pointer to mac address entry
 */
iot_addr_hash_entry_t *iot_addr_hash_table_alloc(iot_addr_hash_table_h handle);

/**
 * @brief iot_addr_hash_table_free() - free an entry back to the specified hash
 *                                     table
 * @param handle:   iot mac address table handle
 * @param entry:    pointer to mac address entry to be freed
 */
void iot_addr_hash_table_free(iot_addr_hash_table_h handle,
    iot_addr_hash_entry_t *entry);
/**
  * @}
  */


#endif /* IOT_ADDR_HASH_TABLE_API_H */