#ifndef __WHITEBOARDAPP_H
#define __WHITEBOARDAPP_H

#include <gtk/gtk.h>

#define WHITEBOARD_APP_TYPE (whiteboard_app_get_type ())
G_DECLARE_FINAL_TYPE (WhiteboardApp, whiteboard_app, WHITEBOARD, APP, GtkApplication)

WhiteboardApp *whiteboard_app_new (void);


#endif /* __WHITEBOARDAPP_H */
