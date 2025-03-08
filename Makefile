CC = gcc
CFLAGS = -std=c11 -Wall -Wextra 

SOURCES = $(shell find src -name '*.c')
HEADERS = $(shell find src -name '*.h')

BUILD_DIR = build
EXECUTABLE = $(BUILD_DIR)/c-monkey-interpreter

all: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) 

$(EXECUTABLE): $(SOURCES) $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -g $^

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
