/****************************************************************************

Copyright(c) 2016 by IoTelic Technologies. ALL RIGHTS RESERVED.

This Information is proprietary to IoTelic Technologies and MAY NOT
be copied by any method or incorporated into another program without
the express written consent of Iotelic. This Information or any portion
thereof remains the property of Iotelic. The Information contained herein
is believed to be accurate and Iotelic assumes no responsibility or
liability for its use in any way and conveys no license or title under
any patent or copyright and makes no representation or warranty that this
Information is free from patent or copyright infringement.

****************************************************************************/

#ifndef IOT_CRYPTO_API_H
#define IOT_CRYPTO_API_H

#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#include <stddef.h>
#include <stdint.h>

#include "mbedtls/aes.h"
#include "mbedtls/bignum.h"
#include "mbedtls/sha256.h"
#include "mbedtls/sha512.h"

struct aes_api {

    void (*_aes_init)(mbedtls_aes_context *ctx);

    void (*_aes_free)(mbedtls_aes_context *ctx);

    int (*_aes_setkey_enc)(mbedtls_aes_context *ctx, const unsigned char *key, unsigned int keybits);

    int (*_aes_setkey_dec)(mbedtls_aes_context *ctx, const unsigned char *key, unsigned int keybits);

    int (*_aes_crypt_ecb)(mbedtls_aes_context *ctx, int mode, const unsigned char input[16], unsigned char output[16]);
    int (*_aes_crypt_cbc)(mbedtls_aes_context *ctx,
                          int mode,
                          size_t length,
                          unsigned char iv[16],
                          const unsigned char *input,
                          unsigned char *output);
    int (*_aes_crypt_ctr)(mbedtls_aes_context *ctx,
                          size_t length,
                          size_t *nc_off,
                          unsigned char nonce_counter[16],
                          unsigned char stream_block[16],
                          const unsigned char *input,
                          unsigned char *output);
};

struct sha256_api {

    void (*_sha256_init)(mbedtls_sha256_context *ctx);

    void (*_sha256_free)(mbedtls_sha256_context *ctx);

    void (*_sha256_starts)(mbedtls_sha256_context *ctx, int is224);

    void (*_sha256_process)(mbedtls_sha256_context *ctx, const unsigned char data[64]);

    void (*_sha256_update)(mbedtls_sha256_context *ctx, const unsigned char *input, size_t ilen);

    void (*_sha256_finish)(mbedtls_sha256_context *ctx, unsigned char output[32]);
};

struct sha512_api {

    void (*_sha512_init)(mbedtls_sha512_context *ctx);

    void (*_sha512_free)(mbedtls_sha512_context *ctx);

    void (*_sha512_starts)(mbedtls_sha512_context *ctx, int is384);

    void (*_sha512_process)(mbedtls_sha512_context *ctx, const unsigned char data[128]);

    void (*_sha512_update)(mbedtls_sha512_context *ctx, const unsigned char *input, size_t ilen);

    void (*_sha512_finish)(mbedtls_sha512_context *ctx, unsigned char output[64]);
};

struct bignum_api {

    int (*_mpi_mul_mpi)(mbedtls_mpi *X, const mbedtls_mpi *A, const mbedtls_mpi *B);

    int (*_mpi_mod_mpi)(mbedtls_mpi *R, const mbedtls_mpi *A, const mbedtls_mpi *B);

    int (*_montmul)(mbedtls_mpi *A,
                    const mbedtls_mpi *B,
                    const mbedtls_mpi *N,
                    mbedtls_mpi_uint mm,
                    const mbedtls_mpi *T);
};

struct rng_api {
    int (*_hardware_poll)(void *data, unsigned char *output, size_t size, size_t *olen);
};

typedef struct _iot_crypto_indirection_table {
    struct aes_api aes_api;
    struct sha256_api sha256_api;
    struct sha512_api sha512_api;
    struct bignum_api bignum_api;
    struct rng_api rng_api;
} _iot_crypto_indirection_table_t;


extern _iot_crypto_indirection_table_t iot_indir_tbl;

#define _IOT_CRYPTO_INDIRECTION_TABLE_SIZE sizeof(_iot_crypto_indirection_table_t)
#define _IOT_CRYPTO_INDIRECTION_TABLE (&iot_indir_tbl)

#define A_INDIR(sym) _IOT_CRYPTO_INDIRECTION_TABLE->sym

#endif // IOT_CRYPTO_API_H
