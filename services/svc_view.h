#ifndef SVC_VIEW_H
#define SVC_VIEW_H

typedef enum
{
    DISPLAY_MODE_NULL,
    DISPLAY_MODE_BASE,
    DISPLAY_MODE_MENU,
    DISPLAY_MODE_BRT
} DisplayMode;

void svc_view_request_update(DisplayMode display_mode);
void svc_view_update_if_needed(void);

#endif

