/**
 * @file cor_render_views.h
 * @brief
 */

#ifndef COR_RENDER_VIEWS_H
#define COR_RENDER_VIEWS_H

#include <stdint.h>

void render_base_view(void);
void render_output_view(void);
void render_fixed_menu_view(void);
void render_dynamic_brt_view(uint8_t brt_value);

#endif

