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

- [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/index.html)
- [Standard Toolchain Setup for Linux and macOS](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html)
- [ESP32 - DEBUGGING your ESP-IDF code using JTAG [VS CODE]](https://www.youtube.com/watch?v=uq93H7T7cOQ)
- [JTAG Debugging](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/jtag-debugging/index.html)
- [ESP32 WROOM, SOLO and WROVER Modules](https://docs.espressif.com/projects/esp-idf/en/v3.3/hw-reference/modules-and-boards.html#wroom-solo-and-wrover-modules)
