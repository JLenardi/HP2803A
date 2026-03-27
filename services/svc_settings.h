/**
 * @file svc_settings.h
 * @brief
 */

#ifndef SVC_SETTINGS_H
#define SVC_SETTINGS_H

#include <stdbool.h>
#include "sys_settings_types.h"

void svc_settings_init(void);
void svc_settings_apply(void);

void svc_handle_settings_requests(void);
const Settings * get_requested_settings(void);
Settings * get_requested_settings_mutable(void);
void svc_settings_handle_pending(void);

#endif

