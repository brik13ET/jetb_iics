cmake_minimum_required(VERSION 3.24)
project(iics_4 C)

set(CMAKE_C_STANDARD 11)

include_directories(src/Native)

add_library(iics_4 SHARED
        src/Native/impl.c)

include_directories(iics_4
        src/Native
        D:/jdks/openjdk-21.0.2/include
        D:/jdks/openjdk-21.0.2/include/win32
)
