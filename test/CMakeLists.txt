cmake_minimum_required(VERSION 3.12)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp engine_test.cpp src/led_driver.h led_driver_test.cpp src/engine.c src/led_driver.c
        src/overcooked.c src/overcooked.h src/scene_tutorial_level_one.c src/scene_game_level_one.c)