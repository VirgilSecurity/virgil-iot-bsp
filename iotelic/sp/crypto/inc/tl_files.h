#ifndef KUNLUN_TL_FILES_H
#define KUNLUN_TL_FILES_H

#include <stdint.h>
#include <stdio.h>
#include "keystorage_private.h"
#include "keystorage_tl.h"

size_t
get_keystorage_default_base_addr(size_t storage_type);
bool
write_tl_header_file(tl_context_t *ctx, const trust_list_header_t *tl_header);
bool
read_tl_header_file(tl_context_t *ctx, trust_list_header_t *tl_header);
bool
remove_keystorage_tl_header_file(tl_context_t *ctx);
bool
write_tl_key_file(tl_context_t *ctx, size_t key_id, const trust_list_pub_key_t *key);
bool
read_tl_key_file(tl_context_t *ctx, size_t key_id, trust_list_pub_key_t *key);
bool
remove_keystorage_tl_key_file(tl_context_t *ctx, tl_key_handle handle);
bool
write_tl_footer_file(tl_context_t *ctx, const trust_list_footer_t *footer);
bool
read_tl_footer_file(tl_context_t *ctx, trust_list_footer_t *footer);
bool
remove_keystorage_tl_footer_file(tl_context_t *ctx);

#endif //KUNLUN_TL_FILES_H
