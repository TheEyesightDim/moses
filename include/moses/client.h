/*
 * Definitions for client-specific functions. Their implementations are
 * not strictly cross-platform and include functionality like initializing
 * and displaying graphics, logging messages, events, and timing.
 */

#pragma once

/* Logging */

// Log levels and categories can be adjusted as necessary
enum MosesLogLevel {
	TRACE,
	VERBOSE,
	INFO,
	WARN,
	ERROR,
	CRITICAL,
};

// Categories can be combined via bitwise OR for filtering
enum MosesLogCategory {
	CPU 		= 1,
	APU 		= 1 << 1,
	PPU 		= 1 << 2,
	CLIENT		= 1 << 3,
	FILESYSTEM	= 1 << 4,
	GENERAL		= 1 << 5,
};

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
               const char* fmt, ...)
__attribute__ ((format (printf, 3, 4)));

// Set a log level threshhold, below which log messages are ignored.
void moses_set_log_threshold(enum MosesLogLevel level);

// Set and unset log categories to filter.
void moses_set_log_categories(int categories);
void moses_unset_log_categories(int categories);

/* Video */
void init_video();
void exit_video();

/* Events */
enum client_event
{
    CLIENT_NONE,
    CLIENT_EXIT
};
enum client_event poll_client_event();

