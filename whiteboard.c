#include <gtk/gtk.h>

#include "cc-drawing-area.h"

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *drawing_area;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Whiteboard");
    gtk_window_set_default_size (GTK_WINDOW (window), 1000, 1000);

    drawing_area = cc_drawing_area_new ();
    gtk_container_add (GTK_CONTAINER (window), drawing_area);

    gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("space.behaviour.whiteboard", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
