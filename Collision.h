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

#include "limits"
#include "math.h"

#include "Body.h"
//#include "Impulse.h"

#endif /* defined(___D_RPG__Collision__) */

class Collision {
public:
    static bool isColliding(Body&, Body&);
    static bool isColliding(Point&, Body&);
    static bool isCollidingMouse(Body&);
private:
    static bool oneCollide(Body&, Body&);
};