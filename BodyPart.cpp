//
//  BodyPart.cpp
//  2D_RPG
//
//  Created by John Damits on 1/20/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "BodyPart.h"

BodyPart::BodyPart(int width, int height, int pivotX, int pivotY) {
    this->width = width;
    this->height = height;
    
    this->pivotX = pivotX;
    this->pivotY = pivotY;
}

void BodyPart::freeResources() {
    
}