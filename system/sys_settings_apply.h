/**
 * @file sys_settings_apply.h
 * @brief
 */

#ifndef SYS_SETTINGS_APPLY_H
#define SYS_SETTINGS_APPLY_H

#include "sys_settings_types.h"

void sys_settings_apply_timebase(TimebaseOption timebase_option);
void settings_apply_sockets(SocketsOption sockets_option);
void settings_apply_probe_a(ProbeOption probe_a_option);
void settings_apply_probe_b(ProbeOption probe_b_option);
void settings_apply_transmit(TransmitOption transmit_option);
void sys_settings_apply(void);
void sys_settings_handle_pending(void);

#endif

