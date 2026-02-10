cmake_minimum_required(VERSION 3.10)

project(HeatGuard)

add_executable(HeatGuard  
    src/main.cpp
    src/object.cpp
    src/alarm.cpp
    src/sensor.cpp)

target_include_directories(HeatGuard PRIVATE include)

