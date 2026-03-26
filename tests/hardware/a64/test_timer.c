/**
 * @file test_timer.c
 */

#define _POSIX_C_SOURCE 200809L

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "timer.h"

static void sleep_ms(long ms)
{
    struct timespec req =
    {
        .tv_sec = ms / 1000,
        .tv_nsec = (ms % 1000) * 1000000L
    };
    nanosleep(&req, NULL);
}

int main(void)
{
    uint64_t prev = timer_now_ms();

    for (int i = 0; i < 10; i++)
    {
        sleep_ms(1000);

       uint64_t cur = timer_now_ms();

        if (cur <= prev)
        {
            printf("FAIL: Not monotonic at step %d (prev =%llu, cur=%llu)\n",
                 i,
               (unsigned long long)prev,
                (unsigned long long)cur);
            return 1;
        }

        uint64_t delta = cur - prev;
        printf("step %d: delta = %llu ms\n",
                i,
                (unsigned long long)delta);

        if (delta < 900 || delta > 1100)
        {
            printf("WARNING: delta out of expected range\n");
        }

        prev = cur;
    }

    printf("PASS: monotonic over 10 samples\n");
    return 0;
}

