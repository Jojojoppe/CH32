/**
 * @file system.h
 * @author Joppe Blondel
 * @date 2023-07-10
 * @brief 
 */
#ifndef __H_HAL_SYSTEM
#define __H_HAL_SYSTEM

#include <stdint.h>

/**
 * @brief Types of supported clock configurations
 */
enum ClockConfiguration{
    /**
     * @brief Maximum clock frequency with as little resources
     */
    CLOCK_CONFIG_DEFAULT
};

/**
 * @brief Initialize clocking network
 * 
 * @param clockConfiguration Clock configuration to use
 */
void clockInit(enum ClockConfiguration clockConfiguration);

/**
 * @brief Get the Clock frequency
 * 
 * @return uint32_t Frequency in Hz
 */
uint32_t getClockFrequency();


#endif // __H_HAL_SYSTEM