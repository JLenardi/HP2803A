/**
 * @file timer.h
 * @brief
 */

#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include <stdint.h>
#include "sys_settings_types.h"

/* TODO: check if these function declarations necessary */
uint64_t timer_now_ms(void);
bool timer_expired(void);
void timer_sine_wave(uint32_t * counts);
void timer_restart(void);

void timer_set_timebase(TimebaseOption timebase_option);
TimebaseOption timer_get_timebase(void);

#endif

