/**
 * @file test_stdin.c
 * @brief Test program for stdin non-blocking keyboard driver.
 *
 * Before running:
 *   stty -icanon -echo min 0 time 0
 *
 * After running:
 *   stty sane
 *
 * Exit with:
 *   Ctrl-C
 */
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <time.h>
#include "hw_input.h"
#include "stdin.h"

static const char *key_to_string(HWKey key)
{
    switch (key)
    {
    case HW_KEY_NULL:   return "HW_KEY_NULL";
    case HW_KEY_SELECT: return "HW_KEY_SELECT";
    case HW_KEY_BACK:   return "HW_KEY_BACK";
    case HW_KEY_CANCEL: return "HW_KEY_CANCEL";
    case HW_KEY_ROTA:   return "HW_KEY_ROTA";
    case HW_KEY_ROTB:   return "HW_KEY_ROTB";
    case HW_KEY_INVALID:return "HW_KEY_INVALID";
    default:            return "UNKNOWN";
    }
}

int main(void)
{
    printf("Non-blocking stdin test\n");

    stdin_init();

    while (1)
    {
        HWKey key = stdin_poll_key();

        if (key != HW_KEY_NULL)
        {
            printf("Key: %s\n", key_to_string(key));
            fflush(stdout);
        }

        const struct timespec ts = {0, 10000000L}; /* 10 ms */
        (void)nanosleep(&ts, NULL);
    }

    return 0;
}
