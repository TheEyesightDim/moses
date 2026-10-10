#pragma once

/*
	Provides the interface to the emulated circuitry in an NES cartridge
	or cartridge slot peripheral (the mapper).
	
	The NES's CPU does not know anything about the nature of the hardware attached
	to its cartridge slot, it just reads and writes over the pins on its address bus.
	Meanwhile, the mapper hardware might do things including, but not limited to:
		- providing expanded game cart size via bank switching
		- providing more RAM or save memory
		- providing additional audio generation
		- providing more advanced graphical capabilities
		- generating interupts to the CPU
		- whatever else you can think of 
*/

#include <stdint.h>
#include <stdio.h>

enum MapperID {
	MAPPER_NROM,
};

// This interface is highly subject to change, but at a minimum we need to
// read and write bytes over the data bus in the cartridge's mapped region.
// The mapper should also be able to reset its state (e.g. internal registers) and free any resources (e.g. handle to rom file).

// Need to forward declare structs because they both refer to eachother
typedef struct MapperVTable MapperVTable;
typedef struct MapperBase MapperBase;


struct MapperVTable {
	void (* write_byte) (MapperBase * mapper, uint16_t address, uint8_t byte);
	uint8_t (* read_byte) (MapperBase * mapper, uint16_t address);
	void (* reset) (MapperBase * mapper);
	void (* delete) (MapperBase * mapper);
};

// Hold the method vtable and common properties of all mappers
struct MapperBase {
	MapperVTable const * vtable;
};

MapperBase * mapper_create_from_rom_filepath(FILE * filepath);

void mapper_delete(MapperBase * mapper);

/*
An example derivation of MapperBase:

	struct Mapper_01 {
		MapperBase base;
		void * mmapped_nes_rom;
		enum CartFormat format;
		uint8_t PRG_ROM_index;
		uint8_t CHR_ROM_index;
	};

	//...

	// detects the correct mapper from header, allocates and inits Mapper_01
	MapperBase * cart = mapper_create_from_rom_filepath(filepath);

	NES * nes = nes_create_system();

	nes_attach_mapper(nes, cart);
*/

