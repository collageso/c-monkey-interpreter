#include "repl.h"
#include "../util/util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eval_lexer(const char* input)
{
    printf("lexer result: %s\n", input);
}

void start_repl(const char* mode, EvalFunc eval)
{
    printf("Hello, Monkey Interpreter REPL!\n");
    printf("Mode: %s\n", mode);

    while (1) {
        printf("> ");
        fflush(stdout);

        char* line = read_line();

        if (strcmp(line, ":q") == 0) {
            break;
        }

        eval(line);
        free(line);
    }
}
