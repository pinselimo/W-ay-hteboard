#include <gtk/gtk.h>
#include <cairo/cairo.h>

#include "cc-drawing-area.h"

static void
on_save ( GtkWidget *widget,
          CcDrawingArea *area)
{
    const char * fname = "test.png";
    cairo_surface_write_to_png(area->surface, fname);
}

static void
close_window (void)
{
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *drawing_area;
    GtkWidget *bt_save;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Whiteboard");
    gtk_window_set_default_size (GTK_WINDOW (window), 1000, 1000);
    gtk_container_set_border_width (GTK_CONTAINER (window), 2);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,2);
    gtk_container_add (GTK_CONTAINER (window), vbox);


    drawing_area = cc_drawing_area_new ();
    gtk_box_pack_start ((GtkBox*)vbox, drawing_area, TRUE, TRUE, 0);

    bt_save = gtk_button_new_with_label("Save");
    g_signal_connect (bt_save, "clicked", G_CALLBACK (on_save), (CcDrawingArea*) drawing_area );
    gtk_box_pack_end((GtkBox*)vbox, bt_save, TRUE, TRUE, 1);

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
