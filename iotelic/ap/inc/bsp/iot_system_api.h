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
#ifndef IOT_SYSTEM_API_H
#define IOT_SYSTEM_API_H

/**
 * @brief   iot_system_restart() - Restart SP and AP CPUs
 *                      This function can be called both from SP and AP CPUs.
 *                      After successful restart, CHIP will boot from ROM.
 */
void iot_system_restart(void);

/**
 * @brief   iot_data_addr_legal() - Whether the address is legal or not
 * @param   addr        the input address
 * @return
 * @return              true -- the input address is legal
 * @return              false -- the input address is illegal
 */
bool_t iot_data_addr_legal(uint32_t addr);

#endif //IOT_SYSTEM_API_H

