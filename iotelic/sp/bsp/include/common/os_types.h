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

#ifndef OS_TYPES_H
#define OS_TYPES_H

#include <stdint.h>

#ifndef IOT_ASSERT
extern void assert_failed(unsigned char *file, unsigned long line);
#define IOT_ASSERT(x) \
        ((!(x))?assert_failed((unsigned char *)__FILE__, __LINE__):NULL)
#endif

#define true    1
#define false   0
typedef uint8_t bool;

#define NULL    ((void *)0)

#define IRAM_ATTR

#endif /* OS_TYPES_H */

