/**
 * @file svc_display.h
 * @brief Display service interface built on top of view_buf.
 */

#ifndef SVC_DISPLAY_H
#define SVC_DISPLAY_H

#include <stdint.h>
#include "cor_view.h"

const char *svc_display_row(uint8_t row);

void svc_display_init(void);
void svc_display_show_startup(void);
void svc_display_blank(void);
void svc_display_set_text(uint8_t row, uint8_t col, const char *str);
void svc_display_update(void);

#endif

