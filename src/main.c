#include "repl/repl.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        // TODO: Whole Interpreter REPL needed to implement
        return 0;
    }

    char* mode = argv[1];

    if (strcmp(mode, "--lexer") == 0) {
        start_repl("lexer", eval_lexer);
    } else {
        fprintf(stderr, "Invalid mode: %s\n", mode);
    }

    return 0;
}
