/**
 * @file
 * @brief
 */

#include "app_init.h"
#include "svc_display.h"
#include "svc_init.h"
#include "svc_input.h"
#include "svc_menu_nav.h"
#include "svc_output.h"
#include "svc_sample.h"
#include "svc_settings.h"
#include "svc_temperature.h"
#include "svc_view.h"
#include "sys_counters.h"
#include "sys_init.h"
#include "sys_settings.h"
#include "cor_menu_nav.h"

int main()
{
    system_init();      // MCU, clocks, GPIO, peripherals...
    services_init();    // Display, input, output, sampling...
    application_init(); // Settings, database, menu/state tree...

    svc_display_show_startup();
    svc_sample_restart_cycle();

    for (;;)
    {
        if (sample_period_complete())
        {
            read_measurement();
            update_temp();                              // Run before changing settings
            svc_view_request_update(DISPLAY_MODE_BASE); // Run before changing settings
            svc_settings_handle_pending();              // Update settings for next cycle
            svc_sample_restart_cycle();
            svc_transmit_results();                     // Can run during measurement cycle
        }

        UIKey key = svc_input_poll_key();
        if (key != UI_KEY_NULL)
        {
            const NodeID active_node_id = menu_nav_get_active_node_id();
            if (active_node_id == NODE_BRT_MAIN || active_node_id == NODE_BRT_OTHER)
            {
                svc_view_request_update(DISPLAY_MODE_BRT);
                /* TODO: Interpret key as editing brightness value */
            }
            else
            {
                svc_menu_step(key);
                svc_view_request_update(DISPLAY_MODE_MENU);
            }
        }

        svc_view_update_if_needed();
    }
}

