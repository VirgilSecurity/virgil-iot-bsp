
#ifndef iotelic_ec_helpers_private_H
#define iotelic_ec_helpers_private_H

#include "export.h"
#include "keypair.h"

#include <stdbool.h>

#include <mbedtls/pk.h>
#include <mbedtls/entropy.h>
#include <mbedtls/ctr_drbg.h>

#ifdef __cplusplus
extern "C" {
#endif

bool
keypair_is_25519(KEYPAIR_TYPE keypair_type);

bool
keypair_is_rsa(KEYPAIR_TYPE keypair_type);

size_t
keypair_rsa_key_size(KEYPAIR_TYPE keypair_type);

size_t
keypair_ec_mpi_size(KEYPAIR_TYPE keypair_type);


bool
create_context_for_private_key(mbedtls_pk_context *ctx, const uint8_t *private_key, size_t private_key_sz);
bool
create_context_for_public_key(mbedtls_pk_context *ctx,
                              KEYPAIR_TYPE keypair_type,
                              const uint8_t *public_key,
                              size_t public_key_sz,
                              bool is_internal_key);

#ifdef __cplusplus
}
#endif

#endif // iotelic_ec_helpers_private_H
