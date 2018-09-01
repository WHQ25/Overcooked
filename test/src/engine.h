//
// Created by Hangqi Wu on 2018/8/22.
//

#ifndef ENGINE_H
#define ENGINE_H

#include <stdint.h>

typedef struct _Coordinate {
    int x;
    int y;
} Coordinate;

typedef struct _RGBColor {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} RGBColor;

typedef struct _Size {
    unsigned int width;
    unsigned int height;
} Size;

typedef struct _Rect {
    Coordinate origin;
    Size size;
} Rect;

typedef enum _Direction {
    up, down, left, right
} Direction;

/**
 * Sprite is the basic element of the game. Everything is a sprite.
 */
typedef struct _Sprite {
    Rect frame;
    Direction facingDirection;
    uint16_t state;
    /**
     * If two sprites are overlapping, sprites with higher priority
     * will be drawn.
     */
    unsigned int priority;
    /**
     * Support up to 32 categories.
     */
    unsigned long category;
    unsigned long collisionMask;
    /**
     * shapeFct determines the shape of a sprite.
     * @param direction
     * @param state
     * @param cdt: coordinate of a pixel
     * @return non-zero if the pixel at cdt is part of the sprite,
     *         zero otherwise
     */
    uint8_t (*shapeFct)(Direction direction, uint16_t state, Coordinate cdt);
    /**
     * The shadingFct determines the look of a sprite.
     * This function will be called only when shapeFct at cdt
     * return non-zero
     *
     * @param direction
     * @param state
     * @param cdt: coordinate of a point in frame
     * @return RGBColor of pixel at cdt
     */
    RGBColor (*shadingFct)(Direction direction, uint16_t state, Coordinate cdt);
} Sprite;

typedef struct _SpriteNode {
    Sprite *sprite;
    struct _SpriteNode *next;
} SpriteNode;

typedef struct _Camera {
    Rect frame;
} Camera;

/**
 * Convert a relative coordinate to absolute coordinate.
 * @param refPoint: reference point of given coordinate
 * @param coordinate: given coordinate
 * @return absolute coordinate
 */
Coordinate _toAbsoluteCoordinate(Coordinate refPoint, Coordinate coordinate);


/**
 * Convert a absolute coordinate to relative coordinate.
 * @param refPoint: reference point
 * @param absCoordinate: absolute coordinate
 * @return coordinate relative to reference point
 */
Coordinate _toRelativeCoordinate(Coordinate refPoint, Coordinate absCoordinate);


/**
 * Convert camera coordinate to sprite coordinate.
 * @param sprite: a sprite
 * @param cam: camera
 * @param camCoor: coordinate in camera's coordinate system
 * @return coordinate in sprite's coordinate system
 */
Coordinate _toSpriteCoordinate(Sprite sprite, Camera cam, Coordinate camCoor);


/**
 * Check if a relative coordinate is in frame.
 * @param frame: frame
 * @param coordinate: relative coordinate
 * @return 1 if the point is in frame, 0 otherwise
 */
unsigned char _isInFrame(Rect frame, Coordinate coordinate);


/**
 * Calculate color of a point in camera.
 * @param cam: camera
 * @param camCoor: coordinate of the point
 * @param root: root spriteNode
 * @return RGBColor
 */
RGBColor renderPoint(Camera cam, Coordinate camCoor);


/**
 * Check collision for new direction and new origin.
 *
 * @param sprite
 * @param direction
 * @param origin
 * @return
 */
uint8_t checkCollision(Sprite *sprite, Direction direction, Coordinate origin);

/**
 * Initialize your scene.
 */
void scene_init();

/**
 * Add a new sprite to scene.
 * @param sprite
 */
void scene_addSprite(Sprite *sprite);

/**
 * Remove a sprite from scene.
 * @param sprite
 */
void scene_removeSprite(Sprite *sprite);

/**
 * Free current scene memory
 */
void scene_destory();


/**
 * Global variables
 */
extern SpriteNode *rootNode;


#endif //ENGINE_H
