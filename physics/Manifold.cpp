//
//  Manifold.cpp
//  2D_RPG
//
//  Created by John Damits on 3/25/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Manifold.h"

Manifold::Manifold() {

}

void Manifold::applyInteractions(Body& shapeA, Body& shapeB) {
    cData = Collision::isCollidingMTV(shapeA, shapeB);

    if (cData.MTV == -1)
        colliding = false;
    else
        colliding = true;

    Impulse::applyPhysics(shapeA);
    Impulse::applyPhysics(shapeB);

    if (colliding)
        Impulse::resolveCollision(shapeA, shapeB, cData);
}


