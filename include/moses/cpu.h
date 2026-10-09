#pragma once

#include <stdint.h>

typedef int8_t reg8;
typedef int16_t reg16;

typedef struct CPU {
	reg16 pc;	// Program counter
	reg8 s;		// Stack Pointer
	reg8 a;		// Accumulator
	reg8 x;		// Index X
	reg8 y;		// Index Y
	reg8 p;		// Status register
} CPU;
