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

void Manifold::applyInteractions(Body& objA, Body& objB, SDL_Renderer* renderer) {
    cData = Collision::isCollidingMTV(objA, objB);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    for (int i = 0; i < cData.collisionPoints.size(); i++) {
        SDL_RenderDrawPoint(renderer, cData.collisionPoints[i].x, cData.collisionPoints[i].y);
//        std::cout << cData.collisionPoints[i].x << " " << cData.collisionPoints[i].y << "\n";
    }

    if (cData.MTV == -1)
        colliding = false;
    else
        colliding = true;

    Impulse::applyPhysics(objA, cData);
    Impulse::applyPhysics(objB, cData);

//    Impulse::applyRotation(objA, cData);
//    Impulse::applyRotation(objB, cData);

    if (colliding) {
        Impulse::resolveCollision(objA, objB, cData);
        Impulse::positionalCorrection(objA, objB, cData);
    }
}