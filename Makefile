CC = gcc
CFLAGS = -std=c11 -Wall -Wextra

SOURCES = $(wildcard src/*.c)
HEADERS = $(wildcard src/*.h)

EXECUTABLE = c-monkey-interpreter

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean
