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
    GtkWidget *drawingarea;
    GtkWidget *btnsave;
    GtkWidget *fname;
};

G_DEFINE_TYPE_WITH_PRIVATE(WhiteboardAppWindow, whiteboard_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void
on_save ( GtkWidget *widget,
          WhiteboardAppWindowPrivate * priv)
{
    CcDrawingArea *area = (CcDrawingArea*) priv->drawingarea;
    cairo_surface_write_to_png( area->surface,
                                gtk_entry_get_text (GTK_ENTRY (priv->fname)));
}

static void
whiteboard_app_window_init (WhiteboardAppWindow *win)
{
    CC_TYPE_DRAWING_AREA;
    gtk_widget_init_template (GTK_WIDGET (win));
    WhiteboardAppWindowPrivate *priv;

    priv = whiteboard_app_window_get_instance_private (win);
    g_signal_connect (GTK_BUTTON (priv->btnsave), "clicked", G_CALLBACK (on_save), priv );

    // gtk_stack_add_titled( GTK_STACK (priv->stack), drawing_area, name, name);

}

static void
whiteboard_app_window_class_init (WhiteboardAppWindowClass *class)
{
    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                                 "/space/behaviour/whiteboard/window.ui");
    gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), WhiteboardAppWindow, drawingarea);
    gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), WhiteboardAppWindow, btnsave);
    gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), WhiteboardAppWindow, fname);
}

WhiteboardAppWindow *
whiteboard_app_window_new (WhiteboardApp *app)
{
    return g_object_new (WHITEBOARD_APP_WINDOW_TYPE, "application", app, NULL);
}
