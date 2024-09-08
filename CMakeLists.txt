cmake_minimum_required(VERSION 3.15)
project(booking)

# Include the Conan toolchain file
if (CMAKE_TOOLCHAIN_FILE)
    include(${CMAKE_TOOLCHAIN_FILE})
else()
    message(FATAL_ERROR "CMAKE_TOOLCHAIN_FILE is not set. Ensure that Conan is installed correctly and you are running CMake from the correct build directory.")
endif()

# Specify the include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Define sources and include directories
file(GLOB SOURCES
    src/*.cpp
)

file(GLOB HEADERS
    include/*.hpp
)

option(BUILD_SHARED_LIBS "Build shared libraries" ${BUILD_SHARED_LIBS})

# Add shared library option
add_library(booking ${SOURCES})

# Handle Windows export macro for shared libraries
if(WIN32 AND BUILD_SHARED_LIBS)
    target_compile_definitions(booking PRIVATE BOOKING_EXPORTS)
endif()

add_executable(booking_app main.cpp)

# Link libraries if necessary
target_link_libraries(booking_app booking)
