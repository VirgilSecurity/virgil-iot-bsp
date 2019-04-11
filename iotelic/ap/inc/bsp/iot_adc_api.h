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

#ifndef IOT_ADC_API_H
#define IOT_ADC_API_H

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
  * @brief ADC channel.
  */
typedef enum {
    ADC_CHANNEL0 = 0,
    ADC_CHANNEL1 = 1,
    ADC_CHANNEL2 = 2,
    ADC_CHANNEL3 = 3,
    ADC_CHANNEL4 = 4,
    ADC_CHANNEL5 = 5,
    ADC_CHANNEL2_3 = 6,
    ADC_CHANNEL0_1 = 7,
}ADC_CHANNEL;

/**
  * @brief ADC ACC.
  */
typedef enum {
    ADC_ACC16 = 4,
    ADC_ACC64 = 6,
}ADC_ACC;

/**
  * @brief ADC GAIN.
  */
typedef enum {
    ADC_GAIN_1V = 11,
    ADC_GAIN_3V = 15,
}ADC_GAIN;

/**
 * @brief iot_adc_init() - init adc sub system
 *
 */
void iot_adc_init();

/**
 * @brief iot_adc_set_channel() - set adc's channel
 * @param ch:  adc channel.
 */
void iot_adc_set_channel(uint32_t ch);

/**
 * @brief iot_adc_start() - start adc's sample
 * @param ch:  adc channel.
 */
void iot_adc_start(uint32_t ch);

/**
 * @brief iot_adc_stop() - stop adc's sample
 * @param ch:  adc channel.
 */
void iot_adc_stop(uint32_t ch);

/**
 * @brief iot_adc_poll_done() - poll adc's output
 * @param ch:  adc channel.
 * @param acc:  enum ADC_ACC
 * @param gain: enum ADC_GAIN
 * @param timeout: timeout return value;
                   0 - normal. data is OK
                   1 - timeout, data is not OK.
 * @return        adc value
 */
int16_t iot_adc_poll_done(uint32_t ch, uint8_t acc, uint8_t gain, uint8_t *timeout);

#endif //IOT_ADC_API_H
