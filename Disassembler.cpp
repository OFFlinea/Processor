#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "commands.h"

void disassembler();


int main() {

    disassembler();

    return 0;
}


void disassembler() {

    FILE* file = fopen("Operations.txt", "r");

    if (!file) {

        printf("%s\n", strerror(errno));
    }

    FILE* file_w = fopen("Assembler.txt", "w");

    if (!file_w) {

        printf("%s\n", strerror(errno));
    }

    int command = 0;

    while (fscanf(file, "%d", &command) != EOF) {

        switch(command) {

            case HLT:

                fprintf(file_w, "hlt\n");
                break;

            case OUTT:

                fprintf(file_w, "out\n");
                break;

            case INN:

                fprintf(file_w, "in\n");
                break;

            case PUSH:
            {
                int number = 0;
                fscanf(file, "%d", &number);
                fprintf(file_w, "push %d\n", number);
                break;
            }

            case ADD:

                fprintf(file_w, "add\n");
                break;

            case SUB:

                fprintf(file_w, "sub\n");
                break;

            case MUL:

                fprintf(file_w, "mul\n");
                break;

            case DIV:

                fprintf(file_w, "div\n");
                break;

            case SQRT:

                fprintf(file_w, "sqrt\n");
                break;

            case SIN:

                fprintf(file_w, "sin\n");
                break;

            case COS:

                fprintf(file_w, "cos\n");
                break;

            default:

                break;
        }
    }
}
