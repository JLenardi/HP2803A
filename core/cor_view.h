/**
 * @file cor_view.h
 * @brief
 */

#ifndef COR_VIEW_H
#define COR_VIEW_H

#include "hw_display.h"

#define VIEW_ROWS DISPLAY_ROWS
#define VIEW_COLS DISPLAY_COLS

void view_clear(void);
void view_set_row(uint8_t row, const char * view_buf_out);
const char * view_get_row(uint8_t row);
void view_update_row(uint8_t row);
void view_update(void);

#endif

