#include <moses/client.h>

int main(void) {
    moses_log("MOSES %s", MOSES_VER);
    init_video();

    bool running = true;

    while (running) {
        enum client_event event = poll_client_event();
        while (event != EVENT_NONE) {
            switch (event) {
            case EVENT_EXIT: {
                running = false;
                break;
            }
            default: break;
            }
            event = poll_client_event();
        }
    }

    exit_video();
    return 0;
}
