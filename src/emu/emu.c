#include <moses/client.h>
#include <moses/emu.h>

void emu_clock_cycles(uint32_t cycles) {

}


int main() {
    moses_log("MOSES %s", MOSES_VER);

    // send off to client
    client_init();
    return 0;
}
