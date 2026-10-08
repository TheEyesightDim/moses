#include <moses/client.h>
#include <SDL3/SDL_events.h>

enum client_event poll_client_event() {
    SDL_Event e;
    if (!SDL_PollEvent(&e)) {
        return EVENT_NONE;
    }

    if (e.type == SDL_EVENT_QUIT)
    {
        return EVENT_EXIT;
    }
    return EVENT_CLIENT;
}
