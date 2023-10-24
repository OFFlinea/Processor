#include <TXLib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include "commands.h"
#include "processor_funcs.h"
#include "stack.h"
#include "Processor.h"


int main() {

    struct SPU spu = {};
    SPUCtor(&spu);

    read_operations(&spu);

    return 0;
}
