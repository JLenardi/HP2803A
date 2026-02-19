/**
 * @file cor_menu_actions.c
 * @brief
 */

#include "svc_settings.h"  // Data container owned by services
#include "sys_settings.h"
#include "sys_settings_apply.h"
#include "cor_brt_actions.h"
#include "cor_core_types.h"
#include "cor_menu_actions.h"
#include "cor_probe_db.h"
#include "cor_probe_edit.h"

ActionContext menu_actions_resolve(ActionID action_id)
{
    switch (action_id)
    {
    case CTX_BRIGHTNESS:
        return (ActionContext){CAT_BRIGHTNESS, BRT_SHOW};

    case CTX_DISP1_T1:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_T1};
    case CTX_DISP1_T2:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_T2};
    case CTX_DISP1_T1MINUST2:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_T1MINUST2};
    case CTX_DISP1_T2MINUST1:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_T2MINUST1};
    case CTX_DISP1_DELTAT1:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_DELTAT1};
    case CTX_DISP1_DELTAT2:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_DELTAT2};
    case CTX_DISP1_MINT1:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_MINT1};
    case CTX_DISP1_MINT2:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_MINT2};
    case CTX_DISP1_MAXT1:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_MAXT1};
    case CTX_DISP1_MAXT2:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_MAXT2};
    case CTX_DISP1_COUNT1:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_COUNT1};
    case CTX_DISP1_COUNT2:
        return (ActionContext){CAT_DISPLAY1, DISPLAY_COUNT2};

    case CTX_DISP2_T1:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_T1};
    case CTX_DISP2_T2:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_T2};
    case CTX_DISP2_T1MINUST2:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_T1MINUST2};
    case CTX_DISP2_T2MINUST1:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_T2MINUST1};
    case CTX_DISP2_DELTAT1:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_DELTAT1};
    case CTX_DISP2_DELTAT2:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_DELTAT2};
    case CTX_DISP2_MINT1:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_MINT1};
    case CTX_DISP2_MINT2:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_MINT2};
    case CTX_DISP2_MAXT1:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_MAXT1};
    case CTX_DISP2_MAXT2:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_MAXT2};
    case CTX_DISP2_COUNT1:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_COUNT1};
    case CTX_DISP2_COUNT2:
        return (ActionContext){CAT_DISPLAY2, DISPLAY_COUNT2};

    case CTX_CELSIUS:
        return (ActionContext){CAT_UNITS, UNITS_CELSIUS};
    case CTX_FAHRENHEIT:
        return (ActionContext){CAT_UNITS, UNITS_FAHRENHEIT};
    case CTX_KELVIN:
        return (ActionContext){CAT_UNITS, UNITS_KELVIN};

    case CTX_SCALE2:
        return (ActionContext){CAT_RESOLUTION, RES_SCALE2};
    case CTX_SCALE3:
        return (ActionContext){CAT_RESOLUTION, RES_SCALE3};
    case CTX_SCALE4:
        return (ActionContext){CAT_RESOLUTION, RES_SCALE4};

    case CTX_BRT_MAIN_VALUE:
        return (ActionContext){CAT_BRIGHTNESS, BRT_MAIN};
    case CTX_BRT_OTHER_VALUE:
        return (ActionContext){CAT_BRIGHTNESS, BRT_OTHER};

    case CTX_FRONT:
        return (ActionContext){CAT_SOCKETS, SOCKETS_FRONT};
    case CTX_BACK:
        return (ActionContext){CAT_SOCKETS, SOCKETS_BACK};

    case CTX_PROBE_A_IDX0:
        return (ActionContext){CAT_PROBE_A, PROBE_IDX0};
    case CTX_PROBE_A_IDX1:
        return (ActionContext){CAT_PROBE_A, PROBE_IDX1};
    case CTX_PROBE_A_IDX2:
        return (ActionContext){CAT_PROBE_A, PROBE_IDX2};

    case CTX_PROBE_B_IDX0:
        return (ActionContext){CAT_PROBE_B, PROBE_IDX0};
    case CTX_PROBE_B_IDX1:
        return (ActionContext){CAT_PROBE_B, PROBE_IDX1};
    case CTX_PROBE_B_IDX2:
        return (ActionContext){CAT_PROBE_B, PROBE_IDX2};

    case CTX_TRANSMIT_ON:
        return (ActionContext){CAT_TRANSMIT, TRANSMIT_ON};
    case CTX_TRANSMIT_OFF:
        return (ActionContext){CAT_TRANSMIT, TRANSMIT_OFF};

    case CTX_SETTINGS_SAVE:
        return (ActionContext){CAT_SETTINGS, SETTINGS_SAVE};
    case CTX_SETTINGS_DISCARD:
        return (ActionContext){CAT_SETTINGS, SETTINGS_DISCARD};
    case CTX_SETTINGS_DEFAULT:
        return (ActionContext){CAT_SETTINGS, SETTINGS_DEFAULT};

    case CTX_PROBE_SAVE:
        return (ActionContext){CAT_PROBE_DB, SETTINGS_SAVE};
    case CTX_PROBE_DISCARD:
        return (ActionContext){CAT_PROBE_DB, SETTINGS_DISCARD};
    case CTX_PROBE_DEFAULT:
        return (ActionContext){CAT_PROBE_DB, SETTINGS_DEFAULT};

    case CTX_PROBE_CORE_IDX:
        return (ActionContext){CAT_PROBE_CORE, PROBE_CORE_IDX};
    case CTX_PROBE_CORE_PARAM:
        return (ActionContext){CAT_PROBE_CORE, PROBE_CORE_PARAM};
    case CTX_PROBE_CORE_VALUE:
        return (ActionContext){CAT_PROBE_CORE, PROBE_CORE_VALUE};

    case CTX_PROBE_CF_IDX:
        return (ActionContext){CAT_PROBE_CF, PROBE_CF_IDX};
    case CTX_PROBE_CF_PARAM:
        return (ActionContext){CAT_PROBE_CF, PROBE_CF_PARAM};
    case CTX_PROBE_CF_VALUE:
        return (ActionContext){CAT_PROBE_CF, PROBE_CF_VALUE};

    default:
        return (ActionContext){CAT_NONE, 0};
    }
}

MenuFlow menu_actions_dispatch(ActionContext* ctx)
{
    Settings * reqd_settings = get_requested_settings_mutable();

    switch (ctx->menu_category)
    {
    case CAT_DISPLAY1:
        reqd_settings->display1_option = ctx->selected_value;
        sys_settings_mark_changed();
        return MENU_FLOW_CANCEL;

    case CAT_DISPLAY2:
        reqd_settings->display2_option = ctx->selected_value;
        sys_settings_mark_changed();
        return MENU_FLOW_CANCEL;

    case CAT_UNITS:
        reqd_settings->units_option = ctx->selected_value;
        sys_settings_mark_changed();
        return MENU_FLOW_CANCEL;

    case CAT_RESOLUTION:
        reqd_settings->resolution_option = ctx->selected_value;
        sys_settings_mark_changed();

        switch (ctx->selected_value)
        {
        case RES_SCALE2:
            reqd_settings->timebase_option = TIMEBASE_100MS;
            break;
        case RES_SCALE3:
            reqd_settings->timebase_option = TIMEBASE_1SEC;
            break;
        case RES_SCALE4:
            reqd_settings->timebase_option = TIMEBASE_10SEC;
            break;
        }
        return MENU_FLOW_CANCEL;

    case CAT_TIMEBASE:
        /* no-op */
        return MENU_FLOW_CANCEL;

    case CAT_BRIGHTNESS:
        switch (ctx->selected_value)
        {
        case BRT_SHOW:
            return brt_menu_actions_show();
        case BRT_MAIN:
            return brt_menu_actions_set_low_nibble();
        case BRT_OTHER:
            return brt_menu_actions_set_high_nibble();
        }
        return MENU_FLOW_CANCEL;

    case CAT_SOCKETS:
        reqd_settings->sockets_option = ctx->selected_value;
        sys_settings_mark_changed();
        return MENU_FLOW_CANCEL;

    case CAT_PROBE_A:
        reqd_settings->probe_a_option = ctx->selected_value;
        sys_settings_mark_changed();
        return MENU_FLOW_CANCEL;

    case CAT_PROBE_B:
        reqd_settings->probe_b_option = ctx->selected_value;
        sys_settings_mark_changed();
        return MENU_FLOW_CANCEL;

    case CAT_TRANSMIT:
        reqd_settings->transmit_option = ctx->selected_value;
        sys_settings_mark_changed();
        return MENU_FLOW_CANCEL;

    case CAT_SETTINGS:
        switch (ctx->selected_value)
        {
        case SETTINGS_SAVE:
            save_current_settings();
            break;
        case SETTINGS_DISCARD:
            discard_current_settings();
            sys_settings_mark_changed();
            break;
        case SETTINGS_DEFAULT:
            use_default_settings();
            sys_settings_mark_changed();
            break;
        }
        return MENU_FLOW_CANCEL;

    case CAT_PROBE_DB:
        switch (ctx->selected_value)
        {
        case SETTINGS_SAVE:
            probe_db_save_current_core();
            probe_db_save_current_cf();
            break;
        case SETTINGS_DISCARD:
            probe_db_discard_current_core();
            probe_db_discard_current_cf();
            break;
        case SETTINGS_DEFAULT:
            probe_db_use_default_core();
            probe_db_use_default_cf();
            break;
        }
        return MENU_FLOW_CANCEL;

    case CAT_PROBE_CORE:
        switch (ctx->selected_value)
        {
        case PROBE_CORE_IDX:
            return probe_set_core_idx();
        case PROBE_CORE_PARAM:
            return probe_set_core_param();
        case PROBE_CORE_VALUE:
            return probe_set_core_value();
        }
        return MENU_FLOW_CANCEL;

    case CAT_PROBE_CF:
        switch (ctx->selected_value)
        {
        case PROBE_CF_IDX:
            return probe_set_cf_idx();
        case PROBE_CF_PARAM:
            return probe_set_cf_param();
        case PROBE_CF_VALUE:
            return probe_set_cf_value();
        }
        return MENU_FLOW_CANCEL;
    }

    return MENU_FLOW_CANCEL;
}

