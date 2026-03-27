/**
 * @file stdout.h
 * @brief
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "hw_display.h"

void stdout_init(void);
void stdout_clear(void);
void stdout_update_char(int row, int col, char view_buf_char);
void stdout_update_row(int row, const char * view_buf_row);
void stdout_update(const char view_buf_in[][DISPLAY_COLS]);

#endif

