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
    EVENT_NONE,     // no events are available from the client, polling should stop
    EVENT_EXIT,     // the client requested to exit
    EVENT_CLIENT    // unspecified client event occurred and polling should continue
};
enum client_event poll_client_event();


#endif