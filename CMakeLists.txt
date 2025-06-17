cmake_minimum_required(VERSION 3.13)
#include the sdk
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
#Project name and language
project(Traffic_light C CXX ASM)
#Set c and c++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
#include Pico SDK
pico_sdk_init()
#Create the executable
add_executable(Traffic_light Lcd.c Sevensegment.c main.c)
#Link libraries
target_link_libraries(Traffic_light pico_stdlib)
#Add extra build outputs(like .uf2 file)
pico_add_extra_outputs(Traffic_light)
