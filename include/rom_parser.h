#pragma once

/*
Interface for parsing an iNES or NES 2.0 format rom into a data structure.
*/

#include <stddef.h>
#include <stdint.h>

enum RDTimingMode {
	RD_TIMING_NTSC,
	RD_TIMING_PAL,
	RD_TIMING_MULTIREGION,
	RD_TIMING_DENDY	
};

enum RDConsoleType {
	RD_CONSOLE_NES,
	RD_CONSOLE_VSSYSTEM,
	RD_CONSOLE_PLAYCHOICE,
	RD_CONSOLE_EXTENDED
};

typedef struct RomDescriptor {
	/*	Not all features enumerated in the iNES/NES 2.0 header are expected to be
		supported, and some may be deliberately unsupported.
	*/

	uint16_t mapper_id;
	uint8_t submapper_id;

	enum RDTimingMode timing_mode;
	enum RDConsoleType console_type;

	int prg_rom_size;
	int chr_rom_size;
	int prg_ram_size;
	int eeprom_size;
	int chr_ram_size;
	int chr_nvram_size;
} RomDescriptor;

// Initialize a RomDescriptor from a buffer holding raw NES rom data.
// Returns 0 on success, non-zero on error.
int rom_descriptor_from_buffer(RomDescriptor * romdesc, void const * buffer);


