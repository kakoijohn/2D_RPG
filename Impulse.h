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

#endif /* defined(___D_RPG__Impulse__) */

#include "Body.h"

class Impulse {
public:
    static float dotProduct(Vect&, Vect&);
    static void resolveCollision(Body&, Body&);
};