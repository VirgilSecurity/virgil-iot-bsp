/****************************************************************************

opyright(c) 2016 - 2017 by IoTelic Technologies. ALL RIGHTS RESERVED.

This Information is proprietary to IoTelic Technologies and MAY NOT
be copied by any method or incorporated into another program without
the express written consent of Iotelic. This Information or any portion
thereof remains the property of Iotelic. The Information contained herein
is believed to be accurate and Iotelic assumes no responsibility or
liability for its use in any way and conveys no license or title under
any patent or copyright and makes no representation or warranty that this
Information is free from patent or copyright infringement.
****************************************************************************/
#ifndef   _IOT_NOR_FLASH_API_H
#define _IOT_NOR_FLASH_API_H
/**
 * @brief norfc_fast_read_data_bytes() - fast read data for address
 * @param data:         the data pointer
 * @param star_addr:    the start address
 * @param lenth:        the lenth of reading data
 * @return              0 success
 *                      1 failed
 */
uint8_t iot_norfc_read_data(void* data, uint32_t star_addr, uint32_t lenth);

/**
 * @brief norfc_erase_data() - erase the data which located by the address
 * @param type:         the erase typ: refer to xxx_ERASE_
 * @param addr:         the erase start address
 * @return              0 success
 *                      1 failed
 */
uint8_t iot_norfc_erase_data(uint8_t type, uint32_t addr);

/**
 * @brief norfc_erase_chip() - erase the chip
 * @param NULL:
 * @return              0 success
 *                      1 failed
 */
uint8_t iot_norfc_erase_chip(void);

/**
 * @brief norfc_read_chip_info() - read the chip information
 * @param NULL:
 * @return              information about the chip
 */
uint32_t iot_norfc_read_chip_info(void);

/**
 * @brief norfc_program_page() - write data at the start address
 * @param data:         the data pointer to be programmed
 * @param star_addr:    the start address
 * @param byte_num:     the lenth of reading data
 * @return              0 success
 *                      1 failed
 */
uint8_t iot_norfc_program_page(const void *data, uint32_t star_addr, uint32_t byte_num);

/**
 * @brief norfc_reset_device() - reset the chip
 * @param NULL:
 * @return              0 success
 *                      1 failed
 */
uint8_t iot_norfc_reset_device(void);

/**
 * @brief norfc_init() - initialize the flash
 * @param NULL:
 * @return              0 success
 *                      1 failed
 */
uint8_t iot_norfc_init(void);

#endif /*_IOT_NOR_FLASH_API_H*/

