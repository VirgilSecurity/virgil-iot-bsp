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
#ifndef IOT_VERSION_API_H
#define IOT_VERSION_API_H

#define BUILD_TIME_YEAR 17
#define BUILD_TIME_MONTH 5
#define BUILD_TIME_DATE 19
#define BUILD_TIME_HOUR 16
#define BUILD_TIME_MIN 9
#define BUILD_TIME_SEC 0

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
 * @brief iot_version_major() - firmware's major version
 *
 * @return             major version
 */
uint8_t iot_version_major(void);

/**
 * @brief iot_version_minor() - firmware's minor version
 *
 * @return             minor version
 */
uint8_t iot_version_minor(void);

/**
 * @brief iot_version_micro() - firmware's micro version
 *
 * @return             micro version
 */
uint8_t iot_version_micro(void);

/**
 * @brief iot_version_build() - firmware's build id
 *
 * @return             build id
 */
uint16_t iot_version_build(void);

/**
 * @brief iot_version_hex() - convert firmware's version to hex
 *
 * @return             hex version
 */
uint32_t iot_version_hex(void);

/**
 * @brief iot_version_type() - firmware's build type
 *
 * @return            build type
 *                    0 - release
 *                    1 - debug
 */
uint8_t iot_version_type(void);

/**
  * @}
  */
#endif /* IOT_VERSION_API_H */
