/**
 * @file
 * @brief
 */

#include "app_init.h"
#include "svc_settings.h"
#include "cor_menu_nav.h"
#include "cor_probe_db.h"

void application_init(void)
{
    probe_db_init();
    menu_nav_init();
    svc_settings_init();
    svc_settings_apply();
}

