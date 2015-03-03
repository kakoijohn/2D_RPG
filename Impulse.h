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
#include "PhysicsConstants.h"

#endif /* defined(___D_RPG__Impulse__) */

class Impulse {
public:
    static void initializeObject(Body&);
    static void applyPhysics(Body&, bool);
private:
    static void setArea(Body&);
    static void setMoment(Body&);
    static void setMass(Body&);
};