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
    
    this->pivot = pivot;
    this->anchor = anchor;
    
    rectangle.corner1 = position;

    rectangle.corner2.x = position.x + rectangle.width;
    rectangle.corner2.y = position.y;
    
    rectangle.corner3.x = position.x + rectangle.width;
    rectangle.corner3.y = position.y + rectangle.height;
    
    rectangle.corner4.x = position.x;
    rectangle.corner4.y = position.y + rectangle.height;
}

Entity::Entity(Rect rectangle, Point position, Point pivot, Point anchor, float rotation) {
    Entity(rectangle, position, pivot, anchor);
    
    rotate(rotation);
}

void Entity::rotate(float degrees) {
    rectangle.rotation += degrees;
    
    if (rectangle.rotation > 360)
        rectangle.rotation =  fmodf(rectangle.rotation, 360);
    
    float distance = sqrtf(powf(pivot.x, 2) + powf(pivot.y, 2));
    
    //update corners

    rectangle.corner1.x += distance * cosf(rectangle.rotation);
    rectangle.corner1.y += distance * sinf(rectangle.rotation);
    
    rectangle.corner2.x += rectangle.width * cosf(rectangle.rotation);
    rectangle.corner2.y += rectangle.width * sinf(rectangle.rotation);
    
    float c3Distance = sqrtf(powf(rectangle.width, 2) + powf(rectangle.height, 2));
    
    rectangle.corner3.x += c3Distance * cosf(rectangle.rotation);
    rectangle.corner3.y += c3Distance * sinf(rectangle.rotation);
    
    rectangle.corner4.x += rectangle.height * cosf(rectangle.rotation);
    rectangle.corner4.y += rectangle.height * sinf(rectangle.rotation);
}

bool Entity::isColliding(Rect object) {
    if (!basicCollision(object))
        return false;
    
    
    
    
    return true;
}

bool Entity::basicCollision(Rect object) {
    Rect boundingBox1;
    Rect boundingBox2;
    
    float minX1 = min(rectangle.corner1.x, rectangle.corner2.x, rectangle.corner3.x, rectangle.corner4.x);
    float minY1 = min(rectangle.corner1.y, rectangle.corner2.y, rectangle.corner3.y, rectangle.corner4.y);
    float maxX1 = max(rectangle.corner1.x, rectangle.corner2.x, rectangle.corner3.x, rectangle.corner4.x);
    float maxY1 = max(rectangle.corner1.y, rectangle.corner2.y, rectangle.corner3.y, rectangle.corner4.y);
    
    boundingBox1.corner1.x = minX1;
    boundingBox1.corner1.y = minY1;
    
    boundingBox1.corner2.x = maxX1;
    boundingBox1.corner2.y = minY1;
    
    boundingBox1.corner3.x = maxX1;
    boundingBox1.corner3.y = maxY1;
    
    boundingBox1.corner4.x = minX1;
    boundingBox1.corner4.y = maxY1;
    
    
    float minX2 = min(object.corner1.x, object.corner2.x, object.corner3.x, object.corner4.x);
    float minY2 = min(object.corner1.y, object.corner2.y, object.corner3.y, object.corner4.y);
    float maxX2 = max(object.corner1.x, object.corner2.x, object.corner3.x, object.corner4.x);
    float maxY2 = max(object.corner1.y, object.corner2.y, object.corner3.y, object.corner4.y);
    
    boundingBox2.corner1.x = minX2;
    boundingBox2.corner1.y = minY2;
    
    boundingBox2.corner2.x = maxX2;
    boundingBox2.corner2.y = minY2;
    
    boundingBox2.corner3.x = maxX2;
    boundingBox2.corner3.y = maxY2;
    
    boundingBox2.corner4.x = minX2;
    boundingBox2.corner4.y = maxY2;
    
    //check if basic collision
    
    
    
    return false;
}

float min(float f1, float f2, float f3, float f4) {
    return fminf(fminf(f1, f2), fminf(f3, f4));
}

float max(float f1, float f2, float f3, float f4) {
    return fmaxf(fmaxf(f1, f2), fmaxf(f3, f4));
}

void Entity::freeResources() {
    
}