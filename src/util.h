#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    char* ch;
    uint8_t len;
} Utf8_Encoded;

void* safe_malloc(size_t size);
void* safe_realloc(void* ptr, size_t size);
char* read_line();
Utf8_Encoded utf8_encoded_new(const char* ch, uint8_t len);
uint8_t get_utf8_len(unsigned char byte);

#endif
