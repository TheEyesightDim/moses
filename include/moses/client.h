/* Definitions for client-specific functions. */

#pragma once

// Client entrypoint
void client_init();

// Logging
void moses_log(const char* fmt, ...) __attribute__ ((format (printf, 1, 2)));