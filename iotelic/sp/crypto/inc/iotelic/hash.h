#ifndef iotelic_hash_H
#define iotelic_hash_H

#include <stdint.h>
#include <crypto_mailbox_interface.h>

typedef enum {
    HASH_SHA_INVALID = -1,
    HASH_SHA_256 = 0,
    HASH_SHA_384,
    HASH_SHA_512,
} HASH_TYPE;

typedef enum {
    HASH_ERROR_GENERAL = -1,
} HASH_RESULT;

#ifdef __cplusplus
extern "C" {
#endif

int
hash_create(HASH_TYPE hash_type,
            const uint8_t *data,
            size_t data_sz,
            uint8_t *hash,
            size_t hash_buf_sz,
            size_t *hash_sz);

int
hash_size(HASH_TYPE hash_type);

const char *
hash_name(HASH_TYPE hash_type);

int32_t
hash_mailbox_sha256(mailbox_cmd_t *packet);

int32_t
hash_mailbox_sha384(mailbox_cmd_t *packet);

int32_t
hash_mailbox_sha512(mailbox_cmd_t *packet);

#ifdef __cplusplus
}
#endif

#endif // iotelic_hash_H
