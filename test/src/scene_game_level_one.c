//
// Created by Hangqi Wu on 2018/9/1.
//

#include <stdlib.h>
#include "overcooked.h"

extern uint16_t OneStarScore;
extern uint16_t TwoStarScore;
extern uint16_t ThreeStarScore;

extern Sprite *chefOne;
extern Sprite *chefTwo;

void setupGameLevelOneScene() {

    OneStarScore = 100;
    TwoStarScore = 200;
    ThreeStarScore = 300;

    Sprite *topWall = (Sprite *)malloc(sizeof(Sprite));
    topWall->frame.origin.x = 1;
    topWall->frame.origin.y = 0;
    topWall->frame.size.width = 15;
    topWall->frame.size.height = 1;
    topWall->priority = 1;
    topWall->category = CATEGORY_COUNTERTOP;
    topWall->shapeFct = &fillFrameShape;
    topWall->shadingFct = &whiteColorShading;
    scene_addSprite(topWall);

    Sprite *midWall = (Sprite *)malloc(sizeof(Sprite));
    midWall->frame.origin.x = 1;
    midWall->frame.origin.y = 8;
    midWall->frame.size.width = 15;
    midWall->frame.size.height = 1;
    midWall->priority = 1;
    midWall->category = CATEGORY_COUNTERTOP;
    midWall->shapeFct = &fillFrameShape;
    midWall->shadingFct = &whiteColorShading;
    scene_addSprite(midWall);

    Sprite *bottomWall = (Sprite *)malloc(sizeof(Sprite));
    bottomWall->frame.origin.x = 1;
    bottomWall->frame.origin.y = 15;
    bottomWall->frame.size.width = 15;
    bottomWall->frame.size.height = 1;
    bottomWall->priority = 1;
    bottomWall->category = CATEGORY_COUNTERTOP;
    bottomWall->shapeFct = &fillFrameShape;
    bottomWall->shadingFct = &whiteColorShading;
    scene_addSprite(bottomWall);

    Sprite *leftWall = (Sprite *)malloc(sizeof(Sprite));
    leftWall->frame.origin.x = 0;
    leftWall->frame.origin.y = 0;
    leftWall->frame.size.width = 1;
    leftWall->frame.size.height = 16;
    leftWall->priority = 1;
    leftWall->category = CATEGORY_COUNTERTOP;
    leftWall->shapeFct = &fillFrameShape;
    leftWall->shadingFct = &whiteColorShading;
    scene_addSprite(leftWall);

    Sprite *breadContainerSprite = (Sprite *)malloc(sizeof(Sprite));
    breadContainerSprite->frame.origin.x = 0;
    breadContainerSprite->frame.origin.y = 9;
    breadContainerSprite->frame.size.width = STORAGE_SIZE_WIDTH;
    breadContainerSprite->frame.size.height = STORAGE_SIZE_HEIGHT;
    breadContainerSprite->priority = 2;
    breadContainerSprite->category = CATEGORY_STORAGE;
    breadContainerSprite->facingDirection = right;
    breadContainerSprite->shapeFct = &ingredientStorageShape;
    breadContainerSprite->shadingFct = &breadShading;
    scene_addSprite(breadContainerSprite);

    Sprite *beefContainerSprite = (Sprite *)malloc(sizeof(Sprite));
    beefContainerSprite->frame.origin.x = 0;
    beefContainerSprite->frame.origin.y = 4;
    beefContainerSprite->frame.size.width = STORAGE_SIZE_WIDTH;
    beefContainerSprite->frame.size.height = STORAGE_SIZE_HEIGHT;
    beefContainerSprite->priority = 2;
    beefContainerSprite->category = CATEGORY_STORAGE;
    beefContainerSprite->facingDirection = right;
    beefContainerSprite->shapeFct = &ingredientStorageShape;
    beefContainerSprite->shadingFct = &beefShading;
    scene_addSprite(beefContainerSprite);

    Sprite *cheeseContainerSprite = (Sprite *)malloc(sizeof(Sprite));
    cheeseContainerSprite->frame.origin.x = 3;
    cheeseContainerSprite->frame.origin.y = 0;
    cheeseContainerSprite->frame.size.width = STORAGE_SIZE_WIDTH;
    cheeseContainerSprite->frame.size.height = STORAGE_SIZE_HEIGHT;
    cheeseContainerSprite->priority = 2;
    cheeseContainerSprite->category = CATEGORY_STORAGE;
    cheeseContainerSprite->facingDirection = down;
    cheeseContainerSprite->shapeFct = &ingredientStorageShape;
    cheeseContainerSprite->shadingFct = &cheeseShading;
    scene_addSprite(cheeseContainerSprite);

    Sprite *lettuceContainerSprite = (Sprite *)malloc(sizeof(Sprite));
    lettuceContainerSprite->frame.origin.x = 7;
    lettuceContainerSprite->frame.origin.y = 0;
    lettuceContainerSprite->frame.size.width = STORAGE_SIZE_WIDTH;
    lettuceContainerSprite->frame.size.height = STORAGE_SIZE_HEIGHT;
    lettuceContainerSprite->priority = 2;
    lettuceContainerSprite->category = CATEGORY_STORAGE;
    lettuceContainerSprite->facingDirection = down;
    lettuceContainerSprite->shapeFct = &ingredientStorageShape;
    lettuceContainerSprite->shadingFct = &lettuceShading;
    scene_addSprite(lettuceContainerSprite);

    Sprite *breadReceiverSprite = (Sprite *)malloc(sizeof(Sprite));
    breadReceiverSprite->frame.origin.x = 14;
    breadReceiverSprite->frame.origin.y = 0;
    breadReceiverSprite->frame.size.width = RECEIVER_SIZE_WIDTH;
    breadReceiverSprite->frame.size.height = RECEIVER_SIZE_HEIGHT;
    breadReceiverSprite->priority = 2;
    breadReceiverSprite->category = CATEGORY_RECEIVER;
    breadReceiverSprite->facingDirection = down;
    breadReceiverSprite->shapeFct = &receiverShape;
    breadReceiverSprite->shadingFct = &breadReceiverShading;
    scene_addSprite(breadReceiverSprite);

    Sprite *cheeseReceiverSprite = (Sprite *)malloc(sizeof(Sprite));
    cheeseReceiverSprite->frame.origin.x = 13;
    cheeseReceiverSprite->frame.origin.y = 0;
    cheeseReceiverSprite->frame.size.width = RECEIVER_SIZE_WIDTH;
    cheeseReceiverSprite->frame.size.height = RECEIVER_SIZE_HEIGHT;
    cheeseReceiverSprite->priority = 2;
    cheeseReceiverSprite->category = CATEGORY_RECEIVER;
    cheeseReceiverSprite->facingDirection = down;
    cheeseReceiverSprite->shapeFct = &receiverShape;
    cheeseReceiverSprite->shadingFct = &cheeseReceiverShading;
    scene_addSprite(cheeseReceiverSprite);

    Sprite *lettuceReceiverSprite = (Sprite *)malloc(sizeof(Sprite));
    lettuceReceiverSprite->frame.origin.x = 12;
    lettuceReceiverSprite->frame.origin.y = 0;
    lettuceReceiverSprite->frame.size.width = RECEIVER_SIZE_WIDTH;
    lettuceReceiverSprite->frame.size.height = RECEIVER_SIZE_HEIGHT;
    lettuceReceiverSprite->priority = 2;
    lettuceReceiverSprite->category = CATEGORY_RECEIVER;
    lettuceReceiverSprite->facingDirection = down;
    lettuceReceiverSprite->shapeFct = &receiverShape;
    lettuceReceiverSprite->shadingFct = &lettuceReceiverShading;
    scene_addSprite(lettuceReceiverSprite);

    Sprite *beefReceiverSprite = (Sprite *)malloc(sizeof(Sprite));
    beefReceiverSprite->frame.origin.x = 11;
    beefReceiverSprite->frame.origin.y = 0;
    beefReceiverSprite->frame.size.width = RECEIVER_SIZE_WIDTH;
    beefReceiverSprite->frame.size.height = RECEIVER_SIZE_HEIGHT;
    beefReceiverSprite->priority = 2;
    beefReceiverSprite->category = CATEGORY_RECEIVER;
    beefReceiverSprite->facingDirection = down;
    beefReceiverSprite->shapeFct = &receiverShape;
    beefReceiverSprite->shadingFct = &beefReceiverShading;
    scene_addSprite(beefReceiverSprite);

    Sprite *panSprite = (Sprite *)malloc(sizeof(Sprite));
    panSprite->frame.origin.x = 6;
    panSprite->frame.origin.y = 14;
    panSprite->frame.size.width = COOKWARE_SIZE_WIDTH;
    panSprite->frame.size.height = COOKWARE_SIZE_HEIGHT;
    panSprite->priority = 2;
    panSprite->category = CATEGORY_COOKWARE;
    panSprite->facingDirection = up;
    panSprite->shapeFct = &cookwareShape;
    panSprite->shadingFct = &panShading;
    scene_addSprite(panSprite);

    Sprite *chopboardSprite = (Sprite *)malloc(sizeof(Sprite));
    chopboardSprite->frame.origin.x = 11;
    chopboardSprite->frame.origin.y = 14;
    chopboardSprite->frame.size.width = COOKWARE_SIZE_WIDTH;
    chopboardSprite->frame.size.height = COOKWARE_SIZE_HEIGHT;
    chopboardSprite->priority = 2;
    chopboardSprite->category = CATEGORY_COOKWARE;
    chopboardSprite->facingDirection = up;
    chopboardSprite->state = MASK_NORMAL;
    chopboardSprite->shapeFct = &cookwareShape;
    chopboardSprite->shadingFct = &chopboardShading;
    scene_addSprite(chopboardSprite);

    Sprite *chef1Sprite = (Sprite *)malloc(sizeof(Sprite));
    chef1Sprite->frame.origin.x = 12;
    chef1Sprite->frame.origin.y = 4;
    chef1Sprite->frame.size.width = CHEF_SIZE_WIDTH;
    chef1Sprite->frame.size.height = CHEF_SIZE_HEIGHT;
    chef1Sprite->priority = 2;
    chef1Sprite->category = CATEGORY_CHEF;
    chef1Sprite->facingDirection = up;
    chef1Sprite->shapeFct = &chefShape;
    chef1Sprite->shadingFct = &chefShading;
    chef1Sprite->collisionMask = (CATEGORY_CHEF | CATEGORY_COOKWARE | CATEGORY_RECEIVER | CATEGORY_STORAGE);
    chef1Sprite->state = 0;
    scene_addSprite(chef1Sprite);

    Sprite *chef2Sprite = (Sprite *)malloc(sizeof(Sprite));
    chef2Sprite->frame.origin.x = 10;
    chef2Sprite->frame.origin.y = 10;
    chef2Sprite->frame.size.width = CHEF_SIZE_WIDTH;
    chef2Sprite->frame.size.height = CHEF_SIZE_HEIGHT;
    chef2Sprite->priority = 2;
    chef2Sprite->category = CATEGORY_CHEF;
    chef2Sprite->facingDirection = left;
    chef2Sprite->shapeFct = &chefShape;
    chef2Sprite->shadingFct = &chefShading;
    chef1Sprite->collisionMask = (CATEGORY_CHEF | CATEGORY_COOKWARE | CATEGORY_RECEIVER | CATEGORY_STORAGE);
    chef2Sprite->state = CHEF_STATE_MASK_SELECTED;
    scene_addSprite(chef2Sprite);

    chefOne = chef1Sprite;
    chefTwo = chef2Sprite;
}

