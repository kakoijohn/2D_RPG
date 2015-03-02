//
//  Impulse.cpp
//  2D_RPG
//
//  Created by John Damits on 3/2/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Impulse.h"

float Impulse::dotProduct(Vect& v1, Vect& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

void Impulse::resolveCollision(Body &A, Body &B) {
    Vect relativeVel = {A.p.vel.x - B.p.vel.x, A.p.vel.y - B.p.vel.y};

    float normalVel = dotProduct(relativeVel, <#Vect &v2#>)
}