//
//  Collision.h
//  2D_RPG
//
//  Created by John Damits on 2/5/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef ___D_RPG__Collision__
#define ___D_RPG__Collision__

#include <stdio.h>
#include "Polygon.h"
#include "limits"
#include "math.h"

#endif /* defined(___D_RPG__Collision__) */

class Collision {
public:
    Collision();
    static bool isColliding(Polygon, Polygon);
    static bool isColliding(Point, Polygon);
private:
    static bool oneCollide(Polygon, Polygon);
};