cmake_minimum_required(VERSION 3.12)

# pico_sdk_import.cmake is a single file copied from this SDK
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(rp2040_mouse VERSION 0.1.0)

# Set custom board header.
# set(ENV{PICO_BOARD_HEADER_DIRS} ${CMAKE_CURRENT_LIST_DIR}/src/boards)
# set(ENV{PICO_BOARD_CMAKE_DIRS} ${CMAKE_CURRENT_LIST_DIR}/src/boards)

set(PICO_BOARD gamekit_rp2040)

# Initialize the SDK
pico_sdk_init()


set(CONFIG_USING_LVGL       NO)
set(CONFIG_USING_TINYUSB    NO)

add_subdirectory("3rd-party/st7789_library_for_pico")

set(SOURCES src/main.c
            src/bsp_button.c
            3rd-party/MultiButton/multi_button.c
)

if (${CONFIG_USING_TINYUSB})
    set(TINYUSB_FAMILY_PROJECT_NAME_PREFIX "tinyusb_dev_")
    list(APPEND SOURCES src/usb_descriptors.c)
endif()

add_executable(rp2040_mouse ${SOURCES} )

# src/usb_descriptors.c

target_include_directories(rp2040_mouse PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src
    ${CMAKE_CURRENT_LIST_DIR}/3rd-party/MultiButton
)

target_link_libraries(rp2040_mouse PRIVATE
    pico_st7789
    pico_stdlib
    hardware_adc
)

if (${CONFIG_USING_LVGL})
    message("Using lvgl submodule!")
    add_subdirectory("3rd-party/lvgl")
    target_link_libraries(rp2040_mouse PRIVATE lvgl)
endif()

if (${CONFIG_USING_TINYUSB})
    message("Using tinyusb submodule!")
    add_subdirectory(${PICO_TINYUSB_PATH}/examples/device tinyusb_device_examples)
    target_link_libraries(rp2040_mouse PRIVATE tinyusb_device tinyusb_board)
endif()

pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(rp2040_mouse)