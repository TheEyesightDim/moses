#include <moses/moses.h>
#include <stdio.h>
#include <stdarg.h>


void moses_log(enum MosesLogCategory category,
               enum MosesLogLevel level,
               char const * fmt, ...) {
    /*
    TODO: There needs to be a client settings struct to refer to, and get the
    log level threshold and category filters from there to compare to,
    then exit early if the parameters don't match 
    */ 
    
    char const * loglevel_name = NULL;
    char const * category_name = NULL;

    switch (level) {
        case TRACE: loglevel_name = LOG_FG_CYAN("TRACE"); break;
        case VERBOSE: loglevel_name = "VERBOSE"; break;
        case INFO: loglevel_name = LOG_FG_GREEN("INFO"); break;
        case WARN: loglevel_name = LOG_FG_YELLOW("WARN"); break;
        case ERROR: loglevel_name = LOG_FG_RED("ERROR"); break;
        case CRITICAL: loglevel_name = LOG_FG_RED("CRITICAL"); break;
        default: loglevel_name = "UNKNOWN";
    }
    switch (category) {
        case CPU: category_name = "CPU"; break;
        case APU: category_name = "APU"; break;
        case PPU: category_name = "PPU"; break;
        case CLIENT: category_name = "Client"; break;
        case FILESYSTEM: category_name = "Filesystem"; break;
        default: category_name = "General"; break;
    }

    // I use the vfprintf/fprintf functions instead of SDL_Log... functions,
    // because I can more easily format everything on a single line,
    // and on PC targets it just uses stderr anyways
    fprintf(stderr, "[%s][%s]  ", loglevel_name, category_name);

    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    fprintf(stderr, "\n");
}
