#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <assert.h>
#include <string.h>
#include "Processor.h"
#include "stack.h"
#include "commands.h"


void SPUCtor(struct SPU* spu) {

    STACK_CTOR(&spu->stk);

    spu->registers = (Elem_t*) calloc(nregisters, sizeof(Elem_t));

    spu->ip = 0;

    file_read(spu);
}


void SPUDtor(struct SPU* spu) {

    StackDtor(&spu->stk);

    free(spu->registers);
    spu->registers = NULL;

    spu->ip = POISON;
    free(spu->cs);
    spu->cs = NULL;
}


size_t SPUVerify(struct SPU* spu) {

    size_t error = StackVerify(&spu->stk);

    if (!spu->cs || !spu->registers) {

        error += 1;
    }

    return error;
}


void SPUDump(struct SPU* spu) {

    printf("SPU:\n");

    for (size_t i = 0; i < spu->ip; i++) {

        printf("%6d ", i);
    }

    putchar('\n');

    size_t i = 0;

    while (spu->cs[i] != HLT) {

        printf("%6d ", spu->cs[i++]);
    }

    putchar('\n');

    printf("Registers:\n");

    for (size_t i = 0; i < nregisters; i++) {

        printf("%d ", spu->registers[i]);
    }

    putchar('\n');

    StackDump(&spu->stk, __FILE__, __LINE__, __func__);
}


enum error file_read(struct SPU* spu) {

    const char* filename = "Operations.txt";

    FILE* file = fopen(filename, "r");

    size_t fsize = filesize(filename) / sizeof(Elem_t) + 1;

    if (!file) {

        printf("%s\n", strerror(errno));

        return FILE_ERROR;
    }

    spu->cs = (Elem_t*) calloc(fsize, sizeof(Elem_t));

    if (!spu->cs) {

        printf("No memory\n");

        return NO_MEM;
    }

    if (fread(spu->cs, sizeof(Elem_t), fsize, file) != fsize) {

        return FILE_ERROR;
    }

    return OK;
}


size_t filesize(const char* filename) {

    assert(filename);

    struct stat sizze = {};

    if (stat(filename, &sizze) == -1) {

        printf("%s\n", strerror(errno));
        return 0;
    }

    return sizze.st_size;
}
