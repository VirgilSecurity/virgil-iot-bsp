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

#ifndef CPL_TYPES_API_H
#define CPL_TYPES_API_H

#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>

/* TBD. need to define this macro to force crash function of gcc */
#ifndef IOT_ASSERT
extern void assert_failed(unsigned char *pucFile, unsigned long ulLine);
#define IOT_ASSERT(x) \
    ((!(x))?assert_failed((unsigned char *)__FILE__, __LINE__):NULL)
#endif

#ifndef IOT_ASSERT_DUMP
extern void assert_failed_dump(unsigned char *pucFile, unsigned long ulLine,
        uint32_t *p, uint32_t size);
#define IOT_ASSERT_DUMP(x, p, s) \
    ((!(x))?assert_failed_dump((unsigned char *)__FILE__, __LINE__, p, s):NULL)
#endif

#ifndef NULL
#define NULL    ((void *)0)
#endif

#define PREPACK
#define POSTPACK

#endif /* CPL_TYPES_API_H */

