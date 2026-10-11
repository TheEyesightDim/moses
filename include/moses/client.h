/* Definitions for client-specific functions. */

#pragma once

// Client entrypoint
void client_init();


/* Logging */

// Log levels and categories can be adjusted as necessary
enum MosesLogLevel {
	LEVEL_TRACE,
	LEVEL_VERBOSE,
	LEVEL_INFO,
	LEVEL_WARN,
	LEVEL_ERROR,
	LEVEL_CRITICAL,
};

// Categories can be combined via bitwise OR for filtering
enum MosesLogCategory {
	CAT_CPU 		= 1,
	CAT_APU 		= 1 << 1,
	CAT_PPU 		= 1 << 2,
	CAT_CLIENT		= 1 << 3,
	CAT_FILESYSTEM	= 1 << 4,
	CAT_GENERAL		= 1 << 5,
};

// VT100 Terminal colors
#define LOG_FG_YELLOW(str) ("\033[33m"str"\033[0m")
#define LOG_FG_RED(str) ("\033[31m"str"\033[0m")
#define LOG_FG_GREEN(str) ("\033[32m"str"\033[0m")
#define LOG_FG_CYAN(str) ("\033[36m"str"\033[0m")
#define LOG_FG_MAGENTA(str) ("\033[35m"str"\033[0m")

/*
 * Write to the log with the given priority level and sorted into the given
 * category.
 * 
 * The attribute tells GCC to check the 3rd argument as the same as the format
 * string of `printf` and the 4th and onward arguments as the interpolated
 * arguments.
 */ 
void moses_log(enum MosesLogCategory category,
               enum MosesLogLevel level,
               char const * fmt, ...)
__attribute__ ((format (printf, 3, 4)));
