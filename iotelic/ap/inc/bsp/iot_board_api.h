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

#ifndef IOT_BOARD_API_H
#define IOT_BOARD_API_H

#include "os_types_api.h"

/** \defgroup BOARD_INFO_APIs
  * @brief WQ30x1 BOARD_INFO API
  */

/** @addtogroup BOARD_INFO_APIs
  * @{
  */

#define GPIO_PLC_EVENT  0
#define GPIO_STA_OUT    1
#define GPIO_TX_LED     2
#define GPIO_RX_LED     3
#define GPIO_PA_LED     4
#define GPIO_PB_LED     5
#define GPIO_PC_LED     6
#define GPIO_RS485_TXE  7
#define GPIO_IR_TXD     8
#define GPIO_IR_RXD     9
#define GPIO_GEODE_OVT  10
#define GPIO_SMART_BOOT_SEL 11
#define GPIO_PM_CHARGE_EN 12
#define GPIO_RST_CTRL   13

/* watchdog reset */
#define SYSTEM_RESET_WDT    0
/*soft reset */
#define SYSTEM_RESET_SOFT   1
/*power on reset */
#define SYSTEM_RESET_PWR    2

/* watchdog boot */
#define SYSTEM_BOOT_WDT     0
/* soft-reset boot */
#define SYSTEM_BOOT_SOFT    1
/* power-on boot */
#define SYSTEM_BOOT_PWR     2

/**
 * @brief iot_board_get_uart() - get a uart port
 * @param type:            the define UART_xxxx_PORT
 *
 * @return                      uart port
 */
uint8_t iot_board_get_uart(uint8_t type);


/**
 * @brief iot_board_get_gpio() - get a gpio
 * @param type:            the define GPIO_XXX
 *
 * @return                      gpio pin
 */
uint8_t iot_board_get_gpio(uint8_t type);

/**
 * @brief iot_board_get_led() - get a led's gpio
 * @param type:            led's id
 *
 * @return                      gpio pin
 */
uint8_t iot_board_get_led(uint8_t id);
/**
 * @brief iot_board_get_led_cnt() - get a led's total number
 *
 * @return                      gpio pin
 */
uint8_t iot_board_get_led_cnt();

/**
 * @brief iot_board_get_led_id() - get a led's id
 * @param sig_out:              gpio matrix signal out number
 *
 * @return                      gpio pin
 */
uint8_t iot_board_get_led_id(uint8_t sig_out);

/**
 * @brief iot_board_get_reset_count() - get reset count
 * @param type:              the define SYSTEM_RESET_xxx
 *
 * @return                      reset count
 */
uint32_t iot_board_get_reset_count(uint8_t type);

/**
 * @brief iot_board_get_boot_reason() - get boot reason
 *
 * @return                      boot reason (defined SYSTEM_BOOT_XXX)
 */
uint32_t iot_board_get_boot_reason();

/**
  * @}
  */

#endif /*IOT_BOARD_API_H*/
