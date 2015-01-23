//
//  BodyPart.h
//  2D_RPG
//
//  Created by John Damits on 1/20/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef ___D_RPG__BodyPart__
#define ___D_RPG__BodyPart__

#include <stdio.h>
#include "iostream"
#include "Structures.h"
#include "math.h"

#endif /* defined(___D_RPG__BodyPart__) */

class Entity {
public:
    Entity(Rect, Point, Point, Point);
    Entity(Rect, Point, Point, Point, float);
    
    void rotate(float);
    bool isColliding(Rect);
    
    void freeResources();
    
    Rect rectangle;
    Point pivot, anchor;
private:
    bool basicCollision(Rect);
    float min(float, float, float, float);
    float max(float, float, float, float);
};