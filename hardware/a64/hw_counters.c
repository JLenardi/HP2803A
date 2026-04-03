/**
 * @file hardware/a64/hw_counters.c
 * @brief Hardware counter interface for A64 platform.
 *
 * This module provides hw_* wrapper functions around the timer_* API
 * implemented in the A64 layer.
 *
 * Mapping:
 *   hw_counters_ready()   -> timer_expired()
 *   hw_read_counters()    -> timer_sine_wave()
 *   hw_restart_counters() -> timer_restart()
 */

#include <stdbool.h>
#include <stdint.h>
#include "hw_counters.h"
#include "timer.h"

bool hw_counters_ready(void)
{
    return timer_expired();
}

void hw_read_counters(uint32_t counts_out[2])
{
    timer_sine_wave(counts_out);
}

void hw_restart_counters(void)
{
    timer_restart();
}
