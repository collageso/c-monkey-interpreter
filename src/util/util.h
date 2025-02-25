#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>

void* safe_malloc(size_t);
void* safe_realloc(void* ptr, size_t size);
char* get_input();

#endif
