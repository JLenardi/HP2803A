/**
 * @file stdin.c
 * @brief Non-blocking stdin keyboard driver for A64/Linux.
 *
 * NOTE:
 *   The terminal must be configured externally using commands such as:
 *      stty -icanon -echo
 *
 *   This driver does NOT modify the terminal.
 */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

#include "hw_input.h"
#include "stdin.h"

void stdin_init(void)
{
    /* Terminal must be configured manually:
     *
     * Before running program:
     * stty -icanon -echo min 0 time 0
     * ./build/prog
     *
     * After running program:
     * stty sane
     */
}

/**
 * @brief Attempt to read a single character from stdin without blocking.
 *
 * This function checks whether input is available on stdin. If a character
 * is ready, it reads and returns it. If no input is available, it returns -1
 * immediately instead of waiting.
 *
 * @return int
 *   ASCII value of the character read
 *   -1 for no input or read error
 */
static int stdin_get_char_nonblocking(void)
{
    // Declare variable rfds as type fd_set
    fd_set rfds;

    // Initialize the file descriptor set
    FD_ZERO(&rfds);

    // Add stdin (file descriptor 0) to the set
    FD_SET(STDIN_FILENO, &rfds);

    // Set timeout to zero
    struct timeval tv = {0, 0};

    // Check if stdin has data ready to read
    int retval = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);

    // No data or error
    if (retval <= 0)
    {
        return -1;
    }

    unsigned char ch;

    // Read one byte from stdin
    ssize_t n = read(STDIN_FILENO, &ch, 1);

    // Read failure or no data
    if (n <= 0)
    {
        return -1;
    }

    // Return character
    return ch;
}
HWKey stdin_poll_key(void)
{
    int ch = stdin_get_char_nonblocking();
    if (ch < 0)
    {
        return HW_KEY_NULL;
    }

    switch (ch)
    {
    case 's':
        return HW_KEY_SELECT;
    case 'b':
        return HW_KEY_BACK;
    case 'c':
        return HW_KEY_CANCEL;
    case 'r':
        return HW_KEY_ROTA;
    case 't':
        return HW_KEY_ROTB;
    default:
        return HW_KEY_INVALID;
    }
}

