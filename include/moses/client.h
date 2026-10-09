/*
 * Definitions for client-specific functions. Their implementations are
 * not strictly cross-platform and include functionality like initializing
 * and displaying graphics, logging messages, events, and timing.
 */

#pragma once

// Client entrypoint
void client_init();

// Logging
void moses_log(const char* fmt, ...) __attribute__ ((format (printf, 1, 2)));