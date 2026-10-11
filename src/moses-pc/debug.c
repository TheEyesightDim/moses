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
        case LEVEL_TRACE: loglevel_name = LOG_FG_CYAN("TRACE"); break;
        case LEVEL_VERBOSE: loglevel_name = "VERBOSE"; break;
        case LEVEL_INFO: loglevel_name = LOG_FG_GREEN("INFO"); break;
        case LEVEL_WARN: loglevel_name = LOG_FG_YELLOW("WARN"); break;
        case LEVEL_ERROR: loglevel_name = LOG_FG_RED("ERROR"); break;
        case LEVEL_CRITICAL: loglevel_name = LOG_FG_RED("CRITICAL"); break;
        default: loglevel_name = "UNKNOWN";
    }
    switch (category) {
        case CAT_CPU: category_name = "CPU"; break;
        case CAT_APU: category_name = "APU"; break;
        case CAT_PPU: category_name = "PPU"; break;
        case CAT_CLIENT: category_name = "Client"; break;
        case CAT_FILESYSTEM: category_name = "Filesystem"; break;
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
