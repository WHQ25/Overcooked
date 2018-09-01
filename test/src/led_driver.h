//
// Created by Hangqi Wu on 2018/8/28.
//

#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "engine.h"

/**
 * Calculate camera coordinate from led matrix index.
 *
 * LED Matrix Spec:
 * 16 x 16 led matrix, start from top right corner wired in serial.
 * Camera's origin located in top left corner (led index 15)
 *
 * @param ledIndex: index of led
 * @param cam: camera
 * @return coordinate in camera
 */
Coordinate _calculateCameraCoordinate(int ledIndex, Coordinate camOffset);

void setColor(uint8_t *buf, uint8_t led, RGBColor color);

#define LED_NUM 256
#define DATA_LENGTH 768

extern void output_grb(uint8_t *buf, uint16_t count);

/**
 * Output to scene to led matrix
 * @param cam: camera
 */
void updateLEDMatrix(Camera cam, Coordinate offset);

#endif //LED_DRIVER_H
