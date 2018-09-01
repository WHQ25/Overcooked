//
// Created by Hangqi Wu on 2018/8/30.
//

#ifndef TEST_OVERCOOKED_H
#define TEST_OVERCOOKED_H

#include "engine.h"

#define CHEF_SIZE_WIDTH 3
#define CHEF_SIZE_HEIGHT 3

#define COOKWARE_SIZE_WIDTH 3
#define COOKWARE_SIZE_HEIGHT 3

#define INGREDIENT_SIZE_WIDTH 1
#define INGREDIENT_SIZE_HEIGHT 1

#define STORAGE_SIZE_WIDTH 3
#define STORAGE_SIZE_HEIGHT 3

#define RECEIVER_SIZE_WIDTH 2
#define RECEIVER_SIZE_HEIGHT 2

#define ARROW_SIZE_WIDTH 6
#define ARROW_SIZE_HEIGHT 6

#define CHOPBOARD_STATE_NORMAL         0
#define CHOPBOARD_STATE_CHOPPING_LEFT  1
#define CHOPBOARD_STATE_CHOPPING_RIGHT 2

#define INGREDIENT_STATE_MASK_RAW     1 << 0
#define INGREDIENT_STATE_MASK_CHOPPED 1 << 1
#define INGREDIENT_STATE_MASK_COOKED  1 << 2

#define CHEF_STATE_MASK_SELECTED 1 << 0
#define CHEF_STATE_MASK_CHOPPING  1 << 1

#define CATEGORY_CHEF       1 << 0
#define CATEGORY_INGREDIENT 1 << 1
#define CATEGORY_COOKWARE   1 << 2
#define CATEGORY_STORAGE    1 << 3
#define CATEGORY_RECEIVER   1 << 4
#define CATEGORY_COUNTERTOP 1 << 5

uint8_t singlePixelShape(Direction d, uint16_t state, Coordinate cdt);
uint8_t fillFrameShape(Direction d, uint16_t state, Coordinate cdt);
uint8_t arrowShape(Direction d, uint16_t state, Coordinate cdt);
RGBColor whiteColorShading(Direction d, uint16_t state, Coordinate cdt);

uint8_t chefShape(Direction d, uint16_t state, Coordinate cdt);
RGBColor chefShading(Direction d, uint16_t state, Coordinate cdt);

uint8_t cookwareShape(Direction d, uint16_t state, Coordinate cdt);
RGBColor chopboardShading(Direction d, uint16_t state, Coordinate cdt);
RGBColor panShading(Direction d, uint16_t state, Coordinate cdt);

uint8_t ingredientStorageShape(Direction d, uint16_t state, Coordinate cdt);

RGBColor breadShading(Direction d, uint16_t state, Coordinate cdt);
RGBColor beefShading(Direction d, uint16_t state, Coordinate cdt);
RGBColor cheeseShading(Direction d, uint16_t state, Coordinate cdt);
RGBColor lettuceShading(Direction d, uint16_t state, Coordinate cdt);

uint8_t receiverShape(Direction d, uint16_t state, Coordinate cdt);
RGBColor breadReceiverShading(Direction d, uint16_t state, Coordinate cdt);
RGBColor beefReceiverShading(Direction d, uint16_t state, Coordinate cdt);
RGBColor cheeseReceiverShading(Direction d, uint16_t state, Coordinate cdt);
RGBColor lettuceReceiverShading(Direction d, uint16_t state, Coordinate cdt);


#endif //TEST_OVERCOOKED_H
