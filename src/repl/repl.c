#include "repl.h"
#include <stdio.h>

void start_repl(const char* mode, EvalFunc eval)
{
    printf("Hello, Monkey Interpreter REPL!\n");
    printf("mode: %s\n", mode);
}
