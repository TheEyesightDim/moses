#pragma once

/*
This provides the interface for controlling the entire emulated NES system as a whole.
*/

#include <stdint.h>
#include <sys/types.h>

#include "cpu.h"
#include "apu.h"
#include "ppu.h"
#include "mapper.h"

#define NES_RAMSIZE	2048

// Reference: https://www.nesdev.org/wiki/Cycle_reference_chart
#define MASTER_CLOCK_HZ_NTSC	(236250000 / 11)
#define MASTER_CLOCK_HZ_PAL		26601712
#define CPU_HZ_NTSC		(MASTER_CLOCK_HZ_NTSC / 12)
#define CPU_HZ_PAL		(MASTER_CLOCK_HZ_NTSC / 16)

typedef struct NES {
	CPU cpu;
	Mapper mapper;
	PPU ppu;
	APU apu;
	char * wram;
	uint64_t tick_count_master;
} NES;

NES * nes_create_system();

void nes_emulate_next_frame();

void nes_emulate_master_ticks(uint64_t n_ticks);

void nes_emulate_cpu_ticks(uint64_t n_ticks);
