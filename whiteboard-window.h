#ifndef __WHITEBOARDAPPWIN_H
#define __WHITEBOARDAPPWIN_H

#include <gtk/gtk.h>
#include "whiteboard-app.h"


#define WHITEBOARD_APP_WINDOW_TYPE (whiteboard_app_window_get_type ())
G_DECLARE_FINAL_TYPE (WhiteboardAppWindow, whiteboard_app_window, WHITEBOARD, APP_WINDOW, GtkApplicationWindow)


WhiteboardAppWindow *whiteboard_app_window_new (WhiteboardApp *app);
void whiteboard_app_window_open (WhiteboardAppWindow *win);


#endif /* __WHITEBOARDAPPWIN_H */

