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

/*#define DEF_CMD(name, code) CMD_##name = code,

enum commands {
    #include "cmd.h"
};

#undef DEF_CMD*/

const size_t nregisters = 4;

const int is_register = 64;
const int is_number = 32;

#endif
