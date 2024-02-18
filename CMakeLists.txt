cmake_minimum_required(VERSION 3.24)
project(iics_4 C)

set(CMAKE_C_STANDARD 11)

include_directories(src/Native)

find_package(JNI)

if (JNI_FOUND)
	message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
	message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()


add_library(iics_4 SHARED
        src/Native/impl.c
        )
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
link_directories(
        "${JNI_LIBRARIES}"
)

include_directories(
        src/Native
        "${JNI_INCLUDE_DIRS}"
)
