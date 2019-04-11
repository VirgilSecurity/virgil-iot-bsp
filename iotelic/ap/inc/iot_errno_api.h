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

#ifndef IOT_ERRNO_API_H
#define IOT_ERRNO_API_H

#define ERR_OK                                  0
/* invalid parameters */
#define ERR_INVAL                               1
/* out of memory */
#define ERR_NOMEM                               2
/* not supported */
#define ERR_NOSUPP                              3
/* not secure due to white list */
#define ERR_NOSEC_WL                            4
/* not exist */
#define ERR_NOT_EXIST                           5
/* again */
#define ERR_AGAIN                               6
/* dev not ready */
#define ERR_NOT_READY                           7
/* already exist */
#define ERR_EXIST                               8
/* busy */
#define ERR_BUSY                                9
/* pending */
#define ERR_PENDING                             10
/* failed */
#define ERR_FAIL                                11
/* not secure due to black list */
#define ERR_NOSEC_BL                            12
/*calu crc but len < 0 */
#define ERR_CRC_LEN                             13


#endif /* IOT_ERRNO_API_H */
