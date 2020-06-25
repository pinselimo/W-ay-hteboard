#include <gtk/gtk.h>

#include "whiteboard-app.h"

int
main (int    argc,
      char **argv)
{
    return g_application_run (G_APPLICATION (whiteboard_app_new ()), argc, argv);
}
