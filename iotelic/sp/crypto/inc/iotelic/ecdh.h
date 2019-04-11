
#ifndef iotelic_ecdh_H
#define iotelic_ecdh_H

#include "keystorage_slots.h"
#include "keypair.h"

typedef enum {
    ECDH_ERROR_GENERAL = -1,
} ECDH_RESULT;

#ifdef __cplusplus
extern "C" {
#endif

int
ecdh(KEYSTORAGE_SLOT slot,
     KEYPAIR_TYPE keypair_type,
     const uint8_t *public_key,
     size_t public_key_sz,
     uint8_t *shared_secret,
     size_t buf_sz,
     size_t *shared_secret_sz);

#ifdef __cplusplus
}
#endif

#endif // iotelic_ecdh
