/**
 * @file timer.c
 * @brief
 */

#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "sys_settings_types.h"
#include "timer.h"

static uint32_t period_ms = 0;
static uint64_t last_tick_ms = 0;

// Monotonic ms timer
static uint64_t now_ms(void)
{
    /*
     * struct timespec (from <time.h>):
     *
     *   struct timespec {
     *       time_t tv_sec;   // whole seconds
     *       long   tv_nsec;  // nanoseconds (0 to 999,999,999)
     *   };
     */
    struct timespec ts;

    // Call and check clock_gettime(...) = 0 (success) or -1 (failure)
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
    {
        return 0;
    }

    uint64_t tv_ms = (uint64_t)ts.tv_sec * 1000ULL + (uint64_t)ts.tv_nsec / 1000000ULL;

    return tv_ms;
}

bool timer_expired(void)
{
    uint64_t now = now_ms();

    if (now - last_tick_ms >= period_ms)
    {
        last_tick_ms = now;

        return true;
    }
    return false;
}

void timer_sine_wave(uint32_t * counts)
{
    const double pi          = 3.141592653589793;
    const double mean        = 28228000.0;
    const double amplitude   = 1000.0;
    const double period_s    = 300.0;
    const double phase_shift = pi / 8.0;

    double t = (double)now_ms() / 1000.0;
    double theta = 2.0 * pi * t / period_s;
    double v1 = mean + amplitude * sin(theta);
    double v2 = mean + amplitude * sin(theta + phase_shift);

    TimebaseOption tb_option = timer_get_timebase();

    switch (tb_option)
    {
    case TIMEBASE_100MS:
        counts[0] = (uint32_t)(v1 / 10.0);
        counts[1] = (uint32_t)(v2 / 10.0);
        break;
    case TIMEBASE_1SEC:
        counts[0] = (uint32_t)v1;
        counts[1] = (uint32_t)v2;
        break;
    case TIMEBASE_10SEC:
        counts[0] = (uint32_t)(v1 * 10.0);
        counts[1] = (uint32_t)(v2 * 10.0);
        break;
    }
}

void timer_restart(void)
{
    last_tick_ms = now_ms();
}

void timer_set_timebase(TimebaseOption timebase_option)
{
    switch (timebase_option)
    {
    case TIMEBASE_100MS:
        period_ms = 100;
        break;
    case TIMEBASE_1SEC:
        period_ms = 1000;
        break;
    case TIMEBASE_10SEC:
        period_ms = 10000;
        break;
    default:
        period_ms = 1000;
        break;
    }
}

TimebaseOption timer_get_timebase(void)
{
    switch (period_ms)
    {
    case 100:
        return TIMEBASE_100MS;
    case 1000:
        return TIMEBASE_1SEC;
    case 10000:
        return TIMEBASE_10SEC;
    default:
        return TIMEBASE_NA;
    }
}

