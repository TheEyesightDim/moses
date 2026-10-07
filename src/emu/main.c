#include <moses/client.h>

int main(void) {
    moses_log("MOSES 0.0.0.0\n");
    init_video();
    while (1) {
        enum client_event event = get_client_event();
        if (event == CLIENT_EXIT) {
            break;
        }
    }
    exit_video();
    return 0;
}