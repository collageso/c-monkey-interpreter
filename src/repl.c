#include "repl.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

void start_repl(const char* mode, EvalFunc eval)
{
    printf("Hello, Monkey Interpreter REPL!\n");
    printf("mode: %s\n", mode);

    while (1) {
        printf("> ");
        fflush(stdout);

        const char* line = read_line();

        if (strcmp(line, ":q") == 0) {
            break;
        }

        eval(line);
    }
}

void eval_lexer(const char* line)
{
    printf("%s\n", line);
    return;
}
