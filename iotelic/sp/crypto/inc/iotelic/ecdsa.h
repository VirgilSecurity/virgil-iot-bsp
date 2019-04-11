
#ifndef iotelic_ecdsa_H
#define iotelic_ecdsa_H

#include "keystorage_slots.h"
#include "keypair.h"
#include "hash.h"

typedef enum {
    ECDSA_VERIFY_OK = 2,
    ECDSA_ERROR_VERIFY = -1,
    ECDSA_ERROR_PARAMS = -2,
    ECDSA_ERROR_GENERAL = -3,
} ECDSA_RESULT;

typedef enum {
    SIGN_COMMON = 0,
    SIGN_PSS = 1,
} SIGN_TYPE;

typedef struct {
    KEYSTORAGE_SLOT slot;
    HASH_TYPE hash_type;
    const uint8_t *hash_data;
    size_t hash_sz;
} vs_ecdsa_sign_cmd_t;

typedef struct {
    KEYPAIR_TYPE keypair_type;
    HASH_TYPE hash_type;
    SIGN_TYPE sign_type;
    const uint8_t *public_key;
    size_t public_key_sz;
    const uint8_t *hash;
    size_t hash_sz;
    const uint8_t *signature;
    size_t signature_sz;
} vs_ecdsa_verify_cmd_t;

#ifdef __cplusplus
extern "C" {
#endif

int
ecdsa_sign(KEYSTORAGE_SLOT key_slot,
           HASH_TYPE hash_type,
           const uint8_t *hash,
           size_t hash_sz,
           uint8_t *signature,
           size_t signature_buf_sz,
           size_t *signature_sz,
           SIGN_TYPE sign_type);

int
ecdsa_verify(KEYPAIR_TYPE keypair_type,
             const uint8_t *public_key,
             size_t public_key_sz,
             HASH_TYPE hash_type,
             const uint8_t *hash,
             size_t hash_sz,
             const uint8_t *signature,
             size_t signature_sz,
             SIGN_TYPE sign_type);

int
ecdsa_verify_with_internal_key(const uint8_t *public_key, size_t public_key_sz,
                               HASH_TYPE hash_type, const uint8_t *hash, size_t hash_sz,
                               const uint8_t *signature, size_t signature_sz, SIGN_TYPE sign_type);

int32_t
ecdsa_sign_mailbox(mailbox_cmd_t *packet);

int32_t
ecdsa_verify_mailbox(mailbox_cmd_t *packet);

#ifdef __cplusplus
}
#endif

#endif // iotelic_ecdsa_H
