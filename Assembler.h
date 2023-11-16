#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>
#include "stack.h"

const int MAX_LEN_COMMAND = 10;

enum error assembler();

void Push(struct Stack* commands, FILE* file);

void Pop(struct Stack* commands, FILE* file);

#endif
