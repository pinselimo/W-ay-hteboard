#include <png.h>
#include <cairo/cairo.h>
#include <gtk/gtk.h>
#include <stdio.h>

#include "cc-drawing-area.h"

typedef struct
{
    unsigned char * data;
    int height;
    int width;
    int bytes_per_pixel;
}
bitmap_t;

#define CLEAN_UP if (fp) fclose (fp);                             \
    if (png_ptr) png_destroy_write_struct ( &png_ptr, &info_ptr); \
    if (row_pointers) free (row_pointers);

#define FAIL(when)                                       \
    if (when)                                            \
    {                                                    \
        g_debug("Failed while preparing to create PNG"); \
        CLEAN_UP;                                        \
        return -1;                                       \
    }

int
png_to_file (const bitmap_t *bitmap, const char *path)
{
    FILE *fp;
    png_structp png_ptr;
    png_infop info_ptr;
    size_t y;
    png_byte **row_pointers;
    int depth = 8;

    fp = fopen (path, "wb");
    FAIL (!fp);
    png_ptr = png_create_write_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    FAIL (!png_ptr);
    info_ptr = png_create_info_struct (png_ptr);
    FAIL (!info_ptr);

    if (setjmp (png_jmpbuf (png_ptr)))
    {
        g_debug("Error: libpng failed.");
        CLEAN_UP;
        return -1;
    }

    png_set_IHDR (png_ptr,
                  info_ptr,
                  bitmap->width,
                  bitmap->height,
                  depth,
                  PNG_COLOR_TYPE_RGBA,
                  PNG_INTERLACE_NONE,
                  PNG_COMPRESSION_TYPE_DEFAULT,
                  PNG_FILTER_TYPE_DEFAULT);

    row_pointers = malloc (bitmap->height * sizeof (png_byte *));
    FAIL (!row_pointers);
    for (y = 0; y < bitmap->height; ++y)
    {
        row_pointers[y] = bitmap->data + bitmap->width * bitmap->bytes_per_pixel * y;
    }

    png_init_io (png_ptr, fp);
    png_set_rows (png_ptr, info_ptr, row_pointers);

    png_write_png (png_ptr, info_ptr, PNG_TRANSFORM_BGR, NULL);

    CLEAN_UP;
    return 0;
}

void
save_png (cairo_surface_t *surface, const char *fname)
{
    bitmap_t bitmap;
    int rv;

    bitmap.data = cairo_image_surface_get_data (surface);
    bitmap.bytes_per_pixel = 4;
    bitmap.width = cairo_image_surface_get_width (surface);
    bitmap.height = cairo_image_surface_get_height (surface);
    rv = png_to_file (&bitmap, fname);
    if (rv != 0)
    {
        g_debug("Failed to write PNG file");
    }
}
