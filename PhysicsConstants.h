
//
//  PhysicsConstants.h
//  2D_RPG
//
//  Created by John Damits on 3/2/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef _D_RPG_PhysicsConstants_h
#define _D_RPG_PhysicsConstants_h

#endif

class PhysConst {
public:
    static Vect gravity;
    static float rhoAir;
};

Vect PhysConst::gravity = {0, -9.8};
float PhysConst::rhoAir  = 1.2f;