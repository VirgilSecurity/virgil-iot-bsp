#ifndef iotelic_mailbox_interface_H
#define iotelic_mailbox_interface_H

#include <stdint.h>

typedef enum {
    VS_IOT_FIRST = 0,

    // Do not change operations order!

    VS_IOT_HASH_SHA256 = VS_IOT_FIRST,
    VS_IOT_HASH_SHA384,
    VS_IOT_HASH_SHA512,
    VS_IOT_HMAC,
    VS_IOT_KDF,
    VS_IOT_PROVISION_SECBOX_OP,
    VS_IOT_KEYPAIR_CREATE,
    VS_IOT_KEYPAIR_GET_PUBLIC,
    VS_IOT_ECDSA_SIGN,
    VS_IOT_ECDSA_VERIFY,

    // Add new operation before this line

    VS_IOT_COMMANDS_AMOUNT

} vscf_command_type_e;

typedef struct mailbox_cmd_s {
    vscf_command_type_e opcode;
    uint16_t op_id;
    const void *in_data;
    size_t ilen;
    int32_t result;
    void *out_data;
    size_t out_buf_sz;
    size_t olen;
} mailbox_cmd_t;

void
crypto_sp_mailbox_handler(mailbox_cmd_t *packet);

void
crypto_sp_mailbox_callback(void);

#endif // iotelic_mailbox_interface_H
