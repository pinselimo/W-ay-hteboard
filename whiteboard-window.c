#include <gtk/gtk.h>

#include "whiteboard-window.h"
#include "cc-drawing-area.h"

typedef struct _WhiteboardAppWindow WhiteboardAppWindow;

struct _WhiteboardAppWindow
{
    GtkApplicationWindow parent;
};

typedef struct _WhiteboardAppWindowPrivate WhiteboardAppWindowPrivate;

struct _WhiteboardAppWindowPrivate
{
    GtkWidget *drawbox;
};

G_DEFINE_TYPE_WITH_PRIVATE(WhiteboardAppWindow, whiteboard_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void
whiteboard_app_window_init (WhiteboardAppWindow *win)
{
    gtk_widget_init_template (GTK_WIDGET (win));
    WhiteboardAppWindowPrivate *priv;
    GtkWidget *drawing_area;

    // gchar *name = "TEST";
    priv = whiteboard_app_window_get_instance_private (win);
    drawing_area = cc_drawing_area_new ();
    gtk_box_pack_start ((GtkBox*)priv->drawbox, drawing_area, TRUE, TRUE, 0);

    // gtk_stack_add_titled( GTK_STACK (priv->stack), drawing_area, name, name);

}

static void
whiteboard_app_window_class_init (WhiteboardAppWindowClass *class)
{
    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                                 "/space/behaviour/whiteboard/window.ui");
    gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), WhiteboardAppWindow, drawbox);
}

WhiteboardAppWindow *
whiteboard_app_window_new (WhiteboardApp *app)
{
    return g_object_new (WHITEBOARD_APP_WINDOW_TYPE, "application", app, NULL);
}

void
whiteboard_app_window_open (WhiteboardAppWindow *win)
{
}
