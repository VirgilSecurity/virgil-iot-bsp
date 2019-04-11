
#ifndef iotelic_hmac_H
#define iotelic_hmac_H

#include <stdint.h>
#include "hash.h"

typedef enum {
    HMAC_ERROR_GENERAL = -1,
} HMAC_RESULT;

typedef struct {
    HASH_TYPE hash_type;
    const uint8_t *key;
    size_t key_sz;
    const uint8_t *input;
    size_t input_sz;
} hmac_cmd_t;

#ifdef __cplusplus
extern "C" {
#endif

int
hmac(HASH_TYPE hash_type,
     const uint8_t *key,
     size_t key_sz,
     const uint8_t *input,
     size_t input_sz,
     uint8_t *output,
     size_t output_buf_sz,
     size_t *output_sz);

int32_t
hmac_mailbox(mailbox_cmd_t *packet);

#ifdef __cplusplus
}
#endif

#endif // iotelic_hmac_H
