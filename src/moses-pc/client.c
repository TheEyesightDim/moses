#include <moses/moses.h>
#include <SDL3/SDL.h>
#include <stdint.h>

#include "video.h"

static float ty = -10;

static void render_sample(SDLContext* ctx) {
    SDL_SetRenderDrawColor(ctx->renderer, 255, 0, 0, 255);
    SDL_RenderDebugTextFormat(ctx->renderer, 20, ty++, "moses v%s", MOSES_VER);
    SDL_SetRenderDrawColor(ctx->renderer, 255, 255, 255, 255);

    if (ty > 265) {
        ty = -10;
    }
}

int main(int argc, char* argv[]) {

    // initialize subsystems
    init_video();

    SDLContext* ctx = get_sdl_context();

    bool running = true;

    uint64_t last = SDL_GetTicksNS();
    constexpr uint64_t ns_per_frame = 1000000000/60;

    while (running) {
        // poll for events
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_EVENT_QUIT: {
                running = false;
            }
            default: break;
            }
        }

        // emulate one frame
        nes_emulate_next_frame();

        // render
        SDL_RenderClear(ctx->renderer);
        render_sample(ctx);
        SDL_RenderPresent(ctx->renderer);

        // delay till next frame
        const uint64_t now = SDL_GetTicksNS();
        const uint64_t render_time = now - last;

        if (render_time > ns_per_frame) {
            moses_log(CAT_CLIENT, LEVEL_WARN, "rendering going slow! took %llu ns", render_time);
        } else {
            const uint64_t delay_time = ns_per_frame - render_time;
            SDL_DelayNS(delay_time);
        }
        last = SDL_GetTicksNS();
    }
    // cleanup
    exit_video();
    return 0;
}

