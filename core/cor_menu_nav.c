/**
 * @file cor_menu_nav.c
 * @brief
 */

#include <stddef.h>
#include <stdio.h>
#include "sys_settings.h"
#include "svc_input.h"
#include "cor_menu_actions.h"
#include "cor_menu_tree.h"
#include "cor_menu_nav.h"
#include "svc_display.h"

static NodeID active_node_id;
static NodeID cursor_node_id;

static void apply_menu_flow(MenuFlow flow);

NodeID menu_nav_get_active_node_id(void)
{
    return active_node_id;
}

NodeID menu_nav_get_cursor_node_id(void)
{
    return cursor_node_id;
}

void menu_nav_init(void)
{
    active_node_id = NODE_NONE;
    cursor_node_id = NODE_BASE;
}

const MenuNode* menu_nav_get_node(NodeID node_id)
{
    for (size_t i = 0; i < NODE_COUNT; i++)
    {
        const MenuNode* node_iter = &menu[i];
        if (node_iter->node_id == node_id)
        {
            return node_iter;
        }
    }

    return NULL;
}

static NodeID menu_first_child(NodeID node_id)
{
    const MenuNode* node = menu_nav_get_node(node_id);

    if (!node)
    {
        return NODE_NONE;
    }

    return node->first_child;
}

static NodeID menu_prev_sibling(NodeID node_id)
{
    const MenuNode* node = menu_nav_get_node(node_id);

    if (!node || node->parent == NODE_NONE)
    {
        return NODE_NONE;
    }

    NodeID last_node_id = NODE_NONE;

    for (size_t i = 0; i < NODE_COUNT; i++)
    {
        const MenuNode* node_iter = &menu[i];
        if (node_iter->parent != node->parent)
        {
            continue;
        }

        if (node_iter->node_id == node_id)
        {
            return last_node_id;
        }

        last_node_id = node_iter->node_id;
    }

    return NODE_NONE;
}

static void menu_reset_to_root(void)
{
    active_node_id = NODE_NONE;
    cursor_node_id = NODE_BASE;
}

void menu_select(void)
{
    const MenuNode* node = menu_nav_get_node(cursor_node_id);
    if (!node)
    {
        return;
    }

    if (menu_first_child(cursor_node_id) != NODE_NONE)
    {
        active_node_id = cursor_node_id;
        cursor_node_id = menu_first_child(active_node_id);
    }

    if (node->action_id)
    {
        ActionContext ctx = menu_actions_resolve(node->action_id);
        MenuFlow flow = menu_actions_dispatch(&ctx);
        apply_menu_flow(flow);
    }
}

static void menu_back(void)
{
    const MenuNode* node;

    node = menu_nav_get_node(active_node_id);
    if (!node || node->parent == NODE_NONE)
    {
        return;
    }
    cursor_node_id = active_node_id;
    active_node_id = node->parent;

    node = menu_nav_get_node(active_node_id);
    if (node->action_id)
    {
        ActionContext ctx = menu_actions_resolve(node->action_id);
        MenuFlow flow = menu_actions_dispatch(&ctx);
        apply_menu_flow(flow);
    }
}

static void menu_reset(void)
{
    menu_reset_to_root();
}

static void menu_next(void)
{
    const MenuNode* cursor_node = menu_nav_get_node(cursor_node_id);

    if (!cursor_node || cursor_node->next_sibling == NODE_NONE)
    {
        return;
    }

    cursor_node_id = cursor_node->next_sibling;
}

static void menu_prev(void)
{
    NodeID prev_node_id = menu_prev_sibling(cursor_node_id);

    if (prev_node_id == NODE_NONE)
    {
        return;
    }

    cursor_node_id = prev_node_id;
}

static void apply_menu_flow(MenuFlow flow)
{
    switch (flow)
    {
    case MENU_FLOW_SELECT:
        menu_select();
        break;

    case MENU_FLOW_BACK:
        menu_back();
        break;

    case MENU_FLOW_CANCEL:
        menu_reset();
        break;

    default:
        break;
    }
}

void menu_nav_step(UIKey key)
{
    switch (key)
    {
    case UI_KEY_SELECT:
        menu_select();
        break;

    case UI_KEY_BACK:
        menu_back();
        break;

    case UI_KEY_CANCEL:
        menu_reset();
        break;

    case UI_KEY_ROTA:
        menu_next();
        break;

    case UI_KEY_ROTB:
        menu_prev();
        break;

    default:
        break;
    }
}

