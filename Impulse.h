//
//  Impulse.h
//  2D_RPG
//
//  Created by John Damits on 3/2/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef ___D_RPG__Impulse__
#define ___D_RPG__Impulse__

#include <stdio.h>

#include "Body.h"
#include "Clock.h"

#endif /* defined(___D_RPG__Impulse__) */

class Impulse {
public:
    static void applyPhysics(Body&, bool);
    static void applyTorque(Body&);
private:
    static Vect add(Vect, Vect);
    static Vect sub(Vect, Vect);
    static Vect scalar(Vect, float);
    static float dot(Vect, Vect);
    static float cross(Vect, Vect);

    static Spring spring;
};