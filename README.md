# Intro to FreeRTOS Using Espressif ESP32

The repository contains notes from [Digi-Key Introduction to RTOS online course](https://www.youtube.com/watch?v=JIr7Xm_riRs&list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz). Git branches represent different lessons.

## Getting Started

```bash
idf.py set-target esp32
idf.py menuconfig
```

### Troubleshooting

- Program upload failure

  - Hardware connection is not correct: run `idf.py -p PORT monitor`, and reboot your board to see if there are any output logs.
  - The baud rate for downloading is too high: lower your baud rate in the `menuconfig` menu, and try again.

## References

- [Introduction to RTOS Part 2 - Getting Started with FreeRTOS | Digi-Key Electronics](https://www.youtube.com/watch?v=JIr7Xm_riRs&list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz&index=2)
- [Passing a char* to ESP_LOGI (IDFGH-5697) #3069](https://github.com/espressif/esp-idf/issues/3069)
- [ESP32 Arduino: Passing a variable as argument of a FreeRTOS task](https://techtutorialsx.com/2017/05/07/esp32-arduino-passing-a-variable-as-argument-of-a-freertos-task/)
- [xTaskCreate](https://www.freertos.org/a00125.html)