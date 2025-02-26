#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void* safe_malloc(size_t size)
{
    void* ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

void* safe_realloc(void* ptr, size_t size)
{
    void* new_ptr = realloc(ptr, size);

    if (new_ptr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }

    return new_ptr;
}

char* read_line()
{
    char buffer[BUFFER_SIZE] = { 0 };
    char* p_line = NULL;
    size_t current_size = 0;
    size_t total_size = 0;

    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);

        current_size = strlen(buffer);
        total_size += current_size;

        if (p_line == NULL) {
            p_line = (char*)safe_malloc(total_size + 1);
            strcpy(p_line, buffer);
        } else {
            p_line = (char*)safe_realloc(p_line, total_size + 1);
            strcat(p_line, buffer);
        }

        if (buffer[current_size - 1] == '\n') {
            *(p_line + total_size - 1) = 0;
            break;
        }
    }

    return p_line;
}
