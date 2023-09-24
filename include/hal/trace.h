/**
 * @file trace.h
 * @author Joppe Blondel
 * @date 2023-07-10
 * @brief Debug trace facility
 */
#ifndef __H_HAL_TRACE
#define __H_HAL_TRACE

/**
 * @brief Initialize trace facilities
 */
void traceInit();

/**
 * @brief Wait for the debugger to attach
 */
void traceWaitForDebugger();

/**
 * @brief Print out a character on the trace facility
 * 
 * @param c Character to print out
 * @return int Number of characters printed (1 or 0)
 */
int tracePutChar(int c);

/**
 * @brief Print out a string on the trace facility
 * 
 * @param str String to print out
 * @return int Number of characters printed
 */
int tracePut(const char * str);

/**
 * @brief Print out a binary representation of an integer
 * 
 * @param val Value to print out
 * @param bits Number of bits to print out
 * @return int Number of characters printed
 */
int traceBinary(int val, int bits);

#endif //__H_HAL_TRACE
