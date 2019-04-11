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
#include <windows.h>

/**
 * temporarily inlcude this file for logging funtion.
 * it should be removed after logging module ready.
 */
#include <stdio.h>

/**
 * temporarily inlcude this file for assert funtion.
 * it should be removed after logging module ready.
 */
__pragma(warning(disable:4127))

#define IOT_ASSERT(cond) \
    do { \
        if ((uint32_t)(cond) == 0) { \
            int*assert_val = NULL; \
            *assert_val = 0; \
        } \
    } while(0)

#define IOT_ASSERT_DUMP(x, p, s) IOT_ASSERT(x)

/**
 * Forces code into IRAM instead of flash.
 * In windows, it defined to null.
 */
#define IRAM_ATTR


/**
 * bit field can have endian difference
 * and can be processed per compiler.
 * use little endian by default.
 * GCC would not give warning for C4214
 * VC has no inline packed define, so ignore it here
 */
#define PREPACK __declspec(align(1))
#define POSTPACK

/**
 * VS seems have a bug when Debugger to calcualte the
 * Debugger 's alignment, the WAR is force the pack
 * set the default alignment for VS Debugger
 * 4 bytes align
 */
#pragma pack(1)

/* suppress the warning for VC */
#pragma warning(push)
/* bit field types other than int */
#pragma warning(disable:4214)
/* avoid zero-sized array warning */
#pragma warning(disable:4200)
/* avoid 'type cast':from function pointer to void* */
#pragma warning(disable:4054)
/* avoid 'type cast':void* to from function pointer */
#pragma warning(disable:4055)

#endif /* CPL_TYPES_API_H */
