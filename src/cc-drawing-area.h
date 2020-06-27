/*
 * Copyright © 2016 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Carlos Garnacho <carlosg@gnome.org>
 */

#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define CC_TYPE_DRAWING_AREA (cc_drawing_area_get_type ())
G_DECLARE_FINAL_TYPE (CcDrawingArea, cc_drawing_area, CC, DRAWING_AREA, GtkEventBox)

GtkWidget *cc_drawing_area_new (void);

typedef struct _CcDrawingArea CcDrawingArea;

struct _CcDrawingArea {
    GtkEventBox parent;
    GdkDevice *current_device;
    cairo_surface_t *surface;
    cairo_t *cr;
    double touch_x_pos;
    double touch_y_pos;
};

G_END_DECLS

