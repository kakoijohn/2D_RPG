//
//  BodyPart.cpp
//  2D_RPG
//
//  Created by John Damits on 1/20/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Entity.h"

Entity::Entity(Rect rectangle, Point position, Point pivot, Point anchor) {
    this->rectangle = rectangle;
    
    this->position = position;
    
    this->pivot = pivot;
    this->anchor = anchor;
}

void Entity::rotate(float degrees) {
    rectangle.rotation += degrees;
    
    if (rectangle.rotation > 360)
        rectangle.rotation =  fmodf(rectangle.rotation, 360);
    
    
}

bool Entity::isColliding(Entity object) {
    
    
    return false;
}

void Entity::freeResources() {
    
}