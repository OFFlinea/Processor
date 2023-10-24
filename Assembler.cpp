#include <TXLib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "stack.h"
#include "commands.h"

enum error assembler();


int main() {

    assembler();

    return 0;
}


enum error assembler() {

    FILE* file = fopen("Assembler.txt", "r");

    if (!file) {

        printf("%s\n", strerror(errno));

        return FILE_ERROR;
    }

    FILE* file_w = fopen("Operations.txt", "w");

    if (!file_w) {

        printf("%s\n", strerror(errno));

        return FILE_ERROR;
    }

    const int MAX_LEN_COMMAND = 10;
    char command[MAX_LEN_COMMAND] = {};

    struct Stack commands = {};
    STACK_CTOR(&commands);

    while (fscanf(file, "%s", command) != EOF) {

        if (strcmp(command, "hlt") == 0) {

            StackPush(&commands, HLT);
        }

        else if (strcmp(command, "out") == 0) {

            StackPush(&commands, OUTT);
        }

        else if (strcmp(command, "in") == 0) {

            StackPush(&commands, INN);
        }

        else if (strcmp(command, "push") == 0) {

            int number = 0;
            char registr[MAX_LEN_COMMAND] = {};

            if (fscanf(file, "%d", &number) == 1) {

                StackPush(&commands, PUSH + is_number);
                StackPush(&commands, number);
            }

            else {

                fscanf(file, "%s", registr);

                StackPush(&commands, PUSH + is_register);
                StackPush(&commands, registr[1] - 'a');
            }
        }

        else if (strcmp(command, "pop") == 0) {

            char registr[MAX_LEN_COMMAND] = {};
            fscanf(file, "%s", registr);

            StackPush(&commands, POP);
            StackPush(&commands, registr[1] - 'a');
        }

        else if (strcmp(command, "add") == 0) {

            StackPush(&commands, ADD);
        }

        else if (strcmp(command, "sub") == 0) {

            StackPush(&commands, SUB);
        }

        else if (strcmp(command, "mul") == 0) {

            StackPush(&commands, MUL);
        }

        else if (strcmp(command, "div") == 0) {

            StackPush(&commands, DIV);
        }

        else if (strcmp(command, "sqrt") == 0) {

            StackPush(&commands, SQRT);
        }

        else if (strcmp(command, "sin") == 0) {

            StackPush(&commands, SIN);
        }

        else if (strcmp(command, "cos") == 0) {

            StackPush(&commands, COS);
        }
    }

    if (fwrite(commands.data, sizeof(commands.data[0]), commands.sizze, file_w) != commands.sizze) {

        printf("Ошибка при записи\n");

        return FILE_ERROR;
    }

    print_data(commands.data, commands.capacity);

    fclose(file_w);
    fclose(file);

    StackDtor(&commands);

    return OK;
}
