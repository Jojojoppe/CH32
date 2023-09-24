/**
 * @file ch32.h
 * @author Joppe Blondel
 * @date 2023-07-07
 * @brief Base header file for the CH32 series chips
 */
#ifndef __H_CH32
#define __H_CH32

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/** @brief macro to define a 64b register */
#define R64(address) (*((volatile uint64_t*)address))
/** @brief macro to define a 32b register */
#define R32(address) (*((volatile uint32_t*)address))
/** @brief macro to define a 16b register */
#define R16(address) (*((volatile uint16_t*)address))
/** @brief macro to define a 8b register */
#define R8(address) (*((volatile uint8_t*)address))

#if defined(CH32V003)
#include <ch32v003.h>
#elif defined(CH32V203)
#include <ch32v203.h>
#else
#error Unknown device defined
#endif

#endif // __H_CH32
