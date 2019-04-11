#ifndef KUNLUN_KEYSTORAGE_TL_STRUCTS_H
#define KUNLUN_KEYSTORAGE_TL_STRUCTS_H

#define TL_STORAGE_SIZE (10*4096)

#define PUBKEY_TINY_SZ (64)
#define PUBKEY_TINY_ID_SZ (2)
#define SIGNATURE_SZ (64)
#define TL_SIGNATURES_QTY (2)

typedef size_t tl_key_handle;

typedef struct __attribute__((__packed__)) {
    union {
        uint8_t     val[PUBKEY_TINY_ID_SZ];
        uint16_t    key_id;
    };
} crypto_public_key_id_t;

typedef struct __attribute__((__packed__)) {
    crypto_public_key_id_t signer_id;
    uint8_t val[SIGNATURE_SZ];
} crypto_signature_t;

typedef struct __attribute__((__packed__)) {
    uint32_t tl_size;
    uint16_t version;
    uint16_t pub_keys_count;
    uint8_t reserved[24];
} trust_list_header_t;

typedef struct __attribute__((__packed__)) {
    crypto_signature_t auth_sign;
    crypto_signature_t tl_service_sign;
    uint8_t tl_type;
    uint8_t reserved[32];
} trust_list_footer_t;

typedef struct __attribute__((__packed__)) {
    crypto_public_key_id_t id;
    uint16_t type;
    uint8_t reserved[28];
} trust_list_pub_key_meta_t;

typedef struct __attribute__((__packed__)) {
    uint8_t val[PUBKEY_TINY_SZ];
    trust_list_pub_key_meta_t meta;
} trust_list_pub_key_t;

typedef struct __attribute__((__packed__)) {
    crypto_public_key_id_t id;
    uint8_t val[PUBKEY_TINY_SZ];
} crypto_hl_public_key_t;

typedef struct __attribute__((__packed__)) {
    crypto_hl_public_key_t public_key;
    crypto_signature_t sign;
} crypto_signed_hl_public_key_t;

#endif //KUNLUN_KEYSTORAGE_TL_STRUCTS_H
