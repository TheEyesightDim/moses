#include <moses/moses.h>
#include <stdio.h>
#include <stdarg.h>

void moses_log(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    printf("\033[31m[moses_log]\033[0m: ");
    vprintf(fmt, ap);
    putchar('\n');
    va_end(ap);
}
