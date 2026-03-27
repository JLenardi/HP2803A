/**
 * @file file_drv.h
 * @brief Low-level file-backed persistent storage driver.
 */

#ifndef FILE_DRV_H
#define FILE_DRV_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "sys_settings_types.h"

void file_drv_init(void);
bool file_drv_read(uint16_t addr, void *data, size_t len);
bool file_drv_write(uint16_t addr, const void *data, size_t len);
void file_drv_commit(void);

bool file_drv_read_settings(Settings * dst);
void file_drv_write_settings(const Settings * src);

#endif

