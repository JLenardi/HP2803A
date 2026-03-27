/* cor_menu_nav.h */

#ifndef COR_MENU_NAV_H
#define COR_MENU_NAV_H

#include "cor_menu_nav.h"
#include "cor_menu_types.h"
#include "svc_input.h"

NodeID menu_nav_get_active_node_id(void);
NodeID menu_nav_get_cursor_node_id(void);
void menu_nav_init(void);
const MenuNode* menu_nav_get_node(NodeID node_id);
void menu_nav_step(UIKey key);

#endif

