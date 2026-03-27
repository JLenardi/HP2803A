/**
 * @file hw_store.h
 * @brief Hardware abstraction for persistent storage.
 */

#ifndef HW_STORE_H
#define HW_STORE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "sys_settings_types.h"

void hw_store_init(void);
bool hw_store_read(uint16_t addr, void * data, size_t len);
bool hw_store_write(uint16_t addr, const void * data, size_t len);
void hw_store_commit(void);

bool hw_store_settings_init(Settings * dst);
bool hw_store_read_settings(Settings * dst);
void hw_store_write_settings(const Settings * src);

const Settings * get_saved_settings(void);
Settings * get_saved_settings_mutable(void);

#endif

