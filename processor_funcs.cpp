#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "processor_funcs.h"
#include "stack.h"
#include "commands.h"
#include "Processor.h"


void read_operations(struct SPU* spu) {

    enum commands command = (enum commands) spu->cs[spu->ip++];

    #define COMMAND(name, number, arg_type, action)     \
                                                        \
            case number + arg_type:                     \
            {                                           \
                action;                                 \
                break;                                  \
            }                                           \

    while (command != HLT) {

        if (SPUVerify(spu)) {

            SPUDump(spu);

            return;
        }

        switch(command) {

            #include "commands.txt"

            /*case HLT:
            {
                Hlt();
                return;
            }

            case OUTT:
            {
                Out(&spu->stk);
                break;
            }

            case INN:
            {
                In(&spu->stk);
                break;
            }

            case PUSH + is_number:
            {
                Push(spu, is_number);
                break;
            }

            case PUSH + is_register:
            {
                Push(spu, is_register);
                break;
            }

            case POP:
            {
                Pop(spu);
                break;
            }

            case ADD:
            {
                Add(&spu->stk);
                break;
            }

            case SUB:
            {
                Sub(&spu->stk);
                break;
            }

            case MUL:
            {
                Mul(&spu->stk);
                break;
            }

            case DIV:
            {
                Div(&spu->stk);
                break;
            }

            case SQRT:
            {
                SqrT(&spu->stk);
                break;
            }

            case SIN:
            {
                SiN(&spu->stk);
                break;
            }

            case COS:
            {
                CoS(&spu->stk);
                break;
            }*/

            default:
            {
                printf("Неверная операция\n");
                break;
            }
        }

        command = (enum commands) spu->cs[spu->ip++];
    }

    #undef COMMAND
}


/*void Hlt() {

    printf("Программа завершена.\n");
}


void Out(struct Stack* stk) {

    Elem_t number = 0;
    StackPop(stk, &number);
    printf("Ответ: %lf\n", (double) number / MOVE_POINT_COEF);
}


void In(struct Stack* stk) {

    Elem_t number = 0;
    printf("Введите число: ");
    scanf("%d", &number);
    number *= MOVE_POINT_COEF;
    StackPush(stk, number);
}


void Push(struct SPU* spu, const int type_command) {

    Elem_t number = (type_command == is_number) ? spu->cs[spu->ip++] :
                     spu->registers[spu->cs[spu->ip++]];

    number *= MOVE_POINT_COEF;
    StackPush(&spu->stk, number);
}


void Pop(struct SPU* spu) {

    StackPop(&spu->stk, &spu->registers[spu->cs[spu->ip]]);
    spu->registers[spu->cs[spu->ip++]] /= 100;
}


void Add(struct Stack* stk) {

    Elem_t number1 = 0;
    Elem_t number2 = 0;

    StackPop(stk, &number2);
    StackPop(stk, &number1);
    StackPush(stk, number1 + number2);
}


void Sub(struct Stack* stk) {

    Elem_t number1 = 0;
    Elem_t number2 = 0;

    StackPop(stk, &number2);
    StackPop(stk, &number1);
    StackPush(stk, number1 - number2);
}


void Mul(struct Stack* stk) {

    Elem_t number1 = 0;
    Elem_t number2 = 0;

    StackPop(stk, &number2);
    StackPop(stk, &number1);
    StackPush(stk, number1 * number2 / MOVE_POINT_COEF);
}


void Div(struct Stack* stk) {

    Elem_t number1 = 0;
    Elem_t number2 = 0;

    StackPop(stk, &number2);
    StackPop(stk, &number1);
    StackPush(stk, (Elem_t) ((double) number1 / (double) number2 * MOVE_POINT_COEF));
}


void SqrT(struct Stack* stk) {

    Elem_t number = 0;
    StackPop(stk, &number);
    StackPush(stk, (Elem_t) (sqrt((double) number / MOVE_POINT_COEF) * MOVE_POINT_COEF));
}


void SiN(struct Stack* stk) {

    Elem_t number = 0;
    StackPop(stk, &number);
    StackPush(stk, (Elem_t) (sin((double) number / MOVE_POINT_COEF) * MOVE_POINT_COEF));
}


void CoS(struct Stack* stk) {

    Elem_t number = 0;
    StackPop(stk, &number);
    StackPush(stk, (Elem_t) (cos((double) number / MOVE_POINT_COEF) * MOVE_POINT_COEF));
}*/
