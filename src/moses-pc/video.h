#pragma once

#include <SDL3/SDL.h>

typedef struct {
    SDL_Renderer* renderer;
    SDL_Window* window;

} SDLContext;


SDLContext* get_sdl_context();
void init_video();
void exit_video();

