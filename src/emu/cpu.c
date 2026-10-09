#include <inttypes.h>
#include <moses/utils.h>
#include <moses/instructions.h>

/*
 * Adds general format for parsing 6502 instructions, including
 * setting up skeleton code for each instruction set (?)
 *
 * format for instructions in groups 0x01 & 0x10: aaabbbcc, where aaa & cc are the
 * op code, and bbb is the addressing mode.
 *
 *
 * ZERO PAGE:   $0000-$00FF
 * STACK PAGE:  $0100-$01FF (starts at $01FF and grows downwards)
 */

void parse_instruction(uint8_t opcode){
    uint8_t group = EXT(opcode, 0, 2);

    if (group == 0x01) {
        struct instr_01 instruction;
        instruction.op = EXT(opcode, 5, 3);
        instruction.mode = EXT(opcode, 2, 3);

    } else if (group == 0x10) {
        // switch or smth for group 2 commands
    }
    // else return error or smth...
}

void ex_group01(struct instr_01) {
    
}