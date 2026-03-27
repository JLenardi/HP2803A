/**
 * @file hw_display.h
 * @brief
 */

#ifndef HW_DISPLAY_H
#define HW_DISPLAY_H

#include <stdint.h>

#define DISPLAY_ROWS 4
#define DISPLAY_COLS 8

void hw_display_init(void);
void hw_display_clear(void);
void hw_display_update_char(uint8_t row, uint8_t col, char view_buf_char);
void hw_display_update_row(uint8_t row, const char * view_buf_row);
void hw_display_update(const char view_buf_in[][DISPLAY_COLS]);
void hw_display_set_brightness(uint8_t row, uint8_t brightness);
void hw_display_set_blink(uint8_t row, uint8_t brightness, uint8_t blink);

#endif

