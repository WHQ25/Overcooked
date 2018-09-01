//
// Created by Hangqi Wu on 2018/8/30.
//

#include <stdlib.h>
#include "overcooked.h"


void setupTutorialLevelOneScene() {
    Sprite *breadContainerSprite = (Sprite *)malloc(sizeof(Sprite));
    breadContainerSprite->frame.origin.x = 1;
    breadContainerSprite->frame.origin.y = 4;
    breadContainerSprite->frame.size.width = STORAGE_SIZE_WIDTH;
    breadContainerSprite->frame.size.height = STORAGE_SIZE_HEIGHT;
    breadContainerSprite->priority = 2;
    breadContainerSprite->facingDirection = right;
    breadContainerSprite->shapeFct = &ingredientStorageShape;
    breadContainerSprite->shadingFct = &breadShading;
    scene_addSprite(breadContainerSprite);

    Sprite *breadSprite = (Sprite *)malloc(sizeof(Sprite));
    breadSprite->frame.origin.x = 4;
    breadSprite->frame.origin.y = 5;
    breadSprite->frame.size.width = INGREDIENT_SIZE_WIDTH;
    breadSprite->frame.size.height = INGREDIENT_SIZE_HEIGHT;
    breadSprite->priority = 3;
    breadSprite->facingDirection = right;
    breadSprite->shapeFct = &singlePixelShape;
    breadSprite->shadingFct = &breadShading;
    scene_addSprite(breadSprite);

    Sprite *arrow1Sprite = (Sprite *)malloc(sizeof(Sprite));
    arrow1Sprite->frame.origin.x = 6;
    arrow1Sprite->frame.origin.y = 3;
    arrow1Sprite->frame.size.width = ARROW_SIZE_WIDTH;
    arrow1Sprite->frame.size.height = ARROW_SIZE_HEIGHT;
    arrow1Sprite->priority = 2;
    arrow1Sprite->facingDirection = right;
    arrow1Sprite->shapeFct = &arrowShape;
    arrow1Sprite->shadingFct = &whiteColorShading;
    scene_addSprite(arrow1Sprite);

    Sprite *breadReceiverSprite = (Sprite *)malloc(sizeof(Sprite));
    breadReceiverSprite->frame.origin.x = 14;
    breadReceiverSprite->frame.origin.y = 4;
    breadReceiverSprite->frame.size.width = RECEIVER_SIZE_WIDTH;
    breadReceiverSprite->frame.size.height = RECEIVER_SIZE_HEIGHT;
    breadReceiverSprite->priority = 2;
    breadReceiverSprite->facingDirection = down;
    breadReceiverSprite->shapeFct = &receiverShape;
    breadReceiverSprite->shadingFct = &breadReceiverShading;
    scene_addSprite(breadReceiverSprite);

    Sprite *lettuceContainerSprite = (Sprite *)malloc(sizeof(Sprite));
    lettuceContainerSprite->frame.origin.x = 17;
    lettuceContainerSprite->frame.origin.y = 2;
    lettuceContainerSprite->frame.size.width = STORAGE_SIZE_WIDTH;
    lettuceContainerSprite->frame.size.height = STORAGE_SIZE_HEIGHT;
    lettuceContainerSprite->priority = 2;
    lettuceContainerSprite->facingDirection = down;
    lettuceContainerSprite->shapeFct = &ingredientStorageShape;
    lettuceContainerSprite->shadingFct = &lettuceShading;
    scene_addSprite(lettuceContainerSprite);

    Sprite *rawLettuceSprite = (Sprite *)malloc(sizeof(Sprite));
    rawLettuceSprite->frame.origin.x = 18;
    rawLettuceSprite->frame.origin.y = 5;
    rawLettuceSprite->frame.size.width = INGREDIENT_SIZE_WIDTH;
    rawLettuceSprite->frame.size.height = INGREDIENT_SIZE_HEIGHT;
    rawLettuceSprite->priority = 3;
    rawLettuceSprite->shapeFct = &singlePixelShape;
    rawLettuceSprite->shadingFct = &lettuceShading;
    rawLettuceSprite->state = INGREDIENT_STATE_MASK_RAW;
    scene_addSprite(rawLettuceSprite);

    Sprite *chopboardSprite = (Sprite *)malloc(sizeof(Sprite));
    chopboardSprite->frame.origin.x = 17;
    chopboardSprite->frame.origin.y = 7;
    chopboardSprite->frame.size.width = COOKWARE_SIZE_WIDTH;
    chopboardSprite->frame.size.height = COOKWARE_SIZE_HEIGHT;
    chopboardSprite->priority = 2;
    chopboardSprite->facingDirection = up;
    chopboardSprite->state = 1;
    chopboardSprite->shapeFct = &cookwareShape;
    chopboardSprite->shadingFct = &chopboardShading;
    scene_addSprite(chopboardSprite);

    Sprite *arrow2Sprite = (Sprite *)malloc(sizeof(Sprite));
    arrow2Sprite->frame.origin.x = 22;
    arrow2Sprite->frame.origin.y = 3;
    arrow2Sprite->frame.size.width = ARROW_SIZE_WIDTH;
    arrow2Sprite->frame.size.height = ARROW_SIZE_HEIGHT;
    arrow2Sprite->priority = 2;
    arrow2Sprite->facingDirection = right;
    arrow2Sprite->shapeFct = &arrowShape;
    arrow2Sprite->shadingFct = &whiteColorShading;
    scene_addSprite(arrow2Sprite);

    Sprite *lettuceReceiverSprite = (Sprite *)malloc(sizeof(Sprite));
    lettuceReceiverSprite->frame.origin.x = 30;
    lettuceReceiverSprite->frame.origin.y = 3;
    lettuceReceiverSprite->frame.size.width = RECEIVER_SIZE_WIDTH;
    lettuceReceiverSprite->frame.size.height = RECEIVER_SIZE_HEIGHT;
    lettuceReceiverSprite->priority = 2;
    lettuceReceiverSprite->facingDirection = down;
    lettuceReceiverSprite->shapeFct = &receiverShape;
    lettuceReceiverSprite->shadingFct = &lettuceReceiverShading;
    scene_addSprite(lettuceReceiverSprite);

    Sprite *choppedLettuceSprite = (Sprite *)malloc(sizeof(Sprite));
    choppedLettuceSprite->frame.origin.x = 30;
    choppedLettuceSprite->frame.origin.y = 6;
    choppedLettuceSprite->frame.size.width = INGREDIENT_SIZE_WIDTH;
    choppedLettuceSprite->frame.size.height = INGREDIENT_SIZE_HEIGHT;
    choppedLettuceSprite->priority = 3;
    choppedLettuceSprite->shapeFct = &singlePixelShape;
    choppedLettuceSprite->shadingFct = &lettuceShading;
    choppedLettuceSprite->state = INGREDIENT_STATE_MASK_CHOPPED;
    scene_addSprite(choppedLettuceSprite);

    Sprite *cheeseContainerSprite = (Sprite *)malloc(sizeof(Sprite));
    cheeseContainerSprite->frame.origin.x = 33;
    cheeseContainerSprite->frame.origin.y = 2;
    cheeseContainerSprite->frame.size.width = STORAGE_SIZE_WIDTH;
    cheeseContainerSprite->frame.size.height = STORAGE_SIZE_HEIGHT;
    cheeseContainerSprite->priority = 2;
    cheeseContainerSprite->facingDirection = down;
    cheeseContainerSprite->shapeFct = &ingredientStorageShape;
    cheeseContainerSprite->shadingFct = &cheeseShading;
    scene_addSprite(cheeseContainerSprite);

    Sprite *rawCheeseSprite = (Sprite *)malloc(sizeof(Sprite));
    rawCheeseSprite->frame.origin.x = 34;
    rawCheeseSprite->frame.origin.y = 5;
    rawCheeseSprite->frame.size.width = INGREDIENT_SIZE_WIDTH;
    rawCheeseSprite->frame.size.height = INGREDIENT_SIZE_HEIGHT;
    rawCheeseSprite->priority = 3;
    rawCheeseSprite->shapeFct = &singlePixelShape;
    rawCheeseSprite->shadingFct = &cheeseShading;
    rawCheeseSprite->state = INGREDIENT_STATE_MASK_RAW;
    scene_addSprite(rawCheeseSprite);

    Sprite *chopboard1Sprite = (Sprite *)malloc(sizeof(Sprite));
    chopboard1Sprite->frame.origin.x = 33;
    chopboard1Sprite->frame.origin.y = 7;
    chopboard1Sprite->frame.size.width = COOKWARE_SIZE_WIDTH;
    chopboard1Sprite->frame.size.height = COOKWARE_SIZE_HEIGHT;
    chopboard1Sprite->priority = 2;
    chopboard1Sprite->facingDirection = up;
    chopboard1Sprite->state = 1;
    chopboard1Sprite->shapeFct = &cookwareShape;
    chopboard1Sprite->shadingFct = &chopboardShading;
    scene_addSprite(chopboard1Sprite);

    Sprite *arrow3Sprite = (Sprite *)malloc(sizeof(Sprite));
    arrow3Sprite->frame.origin.x = 38;
    arrow3Sprite->frame.origin.y = 3;
    arrow3Sprite->frame.size.width = ARROW_SIZE_WIDTH;
    arrow3Sprite->frame.size.height = ARROW_SIZE_HEIGHT;
    arrow3Sprite->priority = 2;
    arrow3Sprite->facingDirection = right;
    arrow3Sprite->shapeFct = &arrowShape;
    arrow3Sprite->shadingFct = &whiteColorShading;
    scene_addSprite(arrow3Sprite);

    Sprite *cheeseReceiverSprite = (Sprite *)malloc(sizeof(Sprite));
    cheeseReceiverSprite->frame.origin.x = 46;
    cheeseReceiverSprite->frame.origin.y = 3;
    cheeseReceiverSprite->frame.size.width = RECEIVER_SIZE_WIDTH;
    cheeseReceiverSprite->frame.size.height = RECEIVER_SIZE_HEIGHT;
    cheeseReceiverSprite->priority = 2;
    cheeseReceiverSprite->facingDirection = down;
    cheeseReceiverSprite->shapeFct = &receiverShape;
    cheeseReceiverSprite->shadingFct = &cheeseReceiverShading;
    scene_addSprite(cheeseReceiverSprite);

    Sprite *choppedCheeseSprite = (Sprite *)malloc(sizeof(Sprite));
    choppedCheeseSprite->frame.origin.x = 46;
    choppedCheeseSprite->frame.origin.y = 6;
    choppedCheeseSprite->frame.size.width = INGREDIENT_SIZE_WIDTH;
    choppedCheeseSprite->frame.size.height = INGREDIENT_SIZE_HEIGHT;
    choppedCheeseSprite->priority = 3;
    choppedCheeseSprite->shapeFct = &singlePixelShape;
    choppedCheeseSprite->shadingFct = &cheeseShading;
    choppedCheeseSprite->state = INGREDIENT_STATE_MASK_CHOPPED;
    scene_addSprite(choppedCheeseSprite);

    Sprite *beefContainerSprite = (Sprite *)malloc(sizeof(Sprite));
    beefContainerSprite->frame.origin.x = 49;
    beefContainerSprite->frame.origin.y = 1;
    beefContainerSprite->frame.size.width = STORAGE_SIZE_WIDTH;
    beefContainerSprite->frame.size.height = STORAGE_SIZE_HEIGHT;
    beefContainerSprite->priority = 2;
    beefContainerSprite->facingDirection = down;
    beefContainerSprite->shapeFct = &ingredientStorageShape;
    beefContainerSprite->shadingFct = &beefShading;
    scene_addSprite(beefContainerSprite);

    Sprite *rawBeefSprite = (Sprite *)malloc(sizeof(Sprite));
    rawBeefSprite->frame.origin.x = 50;
    rawBeefSprite->frame.origin.y = 4;
    rawBeefSprite->frame.size.width = INGREDIENT_SIZE_WIDTH;
    rawBeefSprite->frame.size.height = INGREDIENT_SIZE_HEIGHT;
    rawBeefSprite->priority = 3;
    rawBeefSprite->facingDirection = down;
    rawBeefSprite->shapeFct = &singlePixelShape;
    rawBeefSprite->shadingFct = &beefShading;
    rawBeefSprite->state = INGREDIENT_STATE_MASK_RAW;
    scene_addSprite(rawBeefSprite);

    Sprite *chopboard2Sprite = (Sprite *)malloc(sizeof(Sprite));
    chopboard2Sprite->frame.origin.x = 49;
    chopboard2Sprite->frame.origin.y = 6;
    chopboard2Sprite->frame.size.width = COOKWARE_SIZE_WIDTH;
    chopboard2Sprite->frame.size.height = COOKWARE_SIZE_HEIGHT;
    chopboard2Sprite->priority = 2;
    chopboard2Sprite->facingDirection = up;
    chopboard2Sprite->state = 1;
    chopboard2Sprite->shapeFct = &cookwareShape;
    chopboard2Sprite->shadingFct = &chopboardShading;
    scene_addSprite(chopboard2Sprite);

    Sprite *choppedBeefSprite = (Sprite *)malloc(sizeof(Sprite));
    choppedBeefSprite->frame.origin.x = 50;
    choppedBeefSprite->frame.origin.y = 9;
    choppedBeefSprite->frame.size.width = INGREDIENT_SIZE_WIDTH;
    choppedBeefSprite->frame.size.height = INGREDIENT_SIZE_HEIGHT;
    choppedBeefSprite->priority = 3;
    choppedBeefSprite->facingDirection = down;
    choppedBeefSprite->shapeFct = &singlePixelShape;
    choppedBeefSprite->shadingFct = &beefShading;
    choppedBeefSprite->state = INGREDIENT_STATE_MASK_CHOPPED;
    scene_addSprite(choppedBeefSprite);

    Sprite *panSprite = (Sprite *)malloc(sizeof(Sprite));
    panSprite->frame.origin.x = 49;
    panSprite->frame.origin.y = 11;
    panSprite->frame.size.width = COOKWARE_SIZE_WIDTH;
    panSprite->frame.size.height = COOKWARE_SIZE_HEIGHT;
    panSprite->priority = 2;
    panSprite->facingDirection = up;
    panSprite->shapeFct = &cookwareShape;
    panSprite->shadingFct = &panShading;
    scene_addSprite(panSprite);

    Sprite *arrow4Sprite = (Sprite *)malloc(sizeof(Sprite));
    arrow4Sprite->frame.origin.x = 54;
    arrow4Sprite->frame.origin.y = 4;
    arrow4Sprite->frame.size.width = ARROW_SIZE_WIDTH;
    arrow4Sprite->frame.size.height = ARROW_SIZE_HEIGHT;
    arrow4Sprite->priority = 2;
    arrow4Sprite->facingDirection = right;
    arrow4Sprite->shapeFct = &arrowShape;
    arrow4Sprite->shadingFct = &whiteColorShading;
    scene_addSprite(arrow4Sprite);

    Sprite *beefReceiverSprite = (Sprite *)malloc(sizeof(Sprite));
    beefReceiverSprite->frame.origin.x = 62;
    beefReceiverSprite->frame.origin.y = 4;
    beefReceiverSprite->frame.size.width = RECEIVER_SIZE_WIDTH;
    beefReceiverSprite->frame.size.height = RECEIVER_SIZE_HEIGHT;
    beefReceiverSprite->priority = 2;
    beefReceiverSprite->facingDirection = down;
    beefReceiverSprite->shapeFct = &receiverShape;
    beefReceiverSprite->shadingFct = &beefReceiverShading;
    scene_addSprite(beefReceiverSprite);

    Sprite *cookedBeefSprite = (Sprite *)malloc(sizeof(Sprite));
    cookedBeefSprite->frame.origin.x = 62;
    cookedBeefSprite->frame.origin.y = 7;
    cookedBeefSprite->frame.size.width = INGREDIENT_SIZE_WIDTH;
    cookedBeefSprite->frame.size.height = INGREDIENT_SIZE_HEIGHT;
    cookedBeefSprite->priority = 3;
    cookedBeefSprite->facingDirection = down;
    cookedBeefSprite->shapeFct = &singlePixelShape;
    cookedBeefSprite->shadingFct = &beefShading;
    cookedBeefSprite->state = INGREDIENT_STATE_MASK_COOKED;
    scene_addSprite(cookedBeefSprite);
}
