/*
 * Defines functions which will be used to perform 6502 commands
 */


#ifndef MOSES_COMMANDS_H
#define MOSES_COMMANDS_H

/*
 * This struc (instr_01) holds op codes & addressing modes for 0x01 instructions,
 * and can set the current op/mode using the enum members.
 */
struct instr_01 {
    enum {
        ORA,
        AND,
        EOR,
        ADC,
        STA,
        LDA,
        CMP,
        SCB
    }op;

    enum {
        G1_INDIRECT_X,
        G1_ZERO_PAGE,
        G1_IMMEDIATE,
        G1_ABSOLUTE,
        G1_INDIRECT_Y,
        G1_ZERO_PAGE_X,
        G1_ABSOLUTE_Y,
        G1_ABSOLUTE_X
    }mode;
};

struct instr_02 {
    enum {
        ASL,
        ROL,
        LSR,
        ROR,
        STX,
        LDX,
        DEC,
        INC
    }op;

    enum {
        G2_IMMEDIATE,
        G2_ZERO_PAGE,
        G2_ACCUMULATOR,
        G2_ABSOLUTE,
        G2_ZERO_PAGE_X = 5,
        G2_ABSOLUTE_X = 7
    }mode;
};

struct instr_03 {
    enum {
        BIT = 1,
        JMP,
        JMP_ABS,
        STY,
        LDY,
        CPY,
        CPX
    }op;

    enum {
        G3_IMMEDIATE,
        G3_ZERO_PAGE,
        G3_ABSOLUTE = 3,
        G3_ZERO_PAGE_X = 5,
        G3_ABSOLUTE_X = 7
    }mode;
};



/* Structure:
 * byte 1 = op-code/addressing mode
 * byte 2 = immediate data or 8-bit memory address (or 1st 8 bits of mem. add.)
 * byte 3 = 2nd 8 bits of 16-bit memory address (used in absolute addressing modes)
 *
 *
 */

void parse_instruction(uint8_t opcode);

void ex_group01(struct instr_01);

#endif //MOSES_COMMANDS_H
