#include "lexer.h"
#include "util.h"
#include <stdbool.h>
#include <stdint.h>
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
    Utf8_Encoded utf8_encoded = {
        .ch = { 0 },
        .len = 0
    };

    unsigned long input_len = strlen(l->input);

    if (l->next_position >= input_len) {
        return utf8_encoded;
    }

    unsigned char first_byte = l->input[l->next_position];
    uint8_t ch_len = get_utf8_len(first_byte);

    if (l->next_position + ch_len > input_len) {
        return utf8_encoded;
    }

    memcpy(utf8_encoded.ch, &first_byte, ch_len);
    utf8_encoded.len = ch_len;

    return utf8_encoded;
}

static Utf8_Encoded read_char(Lexer* l)
{
    Utf8_Encoded utf8_encoded = peek_char(l);

    l->position = l->next_position;
    l->next_position += utf8_encoded.len;

    return utf8_encoded;
}

static Token lex_combined_operator(Lexer* l, Token_Kind single, Token_Kind combined, const char* ch, uint8_t len)
{
    Utf8_Encoded utf8_encoded = peek_char(l);

    if (utf8_encoded.len == 0) {
        return token_new(single, ch);
    }

    if (strcmp(utf8_encoded.ch, "=") == 0) {
        read_char(l);
        return token_new(combined, combine_str(ch, len, utf8_encoded.ch, utf8_encoded.len));
    }

    return token_new(single, ch);
}

static Token lex_string(Lexer* l)
{
    size_t start_position = l->next_position;

    while (1) {
        Utf8_Encoded utf8_encoded = read_char(l);

        if (*utf8_encoded.ch == '"') {
            break;
        }

        if (utf8_encoded.len == 0) {
            return token_new(ILLEGAL, "");
        }
    }

    char* str =
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
    uint8_t len = utf8_encoded.len;

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
    case '=':
        return lex_combined_operator(l, ASSIGN, EQUAL, ch, len);
    case '!':
        return lex_combined_operator(l, BANG, NOT_EQUAL, ch, len);
    case '>':
        return lex_combined_operator(l, GREATER_THAN, GREATER_THAN_EQUAL, ch, len);
    case '<':
        return lex_combined_operator(l, LESS_THAN, LESS_THAN_EQUAL, ch, len);
    case 0:
        return token_new(END_OF_FILE, "");
    default:
        return token_new(ILLEGAL, ch);
    }
}
