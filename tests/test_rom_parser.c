#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "moses/rom_parser.h"
#include "test_utils.h"

/*	The data from a NES 2.0 ROM header should be correctly parsed and loaded into the RomDescriptor struct. As feature support improves, more fields should be correctly parsed and tested, but this covers the basic information (mapper type, console timing, description of memory banks).
*/

//	This is the iNes format .nes header from Donkey Kong (1981).
//	sha1:c4eb14a59b853a58f53538e07c5efac56ddfe5fe
//	It contains no proprietary game data, only the header.
static uint8_t const header_dk[16] = {
	0x4e, 0x45, 0x53, 0x1a,
	0x01, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x61,
	0x73, 0x74, 0x65, 0x72
};

// This is the NES 2.0 format .nes header from Super Mario Bros. 3 (1988).
// sha1:a25d2dcbf6ec3634a84318bfe2cfe28d5331d815
// It contains no proprietary game data, only the header.
static uint8_t const header_smb3[16] = {
	0x4e, 0x45, 0x53, 0x1a,
	0x10, 0x10, 0x40, 0x08,
	0x00, 0x00, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x01
};

static RomDescriptor const expected_dk_header = {
	.mapper_id = 0,
	.uses_horizontal_nametable = true,
	.timing_mode = RD_TIMING_NTSC,
	.console_type = RD_CONSOLE_NES,
	.prg_rom_size = 16384,
	.chr_rom_size = 8192,
};

static void test_parsing_ines_header(RomDescriptor const * expected) {
	RomDescriptor test_descriptor;
	int result = make_rom_descriptor(&test_descriptor, rom_bytes);

	TEST_ASSERT("iNes ROM parses successfully", result == 0);

	bool matched = memcmp(expected, &test_descriptor, sizeof(RomDescriptor));
	TEST_ASSERT("RomDescriptor has expected data", matched);
}

int main() {
	printf("Testing \"Donkey Kong\" (1981) header...\n");
	test_parsing_ines_header(&expected_dk_header);
	return 0;
}


