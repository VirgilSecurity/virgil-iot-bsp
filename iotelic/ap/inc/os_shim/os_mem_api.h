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

#ifndef OS_SHIM_MEM_API_H
#define OS_SHIM_MEM_API_H

/* os shim includes */
#include "os_types_api.h"

/* common includes */
#include "iot_module_api.h"

/** \defgroup OS_APIs PLC OS APIs
  * @brief WQ30x1 PLC OS APIs
  */


/** @addtogroup OS_APIs
  * @{
  */

/** \defgroup OS_MEM_APIs PLC OS MEM APIs
  * @brief PLC OS MEM
  *
  * OS MEMORY helper function for customer application
  */

/** @addtogroup OS_MEM_APIs
  * @{
  */

/**
 * @brief os_mem_cpy() - copy memory from one location to another, similar to
 * memcpy in standard c. Calling this function with overlapping source and
 * destination memory location will result in unpredictable result.
 * @param dst:              pointer to destination memory location
 * @param src:              pointer to source memory location
 * @param len:              number of bytes to copy
 */
void os_mem_cpy(void *dst, const void *src, uint32_t len);

/**
 * @breif os_mem_move() - move memory from one location to another, similar as
 * os_mem_cpy except that this function take care of source and destination
 * memory location overlapped case.
 * @param dst:              pointer to destination memory location
 * @param src:              pointer to source memory location
 * @param len:              number of bytes to be copied
 */
void os_mem_move(void *dst, const void *src, uint32_t len);

/**
 * @breif os_mem_cmp() - memory compare, compare two pieces of memory, similar
 * to memcmp function in standard c.
 * @param dst:              pointer to first location in memory to compare
 * @param src:              pointer to second location in memory to compare
 * @param len:              number of bytes to compare
 *
 * @return                  0 -- equal
 * @return                  < 0 -- dst is less than src
 * @return                  > 0 -- dst is bigger than src
 */
int32_t os_mem_cmp(const void *dst, const void *src, uint32_t len);

/**
 * @breif os_mem_set() - set memory with a specified byte value
 * @param ptr:              pointer to memory that will be set
 * @param value:            byte set in memory
 * @param len:              number of bytes to be set
 */
void os_mem_set(void *ptr, uint8_t value, uint32_t len);

/**
 * @breif os_mem_malloc() - allocate memory. Dynamicallly allocate
 * the number of bytes of memory. The allocated memory must be reset to 0.
 * @param module_id:     the module mallocing memory. For the debugging purpose.
 * @param size:          number of bytes of memory to be allocated
 *
 * @return               null -- for failure case
 * @return               otherwise -- pointer of allocated memory
 */
void *os_mem_malloc(module_id_t module_id, size_t size);

/**
 * @breif os_mem_free() - free memory
 * @param ptr:           pointer to the memory to be free'd.
 */
void os_mem_free(void *ptr);

/**
  * @}
  */

/**
  * @}
  */

#endif /* OS_SHIM_MEM_API_H */