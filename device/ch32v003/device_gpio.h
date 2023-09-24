#ifndef __H_DEVICE_GPIO
#define __H_DEVICE_GPIO

struct GpioHandle {
  uint32_t bank;
  uint32_t pin;
  GpioHandle *next;
  GpioInterruptCallback callback;
  void *userData;
};

#endif // __H_DEVICE_GPIO
