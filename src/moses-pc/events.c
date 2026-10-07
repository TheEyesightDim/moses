#include <moses/client.h>
#include <SDL3/SDL_events.h>

enum client_event get_client_event() {
    SDL_Event e;
    SDL_PollEvent(&e);

    if (e.type == SDL_EVENT_QUIT)
    {
        return CLIENT_EXIT;
    }
    return CLIENT_NONE;
}
