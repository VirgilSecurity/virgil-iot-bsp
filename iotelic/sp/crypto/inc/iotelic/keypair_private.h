
#ifndef iotelic_keypair_private_H
#define iotelic_keypair_private_H

#include "keypair.h"

#include <mbedtls/ecp.h>

#define KEYPAIR_PRIVAT_KEY_MAX_SZ 2500

#ifdef __cplusplus
extern "C" {
#endif

int
keypair_get_private_key(KEYSTORAGE_SLOT slot, uint8_t *buf, size_t buf_sz, size_t *key_sz, KEYPAIR_TYPE *keypair_type);

int
keypair_public_key_to_internal(KEYPAIR_TYPE keypair_type,
                               const uint8_t *public_key_in,
                               size_t public_key_in_sz,
                               uint8_t *public_key_out,
                               size_t buf_sz,
                               size_t *public_key_out_sz);

mbedtls_ecp_group_id
keypair_type_to_ecp_group_id(KEYPAIR_TYPE keypair_type);

#ifdef __cplusplus
}
#endif

#endif // iotelic_keypair_private_H
