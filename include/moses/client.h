/*
 * Definitions for client-specific functions. Their implementations are
 * not strictly cross-platform and include functionality like initializing
 * and displaying graphics, logging messages, events, and timing.
 */

#pragma once
#ifndef CLIENT_H
#define CLIENT_H

/* Logging */
void moses_log(const char* fmt, ...) __attribute__ ((format (printf, 1, 2)));

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

#endif