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

#ifndef IOT_CRC_API_H
#define IOT_CRC_API_H

/* os shim includes */
#include "os_types_api.h"
#include "os_mem_api.h"

/** \defgroup MISC_APIs MISC APIs
 *  @brief MISC APIs
 *
 *
 */

/** @addtogroup MISC_APIs
 * @{
 *
 */

/**
 * brief: get 32bit CRC value from a byte stream with init vector 
 * @param init_vect:    the init vector
 * @param buffer:       buffer with data for crc calculating
 * @param len:          length of the buffer
 * @retval:             the CRC of data in buffer
 */
uint32_t iot_getcrc32_update(uint32_t init_vect, uint8_t *buffer, uint32_t len);

/**
 * brief: get 32bit CRC value from a byte stream
 * @param buffer:       buffer with data for crc calculating
 * @param len:          length of the buffer
 * @retval:             the CRC of data in buffer
 */
uint32_t iot_getcrc32(uint8_t *buffer, uint32_t len);

/**
  * @}
  */

#endif /* IOT_UTILS_API_H */
