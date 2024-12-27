#ifndef MEM_H
#define MEM_H

#include <stdio.h>
#include <stdint.h>
#include <signal.h>

#define MEMORY_MAX 65536

extern uint16_t memory[MEMORY_MAX];

void mem_write(uint16_t address, uint16_t val);
uint16_t mem_read(uint16_t address);
void read_image_file(FILE* file);
int read_image(const char* image_path);

#endif

