#include "lexer.h"
#include "util.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static Token token_new(Token_Kind kind, const char* literal)
{
    return (Token) {
        .kind = kind,
        .literal = literal
    };
}

static Utf8_Encoded peek_char(Lexer* l)
{
    Utf8_Encoded utf8_encoded = utf8_encoded_new(NULL, 0);

    unsigned long input_len = strlen(l->input);

    if (l->next_position >= input_len) {
        return utf8_encoded;
    }

    unsigned char first_byte = l->input[l->next_position];
    uint8_t ch_len = get_utf8_len(first_byte);

    if (l->next_position + ch_len > input_len) {
        return utf8_encoded;
    }

    utf8_encoded.ch = (char*)safe_malloc(ch_len);
    utf8_encoded.len = ch_len;
    memcpy(utf8_encoded.ch, &first_byte, ch_len);

    return utf8_encoded;
}

static Utf8_Encoded read_char(Lexer* l)
{
    Utf8_Encoded utf8_encoded = peek_char(l);

    l->position = l->next_position;
    l->next_position += utf8_encoded.len;

    return utf8_encoded;
}

const char* token_kind_to_str(Token_Kind kind)
{
    const char* token_strs[] = {
        [COMMA] = "COMMA",
        [SEMICOLON] = "SEMICOLON",
        [LEFT_PAREN] = "LEFT_PAREN",
        [RIGHT_PAREN] = "RIGHT_PAREN",
        [LEFT_BRACE] = "LEFT_BRACE",
        [RIGHT_BRACE] = "RIGHT_BRACE",
        [ASSIGN] = "ASSIGN",
        [PLUS] = "PLUS",
        [MINUS] = "MINUS",
        [BANG] = "BANG",
        [ASTERISK] = "ASTERISK",
        [SLASH] = "SLASH",
        [EQUAL] = "EQUAL",
        [NOT_EQUAL] = "NOT_EQUAL",
        [GREATER_THAN] = "GREATER_THAN",
        [GREATER_THAN_EQUAL] = "GREATER_THAN_EQUAL",
        [LESS_THAN] = "LESS_THAN",
        [LESS_THAN_EQUAL] = "LESS_THAN_EQUAL",
        [STRING_LITERAL] = "STRING_LITERAL",
        [INT_LITERAL] = "INT_LITERAL",
        [FUNCTION] = "FUNCTION",
        [LET] = "LET",
        [TRUE] = "TRUE",
        [FALSE] = "FALSE",
        [IF] = "IF",
        [ELSE] = "ELSE",
        [RETURN] = "RETURN",
        [IDENT] = "IDENT",
        [ILLEGAL] = "ILLEGAL",
        [END_OF_FILE] = "END_OF_FILE",
    };

    return token_strs[kind];
}

Lexer lexer_new(const char* input)
{
    return (Lexer) {
        .input = input,
        .position = 0,
        .next_position = 0
    };
}

Token lexer_next(Lexer* l)
{
    Utf8_Encoded utf8_encoded = read_char(l);
    char* ch = utf8_encoded.ch;

    if (ch == NULL) {
        return token_new(END_OF_FILE, "");
    }

    switch (*ch) {
    case ',':
        return token_new(COMMA, ch);
    case ';':
        return token_new(SEMICOLON, ch);
    case '(':
        return token_new(LEFT_PAREN, ch);
    case ')':
        return token_new(RIGHT_PAREN, ch);
    case '{':
        return token_new(LEFT_BRACE, ch);
    case '}':
        return token_new(RIGHT_BRACE, ch);
    case '+':
        return token_new(PLUS, ch);
    case '-':
        return token_new(MINUS, ch);
    case '*':
        return token_new(ASTERISK, ch);
    case '/':
        return token_new(SLASH, ch);
    default:
        return token_new(ILLEGAL, ch);
    }
}
