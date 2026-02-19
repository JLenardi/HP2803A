/**
 * @file cor_brt_actions.c
 * @brief
 */

#define DEBUG 0

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "svc_input.h"
#include "sys_settings.h"
#include "cor_core_types.h"
#include "cor_menu_types.h"
#include "cor_render_views.h"
#include "cor_view.h"
#include "utils.h"

#define MIN_BRIGHTNESS 0
#define MAX_BRIGHTNESS 7

#if 0
MenuFlow brt_menu_actions_show(void)
{
    char str[VIEW_COLS + 1];

    // Clear row 3
    view_set_row(3, "        ");

    Settings * s = get_current_settings_mutable();
    uint8_t current_brt = s->brightness_value;
    snprintf(str, sizeof(str), "    0x%02x", current_brt);
    str[VIEW_COLS] = '\0';
    view_set_row(2, str);

    view_update();

    return MENU_FLOW_HOLD;
}
#else
MenuFlow brt_menu_actions_show(void)
{
    const Settings * curr_settings = get_current_settings();
    uint8_t brt_value = curr_settings->brightness_value;

    render_dynamic_brt_view(brt_value);

    return MENU_FLOW_HOLD;
}
#endif

MenuFlow brt_menu_actions_set_low_nibble(void)
{
    char str[VIEW_COLS + 1];
    Settings * s = get_current_settings_mutable();
    uint8_t current_brt_value = s->brightness_value;
    uint8_t brt_low;

    view_set_row(2, "        ");

    brt_low  = utils_get_nibble(s->brightness_value, NIBBLE_LOW);
    brt_low &= 0x07;  // 0b0111 — low nibble limited to 3 bits

    while (1)
    {
        snprintf(str, VIEW_COLS + 1, "%8d", brt_low);
        view_set_row(3, str);
        view_update();

        UIKey key_input = svc_input_poll_key();
        switch (key_input)
        {
        case UI_KEY_SELECT:
            s->brightness_value =
                utils_set_nibble(current_brt_value, NIBBLE_LOW, brt_low);
            return MENU_FLOW_BACK;

        case UI_KEY_BACK:
            return MENU_FLOW_BACK;

        case UI_KEY_CANCEL:
            return MENU_FLOW_CANCEL;

        case UI_KEY_ROTA:
            if (brt_low < MAX_BRIGHTNESS)
            {
                brt_low++;
            }
            break;

        case UI_KEY_ROTB:
            if (brt_low > MIN_BRIGHTNESS)
            {
                brt_low--;
            }
            break;

        default:
            break;
        }
    }

    return MENU_FLOW_BACK;
}

MenuFlow brt_menu_actions_set_high_nibble(void)
{
    char str[VIEW_COLS + 1];
    Settings * s = get_current_settings_mutable();
    uint8_t current_brt_value = s->brightness_value;
    uint8_t brt_high;

    view_set_row(2, "        ");

    brt_high  = utils_get_nibble(s->brightness_value, NIBBLE_HIGH);
    brt_high &= 0x07;  // 0b0111 — high nibble limited to 3 bits

    while (1)
    {
        snprintf(str, VIEW_COLS + 1, "%8d", brt_high);
        view_set_row(3, str);
        view_update();

        UIKey key_input = svc_input_poll_key();
        switch (key_input)
        {
        case UI_KEY_SELECT:
            s->brightness_value =
                utils_set_nibble(current_brt_value, NIBBLE_HIGH, brt_high);
            return MENU_FLOW_BACK;

        case UI_KEY_BACK:
            return MENU_FLOW_BACK;

        case UI_KEY_CANCEL:
            return MENU_FLOW_CANCEL;

        case UI_KEY_ROTA:
            if (brt_high < MAX_BRIGHTNESS)
            {
                brt_high++;
            }
            break;

        case UI_KEY_ROTB:
            if (brt_high > MIN_BRIGHTNESS)
            {
                brt_high--;
            }
            break;

        default:
            break;
        }
    }

    return MENU_FLOW_BACK;
}

