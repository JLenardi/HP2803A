/**
 * @file sys_settings.h
 * @brief Provides storage and management for system settings.
 *
 * sys_settings.* owns current_settings and default_settings.
 * Access to current_settings provided through get_current_settings().
 */

#ifndef SYS_SETTINGS_H
#define SYS_SETTINGS_H

#include <stdbool.h>
#include "sys_settings_types.h"
#include "cor_menu_types.h"

void sys_settings_init(void);
void save_current_settings(void);
void discard_current_settings(void);
void use_default_settings(void);

const Settings * get_current_settings(void);
Settings * get_current_settings_mutable(void);

const Settings * get_requested_settings(void);
Settings * get_requested_settings_mutable(void);

void sys_settings_mark_changed(void);
bool sys_settings_changes_pending(void);
void sys_settings_clear_pending(void);

BrightnessValue sys_settings_get_brightness(void);
void sys_settings_set_brightness(BrightnessValue value);

#endif

