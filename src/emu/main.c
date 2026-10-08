#include <moses/client.h>

int main(void) {
    moses_log(GENERAL, INFO, "MOSES %s", MOSES_VER);
    init_video();
    while (1) {
        enum client_event event = poll_client_event();
        if (event == CLIENT_EXIT) {
            break;
        }
    }
    exit_video();
    return 0;
}

