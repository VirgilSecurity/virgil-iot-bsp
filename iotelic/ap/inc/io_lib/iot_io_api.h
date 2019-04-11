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
#ifndef IOT_IO_API_H
#define IOT_IO_API_H

/* os shim includes */
#include "os_types_api.h"

/* common includes */
#include "iot_config_api.h"

/** \defgroup STRINGIO_APIs STRING IO APIs
  * @brief WQ30x1 STRING IO APIs
  *
  * string helper handle functions for cusotmer applications
  *
  */

/** @addtogroup STRINGIO_APIs
  * @{
  */

/**
 * @brief iot_printf() - print content per format.
 * @param fmt:           the module that creates the event.
 *
 * @return               0 -- always return 0
 */
#if IOT_PRINTF_DEBUG

int32_t iot_printf(const char *fmt, ...);

#else /* IOT_PRINTF_DEBUG */

#define iot_printf(fmt, ...) \
    do { \
        (void)fmt; \
        extern int32_t __iot_printf(uint8_t dummy, ...); \
        __iot_printf(0, ##__VA_ARGS__); \
    } while (0)

#endif /* IOT_PRINTF_DEBUG */


/**
 * @brief iot_cus_printf() -  app used print content per format.
 * @param fmt:           the module that creates the event.
 *
 * @return               0 -- always return 0
 */

int32_t iot_cus_printf(const char *fmt, ...);

/**
 * @brief iot_cus_printf_config(uint8_t enable) - enable or disable iot_printf
 *             this function for app to contorl iot_printf
 * @param enable:                1 - enable uart print. 0 disable
 *
 * @return                       none
 */
void iot_cus_print_config(bool_t enable);

/**
 * @brief iot_sprintf() - print content to target str buffer per format and size.
 * @param str:                   target str buffer
 * @param size                   buffer size
 * @param fmt:                   string format
 *
 * @return                       written content length
 */
int32_t iot_snprintf(char *str, size_t size, const char *format, ...);

/**
 * @brief iot_sprintf() - print content to target str buffer per format and size.
 * @param str:                   target str buffer
 * @param size                   buffer size
 * @param fmt:                   string format
 * @param ap:                    var list used for fmt
 *
 * @return                       written content length
 */
int32_t iot_vsnprintf(char *str, size_t size, const char *format, va_list ap);

/**
 * @brief iot_sprintf() - print content to target str per format.
 * @param str:                   target str buffer
 * @param fmt:                   string format
 *
 * @return                       written content length
 */
int32_t iot_sprintf(char *str, const char *format, ...);

/**
  * @}
  */

#endif /* IOT_IO_API_H */
