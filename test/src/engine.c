//
// Created by Hangqi Wu on 2018/8/28.
//

#include <stdlib.h>
#include <stdio.h>
#include "engine.h"

/**
 * Define global variables
 */
SpriteNode *rootNode;

/**
 * Convert a relative coordinate to absolute coordinate.
 * @param refPoint: reference point of given coordinate
 * @param coordinate: given coordinate
 * @return absolute coordinate
 */
Coordinate _toAbsoluteCoordinate(Coordinate refPoint, Coordinate coordinate) {
    Coordinate result;
    result.x = coordinate.x + refPoint.x;
    result.y = coordinate.y + refPoint.y;
    return result;
}


/**
 * Convert a absolute coordinate to relative coordinate.
 * @param refPoint: reference point
 * @param absCoordinate: absolute coordinate
 * @return coordinate relative to reference point
 */
Coordinate _toRelativeCoordinate(Coordinate refPoint, Coordinate absCoordinate) {
    Coordinate result;
    result.x = absCoordinate.x - refPoint.x;
    result.y = absCoordinate.y - refPoint.y;
    return result;
}


/**
 * Convert camera coordinate to sprite coordinate.
 * @param sprite: a sprite
 * @param cam: camera
 * @param camCoor: coordinate in camera's coordinate system
 * @return coordinate in sprite's coordinate system
 */
Coordinate _toSpriteCoordinate(Sprite sprite, Camera cam, Coordinate camCoor) {
    Coordinate absCoor = _toAbsoluteCoordinate(cam.frame.origin, camCoor);
    return _toRelativeCoordinate(sprite.frame.origin, absCoor);
}


/**
 * Check if a relative coordinate is in frame.
 * @param frame: frame
 * @param coordinate: relative coordinate
 * @return 1 if the point is in frame, 0 otherwise
 */
unsigned char _isInFrame(Rect frame, Coordinate coordinate) {
    if (coordinate.x < 0 || coordinate.y < 0 || coordinate.x > frame.size.width - 1 || coordinate.y > frame.size.height - 1) {
        return 0;
    } else {
        return 1;
    }
}


/**
 * Calculate color of a point in camera.
 * @param cam: camera
 * @param camCoor: coordinate of the point
 * @return RGBColor
 */
RGBColor renderPoint(Camera cam, Coordinate camCoor) {
    unsigned int currentPriority = 0;
    SpriteNode *currentNode = rootNode;
    RGBColor color = { .red = 0, .green = 0, .blue = 0 };
    while(currentNode) {
        Sprite currentSprite = *(currentNode->sprite);
        if (currentSprite.priority > currentPriority) {
            Coordinate spriteCoor = _toSpriteCoordinate(currentSprite, cam, camCoor);
            if (_isInFrame(currentSprite.frame, spriteCoor)) {
                Direction d = currentSprite.facingDirection;
                int s = currentSprite.state;
                if (currentSprite.shapeFct(d, s, spriteCoor)) {
                    color = currentSprite.shadingFct(d, s, spriteCoor);
                    currentPriority = currentSprite.priority;
                }
            }
        }
        currentNode = currentNode->next;
    }
    return color;
}


uint8_t checkCollision(Sprite *sprite, Direction direction, Coordinate origin) {
    SpriteNode *currentNode = rootNode;
    while(currentNode) {
        Sprite *currentSprite = currentNode->sprite;
        if (currentSprite != sprite) {
            if (sprite->collisionMask & currentSprite->category) {
                for (int x = 0; x < sprite->frame.size.width; x++) {
                    for (int y = 0; y < sprite->frame.size.height; y++) {
                        Coordinate reCoor = {.x = x, .y = y};
                        if (sprite->shapeFct(direction, sprite->state, reCoor)) {
                            Coordinate absCoor = _toAbsoluteCoordinate(origin, reCoor);
                            Coordinate currentCoor = _toRelativeCoordinate(currentSprite->frame.origin, absCoor);
                            if (currentSprite->shapeFct(currentSprite->facingDirection, currentSprite->state, currentCoor)) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
        currentNode = currentNode->next;
    }
    return 0;
}


/**
 * Initialize your scene.
 */
void scene_init() {
    rootNode = (SpriteNode *)malloc(sizeof(SpriteNode));
    rootNode->sprite = NULL;
    rootNode->next = NULL;
}

/**
 * Add a sprite to your scene.
 * @param sprite
 */
void scene_addSprite(Sprite *sprite) {
    SpriteNode *currentNode = rootNode;
    if (currentNode->sprite == NULL) {
        currentNode->sprite = sprite;
    } else {
        SpriteNode *newNode = (SpriteNode *)malloc(sizeof(SpriteNode));
        newNode->sprite = sprite;
        newNode->next = NULL;
        while(currentNode->next) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

/**
 * Remove a sprite from scene.
 * @param sprite
 */
void scene_removeSprite(Sprite *sprite) {
    SpriteNode *currentNode = rootNode;
    SpriteNode *prev = NULL;
    SpriteNode *temp;
    while(currentNode) {
        if (currentNode->sprite == sprite) {
            free(sprite);
            if (currentNode == rootNode) {
                if (rootNode->next != NULL) {
                    rootNode = rootNode->next;
                } else {
                    rootNode->sprite = NULL;
                }
                break;
            } else {
                temp = currentNode;
                prev->next = currentNode->next;
                free(temp);
                break;
            }
        } else {
            prev = currentNode;
            currentNode = currentNode->next;
        }
    }
}

/**
 * Free current scene memory
 */
void scene_destory() {
    SpriteNode *currentNode = rootNode;
    while(currentNode) {
        if (currentNode->sprite) {
            free(currentNode->sprite);
        }
        SpriteNode *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
}

