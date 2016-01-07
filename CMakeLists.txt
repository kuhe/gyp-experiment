cmake_minimum_required(VERSION 3.3)
project(gyp_experiment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        binding.cpp
        binding.gyp
        index.js
        package.json src/main.cpp)

add_executable(gyp_experiment ${SOURCE_FILES} src/main.cpp)