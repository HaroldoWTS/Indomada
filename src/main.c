#include "stdio.h"
#include "cairo.h"

int main(){
	cairo_surface_t *surface;
	cairo_t *cr;
	cairo_surface_t * bg;
	int              w, h;
	double scale;
	 cairo_matrix_t matrix;
	surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 1280, 720);
	cr = cairo_create (surface);
	bg = cairo_image_surface_create_from_png ("test/sacking.png");
	w = cairo_image_surface_get_width (bg);
	h = cairo_image_surface_get_height (bg);
	cairo_get_matrix(cr, &matrix);
	cairo_scale (cr, 1280.0/w, 720.0/h);
	cairo_set_source_surface (cr, bg, 0, 0);
	cairo_paint(cr);
	cairo_set_matrix(cr, &matrix);


	bg = cairo_image_surface_create_from_png ("test/gentleman.png");
	w = cairo_image_surface_get_width (bg);
	h = cairo_image_surface_get_height (bg);
	scale = 720.0/w;
	cairo_get_matrix(cr, &matrix);
	cairo_scale (cr, scale, scale);
	cairo_set_source_surface (cr, bg, ((1280.0/scale)-w)/2.0, 0);
	cairo_paint(cr);
	cairo_set_matrix(cr, &matrix);


	cairo_set_line_width (cr, 1);
	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_rectangle (cr, 0, 618, 1280, 100);
	cairo_stroke (cr);
	cairo_surface_write_to_png (surface, "out/first.png");
        cairo_destroy (cr);
        cairo_surface_destroy (surface);
	return 0;
}
