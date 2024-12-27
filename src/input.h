#ifndef INPUT_H
#define INPUT_H
#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>

/* mem mapped regs for io */
enum
{
    MR_KBSR = 0xFE00, // keyboard status 
    MR_KBDR = 0xFE02  // keyboard data 
};

void disable_input_buffering(void);
void restore_input_buffering(void);
uint16_t check_key(void);
void handle_interrupt(int signal);

#endif 
