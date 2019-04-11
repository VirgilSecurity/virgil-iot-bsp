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
#ifndef _IOT_NAND_FLASH_API_H
#define _IOT_NAND_FLASH_API_H

/**
 * @brief nandfc_read_chip_info() - get chip ID
 *
 * @return              the value of the chip ID
 */
uint8_t iot_nandfc_read_chip_ID(void);

/**
 * @brief nandfc_read_manufacture_ID() - get manufacture ID
 *
 * @return              the value of the manufacture ID
 */
uint8_t iot_nandfc_read_manufactury_ID(void);

/**
 * @brief nandfc_reset_device() - set feature register
 *
 * @return              0 success
 * @return              1 failed
 */
int iot_nandfc_reset_device(void);

/**
 * @brief iot_nandfc_erase_block() - set feature register
 * @param addr:         the block address to be erasen
 * @return              0 success
 * @return              1 failed
 */
int iot_nandfc_erase_block(uint32_t addr);

/**
 * @brief iot_nandfc_read_data() - read the random data within addressed page
 * @param data:         the pointer of read back data
 * @param star_addr:    the start address to be read out
 * @param lenth:        the byte number to be read back
 * @return              0 success
 * @                    1 failed
 */
int iot_nandfc_read_data(void* data, uint32_t star_addr, uint32_t lenth);

/**
 * @brief nandfc_program_data_with_erase() - erase the block then write the into the addressed page
 * @param data:         the pointer of read back data
 * @param star_addr:    the start address to be writen
 * @param byte_num:     the byte number to be writen
 * @return              0 success
 * @                    1 failed
 */

int iot_nandfc_program_data_with_erase(const void* data, uint32_t star_addr, uint32_t byte_num);

/**
 * @brief nandfc_init() - initialize the interface of nand flash
 *
 * @return              0 success
 * @                    1 failed
 */
int iot_nandfc_init(void);

#endif /*_IOT_NAND_FLASH_API_H*/
