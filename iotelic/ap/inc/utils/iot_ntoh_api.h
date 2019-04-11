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

#ifndef IOT_NTOH_API_H
#define IOT_NTOH_API_H

#include "os_types_api.h"

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
 * @brief iot_htonl() - convert host 32 bits value to network sequence
 * @param h:           32 bits value
 *
 * @return             network sequence's value
 */
uint32_t iot_htonl(uint32_t h);

/**
 * @brief iot_ntohl() - convert network 32 bits value to host sequence
 * @param n:           32 bits value
 *
 * @return             host sequence's value
 */
uint32_t iot_ntohl(uint32_t n);

/**
 * @brief iot_htons() - convert host 16 bits value to network sequence
 * @param h:           16 bits value
 *
 * @return             network sequence's value
 */
uint16_t iot_htons(uint16_t h);

/**
 * @brief iot_ntohl() - convert network 16 bits value to host sequence
 * @param n:           16 bits value
 *
 * @return             host sequence's value
 */
uint16_t iot_ntohs(uint16_t n);

/**
 * @brief iot_htonll() - convert host 64 bits value to network sequence
 * @param h:           64 bits value
 *
 * @return             network sequence's value
 */
uint64_t iot_htonll(uint64_t h);

/**
 * @brief iot_ntohll() - convert network 64 bits value to host sequence
 * @param n:           64 bits value
 *
 * @return             host sequence's value
 */
uint64_t iot_ntohll(uint64_t n);

/**
  * @}
  */

#endif /*IOT_NTOH_API_H*/
