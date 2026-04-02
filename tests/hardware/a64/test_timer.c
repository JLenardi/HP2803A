#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include "timer.h"

int main(void)
{
    uint32_t counts[2] = {0, 0};
    uint64_t start_ms  = 0;
    uint64_t now_ms    = 0;
    uint64_t elapsed_s = 0;
    unsigned cycles    = 0;

    timer_set_timebase(TIMEBASE_1SEC);
    timer_restart();

    start_ms = timer_now_ms();

    printf("t    counts[0] counts[1]\n");

    while (cycles <= 300)
    {
        if (timer_expired())
        {
            timer_sine_wave(counts);

            now_ms = timer_now_ms();
            elapsed_s = (now_ms - start_ms) / 1000;

            printf("%03" PRIu64 "  %" PRIu32 "  %" PRIu32 "\n",
                   elapsed_s, counts[0], counts[1]);

            ++cycles;
        }
    }

    return 0;
}
