cmake_minimum_required(VERSION 3.12)

set(CMAKE_TOOLCHAIN_FILE cmake/TC-sdcc-msc51.cmake)

project(mcs51 C ASM)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

function(mcs51_add_hex exec)
    add_custom_target(${exec}.hex
        COMMAND packihx ${exec}.ihx > ${exec}.hex
        DEPENDS ${exec}
    )
endfunction(mcs51_add_hex)


add_subdirectory(delay)
add_subdirectory(blink)
add_subdirectory(timer)
