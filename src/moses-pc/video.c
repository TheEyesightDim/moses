#include <stdlib.h>
#include <moses/moses.h>
#include "video.h"
#include <SDL3/SDL.h>

static SDLContext ctx = {0};

SDLContext* get_sdl_context() {
    return &ctx;
}

void init_video() {
    moses_log(CAT_CLIENT, LEVEL_INFO, "Initializing SDL...");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("moses", 256, 240, 0);
    if (window == NULL)
    {
        moses_log(CAT_CLIENT, LEVEL_CRITICAL, "SDL_CreateWindow failed! %s", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL)
    {
        moses_log(CAT_CLIENT, LEVEL_CRITICAL, "SDL_CreateRenderer failed! %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
    ctx.window = window;
    ctx.renderer = renderer;
}

void exit_video() {
    moses_log(CAT_CLIENT, LEVEL_INFO, "Cleaning up SDL...");
    SDL_DestroyRenderer(ctx.renderer);
    SDL_DestroyWindow(ctx.window);
    SDL_Quit();
}
