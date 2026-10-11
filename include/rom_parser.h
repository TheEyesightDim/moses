#pragma once

/*
Interface for parsing an iNes or NES 2.0 format rom into a data structure.
*/

#include <stddef.h>
#include <stdint.h>


typedef uint8_t BANK_PRG[16384]; 
typedef uint8_t BANK_CHR[8192];

typedef uint8_t MapperID;

typedef struct RomDescriptor {
	BANK_PRG * prg_banks;
	BANK_CHR * chr_banks;
	uint8_t num_prg_banks;
	uint8_t num_chr_banks;
	MapperID mapper_id;
} RomDescriptor;
