#ifndef COMMANDS_H
#define COMMANDS_H

enum commands
{
    HLT = -1,
    OUTT,
    INN,
    PUSH,
    POP,
    ADD,
    SUB,
    MUL,
    DIV,
    SQRT,
    SIN,
    COS
};


const size_t nregisters = 4;

const int is_register = 64;
const int is_number = 32;

const int NONE = 0;

#endif
