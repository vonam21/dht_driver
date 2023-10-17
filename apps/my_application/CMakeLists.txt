cmake_minimum_required(VERSION 3.20.0)

set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR}/../../)
set(BOARD blue_pill)

list(APPEND EXTRA_ZEPHYR_MODULES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers
    )

list(APPEND SYSCALL_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers
    )
    
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(led_blink)

target_sources(app PRIVATE src/main.c)



