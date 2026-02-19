/**
 * @file cor_render_views.c
 * @brief
 */

#define NUM_SOCKETS 2

#include <inttypes.h>         // Defines PRIu32
#include <stdint.h>
#include <stdio.h>
#include <string.h>           // Provides memcpy
#include "cor_core_defs.h"
#include "cor_data_provider.h"
#include "cor_menu_nav.h"
#include "cor_menu_tree.h"
#include "cor_render_views.h"
#include "cor_view.h"
#include "sys_settings_types.h"
#include "utils.h"

static TimebaseOption infer_timebase_from_count(uint32_t count)
{
    TimebaseOption tb;

    if (count >= COUNT_MIN_1SEC && count <= COUNT_MAX_1SEC)
    {
        tb = TIMEBASE_1SEC;
    }
    else if (count >= COUNT_MIN_10SEC && count <= COUNT_MAX_10SEC)
    {
        tb = TIMEBASE_10SEC;
    }
    else if (count >= COUNT_MIN_100MS && count <= COUNT_MAX_100MS)
    {
        tb = TIMEBASE_100MS;
    }
    else
    {
        tb = TIMEBASE_NA;
    }

    return tb;
}

static ResolutionOption infer_resolution_from_count(uint32_t count)
{
    ResolutionOption res;

    if (count >= COUNT_MIN_1SEC && count <= COUNT_MAX_1SEC)
    {
        res = RES_SCALE3;
    }
    else if (count >= COUNT_MIN_10SEC && count <= COUNT_MAX_10SEC)
    {
        res = RES_SCALE4;
    }
    else if (count >= COUNT_MIN_100MS && count <= COUNT_MAX_100MS)
    {
        res = RES_SCALE2;
    }
    else
    {
        res = RES_SCALE1;
    }

    return res;
}

static float get_temp_parameter(int socket_idx, DisplayOption display_option)
{
    /* Range control */
    socket_idx &= 0x01;

    const float * temp = cor_get_temps();

    switch (display_option)
    {
    case DISPLAY_T1:
        return temp[0];
    case DISPLAY_T2:
        return temp[1];
    case DISPLAY_T1MINUST2:
        return (temp[0] - temp[1]);
    case DISPLAY_T2MINUST1:
        return (temp[1] - temp[0]);
    case DISPLAY_DELTAT1:  // TODO: complete these cases
    case DISPLAY_DELTAT2:
    case DISPLAY_MINT1:
    case DISPLAY_MINT2:
    case DISPLAY_MAXT1:
    case DISPLAY_MAXT2:
        break;
    }
    return 0.0f;
}

static uint32_t get_count_parameter(int socket_idx, DisplayOption display_option)
{
    uint32_t count_ref = 0;

    /* Range control */
    socket_idx &= 0x01;

    const uint32_t * counts = cor_get_counts();
    TimebaseOption tb = infer_timebase_from_count(counts[0]);

    switch (tb)
    {
    case TIMEBASE_100MS:
        count_ref = COUNT_REF_100MS;
        break;
    case TIMEBASE_1SEC:
        count_ref = COUNT_REF_1SEC;
        break;
    case TIMEBASE_10SEC:
        count_ref = COUNT_REF_10SEC;
        break;
    default:
        return 0;
    }

    if (display_option == DISPLAY_COUNT1)
    {
        return counts[0] - count_ref;
    }
    else if (display_option == DISPLAY_COUNT2)
    {
        return counts[1] - count_ref;
    }

    return 0;
}

static uint8_t get_resolution(void)
{
    const uint32_t * counts = cor_get_counts();
    ResolutionOption res_option = infer_resolution_from_count(counts[0]);

    switch (res_option)
    {
    case RES_SCALE2:
        return 2;
    case RES_SCALE3:
        return 3;
    case RES_SCALE4:
        return 4;
    default:
        return 1;
    }
}

static float convert_celsius(float temp_celsius, UnitsOption units_option)
{
    switch (units_option)
    {
    case UNITS_FAHRENHEIT:
        return 32.0f + (temp_celsius * 9.0f / 5.0f);
    case UNITS_KELVIN:
        return 273.15f + temp_celsius;
    }
    return temp_celsius;
}

void render_base_view(void)
{
    char view_buf_out[VIEW_ROWS][VIEW_COLS];
    char text[VIEW_COLS + 1];  // snprintf() below uses NULL terminator
    DisplayOption display_option;

    const Settings * curr_settings = cor_get_current_settings();
    UnitsOption units_option = curr_settings->units_option;

    view_clear();

    for (int socket_idx = 0; socket_idx < 2; ++socket_idx)
    {
        display_option = (socket_idx)
                         ? curr_settings->display2_option
                         : curr_settings->display1_option;

        if (display_option >= DISPLAY_T_MIN && display_option <= DISPLAY_T_MAX)
        {
            float temp_param = get_temp_parameter(socket_idx, display_option);

            if (units_option != UNITS_CELSIUS)
            {
                temp_param = convert_celsius(temp_param, units_option);
            }

            uint8_t res = get_resolution();
            utils_float_to_text(temp_param, VIEW_COLS, res, text);
        }
        else if (display_option == DISPLAY_COUNT1 || display_option == DISPLAY_COUNT2)
        {
            uint32_t count_param = get_count_parameter(socket_idx, display_option);

            snprintf(text, sizeof(text), "%8" PRIu32, count_param);
        }

        /* socket[0] <-> row[0]    socket[1] <-> row[2] */
        uint8_t row = (socket_idx == 0) ? 0 : 2;
        memcpy(view_buf_out[row], text, VIEW_COLS);  // Excludes NULL terminator '\0'
        view_set_row(row, view_buf_out[row]);
    }
}

void render_output_view(void)
{
    const uint32_t * counts = cor_get_counts();
    const float * temps = cor_get_temps();

    char * buf = cor_get_output_buf_mutable();

    if (!counts || !temps)
    {
        return;
    }

    uint8_t res = get_resolution();

    utils_int_to_text(utils_clamp_u32(counts[0]), 9, &buf[0]);
    utils_int_to_text(utils_clamp_u32(counts[1]), 9, &buf[10]);
    buf[9]   = ',';
    buf[19]  = ',';
    utils_float_to_text(temps[0], 8, res, &buf[20]);
    utils_float_to_text(temps[1], 8, res, &buf[29]);
    buf[28]  = ',';
}

void render_fixed_menu_view(void)
{
    NodeID active_node_id = menu_nav_get_active_node_id();
    NodeID cursor_node_id = menu_nav_get_cursor_node_id();

    const MenuNode * active_node = menu_nav_get_node(active_node_id);
    const MenuNode * cursor_node = menu_nav_get_node(cursor_node_id);

    view_clear();

    if (active_node)
    {
        view_set_row(0, menu_text[active_node->text_id]);
    }
    if (cursor_node)
    {
        view_set_row(1, menu_text[cursor_node->text_id]);
    }
}

void render_dynamic_brt_view(uint8_t brt_value)
{
    NodeID active_node_id = menu_nav_get_active_node_id();
    if (active_node_id != NODE_BRT_MAIN && active_node_id != NODE_BRT_OTHER)
    {
        return;
    }

    char text[VIEW_COLS + 1];  // snprintf() below uses NULL terminator

    /* Show whole brightness value on display[2] */
    snprintf(text, sizeof(text), "    0x%02x", brt_value);
    view_set_row(2, text);

    /* Show separate value (main/other) on display[3] */
    uint8_t brt_nibble = 1;
    if (active_node_id == NODE_BRT_MAIN)
    {
        brt_nibble = utils_get_nibble(brt_value, NIBBLE_LOW)  & 0x07;
    }
    else if (active_node_id == NODE_BRT_OTHER)
    {
        brt_nibble = utils_get_nibble(brt_value, NIBBLE_HIGH) & 0x07;
    }

    snprintf(text, sizeof(text), "       %d", brt_nibble);
    view_set_row(3, text);
}

