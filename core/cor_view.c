/**
 * @file cor_view.c
 * @brief Logical text view management.
 */

#include <string.h>
#include <stdio.h>
#include "cor_view.h"
#include "hw_display.h"

static char view_buf[VIEW_ROWS][VIEW_COLS];

void view_clear(void)
{
    for (uint8_t row = 0; row < VIEW_ROWS; ++row)
    {
        memset(view_buf[row], ' ', VIEW_COLS);
    }
}

void view_set_row(uint8_t row, const char *text)
{
    if (row >= VIEW_ROWS || text == NULL)
    {
        return;
    }

    int len = (int)strlen(text);
    for (int col = 0; col < VIEW_COLS; ++col)
    {
        view_buf[row][col] = (col < len) ? text[col] : ' ';
    }
}

const char * view_get_row(uint8_t row)
{
    if (row >= VIEW_ROWS)
    {
        return "";
    }

    return view_buf[row];
}

void view_update_row(uint8_t row)
{
    if (row >= VIEW_ROWS)
    {
        return;
    }


    hw_display_update_row(row, view_buf[row]);
}

/*
 * view_buf has type char [M][N], which used as
 * a function argument, decays to:       char (*)[N].
 * hw_display_update expects type: const char (*)[N].
 * So this type (const char (*)[N]) is assigned explicitly to view_buf.
 */
void view_update(void)
{
    hw_display_update((const char (*)[VIEW_COLS])view_buf);
}

