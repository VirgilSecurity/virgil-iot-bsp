/****************************************************************************

Copyright(c) 2016 - 2017 by IoTelic Technologies. ALL RIGHTS RESERVED.

This Information is proprietary to IoTelic Technologies and MAY NOT
be copied by any method or incorporated into another program without
the express written consent of Iotelic. This Information or any portion
thereof remains the property of Iotelic. The Information contained herein
is believed to be accurate and Iotelic assumes no responsibility or
liability for its use in any way and conveys no license or title under
any patent or copyright and makes no representation or warranty that this
Information is free from patent or copyright infringement.

****************************************************************************/
#ifndef _IOT_GPIO_API_H_
#define _IOT_GPIO_API_H_

/** \defgroup Gpio_APIs Gpio APIs
  * @brief Gpio APIs
  *
  *
  *
  */

/** @addtogroup Gpio_APIs
  * @{
  */

/**
  * @brief GPIO mode.
  */
enum gpio_mode
{
    GPIO_INPUT, /**< GPIO for INPUT using. */
    GPIO_OUTPUT, /**< GPIO for OUTPUT using. */
    GPIO_INTERRUPT, /**< GPIO for INTERRUPT using */
    GPIO_INVALID /**< Invalid value */
};

/**
  * @brief GPIO pull mode.
  */
enum gpio_pull_mode
{
    GPIO_PULL_NONE,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN,
    GPIO_PULL_UP_DOWN
};

/**
  * @brief GPIO opendrain mode.
  */
enum gpio_drain_mode
{
    GPIO_DRAIN_NORMAL,
    GPIO_DRAIN_ONLY_1,
    GPIO_DRAIN_ONLY_0,
};

/**
  * @brief Modes of interrupt. Only when gpio_mode set as GPIO_INTERRUPT,
  * int_mode is available.
  */
enum gpio_int_trigger_mode
{
    GPIO_INT_DISABLE, /**< Disable the interrupt. */
    GPIO_INT_LEVEL_HIGH, /**< Interrupt triggered when the voltage of this GPIO
        stays in HIGH. */
    GPIO_INT_LEVEL_LOW, /**< Interrupt triggered when the voltage of this GPIO
        stays in LOW. */
    GPIO_INT_EDGE_RAISING, /**< Interrupt triggered when the voltage of this
        GPIO switchs from LOW to HIGH. */
    GPIO_INT_EDGE_FALLING, /**< Interrupt triggered when the voltage of this
        GPIO switchs from HIGH to LOW. */
    GPIO_INT_EDGE_BOTH, /**< Interrupt triggered when the voltage of this GPIO
        switchs to HIGH or LOW . */
    GPIO_INT_INVALID /**< Invalid value */
};

typedef int (*iot_gpio_func1)(int);
typedef int (*iot_gpio_func2)(int, int);

/**
 * @brief iot_gpio_open_as_input() - Open an GPIO as inputting.
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @see iot_gpio_open_as_output()
 * @see iot_gpio_open_as_interrupt()
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_gpio_open_as_input(int gpio);

/**
 * @brief iot_gpio_open_as_output() - Open an GPIO as outputting.
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @see iot_gpio_open_as_input()
 * @see iot_gpio_open_as_interrupt()
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_gpio_open_as_output(int gpio);

/**
 * @brief iot_gpio_open_as_interrupt() - Open an GPIO as interrupting.
 * When an GPIO opened as interrupting,
 * iot_gpio_interrupt_config() should be called .
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @see iot_gpio_open_as_input()
 * @see iot_gpio_open_as_output()
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_gpio_open_as_interrupt(int gpio);

/**
 * @brief iot_gpio_interrupt_config() - This function should be called after
 * iot_gpio_open_as_interrupt() to configure an interrupt.
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @param mode: Interrupt trigger mode.@see enum int_trigger_mode.
 * @param isr:  Interrupt call-back function. It's a function pionter
 * like int (*isr)(int).
 * @param arg:  Argument for isr.
 * @param auto_stop:  Interrupt will be disabled the time after interrupt
 * pending and before isr called if auto_stop is true.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_gpio_interrupt_config
    (int gpio, enum gpio_int_trigger_mode mode, iot_gpio_func1 isr, int arg,
    int auto_stop);

/**
 * @brief iot_gpio_interrupt_enable() - Enable or disable the interrupt.
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @param enable: Disable the interrupt if 'enable' is 0, otherwase enable it.
 * @see iot_gpio_interrupt_config()
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_gpio_interrupt_enable(int gpio, int enable);

/**
 * @brief iot_gpio_value_get() - Get the logic value of an GPIO.An GPIO will be
 * configured as inputting if this GPIO was outputting before
 * iot_gpio_value_get() is called.
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @see ERR_FAIL
 * @return 1 -- Logic high..
 * @return 0 -- Logic low.
 * @return ERR_FAIL -- Operation failed.
 */
int iot_gpio_value_get(int gpio);

/**
 * @brief iot_gpio_value_set() - Set the logic value of an GPIO.
 * An GPIO will be configured as outputting if this GPIO was inputting before
 * iot_gpio_value_set() is called.
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @param value: Set the logic value as low if 'value' is 0, otherwase as high.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_gpio_value_set(int gpio, int value);

/**
 * @brief iot_gpio_set_opendrain_mode() - Set the open drain of an GPIO.
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @param drain_mode:Open drain mode.@see enum gpio_drain_mode.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_gpio_set_opendrain_mode(int gpio, enum gpio_drain_mode drain_mode);

/**
 * @brief iot_gpio_set_pull_mode() - Set the pull up/down of an GPIO.
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @param pull_mode:Pull up/down.@see enum gpio_pull_mode.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_gpio_set_pull_mode(int gpio, enum gpio_pull_mode pull_mode);

/**
 * @brief iot_gpio_close() - Close an GPIO.Interrupt will be disabled if this
 * GPIO opened as interrupt.
 * @param gpio: GPIO-NO that starts from 'Zero'.
 * @see iot_gpio_open_as_input()
 * @see iot_gpio_open_as_output()
 * @see iot_gpio_open_as_interrupt()
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_gpio_close(int gpio);

/**
  * @}
  */

#endif