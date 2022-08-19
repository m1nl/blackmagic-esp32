# Black Magic Probe for ESP32

WiFi/USB capable version of the famous Black Magic Probe debugger. Based on firmware for [Flipper Zero WiFi dev board](https://github.com/flipperdevices/blackmagic-esp32-s2).

# Clone the Repository

Clone the repository with:
```shell
git clone --recursive https://github.com/m1nl/blackmagic-esp32.git
```

You must recursively clone the submodules, which `--recursive` will do for you. When you pull new changes, be sure to run `git submodule update --init --recursive`.

# Develop with ESP-IDF

Set up ESP-IDF following [Espressif's instructions](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html). Make sure `idf.py` is in your PATH and you can successfully run the program.

## Build with ESP-IDF

In your clone of this repository, run:
```shell
idf.py build
```
> Note: the `sdkconfig` file already configures the project to target the ESP32.

## Flash with ESP-IDF

Connect the dev board to your computer with a USB cable. Find the name of the serial port device on your computer that corresponds to the dev board. See the [Espressif's guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html) on how to find the port name.

Run:
```shell
idf.py -p <port> flash
```

## Test with ESP-IDF

Connect to the dev board with:
```shell
idf.py -p <port> monitor
```

You should not see errors in the logs if the firmware is installed and running correctly. 

# GPIO connections

SWCLK is GPIO25

SWDIO is GPIO26

Can be changed in file components/blackmagic/esp32-platform/platform.h
