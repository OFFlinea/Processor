#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "stack.h"
#include "commands.h"
#include "Assembler.h"


enum error assembler() {

    FILE* file = fopen("Assembler.txt", "r");

    if (!file) {

        printf("%s\n", strerror(errno));

        return FILE_ERROR;
    }

    FILE* file_w = fopen("Operations.txt", "wb");

    if (!file_w) {

        printf("%s\n", strerror(errno));

        return FILE_ERROR;
    }

    char command[MAX_LEN_COMMAND] = {};

    struct Stack commands = {};
    STACK_CTOR(&commands);

    #define COMMAND(name, number, arg_type, ...)  \
                                                  \
        if (strcmp(command, #name) == 0) {        \
                                                  \
            StackPush(&commands, number);         \
        }                                         \

    while (fscanf(file, "%s", command) != EOF) {

        if (strcmp(command, "push") == 0) {

            Push(&commands, file);
            continue;
        }

        else if (strcmp(command, "pop") == 0) {

            Pop(&commands, file);
            continue;
        }

        #include "commands.txt"
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


void Push(struct Stack* commands, FILE* file) {

    assert(commands);
    assert(commands->data);
    assert(file);

    int number = 0;

    if (fscanf(file, "%d", &number) == 1) {

        StackPush(commands, PUSH + is_number);
        StackPush(commands, number);
    }

    else {

        char registr[MAX_LEN_COMMAND] = {};
        fscanf(file, "%s", registr);

        StackPush(commands, PUSH + is_register);
        StackPush(commands, registr[1] - 'a');
    }
}


void Pop(struct Stack* commands, FILE* file) {

    assert(commands);
    assert(commands->data);
    assert(file);

    char registr[MAX_LEN_COMMAND] = {};
    fscanf(file, "%s", registr);

    StackPush(commands, POP);
    StackPush(commands, registr[1] - 'a');
}
