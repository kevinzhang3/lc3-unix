#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdint.h>
#include <signal.h>


/* registers for the LC-3 */
enum
{
    // R0-R7 are the eight general purpose regs 16 bits wide each
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,

    // other non-accessibles regs
    R_PC,   // program counter
    R_COND, // condi codes
    R_COUNT
};

extern uint16_t reg[R_COUNT];

/* trap codes */
enum
{
    TRAP_GETC = 0x20,  // get char from keyboard, not echoed 
    TRAP_OUT = 0x21,   // output char 
    TRAP_PUTS = 0x22,  // output word string 
    TRAP_IN = 0x23,    // get char from keyboard, echoed on terminal 
    TRAP_PUTSP = 0x24, // output a byte string 
    TRAP_HALT = 0x25   // halt program 
};

/* the 16 opcodes for LC-3 */
enum
{
    // 16 bit 2's complement int
    OP_BR = 0, // branch
    OP_ADD,    // add
    OP_LD,     // load pc-rel
    OP_ST,     // store pc-rel
    OP_JSR,    // jump reg
    OP_AND,    // bitwise AND
    OP_LDR,    // load reg base+offset
    OP_STR,    // store reg base+offset
    OP_RTI,    // return from interrupt
    OP_NOT,    // bitwise NOT
    OP_LDI,    // load indirect
    OP_STI,    // store indirect
    OP_JMP,    // jump
    OP_RES,    // reserved
    OP_LEA,    // load effective address: imm mode
    OP_TRAP    // changes the PC to the address of OS service routine
};

/* LC-3 has 3 condition flags that store the result of the previous operation */
enum
{
    FL_POS = 1 << 0, // P
    FL_ZRO = 1 << 1, // Z
    FL_NEG = 1 << 2, // N
};

uint16_t sign_extend(uint16_t x, int bit_count);
uint16_t swap16(uint16_t x);
void update_flags(uint16_t r);

#endif
