/**
 * @file system.h
 * @author Joppe Blondel
 * @date 2023-07-10
 * @brief
 */
#ifndef __H_HAL_GPIO
#define __H_HAL_GPIO

#include <stdbool.h>
#include <stdint.h>

enum GpioInterruptMode {
  GPIO_INTERRUPT_NONE,
  GPIO_INTERRUPT_FALLING,
  GPIO_INTERRUPT_RISING,
  GPIO_INTERRUPT_BOTH,
};

enum GpioMode {
  GPIO_MODE_DIGITAL_OUTPUT,
  GPIO_MODE_DIGITAL_OUTPUT_FAST,
  GPIO_MODE_DIGITAL_INPUT,
  GPIO_MODE_ANALOG_INPUT,
};

enum GpioInputMode {
  GPIO_INPUT_MODE_NORMAL,
  GPIO_INPUT_MODE_PULL_UP,
  GPIO_INPUT_MODE_PULL_DOWN,
};

enum GpioOutputMode {
  GPIO_OUTPUT_MODE_PUSH_PULL,
  GPIO_OUTPUT_MODE_OPEN_DRAIN,
};

typedef struct GpioConfig {
  enum GpioInterruptMode interruptMode;
  enum GpioMode mode;
  enum GpioInputMode inputMode;
  enum GpioOutputMode outputMode;
  bool alternateFunction;
} GpioConfig;

typedef struct GpioHandle GpioHandle;

typedef void (*GpioInterruptCallback)(GpioHandle *handle, void *userData);

struct GpioHandle {
  uint32_t bank;
  uint32_t pin;
  GpioHandle *next;
  GpioInterruptCallback callback;
  void *userData;
};

void gpioInit(GpioHandle *handle, GpioConfig *config, uint32_t bank,
              uint32_t pin);
void gpioSetConfig(GpioHandle *handle, GpioConfig *config);
void gpioRegisterInterruptCallback(GpioHandle volatile *handle,
                                   GpioInterruptCallback callback,
                                   void *userData);
void gpioSetDigital(GpioHandle *handle, uint32_t value);
uint32_t gpiogetDigital(GpioHandle *handle);

#endif // __H_HAL_GPIO
