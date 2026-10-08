#include <moses/client.h>
#include <SDL3/SDL_log.h>
#include <stdio.h>

static enum MosesLogLevel threshold = INFO;
static int log_categories = -1; // log all categories by default

static char * const level_strs[] = {
    "TRACE",
    "VERBOSE",
    "INFO",
    "WARN",
    "ERROR",
    "CRITICAL"
};

static char * const category_strs[] = {
    "CPU",
    "APU",
    "PPU",
    "CLIENT",
    "FILESYSTEM",
    "GENERAL",
};

void moses_log(enum MosesLogCategory category,
               enum MosesLogLevel level,
               const char *fmt, ...) {
    if (!(level >= threshold && log_categories & category))
        return;
    
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
    // SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, fmt, ap);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    fprintf(stderr, "\n");
}

void moses_set_log_threshold(enum MosesLogLevel level) {
    threshold = level;
}

void moses_set_log_categories(int categories) {
    log_categories |= categories;
}

void moses_unset_log_categories(int categories) {
    // clear all the bits that are set in categories, but leave the rest
    log_categories &= ~categories;
}

