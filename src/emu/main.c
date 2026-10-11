#include <moses/moses.h>

int main() {
    moses_log("MOSES %s", MOSES_VER);

    // send off to client
    client_init();
    return 0;
}
