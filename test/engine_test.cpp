//
// Created by Hangqi Wu on 2018/8/26.
//

#include "catch.hpp"
#include <iostream>

extern "C" {
#include "src/engine.h"
}

uint8_t squareShape(Direction d, uint16_t state, Coordinate coor) {
    return 1;
}

RGBColor whiteColorShading(Direction d, uint16_t state, Coordinate coor) {
    RGBColor color = {.red = 255, .green = 255, .blue = 255};
    return color;
}

RGBColor blueColorShading(Direction d, uint16_t state, Coordinate coor) {
    RGBColor color = {.red = 0, .green = 0, .blue = 255};
    return color;
}

RGBColor redColorShading(Direction d, uint16_t state, Coordinate coor) {
    RGBColor color = {.red = 255, .green = 0, .blue = 0};
    return color;
}

RGBColor greenColorShading(Direction d, uint16_t state, Coordinate coor) {
    RGBColor color = {.red = 0, .green = 255, .blue = 0};
    return color;
}

bool sameColor(RGBColor color, uint8_t r, uint8_t g, uint8_t b) {
    return (color.red == r && color.green == g && color.blue == b);
}

Sprite *testWhiteSquare;
Sprite *testRedSquare;
Sprite *testBlueSquare;

void setupScene() {
    Sprite *whiteSquare = (Sprite *)malloc(sizeof(Sprite));
    whiteSquare->frame.origin.x = 0;
    whiteSquare->frame.origin.y = 0;
    whiteSquare->frame.size.width = 5;
    whiteSquare->frame.size.height = 5;
    whiteSquare->priority = 1;
    whiteSquare->shapeFct = &squareShape;
    whiteSquare->shadingFct = &whiteColorShading;
    scene_addSprite(whiteSquare);
    testWhiteSquare = whiteSquare;

    Sprite *redSquare = (Sprite *)malloc(sizeof(Sprite));
    redSquare->frame.origin.x = 1;
    redSquare->frame.origin.y = 1;
    redSquare->frame.size.width = 4;
    redSquare->frame.size.height = 4;
    redSquare->priority = 2;
    redSquare->shapeFct = &squareShape;
    redSquare->shadingFct = &redColorShading;
    scene_addSprite(redSquare);
    testRedSquare = redSquare;

    Sprite *greenSquare = (Sprite *)malloc(sizeof(Sprite));
    greenSquare->frame.origin.x = 2;
    greenSquare->frame.origin.y = 2;
    greenSquare->frame.size.width = 3;
    greenSquare->frame.size.height = 3;
    greenSquare->priority = 3;
    greenSquare->shapeFct = &squareShape;
    greenSquare->shadingFct = &greenColorShading;
    scene_addSprite(greenSquare);

    Sprite *blueSquare = (Sprite *)malloc(sizeof(Sprite));
    blueSquare->frame.origin.x = 3;
    blueSquare->frame.origin.y = 3;
    blueSquare->frame.size.width = 2;
    blueSquare->frame.size.height = 2;
    blueSquare->priority = 4;
    blueSquare->shapeFct = &squareShape;
    blueSquare->shadingFct = &blueColorShading;
    scene_addSprite(blueSquare);
    testBlueSquare = blueSquare;
}


SCENARIO("Test game engine render function", "[engine]") {
    GIVEN("5 x 5 camera and 4 square shaped sprites") {
        scene_init();
        setupScene();

        Camera cam;
        cam.frame.size.height = 5;
        cam.frame.size.width = 5;

        WHEN("camera positioned at (0, 0)") {
            cam.frame.origin.x = 0;
            cam.frame.origin.y = 0;
            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 0}), 255, 255, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 0}), 255, 255, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 0}), 255, 255, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 0}), 255, 255, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 0}), 255, 255, 255));

            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 1}), 255, 255, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 1}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 1}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 1}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 1}), 255, 0, 0));

            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 2}), 255, 255, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 2}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 2}), 0, 255, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 2}), 0, 255, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 2}), 0, 255, 0));

            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 3}), 255, 255, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 3}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 3}), 0, 255, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 3}), 0, 0, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 3}), 0, 0, 255));

            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 4}), 255, 255, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 4}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 4}), 0, 255, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 4}), 0, 0, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 4}), 0, 0, 255));
            scene_destory();
        }

        WHEN("camera move to (1, 1)") {
            cam.frame.origin.x = 1;
            cam.frame.origin.y = 1;

            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 0}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 0}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 0}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 0}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 0}), 0, 0, 0));

            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 1}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 1}), 0, 255, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 1}), 0, 255, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 1}), 0, 255, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 1}), 0, 0, 0));

            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 2}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 2}), 0, 255, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 2}), 0, 0, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 2}), 0, 0, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 2}), 0, 0, 0));

            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 3}), 255, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 3}), 0, 255, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 3}), 0, 0, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 3}), 0, 0, 255));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 3}), 0, 0, 0));

            REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 4}), 0, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 4}), 0, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 4}), 0, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 4}), 0, 0, 0));
            REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 4}), 0, 0, 0));
            scene_destory();
        }
    }
}

SCENARIO("Test remove sprite function", "[engine]") {
    GIVEN("simple 4 square sprites and 5x5 camera located at (0, 0)") {
        scene_init();
        setupScene();

        Camera cam;
        cam.frame.size.height = 5;
        cam.frame.size.width = 5;
        cam.frame.origin.x = 0;
        cam.frame.origin.y = 0;

        WHEN("remove whiteSquare sprite") {
            scene_removeSprite(testWhiteSquare);

            THEN("All white pixel should disappear") {
                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 0}), 0, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 0}), 0, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 0}), 0, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 0}), 0, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 0}), 0, 0, 0));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 1}), 0, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 1}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 1}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 1}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 1}), 255, 0, 0));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 2}), 0, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 2}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 2}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 2}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 2}), 0, 255, 0));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 3}), 0, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 3}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 3}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 3}), 0, 0, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 3}), 0, 0, 255));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 4}), 0, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 4}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 4}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 4}), 0, 0, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 4}), 0, 0, 255));
                scene_destory();
            }
        }

        WHEN("remove redSquare sprite") {
            scene_removeSprite(testRedSquare);

            THEN("all red pixel should replaced by white pixel") {
                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 0}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 0}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 0}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 0}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 0}), 255, 255, 255));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 1}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 1}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 1}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 1}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 1}), 255, 255, 255));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 2}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 2}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 2}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 2}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 2}), 0, 255, 0));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 3}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 3}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 3}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 3}), 0, 0, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 3}), 0, 0, 255));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 4}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 4}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 4}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 4}), 0, 0, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 4}), 0, 0, 255));
                scene_destory();
            }
        }

        WHEN("remove blueSquare sprite") {
            scene_removeSprite(testBlueSquare);

            THEN("all blue pixel should replaced by green pixel") {
                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 0}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 0}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 0}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 0}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 0}), 255, 255, 255));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 1}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 1}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 1}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 1}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 1}), 255, 0, 0));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 2}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 2}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 2}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 2}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 2}), 0, 255, 0));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 3}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 3}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 3}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 3}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 3}), 0, 255, 0));

                REQUIRE(sameColor(renderPoint(cam, {.x = 0, .y = 4}), 255, 255, 255));
                REQUIRE(sameColor(renderPoint(cam, {.x = 1, .y = 4}), 255, 0, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 2, .y = 4}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 3, .y = 4}), 0, 255, 0));
                REQUIRE(sameColor(renderPoint(cam, {.x = 4, .y = 4}), 0, 255, 0));
                scene_destory();
            }
        }
    }
}

