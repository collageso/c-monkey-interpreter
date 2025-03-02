#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
    // Puctuations
    COMMA,
    SEMICOLON,
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    // Operators
    ASSIGN,
    PLUS,
    MINUS,
    BANG,
    ASTERISK,
    SLASH,
    EQUAL,
    NOT_EQUAL,
    GREATER_THAN,
    GREATER_THAN_EQUAL,
    LESS_THAN,
    LESS_THAN_EQUAL,
    // Literals
    STRING_LITERAL,
    INT_LITERAL,
    // Reserved words and Identifier
    FUNCTION,
    LET,
    TRUE,
    FALSE,
    IF,
    ELSE,
    RETURN,
    IDENT,
    // ETC
    ILLEGAL,
    END_OF_FILE,
} Token_Kind;

typedef struct {
    Token_Kind kind;
    const char* literal;
} Token;

typedef struct {
    const char* input;
    size_t position;
    size_t next_position;
} Lexer;

const char* token_kind_to_str(Token_Kind kind);
Lexer lexer_new(const char* input);
Token lexer_next(Lexer* l);

#endif
