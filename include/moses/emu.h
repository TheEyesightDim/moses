/* Core emulator functions and defines. */

#pragma once

#include <stdint.h>

#define MOSES_MASTER_CLOCK_FREQ 21477272

/* Execute the specified number of cycles across the
 * emulated system. These cycles should be in terms
 * of the 21.477272 MHz master clock.
 */
void emu_clock_cycles(uint32_t cycles);

#define FLAG_N (1 << 7)
#define FLAG_V (1 << 6)
#define FLAG_B (1 << 4)
#define FLAG_D (1 << 3)
#define FLAG_I (1 << 2)
#define FLAG_Z (1 << 1)
#define FLAG_C (1)

struct cpu {
    uint16_t pc;
    uint8_t s;
    uint8_t p;
    uint8_t a;
    uint8_t x;
    uint8_t y;
};

/* Execute the specified number of CPU cycles.
 * This should be in terms of the CPU clock,
 * which is the master clock divided by 12.
 */
void ex_cpu_cycles(uint32_t cpu_cycles);

/* Retrieve the byte at the specified address
 * in the memory map.
 */
uint8_t read_addr(uint16_t addr);

/* Write the specified byte to the specified
 * address in the memory map.
 */
void write_addr(uint16_t addr, uint8_t data);
