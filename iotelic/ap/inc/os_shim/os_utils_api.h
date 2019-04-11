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

#ifndef OS_SHIM_UTILS_API_H
#define OS_SHIM_UTILS_API_H

/* os shim includes */
#include "os_types_api.h"


/** \defgroup OS_APIs PLC OS APIs
  * @brief WQ30x1 PLC OS APIs
  */


/** @addtogroup OS_APIs
  * @{
  */

/** \defgroup OS_UTILS_APIs PLC OS UTILS APIs
  * @brief PLC OS UTILS
  *
  * OS Timer helper function for applications
  *
  */

/** @addtogroup OS_UTILS_APIs
  * @{
  */

/**
 * @brief os_boot_time32() - get the time since boot up in ms. uint32_t time
 * value will overflow in 49.71 days.
 *
 * @return                     duration in milliseconds since the system boot up
 */
uint32_t os_boot_time32();

/**
 * @brief os_boot_time64() - get the time since boot up in ms
 *
 * @return                     duration in milliseconds since the system boot up
 */
uint64_t os_boot_time64();

/**
 * @brief os_rand() - get a pseudo random number
 *
 * @return                     a pseudo random number
 */
uint32_t os_rand();

/**
 * @brief os_delay - wait for timeout (Time Delay)
 * @param millisec:             millisec time delay value
 */
uint32_t os_delay(uint32_t millisec);

/**
 * @brief: convert a value from network byte order to host byte order
 */
static inline uint16_t os_ntoh_16(uint16_t value) {
    return (value >> 8) | (value << 8);
}

static inline uint32_t os_ntoh_32(uint32_t value) {
    return ((value & 0xFF) << 24) |
           ((value & 0xFF00) << 8) |
           ((value & 0xFF0000) >> 8) |
           ((value & 0xFF000000) >> 24);
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* OS_SHIM_UTILS_API_H */