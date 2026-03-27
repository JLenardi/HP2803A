/**
 * @file eeprom_drv.h
 * @brief Low-level AVR EEPROM access driver.
 */

#ifndef EEPROM_DRV_H
#define EEPROM_DRV_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void eeprom_drv_init(void);
bool eeprom_drv_read(uint16_t addr, void * data, size_t len);
bool eeprom_drv_write(uint16_t addr, const void * data, size_t len);
void eeprom_drv_commit(void);

bool eeprom_drv_read_settings(Settings * dst);
void eeprom_drv_write_settings(const Settings * src);

#endif

