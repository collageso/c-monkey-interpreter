#include "repl.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc < 2) {
        // TODO: Whole Interpreter REPL needed to implement
        return 0;
    }

    char* option = argv[1];

    if (strcmp(option, "--lexer") == 0) {
        start_repl("lexer", eval_lexer);
    } else {
        fprintf(stderr, "Invalid option: %s\n", option);
    }

    return 0;
}
