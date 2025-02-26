#include "repl.h"
#include "util.h"
#include <stdio.h>

void start_repl(const char* mode, EvalFunc eval)
{
    printf("Hello, Monkey Interpreter REPL!\n");
    printf("mode: %s\n", mode);

    const char* line = read_line();
    printf("%s", line);
}

void eval_lexer(const char* line)
{
    return;
}
