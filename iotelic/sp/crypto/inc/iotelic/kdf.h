#ifndef iotelic_kdf_H
#define iotelic_kdf_H

#include <stdint.h>
#include "hash.h"

typedef enum {
    KDF_INVALID = -1,
    KDF_2 = 0,
} KDF_TYPE;

typedef enum {
    KDF_ERROR_GENERAL = -1,
} KDF_RESULT;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    KDF_TYPE kdf_type;
    HASH_TYPE hash_type;
    const uint8_t *input;
    size_t input_sz;
} kdf_cmd_t;

int
kdf(KDF_TYPE kdf_type, HASH_TYPE hash_type, const uint8_t *input, size_t input_sz, uint8_t *output, size_t output_sz);

int
hkdf(HASH_TYPE hash_type,
     const uint8_t *input,
     size_t input_sz,
     const uint8_t *salt,
     size_t salt_sz,
     const uint8_t *info,
     size_t info_sz,
     uint8_t *output,
     size_t output_sz);

int32_t
kdf_mailbox(mailbox_cmd_t *packet);

#ifdef __cplusplus
}
#endif

#endif // iotelic_kdf_H
