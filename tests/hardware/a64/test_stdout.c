#include "hw_display.h"
#include "stdout.h"

int main(void)
{
    static const char fill_chars[] = "ABCDEGHIJKLMNOPQRSTUVWXYZ";
    char row_buf[DISPLAY_COLS];

    stdout_init();

    for (int r = 0; r < DISPLAY_ROWS; r++)
    {
        const char ch = fill_chars[r % 26];

        for (int c = 0; c < DISPLAY_COLS; c++)
        {
            row_buf[c] = ch;
        }

        stdout_update_row(r, row_buf);
    }

    return 0;
}
