#include <moses/client.h>
#include <stdio.h>
#include <stdarg.h>

void moses_log(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}
