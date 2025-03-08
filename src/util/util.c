#include "util.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void* safe_malloc(size_t size)
{
    void* ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Memort allocation failed\n");
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
    char* line = NULL;
    size_t current_size = 0;
    size_t total_size = 0;

    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        current_size = strlen(buffer);
        total_size += current_size;

        if (line == NULL) {
            line = (char*)safe_malloc(total_size + 1);
            strcpy(line, buffer);
        } else {
            line = (char*)safe_realloc(line, total_size + 1);
            strcat(line, buffer);
        }

        if (line[total_size - 1] == '\n') {
            line[total_size - 1] = '\0';
            break;
        }
    }

    return line;
}
