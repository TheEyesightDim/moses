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
		- whatever else you can think of 

	The Mapper interface represents the device that the CPU is interacting with through its cartridge slot.
*/

enum MapperID {
	MAPPER_UNKNOWN = -1
};

typedef struct Mapper {
	// an opaque pointer to a specific mapper struct
	void * mapper_resource_handle;
	enum MapperID mapper_id;
} Mapper;

// Initializes a Mapper to a useable state
void init_mapper(Mapper * mapper, enum MapperID mapper_id, ...);



// Clean up all resources used by a Mapper instance.
void delete_mapper(Mapper * mapper);
