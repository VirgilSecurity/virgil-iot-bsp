
#ifndef iotelic_keypair_H
#define iotelic_keypair_H

#include "keystorage_slots.h"
#include <crypto_mailbox_interface.h>

typedef enum {
    KEYPAIR_ERROR_GENERAL = -1,
    KEYPAIR_ERROR_PARAMS = -2,
} KEYPAIR_RESULT;

typedef enum {
    KEYPAIR_INVALID = -1,
    KEYPAIR_EC_SECP192R1 = 1, ///< 192-bits NIST curve
    KEYPAIR_EC_SECP224R1,     ///< 224-bits NIST curve
    KEYPAIR_EC_SECP256R1,     ///< 256-bits NIST curve
    KEYPAIR_EC_SECP384R1,     ///< 384-bits NIST curve
    KEYPAIR_EC_SECP521R1,     ///< 521-bits NIST curve
    KEYPAIR_EC_SECP192K1,     ///< 192-bits "Koblitz" curve
    KEYPAIR_EC_SECP224K1,     ///< 224-bits "Koblitz" curve
    KEYPAIR_EC_SECP256K1,     ///< 256-bits "Koblitz" curve
    KEYPAIR_EC_CURVE25519,    ///< Curve25519
    KEYPAIR_EC_ED25519,       ///< Ed25519
    KEYPAIR_RSA_2048,         ///< RSA 2048 bit (not recommended)
    KEYPAIR_RSA_3072,         ///< RSA 3072 bit
    KEYPAIR_RSA_4096,         ///< RSA 4096 bit
    KEYPAIR_MAX
} KEYPAIR_TYPE;

typedef struct {
    KEYSTORAGE_SLOT slot;
    KEYPAIR_TYPE keypair_type;
} vs_keypair_cmd_t;

#ifdef __cplusplus
extern "C" {
#endif

int
keypair_create(KEYSTORAGE_SLOT slot, KEYPAIR_TYPE keypair_type);

int
keypair_get_pubkey(KEYSTORAGE_SLOT slot, uint8_t *buf, size_t buf_sz, size_t *key_sz, KEYPAIR_TYPE *keypair_type);

const char *
keypair_name(KEYPAIR_TYPE keypair_type);

int
keypair_public_key_from_internal(KEYPAIR_TYPE keypair_type,
                                 uint8_t *public_key,
                                 size_t public_key_in_sz,
                                 size_t *public_key_out_sz);

int
keypair_save_raw(KEYSTORAGE_SLOT slot, KEYPAIR_TYPE keypair_type, const uint8_t *key, size_t key_sz);

int32_t
keypair_generate_mailbox(mailbox_cmd_t *packet);

int32_t
keypair_get_public_mailbox(mailbox_cmd_t *packet);

#ifdef __cplusplus
}
#endif

#endif // iotelic_keypair
