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
    void initializeObject();

    Polygon p;

    Vect vel;
    Vect angVel;
    Vect force;
    Vect accel;

    int collisionLoc;

    float area;
    float mass;
    float density;

    float theta;
    float omega;
    float alpha;
    float angularB;

    float moment;
    float restitution;
    float dragCoef;
    float statFrict;
    float dynFrict;
    
private:
    void setArea();
    void setMoment();
    void setMass();
};