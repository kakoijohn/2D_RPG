//
//  BodyPart.cpp
//  2D_RPG
//
//  Created by John Damits on 1/20/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "BodyPart.h"

BodyPart::BodyPart(float width, float height, Point position, Point pivot) {
    this->width = width;
    this->height = height;
    
    this->position = position;
    
    this->pivot1 = pivot;
}

BodyPart::BodyPart(float width, float height, Point position, Point pivot1, Point pivot2) {
    this->width = width;
    this->height = height;
    
    this->position = position;
    
    this->pivot1 = pivot1;
    this->pivot2 = pivot2;
}

void BodyPart::freeResources() {
    
}