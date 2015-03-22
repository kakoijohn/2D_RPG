//
//  Impulse.cpp
//  2D_RPG
//
//  Created by John Damits on 3/2/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Impulse.h"

void Impulse::applyPhysics(Body& obj, bool isColliding) {
    //http://buildnewgames.com/gamephysics/

    float dt = Clock::dt();

    //weight force y direction
    float fy = obj.mass * PhysConst::gravity.y;
    //air resistance
    fy += -1 * 0.5 * PhysConst::rhoAir * obj.dragCoef * obj.area * obj.vel.y * obj.vel.y;

    //verlet integration
    float dy = obj.vel.y * dt + (0.5 * obj.accel.y * dt * dt);

    obj.p.move({0, dy * 100});

    float new_ay = fy / obj.mass;
    float avg_ay = 0.5 * (new_ay + obj.accel.y);

    obj.vel.y += avg_ay * dt;

    if (isColliding) {
        obj.vel.y *= obj.restitution;
        obj.p.move({0, -10});
    }
}
