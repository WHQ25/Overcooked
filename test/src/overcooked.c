//
// Created by Hangqi Wu on 2018/8/30.
//

#include "overcooked.h"

// Global variable
uint16_t OneStarScore;
uint16_t TwoStarScore;
uint16_t ThreeStarScore;

Sprite *chefOne;
Sprite *chefTwo;
Sprite *chefOneIngredient;
Sprite *chefTwoIngredient;

Sprite * getSelectedChef() {
    if (chefOne->state & CHEF_STATE_MASK_SELECTED) {
        return chefOne;
    } else {
        return chefTwo;
    }
}

Sprite * getSelectedIngredient() {
    if (chefOne->state & CHEF_STATE_MASK_SELECTED) {
        return chefOneIngredient;
    } else {
        return chefTwoIngredient;
    }
}


uint8_t singlePixelShape(Direction d, uint16_t state, Coordinate cdt) {
    if (cdt.x == 0 && cdt.y == 0) {
        return 1;
    } else {
        return 0;
    }
}

uint8_t fillFrameShape(Direction d, uint16_t state, Coordinate cdt) {
    return 1;
}

uint8_t arrowShape(Direction d, uint16_t state, Coordinate cdt) {
    switch(d) {
        case right:
            if (cdt.y == 2) { return 1; }
            if (cdt.x == 3 && (cdt.y == 0 || cdt.y == 4)) { return 1; }
            if (cdt.x == 4 && (cdt.y == 1 || cdt.y == 3)) { return 1; }
            break;
    }
    return 0;
}

RGBColor whiteColorShading(Direction d, uint16_t state, Coordinate cdt) {
    RGBColor white = { .red = 0xff, .green = 0xff, .blue = 0xff };
    return white;
}

uint8_t chefShape(Direction d, uint16_t state, Coordinate cdt) {
    switch(d) {
        case up:
            if (state & CHEF_STATE_MASK_CHOPPING) {
                if (cdt.y == 1) {return 1;}
            } else {
                if (cdt.y == 1) {return 1;}
                if (cdt.y == 0 && cdt.x != 1) {return 1;}
            }
            break;
        case down:
            if (state & CHEF_STATE_MASK_CHOPPING) {
                if (cdt.y == 1) {return 1;}
            } else {
                if (cdt.y == 1) {return 1;}
                if (cdt.y == 2 && cdt.x != 1) {return 1;}
            }
            break;
        case left:
            if (state & CHEF_STATE_MASK_CHOPPING) {
                if (cdt.x == 1) {return 1;}
            } else {
                if (cdt.x == 1) {return 1;}
                if (cdt.x == 0 && cdt.y != 1) {return 1;}
            }
            break;
        case right:
            if (state & CHEF_STATE_MASK_CHOPPING) {
                if (cdt.x == 1) {return 1;}
            } else {
                if (cdt.x == 1) {return 1;}
                if (cdt.x == 2 && cdt.y != 1) {return 1;}
            }
            break;
    }
    return 0;
}

uint8_t chef1Shape(Direction d, uint16_t state, Coordinate cdt) {
    switch(d) {
        case up:
            if (state & CHEF_STATE_MASK_CHOPPING) {
                if (cdt.y == 0) {return 1;}
            } else {
                if (cdt.y == 1) {return 1;}
                if (cdt.y == 0 && cdt.x != 1) {return 1;}
            }
            break;
        case down:
            if (state & CHEF_STATE_MASK_CHOPPING) {
                if (cdt.y == 0) {return 1;}
            } else {
                if (cdt.y == 0) {return 1;}
                if (cdt.y == 1 && cdt.x != 1) {return 1;}
            }
            break;
        case left:
            if (state & CHEF_STATE_MASK_CHOPPING) {
                if (cdt.x == 0) {return 1;}
            } else {
                if (cdt.x == 1) {return 1;}
                if (cdt.x == 0 && cdt.y != 1) {return 1;}
            }
            break;
        case right:
            if (state & CHEF_STATE_MASK_CHOPPING) {
                if (cdt.x == 0) {return 1;}
            } else {
                if (cdt.x == 0) {return 1;}
                if (cdt.x == 1 && cdt.y != 1) {return 1;}
            }
            break;
    }
    return 0;
}

RGBColor chefShading(Direction d, uint16_t state, Coordinate cdt) {
    RGBColor white = { .red = 0xff, .green = 0xff, .blue = 0xff };
    RGBColor lightGreen = { .red = 0x8b, .green = 0xc3, .blue = 0x4a };
    RGBColor orange = { .red = 0xff, .green = 0x98, .blue = 0x00 };

    if (cdt.x == 1 && cdt.y == 1) {
        if (state & CHEF_STATE_MASK_SELECTED) {
            return orange;
        } else {
            return lightGreen;
        }
    }

    return white;
}

uint8_t cookwareShape(Direction d, uint16_t state, Coordinate cdt) {
    switch(d) {
        case up:
            if (cdt.y == 1) { return 1; }
            else {
                if (cdt.y == 0 && cdt.x != 1) {
                    return 1;
                } else {
                    return 0;
                }
            }
        case down:
            if (cdt.y == 0) { return 1; }
            else {
                if (cdt.y == 1 && cdt.x != 1) {
                    return 1;
                } else {
                    return 0;
                }
            }
        case left:
            if (cdt.x == 1) { return 1; }
            else {
                if (cdt.x == 0 && cdt.y != 1) {
                    return 1;
                } else {
                    return 0;
                }
            }
        case right:
            if (cdt.x == 0) { return 1; }
            else {
                if (cdt.x == 1 && cdt.y != 1) {
                    return 1;
                } else {
                    return 0;
                }
            }
    }
}


RGBColor chopboardShading(Direction d, uint16_t state, Coordinate cdt) {
    RGBColor white = {.red = 0xff, .green = 0xff, .blue = 0xff};
    RGBColor lightBlue = { .red = 0x03, .green = 0xa9, .blue = 0xf4};
    switch(d) {
        case up:
        case down:
            if (cdt.y == 1) { return lightBlue; }
            if (cdt.x == 0 && (state & CHOPBOARD_STATE_CHOPPING_LEFT )) {
                return white;
            }
            else if (cdt.x == 2 && (state & CHOPBOARD_STATE_CHOPPING_RIGHT)) {
                return white;
            }
            else {
                return lightBlue;
            }
        case left:
        case right:
            if (cdt.x == 1) { return lightBlue; }
            if (cdt.y == 0 && (state & CHOPBOARD_STATE_CHOPPING_LEFT )) {
                return white;
            }
            else if (cdt.y == 2 && (state & CHOPBOARD_STATE_CHOPPING_RIGHT)) {
                return white;
            }
            else {
                return lightBlue;
            }
    }
}

RGBColor panShading(Direction d, uint16_t state, Coordinate cdt) {
    RGBColor purple = { .red = 0x9c, .green = 0x27, .blue = 0xb0 };
    return purple;
}

uint8_t ingredientStorageShape(Direction d, uint16_t state, Coordinate cdt) {
    switch(d) {
        case up:
            if (cdt.y == 1) { return 1; }
            if (cdt.y == 0 && cdt.x == 1) { return 1; }
            break;
        case down:
            if (cdt.y == 0) { return 1; }
            if (cdt.y == 1 && cdt.x == 1) { return 1; }
            break;
        case left:
            if (cdt.x == 1) { return 1; }
            if (cdt.x == 0 && cdt.y == 1) { return 1; }
            break;
        case right:
            if (cdt.x == 0) { return 1; }
            if (cdt.x == 1 && cdt.y == 1) { return 1; }
            break;
    }
    return 0;
}

RGBColor breadShading(Direction d, uint16_t state, Coordinate cdt) {
    RGBColor brown = { .red = 0x79, .green = 0x55, .blue = 0x48 };
    return brown;
}

RGBColor beefShading(Direction d, uint16_t state, Coordinate cdt) {
    RGBColor lightPink = { .red = 0xe9, .green = 0x1e, .blue = 0x63 };
    RGBColor orange = { .red = 0x79, .green = 0x55, .blue = 0x48 };
    RGBColor red = { .red = 0x79, .green = 0x55, .blue = 0x48 };
    if (state & INGREDIENT_STATE_MASK_COOKED) {
        return red;
    }
    if (state & INGREDIENT_STATE_MASK_COOKED) {
        return orange;
    }
    return lightPink;
}

RGBColor cheeseShading(Direction d, uint16_t state, Coordinate cdt) {
    RGBColor yellow = { .red = 0xff, .green = 0xeb, .blue = 0x3b };
    RGBColor darkYellow = { .red = 0xff, .green = 0xc1, .blue = 0x07 };
    if (state & INGREDIENT_STATE_MASK_COOKED) {
        return darkYellow;
    }
    return yellow;
}

RGBColor lettuceShading(Direction d, uint16_t state, Coordinate cdt) {
    RGBColor lightGreen = { .red = 0x8b, .green = 0xc3, .blue = 0x4a };
    RGBColor darkGreen = { .red = 0x4c, .green = 0xaf, .blue = 0x50 };
    if (state & INGREDIENT_STATE_MASK_COOKED) {
        return darkGreen;
    }
    return lightGreen;
}

uint8_t receiverShape(Direction d, uint16_t state, Coordinate cdt) {
    switch(d) {
        case up:
        case down:
            if (cdt.x == 0 && cdt.y == 0) { return 1; }
            if (cdt.x == 0 && cdt.y == 1) { return 1; }
            break;
        case left:
        case right:
            if (cdt.x == 0 && cdt.y == 0) { return 1; }
            if (cdt.x == 1 && cdt.y == 0) { return 1; }
            break;
    }
    return 0;
}

RGBColor breadReceiverShading(Direction d, uint16_t state, Coordinate cdt) {
    if (cdt.x == 0 && cdt.y == 0) {
        RGBColor brown = { .red = 0x79, .green = 0x55, .blue = 0x48 };
        return brown;
    } else {
        RGBColor white = {.red = 0xff, .green = 0xff, .blue = 0xff};
        return white;
    }
}

RGBColor beefReceiverShading(Direction d, uint16_t state, Coordinate cdt) {
    if (cdt.x == 0 && cdt.y == 0) {
        RGBColor red = { .red = 0x79, .green = 0x55, .blue = 0x48 };
        return red;
    } else {
        RGBColor white = {.red = 0xff, .green = 0xff, .blue = 0xff};
        return white;
    }
}

RGBColor cheeseReceiverShading(Direction d, uint16_t state, Coordinate cdt) {
    if (cdt.x == 0 && cdt.y == 0) {
        RGBColor darkYellow = { .red = 0xff, .green = 0xc1, .blue = 0x07 };
        return darkYellow;
    } else {
        RGBColor white = {.red = 0xff, .green = 0xff, .blue = 0xff};
        return white;
    }
}

RGBColor lettuceReceiverShading(Direction d, uint16_t state, Coordinate cdt) {
    if (cdt.x == 0 && cdt.y == 0) {
        RGBColor darkGreen = { .red = 0x4c, .green = 0xaf, .blue = 0x50 };
        return darkGreen;
    } else {
        RGBColor white = {.red = 0xff, .green = 0xff, .blue = 0xff};
        return white;
    }
}


