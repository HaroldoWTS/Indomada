#include "stdio.h"
#include "cairo.h"

int main(){
	cairo_surface_t *surface;
	cairo_t *cr;

	surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 1280, 720);
	cr = cairo_create (surface);
	cairo_set_line_width (cr, 1);
	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_rectangle (cr, 30, 30, 100, 100);
	cairo_stroke (cr);
	cairo_surface_write_to_png (surface, "../out/first.png");
        cairo_destroy (cr);
        cairo_surface_destroy (surface);
	return 0;
}
