#include <gtk/gtk.h>

#include "whiteboard-app.h"
#include "whiteboard-window.h"

struct _WhiteboardApp
{
    GtkApplication parent;
};

G_DEFINE_TYPE(WhiteboardApp, whiteboard_app, GTK_TYPE_APPLICATION);

static void
whiteboard_app_init (WhiteboardApp *app)
{
}

static void
whiteboard_app_activate (GApplication *app)
{
    WhiteboardAppWindow *win;

    win = whiteboard_app_window_new (WHITEBOARD_APP (app));
    gtk_window_present (GTK_WINDOW (win));
}

static void
whiteboard_app_class_init (WhiteboardAppClass *class)
{
    G_APPLICATION_CLASS (class)->activate = whiteboard_app_activate;
}

WhiteboardApp *
whiteboard_app_new (void)
{
    return g_object_new (WHITEBOARD_APP_TYPE,
                        "application-id", "space.behaviour.whiteboard",
                        NULL);
}
