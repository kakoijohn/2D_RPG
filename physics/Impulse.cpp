//
//  Impulse.cpp
//  2D_RPG
//
//  Created by John Damits on 3/2/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Impulse.h"

void Impulse::applyPhysics(Body& obj) {
    if (obj.mass == 0)
        return;

    //http://buildnewgames.com/gamephysics/

    float dt = Clock::dt();

    //weight force y direction
    float fx = obj.mass * PhysConst::gravity.x;
    float fy = obj.mass * PhysConst::gravity.y;
    //air resistance
    fx += -1 * 0.5 * PhysConst::rhoAir * obj.dragCoef * obj.area * obj.vel.x * obj.vel.x;
    fy += -1 * 0.5 * PhysConst::rhoAir * obj.dragCoef * obj.area * obj.vel.y * obj.vel.y;

    //verlet integration
    float dx = obj.vel.x * dt + (0.5 * obj.accel.x * dt * dt);
    float dy = obj.vel.y * dt + (0.5 * obj.accel.y * dt * dt);

    obj.move({dx * 100, dy * 100});

    float new_ax = fx / obj.mass;
    float avg_ax = 0.5 * (new_ax + obj.accel.x);
    obj.vel.x += avg_ax * dt;

    float new_ay = fy / obj.mass;
    float avg_ay = 0.5 * (new_ay + obj.accel.y);
    obj.vel.y += avg_ay * dt;
}

void Impulse::resolveCollision(Body& objA, Body& objB, CollData cData) {
    if (objA.mass == 0 && objB.mass == 0)
        return;

    if (cData.MTV > 0) {
        if (objA.mass != 0)
            objA.move({-cData.MTV * cData.normal.x, -cData.MTV * cData.normal.y});
        else if (objB.mass != 0)
            objB.move({cData.MTV * cData.normal.x, cData.MTV * cData.normal.y});

        Vect relVel = {objB.vel.x - objA.vel.x, objB.vel.y - objA.vel.y};
        float velAlongNormal = relVel.x * cData.normal.x + relVel.y * cData.normal.y;

        if (velAlongNormal > 0)
            return;

        float e = (objA.restitution + objB.restitution) / 2;
        float j = (-(1 + e) * velAlongNormal) / (objA.invMass + objB.invMass);

        Vect impulse = {j * cData.normal.x, j * cData.normal.y};
        if (objA.mass != 0)
            objA.vel = {objA.vel.x - objA.invMass * impulse.x, objA.vel.y - objA.invMass * impulse.y};
        if (objB.mass != 0)
            objB.vel = {objB.vel.x + objB.invMass * impulse.x, objB.vel.y + objB.invMass * impulse.y};
    }
}