// Functionality for internal usage only

// TODO: USE EFUSE FOR RISC-V BUILD

#ifndef iotelic_keystorage_H
#define iotelic_keystorage_H

#include <stdint.h>
#include "iotelic/global.h"
#include "iotelic/keystorage_slots.h"

#define FLAGS_OTP	(0x80)
#define FLAGS_MTP	(0x40)

#define FLASH_BASE_ADDR	(0x00090000)

typedef enum {
    KEYSTORAGE_ERROR_GENERAL = -1,
    KEYSTORAGE_ERROR_PARAMS = -2,
    KEYSTORAGE_ERROR_SMALL_BUFFER = -3,
    KEYSTORAGE_ERROR_FLASH_ERASE = -4,
    KEYSTORAGE_ERROR_FLASH_WRITE = -5,
    KEYSTORAGE_ERROR_FLASH_READ = -6,
    KEYSTORAGE_ERROR_OTP_SLOT = -7,
} KEYSTORAGE_RESULT;

typedef struct __attribute__((__packed__)) {
	uint16_t sz;
	uint8_t flags;
	uint8_t data[KEY_SLOT_MTP_MAX_SIZE];
} keystorage_data_t;

#ifdef __cplusplus
extern "C" {
#endif

int
keystorage_save(KEYSTORAGE_SLOT slot, const uint8_t *data, size_t data_sz);

int
keystorage_load(KEYSTORAGE_SLOT slot, uint8_t *data, size_t buf_sz, size_t *read_sz);

#ifdef __cplusplus
}
#endif

#endif // iotelic_keystorage
