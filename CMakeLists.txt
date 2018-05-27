cmake_minimum_required(VERSION 3.6)
project(drivers)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(../Logger/include)

link_directories(cmake-build-debug)
link_directories(../Logger/cmake-build-debug)

add_library(gpio
        src/devices/core/interfacing/memory/mapmem.c
        src/devices/core/interfacing/memory/gpio/gpio_mem.c
        src/devices/core/interfacing/memory/gpio/GPIOMemoryDevice.cpp
        src/devices/core/interfacing/sysfs/gpio/gpio_sysfs.c
        src/devices/core/interfacing/sysfs/gpio/GPIOSYSFSDevice.cpp
        src/devices/core/Device.cpp
        src/devices/core/GPIODevice.cpp)

add_library(i2c
        src/devices/core/Device.cpp
        src/devices/core/I2CDevice.cpp)

add_library(ip
        src/devices/core/Device.cpp
        src/devices/core/IPDevice.cpp)

add_library(onewire
        src/devices/core/Device.cpp
        src/devices/core/OneWireDevice.cpp
        src/devices/core/interfacing/sysfs/onewire/OneWireSYSFSDevice.cpp)

add_library(serial
        src/devices/core/Device.cpp
        src/devices/core/SerialDevice.cpp)

add_library(spi
        src/devices/core/Device.cpp
        src/devices/core/SPIDevice.cpp)

target_link_libraries(spi liblogger.a)

add_library(bcm2835
        src/chipsets/bcm2835/bcm2835_mem.c)

target_link_libraries(bcm2835 libgpio.a)

add_library(ds18b20
        src/devices/environment/temperature/thermometers/DS18B20.cpp)

target_link_libraries(ds18b20 libonewire.a)
