#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>
#include <stdint.h>

#define MAX_UTF8_CHAR_LEN 4

typedef struct {
    char ch[MAX_UTF8_CHAR_LEN];
    uint8_t len;
} Utf8_Encoded;

void* safe_malloc(size_t size);
void* safe_realloc(void* ptr, size_t size);
char* read_line();
uint8_t get_utf8_len(unsigned char byte);
char* combine_str(const char* str1, size_t len1, const char* str2, size_t len2);

#endif
