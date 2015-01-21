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
#include "Point.h"

#endif /* defined(___D_RPG__BodyPart__) */

class BodyPart {
public:
    BodyPart(float, float, Point, Point);
    BodyPart(float, float, Point, Point, Point);
    
    void freeResources();
private:
    float height, width, rotation;
    Point position, pivot1, pivot2;
};