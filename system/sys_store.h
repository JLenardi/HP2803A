/**
 * @file sys_store.h
 * @brief System-level persistent storage interface (platform-neutral).
 */

#ifndef SYS_STORE_H
#define SYS_STORE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "sys_settings_types.h"

void sys_store_init(void);
bool sys_store_load(uint16_t addr, void *buf, size_t len);
bool sys_store_save(uint16_t addr, const void *buf, size_t len);
void sys_store_commit(void);

void sys_store_settings_init(Settings * dst);
void sys_store_read_settings(Settings * dst);
void sys_store_write_settings(const Settings * src);

#endif

