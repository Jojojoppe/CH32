/**
 * @file trace.c
 * @author Joppe Blondel
 * @date 2023-07-10
 * @brief trace io via SWIO. Functions come from ch32v003fun
 */
#include <ch32.h>
#include <hal/trace.h>
#include <stdint.h>

// For debug writing to the debug interface.
#define DMDATA0 ((volatile uint32_t *)0xe00000f4)
#define DMDATA1 ((volatile uint32_t *)0xe00000f8)
#define FUNCONF_DEBUGPRINTF_TIMEOUT (1<<31) // Wait for a very very long time.

void handle_debug_input(int numbytes, uint8_t *data) __attribute__((weak));
void handle_debug_input(int numbytes, uint8_t *data) {}

static void internal_handle_input(uint32_t *dmdata0) {
  uint32_t dmd0 = *dmdata0;
  int bytes = (dmd0 & 0x3f) - 4;
  if (bytes > 0) {
    handle_debug_input(bytes, ((uint8_t *)dmdata0) + 1);
  }
}

void poll_input() {
  uint32_t lastdmd = (*DMDATA0);
  if (!(lastdmd & 0x80)) {
    internal_handle_input((uint32_t *)DMDATA0);
    *DMDATA0 = 0x84; // Negative
  }
}

void traceInit() {
  // Clear out the sending flag.
  *DMDATA1 = 0x0;
  *DMDATA0 = 0x80;
}

void traceWaitForDebugger() {
  while (((*DMDATA0) & 0x80))
    ;
}

int tracePutChar(int c) {
  int timeout = FUNCONF_DEBUGPRINTF_TIMEOUT;
  uint32_t lastdmd = 0;

  while ((lastdmd = (*DMDATA0)) & 0x80)
    if (timeout-- == 0)
      return 0;

  // Simply seeking input.
  lastdmd = (*DMDATA0);
  if (lastdmd)
    internal_handle_input((uint32_t *)DMDATA0);

  while ((lastdmd = (*DMDATA0)) & 0x80)
    if (timeout-- == 0)
      return 0;
  if (lastdmd)
    internal_handle_input((uint32_t *)DMDATA0);
  *DMDATA0 = 0x85 | ((const char)c << 8);
  return 1;
}

int tracePut(const char * str){
  uint32_t i = 0;
  while(str[i]!=0){
    tracePutChar(str[i]);
    i++;
  }
  return i;
}

int traceBinary(int val, int bits){
  int j = tracePut("0b");
  for(int i=bits-1; i>=0; i--){
    if(((val>>i)&1)!=0){
      j += tracePutChar('1');
    }else{
      j += tracePutChar('0');
    }
    if((i%4)==0){
      j += tracePutChar(' ');
    }
  }
  return j;
}
