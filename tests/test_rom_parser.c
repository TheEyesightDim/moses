#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "rom_parser.h"

/*	The data from a NES 2.0 ROM header should be correctly parsed and loaded into the RomDescriptor struct. As feature support improves, more fields should be correctly parsed and tested, but this covers the basic information (mapper type, console timing, description of memory banks).
*/

uint8_t const rom_bytes[] = {
	/* 	Either define the bytes inline (painful),
		or generate them programmatically into a rom,
		then use:
		`#embed "../res/test_roms/file"` inside a const array.
	*/
};

static bool compare_rom_descriptors(RomDescriptor const * first,
                                    RomDescriptor const * second);

static void test_parsing_nes2_header_basic() {

	// The values are chosen here arbitrarily and not meant to correspond to the header of any real cartridge.
	RomDescriptor expected = {
		.mapper_id = 7,
		.submapper_id = 7,

		.timing_mode = RD_TIMING_NTSC,
		.console_type = RD_CONSOLE_NES,
		.prg_rom_size = 16384,
		.chr_rom_size = 8192,
		.prg_ram_size = 8192,
		.eeprom_size = 8192,
		.chr_ram_size = 0,
		.chr_nvram_size = 0,
	};

	RomDescriptor test_descriptor;
	int result = rom_descriptor_from_buffer(&test_descriptor, rom_bytes);

	assert(result == 0);
	assert(compare_rom_descriptors(&test_descriptor, &expected));
}

int main() {
	test_parsing_nes2_header_basic();
	return 0;
}

static bool compare_rom_descriptors(RomDescriptor const * first,
                                    RomDescriptor const * second) {
	return
	first-> mapper_id == second->mapper_id
	&& first->submapper_id == second->submapper_id
	&& first->timing_mode == second->timing_mode
	&& first->console_type == second->console_type
	&& first->prg_rom_size == second->prg_rom_size
	&& first->chr_rom_size == second->chr_rom_size
	&& first->prg_ram_size == second->prg_ram_size
	&& first->eeprom_size == second->eeprom_size
	&& first->chr_ram_size == second->chr_ram_size
	&& first->chr_nvram_size == second->chr_nvram_size;
}
