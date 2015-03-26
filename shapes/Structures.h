//
//  Point.h
//  2D_RPG
//
//  Created by John Damits on 1/21/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef ___D_RPG__Point__
#define ___D_RPG__Point__

#include <stdio.h>

#endif /* defined(___D_RPG__Point__) */

struct Point {
    float x;
    float y;
};

struct Circle {
    Point center;
    float rotation;
    float radius;
};

struct Vect {
    float x;
    float y;
};

struct CollData {
    Vect normal;
    float MTV;
};