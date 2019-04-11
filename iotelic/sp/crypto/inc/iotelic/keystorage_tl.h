
#ifndef KUNLUN_KEYSTORAGE_TL_H
#define KUNLUN_KEYSTORAGE_TL_H

#include <stdint.h>
#include <stdbool.h>
#include "keystorage_tl_structs.h"

#define TL_STORAGE_TYPE_STATIC 0
#define TL_STORAGE_TYPE_DYNAMIC 1
#define TL_STORAGE_TYPE_TMP 2

typedef struct __attribute__((__packed__)) {
    size_t storage_type;
    size_t addr;
}tl_storage_ctx_t;

typedef struct __attribute__((__packed__)) {
    uint16_t keys_amount;
    uint16_t keys_count;
}tl_keys_qty_t;

typedef struct __attribute__((__packed__)){
    bool ready;
    tl_storage_ctx_t storage;
    tl_keys_qty_t keys_qty;
} tl_context_t;

bool
keystorage_verify_hl_key_sign(const uint8_t *key_to_check, size_t key_size);
void
init_keystorage_tl();
int
keystorage_invalidate_tl(size_t storage_type);
int
keystorage_save_tl_header(size_t storage_type, const trust_list_header_t *header);
int
keystorage_load_tl_header(size_t storage_type, trust_list_header_t *header);
int
keystorage_save_tl_footer(size_t storage_type,const trust_list_footer_t *footer);
int
keystorage_apply_tmp_tl_to(size_t storage_type);
int
keystorage_load_tl_footer(size_t storage_type,trust_list_footer_t *footer);
int
keystorage_save_tl_key(size_t storage_type,const trust_list_pub_key_t* key);
int
keystorage_load_tl_key(size_t storage_type, tl_key_handle handle, trust_list_pub_key_t* key);

#endif //KUNLUN_KEYSTORAGE_TL_H
