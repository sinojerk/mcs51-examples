list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

# the name of the target operating system
set(CMAKE_SYSTEM_NAME Generic)
# which compilers to use for C and C++
set(CMAKE_C_COMPILER sdcc)
set(CMAKE_CXX_COMPILER sdcc-c++-unsupported)
set(CMAKE_OBJCOPY sdobjcopy)
set(CMAKE_AR sdar)
set(CMAKE_NM sdnm)
set(CMAKE_RANLIB sdranlib)

set(CMAKE_ASM_COMPILER sdas8051)
set(CMAKE_ASM_COMPILER_ID "SDCC-8051")

set(CMAKE_C_FLAGS_INIT "")
SET(CMAKE_C_FLAGS "-mmcs51 --model-small")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --debug")
endif()


set(CMAKE_ASM_FLAGS_INIT "")
