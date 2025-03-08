#include "repl.h"
#include "lexer.h"
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
    Lexer l = lexer_new(line);

    while (1) {
        Token token = lexer_next(&l);
        const char* token_str = token_kind_to_str(token.kind);

        if (strcmp(token_str, "ILLEGAL") == 0 || strcmp(token_str, "END_OF_FILE") == 0) {
            printf("\n");
            return;
        }

        printf("%s(\"%s\") ", token_str, token.literal);
        fflush(stdout);
    }
}
