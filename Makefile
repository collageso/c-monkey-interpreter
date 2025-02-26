CC = gcc
CFLAGS = -std=c11 -Wall -Wextra

SOURCES = $(wildcard src/*.c)
HEADERS = $(wildcard src/*.h)

BUILD_DIR = build
EXECUTABLE = $(BUILD_DIR)/c-monkey-interpreter

all: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) 

$(EXECUTABLE): $(SOURCES) $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
