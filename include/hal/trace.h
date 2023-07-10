/**
 * @file trace.h
 * @author Joppe Blondel
 * @date 2023-07-10
 * @brief 
 */
#ifndef __H_HAL_TRACE
#define __H_HAL_TRACE

void traceInit();

void traceWaitForDebugger();

int tracePutChar(int c);

#endif //__H_HAL_TRACE
