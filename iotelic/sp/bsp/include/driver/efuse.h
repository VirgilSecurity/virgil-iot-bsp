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
#ifndef _EFUSE_H_
#define _EFUSE_H_

#include <stdint.h>

typedef struct {
    uint8_t  name[30];
    uint16_t addr;
} efuse_table_entry;

void efuse_dump();

uint8_t efuse_byte_read(int offset);

int efuse_byte_write(int offset, uint8_t val);

int efuse_protect();

int efuse_protect_off();

#endif /* _EFUSE_H_ */
