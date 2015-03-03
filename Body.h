//
//  Body.h
//  2D_RPG
//
//  Created by John Damits on 3/2/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef _D_RPG_Body_h
#define _D_RPG_Body_h

#include "Polygon.h"

#endif

class Body {
public:
    Body(int);

    Polygon s;

    Vect vel;
    Vect angVel;
    Vect accel;
    Material material;
    float dragCoef;
    float moment;
    float mass;
    float area;
};

Body::Body(int vertecies) : s(vertecies) {

}