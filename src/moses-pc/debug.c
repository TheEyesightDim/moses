#include <moses/client.h>
#include <SDL3/SDL_log.h>

void moses_log(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf("\033[31m[moses_log]\033[0m: ");
    vprintf(fmt, ap);
    putchar('\n');
    va_end(ap);
}
