#include <moses/moses.h>

int main() {
    moses_log(GENERAL, INFO, LOG_FG_GREEN("MOSES %s"), MOSES_VER);

    // send off to client
    client_init();
    return 0;
}
