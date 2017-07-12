#include <iostream>
#include <SDL.h>
#include <cairo.h>
#include <string.h>
#include <pango/pangocairo.h>

SDL_Window *g_pWindow = 0;

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    g_pWindow = SDL_CreateWindow("hello",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 512, 512,
                                 SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);


    SDL_Surface *sdl_surface = SDL_GetWindowSurface(g_pWindow);


    cairo_surface_t *cairo_surface =
            cairo_image_surface_create_for_data(
                    (unsigned char *) sdl_surface->pixels,
                    CAIRO_FORMAT_RGB24,
                    sdl_surface->w,
                    sdl_surface->h,
                    sdl_surface->pitch
            );

    cairo_t *cr =
            cairo_create(cairo_surface);
    cairo_set_source_rgb(cr, 0.5, 0.9, 0.5);
    cairo_paint(cr);

//    cairo_surface_t *bitmap_surface = cairo_image_surface_create_from_png("basn3p08.png");
//    cairo_set_source_surface(cr, bitmap_surface, 0, 0);
//    cairo_paint(cr);
//
//    cairo_select_font_face(cr, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
//    cairo_set_font_size(cr, 30.0);
//    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
//    cairo_move_to(cr, 10.0, 50.0);
//    cairo_show_text(cr, "Hello there");
//
//    cairo_move_to(cr, 100, 100);
//    cairo_line_to(cr, 20, 10);
//    cairo_set_line_width(cr, 1);
//    cairo_stroke(cr);

    PangoLayout *layout;
    PangoFontDescription *font_description;

    font_description = pango_font_description_new();
    pango_font_description_set_family(font_description, "serif");
    pango_font_description_set_weight(font_description, PANGO_WEIGHT_BOLD);
    pango_font_description_set_absolute_size(font_description, 32 * PANGO_SCALE);

    layout = pango_cairo_create_layout(cr);
    pango_layout_set_font_description(layout, font_description);
    pango_layout_set_text(layout, "Hello, world", -1);

    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
    cairo_move_to(cr, 10.0, 50.0);
    pango_cairo_show_layout(cr, layout);

    SDL_UpdateWindowSurface(g_pWindow);

    SDL_Delay(50000);
    SDL_Quit();

    cairo_destroy(cr);
    cairo_surface_destroy(cairo_surface);
    return 0;
}