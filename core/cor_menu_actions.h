/**
 * @file cor_menu_actions.h
 * @brief
 */

#ifndef COR_MENU_ACTIONS_H
#define COR_MENU_ACTIONS_H

#include "cor_core_types.h"
#include "cor_menu_types.h"

MenuFlow menu_actions_dispatch(ActionContext* ctx);
ActionContext menu_actions_resolve(ActionID id);

#endif

