/****************************************************************************

Copyright(c) 2016 by WuQi Technologies. ALL RIGHTS RESERVED.

This Information is proprietary to WuQi Technologies and MAY NOT
be copied by any method or incorporated into another program without
the express written consent of WuQi. This Information or any portion
thereof remains the property of WuQi. The Information contained herein
is believed to be accurate and WuQi assumes no responsibility or
liability for its use in any way and conveys no license or title under
any patent or copyright and makes no representation or warranty that this
Information is free from patent or copyright infringement.

****************************************************************************/

#ifndef _MAILBOX_H_
#define _MAILBOX_H_

#include "mailbox_hw.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    IPC_APPCPU_ID = 0,
    IPC_SECCPU_ID = 1,
}IPC_CPU_ID;

typedef void(*iot_mb_msg_cb)(void);

uint32_t iot_mb_open(iot_mb_msg_cb cb);
uint32_t iot_mb_close(void);
uint32_t iot_mb_send(uint32_t target, size_t data);
uint32_t iot_mb_read(size_t *p_data);
uint32_t iot_mb_get_read_space(void);
uint32_t iot_mb_get_write_space(uint32_t target);
void iot_mb_init(void);
uint32_t iot_mb_mask();
uint32_t iot_mb_unmask();

#ifdef __cplusplus
}
#endif

#endif
