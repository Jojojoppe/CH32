/**
 * @file ch32.h
 * @author Joppe Blondel
 * @date 2023-07-07
 * @brief 
 */
#ifndef __H_CH32
#define __H_CH32

#include <stdint.h>

#define R64(address) (*((uint64_t*)address))
#define R32(address) (*((uint32_t*)address))
#define R16(address) (*((uint16_t*)address))
#define R8(address) (*((uint8_t*)address))

#if defined(CH32V003)
#include <ch32v003.h>
#elif defined(CH32V203)
#include <ch32v203.h>
#else
#error Unknown device defined
#endif

#endif // __H_CH32
