#include <moses/moses.h>
#include <stdio.h>
#include <stdarg.h>

// VT100 Terminal colors
#define LOG_FG_YELLOW(str) ("\033[33m"str"\033[0m")
#define LOG_FG_RED(str) ("\033[31m"str"\033[0m")
#define LOG_FG_GREEN(str) ("\033[32m"str"\033[0m")
#define LOG_FG_CYAN(str) ("\033[36m"str"\033[0m")
#define LOG_FG_MAGENTA(str) ("\033[35m"str"\033[0m")

static char const * level_strs[] = {
    LOG_FG_CYAN("TRACE"),
    "VERBOSE",
    "INFO",
    LOG_FG_YELLOW("WARN"),
    LOG_FG_RED("ERROR"),
    LOG_FG_RED("CRITICAL"),
};

static char const * category_strs[] = {
    "CPU",
    "APU",
    "PPU",
    "CLIENT",
    "FILESYSTEM",
    "GENERAL",
};

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
        case TRACE: loglevel_name = "TRACE"; break;
        case VERBOSE: loglevel_name = "VERBOSE"; break;
        case INFO: loglevel_name = "INFO"; break;
        case WARN: loglevel_name = "WARN"; break;
        case ERROR: loglevel_name = "ERROR"; break;
        case CRITICAL: loglevel_name = "CRITICAL"; break;
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
