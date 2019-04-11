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
#ifndef IOT_STRING_API_H
#define IOT_STRING_API_H

/* os shim includes */
#include "os_types_api.h"

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
 * @brief iot_strchr() - find the first occurrence of character in the string.
 * @param s:                   string
 * @param c:                   character to be located
 *
 * @return                     NULL -- for cannot find case
 * @return                     otherwise -- a pointer to the first occurrence
 */
char* iot_strchr( const char *s,  uint32_t c );

/**
 * @brief iot_strcpy() - copy the string pointed by source into the buffer.
 * pointed by destination
 * @param s:                   destination buffer
 * @param t:                   string to be copied
 *
 * @return                     NULL -- for cannot find case
 * @return                     otherwise -- a pointer to the first occurrence
 */
char* iot_strcpy( char *s, const char *t);

/**
 * @brief iot_strcmp() - compare the str1 to the str2.
 * @param s:                   string
 * @param c:                   character to be located
 *
 * @return                     NULL -- for cannot find case
 * @return                     otherwise -- a pointer to the first occurrence
 */
uint16_t iot_strcmp( const char *s1, const char *s2 );

/**
 * @brief iot_strlen() - return the length of the str.
 * @param s:                   string
 *
 * @return                     str length
 */
size_t iot_strlen( const char *s );

/**
 * @brief iot_strcat() - append a copy of the source string to the.
 * destination string
 * @param s1:                  destination string
 * @param s2:                  source string
 *
 *
 * @return                     destination string
 */
char* iot_strcat( char *s1, const char *s2 );

/**
  * @}
  */

#endif /* IOT_STRING_API_H */