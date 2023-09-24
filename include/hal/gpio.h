/**
 * @file gpio.h
 * @author Joppe Blondel
 * @date 2023-07-10
 * @brief GPIO pin driver
 */
#ifndef __H_HAL_GPIO
#define __H_HAL_GPIO

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief GPIO Pin handle
 */
typedef struct GpioHandle GpioHandle;

/**
 * @brief Pin mode
 */
enum GpioMode {
  /** @brief Normal digital output */
  GPIO_MODE_DIGITAL_OUTPUT,
  /** @brief Digital output with fast slew rates */
  GPIO_MODE_DIGITAL_OUTPUT_FAST,
  /** @brief Normal digital input */
  GPIO_MODE_DIGITAL_INPUT,
  /** @brief Analog input */
  GPIO_MODE_ANALOG_INPUT,
};

/**
 * @brief Pull up/down configuration for input
 */
enum GpioInputMode {
  /** @brief Normal input */
  GPIO_INPUT_MODE_NORMAL,
  /** @brief Input with pull-up resistor */
  GPIO_INPUT_MODE_PULL_UP,
  /** @brief Input with pull-down resistor */
  GPIO_INPUT_MODE_PULL_DOWN,
};

/**
 * @brief Output pin configuration
 */
enum GpioOutputMode {
  /** @brief Output is in push-pull configuration */
  GPIO_OUTPUT_MODE_PUSH_PULL,
  /** @brief Output is in open drain configuration */
  GPIO_OUTPUT_MODE_OPEN_DRAIN,
};

/**
 * @brief Pin change interrupt mode
 * 
 * @note All banks share the same external interrupt hardware. Pins with the
 * same number on different banks cannot share the same interrupt hardware
 */
enum GpioInterruptMode {
  /** @brief Interrupts disabled */
  GPIO_INTERRUPT_NONE,
  /** @brief Interrupt on falling edge */
  GPIO_INTERRUPT_FALLING,
  /** @brief Interrupt on rising edge */
  GPIO_INTERRUPT_RISING,
  /** @brief Interrupt on both falling and rising edge */
  GPIO_INTERRUPT_BOTH,
};

/**
 * @brief Callback type of function that will be called when a GPIO interrupt
 * is triggered
 * 
 * @param handle Pointer to the GpioHandle which triggered the interrupt
 * @param userData Void pointer passed onto the callback
 */
typedef void (*GpioInterruptCallback)(GpioHandle *handle, void *userData);

/**
 * @brief GPIO pin configuration
 */
typedef struct GpioConfig {
  /** @brief Pin mode */
  enum GpioMode mode;
  /** @brief Pull up/down configuration of input pin */
  enum GpioInputMode inputMode;
  /** @brief Output pin configuration */
  enum GpioOutputMode outputMode;
  /** @brief Pin change interrupt mode */
  enum GpioInterruptMode interruptMode;
  /** @brief Pin used for alternate functions */
  bool alternateFunction;
} GpioConfig;

// Include device specific structs
// must include GpioHandle struct
#include <device_gpio.h>

/**
 * @brief Initialize GPIO pin
 * 
 * @param handle Poiner to a valid pin handle
 * @param config Pointer to a valid configuration
 * @param bank Bank number
 * @param pin Pin number
 */
void gpioInit(GpioHandle *handle, GpioConfig *config, uint32_t bank,
              uint32_t pin);

/**
 * @brief Set the GPIO configuration of a pin
 * 
 * @param handle Pointer to a valid pin handle
 * @param config Pointer to a valid configuration
 */
void gpioSetConfig(GpioHandle *handle, GpioConfig *config);

/**
 * @brief Register a pin changed interrupt
 * 
 * @note Some devices need the GPIO_USE_INTERRUPTS macro to be defined
 * 
 * @param handle Pointer to a valid pin handle
 * @param callback Callback function to be called on a triggered interrupt
 * @param userData Void pointer passed onto the callback function
 */
void gpioRegisterInterruptCallback(GpioHandle volatile *handle,
                                   GpioInterruptCallback callback,
                                   void *userData);

/**
 * @brief Set digital output value of pin
 * 
 * @param handle Pointer to a valid pin handle
 * @param value Value to set the pin to (0 or non-0)
 */
void gpioSetDigital(GpioHandle *handle, uint32_t value);

/**
 * @brief Get the digital value of a pin
 * 
 * @param handle Pointer to a valid pin handle
 * @return uint32_t Value to the pin is at (0 or 1)
 */
uint32_t gpiogetDigital(GpioHandle *handle);

#endif // __H_HAL_GPIO
