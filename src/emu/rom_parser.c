#include "moses/rom_parser.h"
#include <string.h>
#include <stdint.h>

#define PRG_ROM_BANK_SIZE 16384
#define PRG_RAM_BANK_SIZE 8192
#define CHR_ROM_BANK_SIZE 8192

static int parse_nes2_header(RomDescriptor * romdesc, const uint8_t header[16]);
static int parse_ines_header(RomDescriptor * romdesc, const uint8_t header[16]);

int make_rom_descriptor(RomDescriptor * romdesc, void const * buffer) {
	uint8_t const * header = buffer;

	// Magic string for iNes and NES 2.0 headers
	if (!(header[0]=='N' && header[1]=='E' && header[2]=='S' && header[3]==0x1a))
		return 1;

	if ((header[7] & 0xC) == 0x8)
		return parse_nes2_header(romdesc, header);
	else
		return parse_ines_header(romdesc, header);
		
	return 1;
}

static int parse_ines_header(RomDescriptor * romdesc, const uint8_t header[16]) {
	// initialize descriptor to zero
	memset(romdesc, 0, sizeof(RomDescriptor));

	romdesc->prg_rom_size = PRG_ROM_BANK_SIZE * header[4];
	romdesc->chr_rom_size = CHR_ROM_BANK_SIZE * header[5];
	romdesc->mapper_id = (header[6] >> 4) | (header[7] & 0xF0);
	romdesc->uses_horizontal_nametable = header[6] & 0x1;
	romdesc->uses_alternative_nametable = header[6] & 0x8;
	romdesc->has_persistent_memory = header[6] & 0x2;
	romdesc->has_trainer_data = header[6] & 0x4;
	romdesc->console_type = header[7] & 0x3;
	// iNes headers always give carts 8KiB of PRG RAM, even when they don't have any
	// https://www.nesdev.org/wiki/INES#Flags_8
	romdesc->prg_ram_size = header[8] ?
		PRG_RAM_BANK_SIZE * header[8] : PRG_RAM_BANK_SIZE;
	romdesc->timing_mode = header[9] & 0x1;
	
	
	return 0;
}

static int parse_nes2_header(RomDescriptor * romdesc, const uint8_t header[16]) {
	return 1;
}
