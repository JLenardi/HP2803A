/**
 * @file svc_input.h
 * @brief
 */

#ifndef SVC_INPUT_H
#define SVC_INPUT_H

#include <stdint.h>
#include <hw_input.h>

typedef uint8_t UIKey;
enum UIKey_enum
{
    UI_KEY_SELECT  = HW_KEY_SELECT,
    UI_KEY_BACK    = HW_KEY_BACK,
    UI_KEY_CANCEL  = HW_KEY_CANCEL,
    UI_KEY_ROTA    = HW_KEY_ROTA,
    UI_KEY_ROTB    = HW_KEY_ROTB,
    UI_KEY_INVALID = HW_KEY_INVALID,
    UI_KEY_NULL    = HW_KEY_NULL
};

UIKey svc_input_poll_key(void);
int32_t ui_input_edit_number(int32_t start_value);

#endif

