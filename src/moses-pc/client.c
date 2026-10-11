#include <moses/moses.h>
#include <SDL3/SDL.h>
#include <stdint.h>

#include "video.h"

void client_init() {
    // initialize subsystems
    init_video();

    bool running = true;


    const uint64_t freq = SDL_GetPerformanceFrequency();
    uint64_t start = SDL_GetPerformanceCounter();


    while (running) {

        // determine how many master clock cycles have occurred
        const uint64_t now = SDL_GetPerformanceCounter();
        const uint64_t cycles = (now - start) * (MOSES_MASTER_CLOCK_FREQ) / freq;

        // move forward this many cycles on the emulator
        emu_clock_cycles((uint32_t) cycles);

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
    }
    // cleanup
    exit_video();
}

