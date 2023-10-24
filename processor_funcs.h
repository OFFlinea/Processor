#ifndef PROCESSOR_FUNCS_H
#define PROCESSOR_FUNCS_H

#include "stack.h"

const int MOVE_POINT_COEF = 100;

void read_operations(struct SPU* spu);

void Hlt();

void Out(struct Stack* stk);

void In(struct Stack* stk);

void Push(struct SPU* spu, const int type_command);

void Pop(struct SPU* spu);

void Add(struct Stack* stk);

void Sub(struct Stack* stk);

void Mul(struct Stack* stk);

void Div(struct Stack* stk);

void SqrT(struct Stack* stk);

void SiN(struct Stack* stk);

void CoS(struct Stack* stk);

#endif
