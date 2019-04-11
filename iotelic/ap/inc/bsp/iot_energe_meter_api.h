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
#ifndef IOT_ENERGE_METER_API_H
#define IOT_ENERGE_METER_API_H


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
 * @brief iot_energe_meter_init() - enable energe meter sub system
 *
 */
void iot_energe_meter_init();

/**
 * @brief iot_energe_meter_get_rms_voltage() - get voltage's rms.
 * @return voltage's rms
 *
 */
float iot_energe_meter_get_rms_voltage(void);

/**
 * @brief iot_energe_meter_get_rms_current() - get current's rms.
 * @return current's rms
 *
 */
float iot_energe_meter_get_rms_current(void);

/**
 * @brief iot_energe_meter_get_active_power() - get active power.
 * @return active power
 *
 */
float iot_energe_meter_get_active_power(void);

/**
 * @brief iot_energe_meter_get_reactive_power() - get reactive power.
 * @return reactive power
 *
 */
float iot_energe_meter_get_reactive_power(void);

/**
 * @brief iot_energe_meter_get_factor() - get power factor.
 * @return power factor
 *
 */
float iot_energe_meter_get_power_factor(void);

/**
 * @brief iot_energe_meter_get_freq() - get main frequency.
 * @return main frequency
 *
 */
uint32_t iot_energe_meter_get_freq(void);

/**
 * @}
 */

#endif /*IOT_ENERGE_METER_API_H*/
