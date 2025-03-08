#ifndef REPL_H
#define REPL_H

typedef void (*EvalFunc)(const char* input);

void start_repl(const char* mode, EvalFunc eval);
void eval_lexer(const char* input);

#endif
