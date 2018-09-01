//
// Created by Hangqi Wu on 2018/8/28.
//

#include "catch.hpp"

extern "C" {
#include "src/led_driver.h"
}

void output_grb(uint8_t *data, uint16_t count) {};

SCENARIO("Test _calculateCameraCoordinate(int ledIndex) function", "[led_driver]") {
    GIVEN("led index 0") {
        WHEN("camera offset (0, 0)") {
            Coordinate coor = _calculateCameraCoordinate(0, {.x = 0, .y = 0});
            REQUIRE(coor.x == 15);
            REQUIRE(coor.y == 0);
        }
        WHEN("camera offset is (1, 1)") {
            Coordinate coor = _calculateCameraCoordinate(0, {.x = 1, .y = 1});
            REQUIRE(coor.x == 14);
            REQUIRE(coor.y == -1);
        }
    }

    GIVEN("led index 15") {
        WHEN("camera offset (0, 0)") {
            Coordinate coor = _calculateCameraCoordinate(15, {.x = 0, .y = 0});
            REQUIRE(coor.x == 0);
            REQUIRE(coor.y == 0);
        }
        WHEN("camera offset is (1, 1)") {
            Coordinate coor = _calculateCameraCoordinate(15, {.x = 1, .y = 1});
            REQUIRE(coor.x == -1);
            REQUIRE(coor.y == -1);
        }
    }

    GIVEN("led index 16") {
        WHEN("camera offset (0, 0)") {
            Coordinate coor = _calculateCameraCoordinate(16, {.x = 0, .y = 0});
            REQUIRE(coor.x == 0);
            REQUIRE(coor.y == 1);
        }
        WHEN("camera offset is (1, 1)") {
            Coordinate coor = _calculateCameraCoordinate(16, {.x = 1, .y = 1});
            REQUIRE(coor.x == -1);
            REQUIRE(coor.y == 0);
        }
    }
}