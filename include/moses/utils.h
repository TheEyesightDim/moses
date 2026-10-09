/*
 * Definitions of macros and other utilities (probably)
 */

#pragma once

/*
 * Takes binary data and a bit number, then evaluates to
 * the specified bit value.
 */
#define BIT(data, bit) ((data >> bit) & 0x1)

/*
 * Takes binary data and a bit number, then evaluates to
 * the data with the specified bit cleared.
 */
#define CLRB(data, bit) (~(0x1 << bit) & data)

/*
 * Takes binary data and a bit number, then evaluates to
 * the data with the specified bit set.
 */
#define SETB(data, bit) ((0x1 << bit) | data)

/*
 * Takes binary data, a bit number, and a number of bits to isolate
 * from right to left; evaluates to the isolated bits starting from
 * bit number.
 */
#define EXT(data, bit, len) ((data >> bit) & ((0x1 << len) - 0x1))
