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

#ifndef IOT_PIB_API_H
#define IOT_PIB_API_H

/* os shim includes */
#include "os_types_api.h"

/* common includes */
#include "iot_module_api.h"

/* pack for the structures in the whole file */
#pragma pack(push)  // save the pack status
#pragma pack(1)     // 1 byte align

#define CCO_PIB_TYPE                    (0)
#define STA_PIB_TYPE                    (1)
#define MAX_PIB_TYPE                    STA_PIB_TYPE

#define iot_pib_type_t                  uint8_t

#define IOT_PIB_CCO_APP_READ_SECTION_SIZE   (32)
#define IOT_PIB_STA_APP_READ_SECTION_SIZE   (32)
#define IOT_PIB_BOARD_SECTION_SIZE          (128)

#define IOT_PIB_CCO_APP_WRITE_SECTION_SIZE  (7544)
#define IOT_PIB_STA_APP_WRITE_SECTION_SIZE  (376)

/* get section in read only memory */
#define IOT_PIB_APP_GET_READ_SECTION        (0)
/* get section in writable memory */
#define IOT_PIB_APP_GET_WRITE_SECTION       (1)

#define IOT_PIB_BOARD_GET_READ_SECTION      IOT_PIB_APP_GET_READ_SECTION
#define IOT_PIB_BOARD_GET_WRITE_SECTION     IOT_PIB_APP_GET_WRITE_SECTION

/** \defgroup PIB_APIs PIB APIs
  * @brief WQ30x1 Product Information Block
  *
  * System configuration parameters save in chip flash
  *
  */

/** @addtogroup PIB_APIs
  * @{
  */

/**
 * @brief  iot_pib_get_app_section() - function used to get app section address.
 * @param  psection:  return pointer to app section start address.
 * @param  pibtype:   return pib type.
 * @param  rw:        get section in read only memory or writable memory,
 *                    see IOT_PIB_APP_GET_XXX_SECTION.
 *
 * @return            0          -   success.
 * @return            otherwise  -   error code.
 */
uint32_t iot_pib_get_app_section(uint8_t **psection, iot_pib_type_t *pibtype,
    uint8_t rw);

/**
 * @brief  iot_pib_acquire_app_commit_ref() - function to hold pib commit
 *                         execute until free commit reference. app should call
 *                         this function before pib modification.
 * @param  cur_refcount:   current app pib reference counter, unless
 *                         this value is 0, commit won't take effect.
 * @return                 0           -   success.
 * @return                 otherwise   -   error.
 */
uint32_t iot_pib_acquire_app_commit_ref(uint8_t *cur_refcount);

/**
 * @brief iot_pib_release_app_commit_ref() - function to release pib commit
 *                       referecne count. app should call this function after
 *                       pib modification.
 * @param cur_refcount:  current app pib reference counter, unless this
 *                       value is 0, commit won't take effect.
 * @return               0           -   success.
 * @return               otherwise   -   error.
 */
uint32_t iot_pib_release_app_commit_ref(uint8_t *cur_refcount);

/**
 * @brief  iot_pib_app_commit() - function used by app to trigger write pib
 *                         to flash.
 * @param  commit_ticket:  pib assigned commit request id. can be used in
 *                         commit callback function to adjust whether
 *                         request done.
 * @return                 0           -   success.
 * @return                 otherwise   -   error.
 */
uint32_t iot_pib_app_commit(uint16_t* commit_ticket);

#define IOT_PIB_APP_STATUS_COMMIT_REC   1
#define IOT_PIB_APP_STATUS_COMMIT_DONE  2

/**
 * @brief  iot_pib_app_report_commit_status_func_t() - function callback for
 *                         app to receive pib commit status.
 * @param  status:         pib commit status.
 */
typedef void(*iot_pib_app_report_commit_status_func_t)(uint8_t status,
                           uint16_t commit_ticket);

/**
 * @brief   iot_pib_register_commit_cb() - register pib commit status callback
 *               function.
 * @param   cb:  callback function provide by app to receive pib commit status.
 * @return       0             - success.
 * @return       otherwise     - error.
*/
uint32_t iot_pib_register_app_commit_cb(
                                    iot_pib_app_report_commit_status_func_t cb);

/**
 * @brief   iot_pib_app_get_crc_status(uint8_t *r_crc, uint8_t* w_crc) - get
 *                      read/write section crc status. caller module
 *                      should not use cfg data if crc is wrong
 * @param  r_crc:       0 -crc wrong. 1 - crc valid
 * @param  w_crc:       0 -crc wrong. 1 - crc valid
 * @return              0         - success.
 * @return              otherwise - fail.
 */
void iot_pib_app_get_crc_status(uint8_t* r_crc, uint8_t* w_crc);

/**
 * @brief iot_pib_get_board_section - function used to get board section address
 * @param psection:     -output- return pointer to board section start address
 * @param pibtype:      -output- return pib type
 * @param  rw:        get section in read only memory or writable memory,
 *                    see IOT_PIB_BOARD_GET_XXX_SECTION.
 *
 * @return              0 - success
 * @return              otherwise - error code
 */
uint32_t iot_pib_get_board_section(uint8_t **psection, iot_pib_type_t *pibtype,
                                   uint8_t rw);

/**
 * @brief iot_pib_acquire_board_commit_ref - function to hold pib commit execute
 *                      until free commit reference. board should call this
 *                      function before pib modification.
 * @param cur_refcount: -output- current board pib reference counter, unless
 *                      this value is 0, commit won't take effect.
 *
 *  @return             0 - success
 *  @return             otherwise - error
 */
uint32_t iot_pib_acquire_board_commit_ref(uint8_t *cur_refcount);

/**
 * @brief iot_pib_release_board_commit_ref - function to release pib commit
 *                      referecne count. board should call this function after
 *                      pib modification.
 * @param cur_refcount: -output- current board pib reference counter, unless
 *                      this value is 0, commit won't take effect.
 *
 * @return              0 - success
 * @return              otherwise - error
 */
uint32_t iot_pib_release_board_commit_ref(uint8_t *cur_refcount);

/**
 * @brief iot_pib_board_commit - function used to trigger write pib to flash.
 * @param commit_ticket:pib assigned commit request id. can be used in commit
 *                      callback function to adjust whether request done.
 * @return              0 - success
 * @return              otherwise - error
 */
uint32_t iot_pib_board_commit(uint16_t* commit_ticket);

/**
 * @brief iot_pib_board_report_commit_status_func_t - function callback for
 *                      board to receive pib commit status.
 * @param status:       pib commit status
 */
typedef void(*iot_pib_board_report_commit_status_func_t)(uint8_t status,
                           uint16_t commit_ticket);

/**
 * @brief iot_pib_register_board_commit_cb - register pib commit status
 *                      callback function
 * @param cb:           callback function provied by board to receive pib
 *                      commit status
 * @return              0 - success
 * @return              otherwise - error
 */
uint32_t iot_pib_register_board_commit_cb(
                            iot_pib_board_report_commit_status_func_t cb);

/**
 * @brief   iot_pib_board_get_crc_status - get read/write section crc status.
 *                      caller module should not use cfg data if crc is wrong
 * @param  r_crc:       0 -crc wrong. 1 - crc valid
 * @param  w_crc:       0 -crc wrong. 1 - crc valid
 * @return              0         - success.
 * @return              otherwise - fail.
 */
void iot_pib_board_get_crc_status(uint8_t* r_crc, uint8_t* w_crc);

/**
 * @brief iot_pib_get_halphy_section - function used to get board section address
 * @param psection:     -output- return pointer to board section start address
 * @param pibtype:      -output- return pib type
 * @param  rw:        get section in read only memory or writable memory,
 *                    see IOT_PIB_BOARD_GET_XXX_SECTION.
 *
 * @return              0 - success
 * @return              otherwise - error code
 */
uint32_t iot_pib_get_halphy_section(uint8_t **psection, iot_pib_type_t *pibtype,
                                   uint8_t rw);

/**
 * @brief iot_pib_acquire_halphy_commit_ref - function to hold pib commit execute
 *                      until free commit reference. board should call this
 *                      function before pib modification.
 * @param cur_refcount: -output- current board pib reference counter, unless
 *                      this value is 0, commit won't take effect.
 *
 *  @return             0 - success
 *  @return             otherwise - error
 */
uint32_t iot_pib_acquire_halphy_commit_ref(uint8_t *cur_refcount);

/**
 * @brief iot_pib_release_halphy_commit_ref - function to release pib commit
 *                      referecne count. board should call this function after
 *                      pib modification.
 * @param cur_refcount: -output- current board pib reference counter, unless
 *                      this value is 0, commit won't take effect.
 *
 * @return              0 - success
 * @return              otherwise - error
 */
uint32_t iot_pib_release_halphy_commit_ref(uint8_t *cur_refcount);

/**
 * @brief iot_pib_halphy_commit - function used to trigger write pib to flash.
 * @param commit_ticket:pib assigned commit request id. can be used in commit
 *                      callback function to adjust whether request done.
 * @return              0 - success
 * @return              otherwise - error
 */
uint32_t iot_pib_halphy_commit(uint16_t* commit_ticket);

/**
 * @brief iot_pib_register_halphy_commit_cb - register pib commit status
 *                      callback function
 * @param cb:           callback function provied by board to receive pib
 *                      commit status
 * @return              0 - success
 * @return              otherwise - error
 */
uint32_t iot_pib_register_halphy_commit_cb(
                                   iot_pib_app_report_commit_status_func_t cb);

/**
 * @brief   iot_pib_halphy_get_crc_status(uint8_t *r_crc, uint8_t* w_crc) - get
 *                      read/write section crc status. caller module
 *                      should not use cfg data if crc is wrong
 * @param  r_crc:       0 -crc wrong. 1 - crc valid
 * @param  w_crc:       0 -crc wrong. 1 - crc valid
 * @return              0         - success.
 * @return              otherwise - fail.
 */
void iot_pib_halphy_get_crc_status(uint8_t* r_crc, uint8_t* w_crc);


/**
  * @}
  */

#pragma pack(pop)   // restore the pack status

#endif /* IOT_PIB_API_H */
