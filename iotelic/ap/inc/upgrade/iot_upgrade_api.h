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

#ifndef IOT_UPGRADE_API_H
#define IOT_UPGRADE_API_H

#include "iot_pkt_api.h"
#include "iot_queue_api.h"
#include "iot_mem_pool_api.h"
#include "iot_config_api.h"

/** \defgroup UPGARDE_APIs UPGARDE APIs
 *  @brief UPGRADE APIs
 *
 *
 */

/** @addtogroup UPGARDE_APIs
 * @{
 *
 */

#define IOT_XOR_VENDOR_ID               0x4D54
#define IOT_MAGIC_NO                    0x5566
#define IOT_XOR_VALUE                   0xAA
#define IOT_FILE_MODE_PLAIN             0x00
#define IOT_FILE_MODE_ADD               0x01
#define IOT_FILE_MODE_SUB               0x02
#define IOT_FILE_MODE_XOR               0x03
#define IOT_FILE_MODE_UNKNOWN           0xFF

#define IOT_FILE_TYPE_CCO       0
#define IOT_FILE_TYPE_STA       1
#define IOT_FILE_TYPE_INVALID   0xFFFF

#define IOT_FILE_HDR_LEN        0x60

/* 8 blocks in a upgrade window */
#define IOT_SG_STA_UPGRADE_BM_SIZE      (1)
#define IOT_SG_CCO_UPGRADE_BM_SIZE      (1)

#define IOT_SG_CCO_UPGRADE_WINDOW_SIZE  (IOT_SG_CCO_UPGRADE_BM_SIZE *8)
#define IOT_SG_STA_UPGRADE_WINDOW_SIZE  (IOT_SG_STA_UPGRADE_BM_SIZE *8)

#if (IOT_SMART_GRID_ENABLE && PLC_SUPPORT_STA_ROLE)
#define IOT_SG_UPGRADE_BLOCK_CNT        IOT_SG_STA_UPGRADE_WINDOW_SIZE
#else
#define IOT_SG_UPGRADE_BLOCK_CNT        0
#endif

typedef enum {
    UPGRADE_DATA_TYPE_FW,
    UPGRADE_DATA_TYPE_PIB,
    UPGRADE_DATA_TYPE_PKG,
    UPGRADE_DATA_TYPE_INVALID = 0xFF,
} iot_upgrade_data_type;

typedef enum {
    PART_0,
    PART_1,
    PART_INVALID = 0xFF,
} iot_upgrade_part_t;

/* callback for crc check */
typedef void (*file_part_crc_check)(uint8_t result);

/* callback for crc check */
typedef void(*falsh_read_end)(void *data, uint16_t size);

typedef struct _iot_start_src {
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    uint32_t block_size; /* upgrade data block size, unit is byte,
                            valid value: 100 200 300 400 */
    uint32_t fw_size;    /* firmware size, uint is byte, max size : 444K */
    uint32_t pib_size;   /* pib size, uint is byte, now : 32K */
    uint32_t fw_crc;     /* firmware crc-32 */
    uint32_t pib_crc;    /* pib crc-32 */
    iot_pkt_t   *crc_check_buf;    /* crc check buffer */
    file_part_crc_check crc_check; /* crc check callback */
    falsh_read_end      read_end;  /* flash read end callback */
} iot_start_src_t;

typedef struct _iot_start_rst {
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    uint32_t flags;      /* start to upgrade result code */
} iot_start_rst_t;

typedef struct _iot_trans_cmd {
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    uint32_t crc_flag;   /* block data use crc or not */
    uint32_t block_size; /* upgrade data block size, unit is byte,
                            valid value: 100 200 300 400 */
    uint32_t block_num;  /* data block number */
    uint8_t data_type;   /* type of data,PIB or FW,see iot_upgrade_data_type */
    iot_pkt_t *data;     /* iot packet data -- fw block data */
} iot_trans_cmd_t;

typedef struct _iot_upg_sts_src {
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    uint32_t block_size; /* upgrade data block size, unit is byte */
    uint32_t file_type;  /* type of data,PIB or FW,see iot_upgrade_data_type */
    uint32_t bmp_start;  /* bitmap start position, unit is byte */
    uint32_t bmp_len;    /* bitmap length, unit is byte */
} iot_upg_sts_src_t;

typedef struct _iot_upg_sts_rst {
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    uint32_t block_size; /* upgrade data block size */
    uint32_t state;      /* upgrade current state */
    uint32_t pos_zero;   /* sign bitmap first zero position */
    uint8_t *bitmap;     /* bitmap size: > 444K/100 */
} iot_upg_sts_rst_t;

typedef struct _iot_pkg_upg_sts_src {
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    uint32_t block_size; /* upgrade data block size, unit is byte */
    uint32_t block_index;/* start block index in bitmap */
    uint32_t block_cnt;  /* block count to query */
} iot_pkg_upg_sts_src_t;

typedef struct _iot_pkg_upg_sts_rst {
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    uint32_t state;      /* upgrade current state */
    uint32_t block_index;/* start block index in bitmap */
    uint32_t block_cnt;  /* block count queried */
    uint32_t bmp_size;   /* size of the bitmap buffer in byte */
    uint8_t *bitmap;     /* bitmap size: > 444K/100 */
} iot_pkg_upg_sts_rst_t;

typedef struct _iot_sta_info_src {
    uint8_t list;        /* query list id */
} iot_sta_info_src_t;

typedef struct _iot_sta_info_rst {
    uint8_t list;        /* query list id */
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    uint32_t info;
} iot_sta_info_rst_t;

typedef struct _iot_upg_block_info_src {
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    uint32_t block_index;/* start block index in bitmap */
    uint32_t file_type;  /* type of data,PIB or FW,see iot_upgrade_data_type */
}iot_upg_block_info_src;

typedef struct _iot_upg_block_info_rst {
    uint32_t id;         /* upgrade ID, remains the same in single progress */
    bool_t   blank;      /* is unwritten block */
    uint32_t file_type;  /* type of data,PIB or FW,see iot_upgrade_data_type */
    uint32_t next_blank_block_index;
}iot_upg_block_info_rst;

#define UPGRADE_VALUE_CHECK(src, dest, str) \
    if ( src != dest ) { \
        iot_printf(" %s(%d): %s\n", __FUNCTION__, __LINE__, str); \
        return (1); \
    }
/**
 * @brief - get a random value as the length.
 *          only when file length from flash is 0.
 * @return: file length
 */
uint32_t iot_upgrade_get_backup_len();

/**
 * @brief - get a random value as the crc.
 *          only when CRC from flash is 0.
 * @return: file crc
 */
uint32_t iot_upgrade_get_backup_crc();

/**
 * @brief: get boot partition id.
 * @param boot_part: 0 for part 0. 1 for part 1.
 * @retval: 0 for success case. other for failed case.
 */
uint32_t iot_upgrade_get_part(uint32_t *boot_part);

/**
 * @brief: get the partition id other than the boot partition.
 * @retval: id of the part id
 */
uint32_t iot_upgrade_get_another_part(uint32_t part);

/**
 * @brief iot_upgrade_get_fw_crc() - get upgrade firmware crc value
 * @param part: firmware partition number
 *
 * @return              0 - failed case
 * @return              other value for CRC
 */
uint32_t iot_upgrade_get_fw_crc(uint32_t part);

/**
 * @brief iot_upgrade_get_fw_size() - get upgrade firmware size
 * @param part: firmware partition number
 *
 * @return              0 - failed
 * @return          other - the crc value
 */
uint32_t iot_upgrade_get_fw_size(uint32_t part);

/**
 * @brief iot_upgrade_get_fw_sts() - get upgrade firmware status
 * @param part: firmware partition number
 * @param crc: firmware status
 *
 * @return              0 - succeed
 * @return              1 - fail
 */
uint32_t iot_upgrade_get_fw_sts(uint32_t part, char *sts);

/**
 * @brief iot_upgrade_get_trail_run_dur() - get upgrade running period time
 * @param part:     firmware partition number
 * @return:         trail run duration
 */
uint32_t iot_upgrade_get_trail_run_dur(uint32_t part);

/**
 * @brief iot_upgrade_save_fw_crc() - save upgrade firmware crc value
 * @param part: firmware partition number
 * @param crc: firmware crc value to be saved
 */
void iot_upgrade_save_fw_crc(uint32_t part, uint32_t crc);

/**
 * @brief iot_upgrade_save_fw_size() - save upgrade firmware size
 * @param part: firmware partition number
 * @param crc: firmware size to be saved
 */
void iot_upgrade_save_fw_len(uint32_t part, uint32_t len);

/**
 * @brief iot_upgrade_save_fw_sts() - save upgrade firmware status
 * @param part: firmware partition number
 * @param crc: firmware status to be saved
 */
void iot_upgrade_save_fw_sts(uint32_t part, uint32_t state);

/**
 * @brief iot_upgrade_save_fw_period() - save upgrade running period time
 * @param part:     firmware partition number
 * @param tr_dur:   train run duration
 */
void iot_upgrade_save_trail_run_dur(uint32_t part, uint32_t tr_dur);

/**
 * @brief iot_upgrade_reset() - reset the chip
 * @return              0 - succeed
 * @return              1 - fail
 */
uint32_t iot_upgrade_reset();

/**
 * @brief iot_upgrade_start() - Prepare the environment of upgrade and active
 *                              transfer-status
 * @param rst: pointer to the output of upgrade start structure
 * @param src: pointer to the input of upgrade start structure
 *
 * @return              0 - succeed
 * @return              1 - fail
 */
uint32_t iot_upgrade_start(iot_start_rst_t *rst, iot_start_src_t *src);

/**
 * @brief iot_upgrade_read_fw_data() - Read fw data from flash
 * @param data: data buffer
 * @param size: data buffer size
 * @param offset: part offset from which to read
 * @param part: file part to read
 *
 * @retval:             0 - succeed
 * @retval:             1 - fail
 */
uint32_t iot_upgrade_read_fw_data(void *data, uint32_t size,
    uint32_t offset, uint32_t part);

/**
 * @brief iot_upgrade_trans() - Handle a transfer command frame.
 *        It always free trans->pkt.
 * @param trans: pointer to the input of upgrade transfer command infos
 *
 * @return              0 - succeed. trans->pkt is consumed.
 * @return              1 - fail. trans->pkt is NOT consumed. User shall free it.
 */
uint32_t iot_upgrade_trans(iot_trans_cmd_t *trans);

uint32_t iot_upgrade_read(iot_trans_cmd_t *trans);

/**
 * @brief iot_upgrade_query_written_block_num() - Query written block num
 *
 * @retval:             written block num
 */
uint32_t iot_upgrade_query_written_block_num();

/**
 * @brief iot_upgrade_query_next_block() - Query next blank block
 * @param rst: result info
 * @param src: current index and file type info
 *
 * @retval:             0 - succeed
 * @retval:             1 - fail
 */
uint32_t iot_upgrade_query_next_block(iot_upg_block_info_rst *rst,
    iot_upg_block_info_src *src);

/**
 * @brief iot_upgrade_is_completed() - Check if no block is blank
 *
 * @retval:             0 - uncompleted
 * @retval:             1 - completed
 */
uint32_t iot_upgrade_is_completed();

/**
 * @brief iot_upgrade_query_block_info() - Query specified block in
 * @param rst: result info
 * @param src: index and file type info
 *
 * @retval:             0 - succeed
 * @retval:             1 - fail
 */
uint32_t iot_upgrade_query_block_info(iot_upg_block_info_rst *rst,
    iot_upg_block_info_src *src);

/**
 * @brief iot_upgrade_query_state() - Query upgrade state
 * @param rst : pointer to the output of upgrade query structure
 * @param src : pointer to the input of upgrade query structure
 *
 * @return              0 - succeed
 * @return              1 - fail
 */
uint32_t iot_upgrade_query_state(iot_upg_sts_rst_t *rst,
                                 iot_upg_sts_src_t *src);

/**
 * @brief iot_upgrade_query_station_info() - Query station infomations
 * @param rst: pointer to the output of station info structure
 * @param src: pointer to the input of station info structure
 *
 * @return              0 - succeed
 * @return              1 - fail
 */
uint32_t iot_upgrade_query_station_info(iot_sta_info_rst_t * rst,
                                        iot_sta_info_src_t *src);

/**
 * @brief iot_upgrade_commit() - Handle a commit command when upgrade frame
 *                               transfer finished
 * @param upgrade_id:   current upgrade id
 *
 * @return              0 = succeed
 * @return              1 = fail
 */
uint32_t iot_upgrade_commit(uint32_t upgrade_id);

/**
 * @brief: read data of PIB/FW from flash
 * @param buf:          the buffer to store request data
 * @param read_size:    number of byte to read. shall aligh to 4 byte
 * @param offset:       offset of the PIB/FW to be read
 * @param read_pib:     1 for read pib. 0 for read fw.
 * @retval:             ERR_OK for successfully case.
 *                      See ERR_XXX for failed case.
 */
uint32_t iot_pkg_upgrade_read(uint8_t *buf, uint32_t read_size, uint32_t offset,
    uint32_t read_pib);
/**
 * @brief iot_upgrade_cancel_commit() - Handle a cancel commit command
 * @param upgrade_id:   current upgrade id
 *
 * @return              0 = succeed
 * @return              1 = fail
 */
uint32_t iot_upgrade_cancel_commit(uint32_t upgrade_id);

/**
 * @ @brief: get length of pib
 * @return: length of pib
 */
uint32_t iot_upgrade_get_pib_len();

/**
 * @ @brief: get length of fw
 * @return: length of fw
 */
uint32_t iot_upgrade_get_fw_len();

/**
 * @brief: set a bit in received bitmap
 * @param index: index of the block
 * @return: ERR_OK if successed. ERR_FAILED if failed.
 */
uint32_t iot_pkg_upgrade_set_bit(uint32_t index);

/**
 * @brief: set a bit in received bitmap
 * @param index: index of the block
 * @return: 1 if the bit was set. 0 for other case.
 */
uint32_t iot_pkg_upgrade_get_bit(uint32_t index);

/**
 * @brief: check if all blocks were transferred
 * @param block_cnt:    total count of blocks to check
 * @return: 1 if all blocks were transferred. 0 for other case.
 */
uint32_t iot_pkt_upgrade_trans_all_done(uint32_t block_cnt);
/**
 * @brief:  get file type
 * @param file_hdr: file header data
 * @retval: the file type. see IOT_FILE_TYPE_XXX
 */
uint32_t iot_get_file_type(uint8_t *file_hdr);

/**
 * @brief:  get file length
 * @param file_hdr: file header data
 * @retval: length of the file. Or return 0 if file hdr is invalid.
 */
uint32_t iot_get_file_len(uint8_t *file_hdr);

/**
 * @brief:  get file CRC
 * @param file_hdr: file header data
 * @retval: CRC of the file. Or return 0 if file hdr is invalid.
 */
uint32_t iot_get_file_crc(uint8_t *file_hdr);

/**
 * @brief:  check mode of the file
 * @param file_hdr: file header data
 * @retval: get mode of the file.
 */
uint8_t iot_get_file_mode(uint8_t *file_hdr);

/**
 * @brief:  get enc mode from upgrade file
 * @param file_hdr: file header data
 * @retval: enc mode of the file.
 */
uint8_t iot_pkt_upgrade_get_enc_mode(uint8_t *file_hdr);

/**
 * @brief:  get file version
 * @param file_hdr: file header data
 * @retval: version of the file.
 */
uint32_t iot_get_file_version(uint8_t *file_hdr);

/**
 * @brief:  start upgrading with upgrade package file
 * @param rst:          pointer to the output of upgrade start structure
 * @param upgrade_id:   upgrade id
 * @param block_size:   block size
 * @param file_size:    size of the upgrade package file.
 * @param file_hdr:     pointer to buffer of file header
 * @retval: 0 for succeed case. Other for failed case.
 */
uint32_t iot_pkg_upgrade_start(iot_start_rst_t *rst, uint32_t upgrade_id,
    uint32_t block_size, uint32_t file_size, uint8_t* file_hdr);

/**
 * @brief iot_upgrade_switch_part(): swicth boot partition to another
 * @retval: 0 for succeed case. Other for failed case.
 */
uint32_t iot_upgrade_switch_part();

/**
 * @brief: transfer data to flash. It always consume trans->pkt.
 * @param trans:    the trans file obj with data to be transfered.
 * @retval:         ERR_OK for successfully case. other value for failed case.
 *                  See ERR_XXX for failed case.
 */
uint32_t iot_pkg_upgrade_trans(iot_trans_cmd_t *trans);

/**
* @brief: query upgrade state for upgrading by package
* @param rst: pointer to the output of upgrade start structure
* @param src: pointer to the input of upgrade start structure
* @retval: ERR_OK for succeed case. see ERR_XXX for failed case.
*/
uint32_t iot_pkg_upgrade_query_state(iot_pkg_upg_sts_rst_t *rst,
    iot_pkg_upg_sts_src_t *src);

/**
* @brief: get pad value
* @return: the pad value in upgrading file
*/
uint8_t iot_pkg_get_pad_value();

/**
* @brief: query station information
* @param rst: pointer to the output of station info structure
* @param src: pointer to the input of station info structure
* @retval:    ERR_OK for succeed case. see ERR_XXX for failed case.
*/
uint32_t iot_pkg_upgrade_query_station_info(iot_sta_info_rst_t * rst,
    iot_sta_info_src_t *src);
/**
* @brief: commit a sg upgrade from package
* @param upgrade_id:   upgrade id
* @retval:     ERR_OK for succeed case. see ERR_XXX for failed case.
*/
uint32_t iot_pkg_upgrade_commit(uint32_t upgrade_id);

/**
* @brief: cancel a sg upgrade from package
* @param upgrade_id:       upgrade id
* @param cancel_commit:   cancel commit
* @retval:     ERR_OK for succeed case. see ERR_XXX for failed case.
*/
uint32_t iot_pkg_upgrade_cancel_commit(uint32_t upgrade_id,
    uint32_t cancel_commit);

/**
* @brief iot_pkg_upgrade_reset() - reset the chip for upgrading through package
* @return              0 - succeed
* @return              1 - fail
*/
uint32_t iot_pkg_upgrade_reset();

/**
  * @}
  */

#endif
