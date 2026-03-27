/**
 * @file cor_menu_types.h
 * @brief Defines types and data structures for the hierarchical menu system.
 */
#ifndef COR_MENU_TYPES_H
#define COR_MENU_TYPES_H

#include <stdint.h>
#include "cor_menu_types.h"

typedef uint8_t NodeID;
enum NodeID_enum
{
    NODE_NONE = 0xff,
    NODE_BASE = 0,
    NODE_DISPLAY1,
    NODE_DISPLAY2,
    NODE_UNITS,
    NODE_RESOLUTION,
    NODE_BRIGHTNESS,
    NODE_SOCKETS,
    NODE_PROBE_A,
    NODE_PROBE_B,
    NODE_TRANSMIT,
    NODE_SETTINGS,
    NODE_CALIBRATE,
    NODE_PROBE_DB,
    NODE_DISP1_T1,
    NODE_DISP1_T2,
    NODE_DISP1_T1MINUST2,
    NODE_DISP1_T2MINUST1,
    NODE_DISP1_DELTAT1,
    NODE_DISP1_DELTAT2,
    NODE_DISP1_MINT1,
    NODE_DISP1_MINT2,
    NODE_DISP1_MAXT1,
    NODE_DISP1_MAXT2,
    NODE_DISP1_COUNT1,
    NODE_DISP1_COUNT2,
    NODE_DISP2_T1,
    NODE_DISP2_T2,
    NODE_DISP2_T1MINUST2,
    NODE_DISP2_T2MINUST1,
    NODE_DISP2_DELTAT1,
    NODE_DISP2_DELTAT2,
    NODE_DISP2_MINT1,
    NODE_DISP2_MINT2,
    NODE_DISP2_MAXT1,
    NODE_DISP2_MAXT2,
    NODE_DISP2_COUNT1,
    NODE_DISP2_COUNT2,
    NODE_CELSIUS,
    NODE_FAHRENHEIT,
    NODE_KELVIN,
    NODE_SCALE4,
    NODE_SCALE3,
    NODE_SCALE2,
    NODE_BRT_MAIN,
    NODE_BRT_OTHER,
    NODE_BRT_MAIN_VALUE,
    NODE_BRT_OTHER_VALUE,
    NODE_FRONT,
    NODE_BACK,
    NODE_PROBE_A_IDX0,
    NODE_PROBE_A_IDX1,
    NODE_PROBE_A_IDX2,
    NODE_PROBE_B_IDX0,
    NODE_PROBE_B_IDX1,
    NODE_PROBE_B_IDX2,
    NODE_TRANSMIT_ON,
    NODE_TRANSMIT_OFF,
    NODE_SAVE,
    NODE_DISCARD,
    NODE_DEFAULT,
    NODE_PROBE_EDIT,
    NODE_PROBE_SAVE,
    NODE_PROBE_DISCARD,
    NODE_PROBE_DEFAULT,
    NODE_PROBE_CORE,
    NODE_PROBE_CORE_IDX,
    NODE_PROBE_CORE_PARAM,
    NODE_PROBE_CORE_VALUE,
    NODE_PROBE_CF,
    NODE_PROBE_CF_IDX,
    NODE_PROBE_CF_PARAM,
    NODE_PROBE_CF_VALUE,
    NODE_COUNT
};

typedef uint8_t TextID;
enum TextID_enum
{
    TEXT_BLANK = 0,
    TEXT_DISPLAY1,
    TEXT_DISPLAY2,
    TEXT_UNITS,
    TEXT_RESOLUTION,
    TEXT_BRIGHTNESS,
    TEXT_SOCKETS,
    TEXT_PROBE_A,
    TEXT_PROBE_B,
    TEXT_TRANSMIT,
    TEXT_SETTINGS,
    TEXT_CALIBRATE,
    TEXT_PROBE_DB,
    TEXT_T1,
    TEXT_T2,
    TEXT_T1MINUST2,
    TEXT_T2MINUST1,
    TEXT_DELTAT1,
    TEXT_DELTAT2,
    TEXT_MINT1,
    TEXT_MINT2,
    TEXT_MAXT1,
    TEXT_MAXT2,
    TEXT_COUNT1,
    TEXT_COUNT2,
    TEXT_CELSIUS,
    TEXT_FAHRENHEIT,
    TEXT_KELVIN,
    TEXT_LOW,
    TEXT_MEDIUM,
    TEXT_HIGH,
    TEXT_BRT_MAIN,
    TEXT_BRT_OTHER,
    TEXT_FRONT,
    TEXT_BACK,
    TEXT_IDX0,
    TEXT_IDX1,
    TEXT_IDX2,
    TEXT_ON,
    TEXT_OFF,
    TEXT_SAVE,
    TEXT_DISCARD,
    TEXT_DEFAULT,
    TEXT_EDIT,
    TEXT_CORE,
    TEXT_CF,
    TEXT_COUNT
};

typedef uint8_t ActionID;
enum ActionID_enum
{
    CTX_NONE,
    CTX_BRIGHTNESS,
    CTX_DISP1_T1,
    CTX_DISP1_T2,
    CTX_DISP1_T1MINUST2,
    CTX_DISP1_T2MINUST1,
    CTX_DISP1_DELTAT1,
    CTX_DISP1_DELTAT2,
    CTX_DISP1_MINT1,
    CTX_DISP1_MINT2,
    CTX_DISP1_MAXT1,
    CTX_DISP1_MAXT2,
    CTX_DISP1_COUNT1,
    CTX_DISP1_COUNT2,
    CTX_DISP2_T1,
    CTX_DISP2_T2,
    CTX_DISP2_T1MINUST2,
    CTX_DISP2_T2MINUST1,
    CTX_DISP2_DELTAT1,
    CTX_DISP2_DELTAT2,
    CTX_DISP2_MINT1,
    CTX_DISP2_MINT2,
    CTX_DISP2_MAXT1,
    CTX_DISP2_MAXT2,
    CTX_DISP2_COUNT1,
    CTX_DISP2_COUNT2,
    CTX_CELSIUS,
    CTX_FAHRENHEIT,
    CTX_KELVIN,
    CTX_SCALE2,
    CTX_SCALE3,
    CTX_SCALE4,
    CTX_BRT_MAIN_VALUE,
    CTX_BRT_OTHER_VALUE,
    CTX_FRONT,
    CTX_BACK,
    CTX_PROBE_A_IDX0,
    CTX_PROBE_A_IDX1,
    CTX_PROBE_A_IDX2,
    CTX_PROBE_B_IDX0,
    CTX_PROBE_B_IDX1,
    CTX_PROBE_B_IDX2,
    CTX_TRANSMIT_ON,
    CTX_TRANSMIT_OFF,
    CTX_SETTINGS_SAVE,
    CTX_SETTINGS_DISCARD,
    CTX_SETTINGS_DEFAULT,
    CTX_PROBE_SAVE,
    CTX_PROBE_DISCARD,
    CTX_PROBE_DEFAULT,
    CTX_PROBE_CORE_IDX,
    CTX_PROBE_CORE_PARAM,
    CTX_PROBE_CORE_VALUE,
    CTX_PROBE_CF_IDX,
    CTX_PROBE_CF_PARAM,
    CTX_PROBE_CF_VALUE
};

/**
 * @struct MenuNode
 * @brief Represents a single node in the menu tree.
 *
 * Each node contains:
 *   - node_id:      Unique identifier for the node.
 *   - text_id:      Identifier for the display text of the node.
 *   - parent:       NodeID of the parent node; NODE_NONE if root.
 *   - first_child:  NodeID of the first child node; NODE_NONE if no children.
 *   - next_sibling: NodeID of the next sibling node; NODE_NONE if none.
 *   - action_id:    Action triggered when this node is selected; CTX_NONE if none.
 */
typedef struct MenuNode
{
    NodeID   node_id;
    TextID   text_id;
    NodeID   parent;
    NodeID   first_child;
    NodeID   next_sibling;
    ActionID action_id;
} MenuNode;

#endif

