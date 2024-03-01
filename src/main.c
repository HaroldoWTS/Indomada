#include "stdio.h"
#include "cairo.h"

int main(){
	cairo_surface_t *surface;
	cairo_t *cr;

	surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 120, 120);
	cr = cairo_create (surface);
	printf("E assim come");
	return 0;
}
