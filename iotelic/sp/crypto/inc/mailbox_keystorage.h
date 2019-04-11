#ifndef KUNLUN_MAILBOX_SECBOX_H
#define KUNLUN_MAILBOX_SECBOX_H

#include <stdint.h>
#include "iotelic/keystorage_slots.h"
#include "crypto_mailbox_interface.h"

#define PROVISION_KEYS_QTY 2

#define PRIVATE_KEY_SLOT KEY_SLOT_OTP_1

#define REC1_KEY_SLOT KEY_SLOT_OTP_2
#define REC2_KEY_SLOT KEY_SLOT_OTP_3

#define AUTH1_KEY_SLOT KEY_SLOT_MTP_2
#define AUTH2_KEY_SLOT KEY_SLOT_MTP_3

#define TL1_KEY_SLOT KEY_SLOT_MTP_4
#define TL2_KEY_SLOT KEY_SLOT_MTP_5

#define FW1_KEY_SLOT KEY_SLOT_MTP_6
#define FW2_KEY_SLOT KEY_SLOT_MTP_7

#define SIGNATURE_SLOT KEY_SLOT_MTP_8

typedef enum {
    STORAGE_OP_READ,
    STORAGE_OP_WRITE,
    STORAGE_OP_DEL,
} STORAGE_OP_TYPE;

typedef enum {
    STORAGE_ELEMENT_MIN = 0,
    STORAGE_ELEMENT_PBR,
    STORAGE_ELEMENT_PBA,
    STORAGE_ELEMENT_PBT,
    STORAGE_ELEMENT_PBF,
    STORAGE_ELEMENT_TLH,
    STORAGE_ELEMENT_TLC,
    STORAGE_ELEMENT_TLF,
    STORAGE_ELEMENT_SGN,
    STORAGE_ELEMENT_MAX,
} STORAGE_ELEMENT_TYPE;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    STORAGE_OP_TYPE op_type;
    STORAGE_ELEMENT_TYPE elem_type;
    KEYSTORAGE_SLOT slot;
    const uint8_t *data_in;
    size_t data_sz;
} keystorage_cmd_t;

int32_t
keystorage_provision_mailbox(mailbox_cmd_t *packet);

extern const KEYSTORAGE_SLOT rec_key_slot[PROVISION_KEYS_QTY];
extern const KEYSTORAGE_SLOT auth_key_slot[PROVISION_KEYS_QTY];
extern const KEYSTORAGE_SLOT tl_key_slot[PROVISION_KEYS_QTY];
extern const KEYSTORAGE_SLOT fw_key_slot[PROVISION_KEYS_QTY];

#ifdef __cplusplus
}
#endif

#endif // KUNLUN_MAILBOX_SECBOX_H
