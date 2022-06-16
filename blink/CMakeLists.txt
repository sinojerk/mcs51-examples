add_executable(blink blink.c)

target_link_libraries(blink PUBLIC delay)

target_include_directories(blink PUBLIC
    "${PROJECT_SOURCE_DIR}/delay"
)

mcs51_add_hex(blink)