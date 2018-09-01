//
// Created by Hangqi Wu on 2018/8/28.
//

#include "led_driver.h"

/**
 * Calculate camera coordinate from led matrix index.
 *
 * LED Matrix Spec:
 * 16 x 16 led matrix, start from top right corner wired in serial.
 * Camera's origin is located in camOffset of the led matrix.
 * example:
 *
 * | | | | | |
 * | | | | | |
 * | |X| | | |
 * | | | | | |
 * | | | | | |
 * camera's orgin located in X, then offset is (1, 2)
 *
 * @param ledIndex: index of led
 * @param cam: camera
 * @param camOffset: camera offset
 * @return coordinate in camera
 */
Coordinate _calculateCameraCoordinate(int ledIndex, Coordinate camOffset) {
#define LED_MATRIX_WIDTH 16
    int y = ledIndex / LED_MATRIX_WIDTH;
    int x;
    if (y % 2 == 0) {
        x = LED_MATRIX_WIDTH - (ledIndex % LED_MATRIX_WIDTH) - 1;
    } else {
        x = (ledIndex) % LED_MATRIX_WIDTH;
    }
    Coordinate co = {.x = x - camOffset.x, .y = y - camOffset.y};
    return co;
}

void setColor(uint8_t *buf, uint8_t led, RGBColor color) {
    uint16_t index = 3 * led;
    buf[index] = color.green;
    buf[index+1] = color.red;
    buf[index+2] = color.blue;
}


/**
 * Output to scene to led matrix
 * @param cam: camera
 * @param offset: camera offset
 */
void updateLEDMatrix(Camera cam, Coordinate offset) {
    static uint8_t buffer[DATA_LENGTH];
    RGBColor defaultColor = { .red = 0, .green = 0, .blue = 0 };
    for (int i = 0; i < LED_NUM; i++) {
        Coordinate camCoor = _calculateCameraCoordinate(i, offset);
        if (_isInFrame(cam.frame, camCoor)) {
            setColor(buffer, i, renderPoint(cam, camCoor));
        } else {
            setColor(buffer, i, defaultColor);
        }
    }
    output_grb(buffer, DATA_LENGTH);
}