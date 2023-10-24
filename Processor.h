#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "stack.h"

typedef int Elem_t;

struct SPU
{
    struct Stack stk;
    Elem_t* registers;
    size_t ip;
    Elem_t* cs;
};

void SPUCtor(struct SPU* spu);

void SPUDtor(struct SPU* spu);

size_t SPUVerify(struct SPU* spu);

void SPUDump(struct SPU* spu);

enum error file_read(struct SPU* spu);

size_t filesize(const char* filename);

#endif
