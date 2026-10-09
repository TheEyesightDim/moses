/*
 *
 */

#pragma once

#include <stdint.h>

#define MOSES_MASTER_CLOCK_FREQ 21477272

/* Execute the specified number of cycles across the
 * emulated system. These cycles should be in terms
 * of the 21.477272 MHz master clock.
 */
void emu_clock_cycles(uint32_t cycles);
