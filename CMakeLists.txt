cmake_minimum_required(VERSION 3.12)

# pico_sdk_import.cmake is a single file copied from this SDK
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(rp2040_mouse VERSION 0.1.0)

# Initialize the SDK
pico_sdk_init()

set(FAMILY rp2040)
set(BOARD pico_sdk)

set(CONFIG_USING_LVGL       NO)
set(CONFIG_USING_TINYUSB    NO)

set(TINYUSB_FAMILY_PROJECT_NAME_PREFIX "tinyusb_dev_")

add_subdirectory("3rd-party/st7789_library_for_pico")

add_executable(rp2040_mouse
    src/main.c
)

target_include_directories(rp2040_mouse PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src
)

target_link_libraries(rp2040_mouse PRIVATE
    pico_st7789
    pico_stdlib
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


# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(rp2040_mouse)