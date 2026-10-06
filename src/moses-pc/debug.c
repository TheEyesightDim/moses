#include <stdio.h>
#include <moses/client.h>
#include <SDL3/SDL_main.h>

#include "SDL3/SDL_log.h"

void moses_log(const char* str)
{
    SDL_Log("%s", str);
}
