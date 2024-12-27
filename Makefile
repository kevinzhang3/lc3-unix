CC = gcc
INCLUDES = -I.
CFLAGS = -g -Wall -fPIC -std=c99 -pedantic -g

EXECUTABLES = lc3
BUILD_DIR = build

.PHONY: all clean

all: $(EXECUTABLES)

clean: 
	rm -rf $(EXECUTABLES) build/

$(BUILD_DIR) :
	mkdir -p $@

$(BUILD_DIR)/cpu.o : src/cpu.c src/cpu.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/input.o : src/input.c src/input.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/mem.o : src/mem.c src/input.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/main.o : src/main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

lc3: $(BUILD_DIR)/cpu.o $(BUILD_DIR)/input.o $(BUILD_DIR)/mem.o $(BUILD_DIR)/main.o
	$(CC) $(CFLAGS) $^ -o $@
