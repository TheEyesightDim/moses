#pragma once
#ifndef CLIENT_H
#define CLIENT_H

/* Logging */
void moses_log(const char* fmt, ...) __attribute__ ((format (printf, 1, 2)));;

void init_video();
void exit_video();

enum client_event
{
    CLIENT_NONE,
    CLIENT_EXIT
};

enum client_event get_client_event();

#endif