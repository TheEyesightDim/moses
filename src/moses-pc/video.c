#include <stdlib.h>
#include <moses/moses.h>
#include "video.h"
#include <SDL3/SDL.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;


void init_video() {
    moses_log("Initializing SDL...");
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("moses", 256, 240, 0);
    if (window == NULL)
    {
        moses_log("SDL_CreateWindow failed! %s", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL)
    {
        moses_log("SDL_CreateRenderer failed! %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
}

void exit_video() {
    moses_log("Cleaning up SDL...");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}