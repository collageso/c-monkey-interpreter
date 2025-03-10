#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>

void* safe_malloc(size_t size);
void* safe_realloc(void* ptr, size_t size);
char* read_line();

#endif
