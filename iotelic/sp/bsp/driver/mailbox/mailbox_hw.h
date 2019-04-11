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
#ifndef _MAILBOX_HW_H_
#define _MAILBOX_HW_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MB_HW_CHANNEL_NUM       2
#define MB_HW_CHANNEL_DEEP      8


void mb_hw_init();
uint32_t mb_hw_is_full(uint32_t ch);
uint32_t mb_hw_is_empty(uint32_t ch);
uint32_t mb_hw_get_counter_for_read(uint32_t ch);
uint32_t mb_hw_get_counter_for_write(uint32_t ch);
uint32_t mb_hw_read(uint32_t ch, size_t *p_data);
uint32_t mb_hw_write(uint32_t ch, size_t data);
uint32_t mb_hw_get_vector(uint32_t ch, uint32_t *p_vec);

#ifdef __cplusplus
}
#endif

#endif
