//
//  Impulse.cpp
//  2D_RPG
//
//  Created by John Damits on 3/2/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Impulse.h"

void Impulse::initializeObject(Body& obj) {
    setArea(obj);
    setMoment(obj);
    setMass(obj);
}

void Impulse::applyPhysics(Body& obj, bool isColliding) {
    //http://buildnewgames.com/gamephysics/

    float dt = Clock::dt();

    //weight force y direction
    float fy = obj.mass * PhysConst::gravity.y;
    //air resistance
    fy += -1 * 0.5 * PhysConst::rhoAir * obj.dragCoef * obj.area * obj.vel.y * obj.vel.y;

    //verlet integration
    float dy = obj.vel.y * dt + (0.5 * obj.accel.y * dt * dt);

    obj.s.move({0, dy * 100});

    float new_ay = fy / obj.mass;
    float avg_ay = 0.5 * (new_ay + obj.accel.y);

    obj.vel.y += avg_ay * dt;

    if (isColliding) {
        obj.vel.y *= obj.material.restitution;
    }
}

void Impulse::setArea(Body& obj) {
    //http://mathworld.wolfram.com/PolygonArea.html

    for (int i = 0; i < obj.s.vert.size(); i++) {
        if (i == obj.s.vert.size() - 1)
            obj.area += obj.s.vert.at(i).x * obj.s.vert.at(0).y - obj.s.vert.at(0).x - obj.s.vert.at(i).y;
        else
            obj.area += obj.s.vert.at(i).x * obj.s.vert.at(i + 1).y - obj.s.vert.at(i + 1).x - obj.s.vert.at(i).y;
    }

    obj.area = fabsf(0.5f * obj.area);
}

void Impulse::setMoment(Body& obj) {
    //http://en.wikipedia.org/wiki/Second_moment_of_area#Any_polygon

    for (int i = 0; i < obj.s.vert.size(); i++) {
        if (i == obj.s.vert.size() - 1)
            obj.moment += (obj.s.vert.at(i).x * obj.s.vert.at(0).y + 2 * obj.s.vert.at(0).x * obj.s.vert.at(0).y + obj.s.vert.at(0).x * obj.s.vert.at(i).y) * (obj.s.vert.at(i).x * obj.s.vert.at(0).y - obj.s.vert.at(0).x * obj.s.vert.at(i).y);
        else
            obj.moment += (obj.s.vert.at(i).x * obj.s.vert.at(i + 1).y + 2 * obj.s.vert.at(i + 1).x * obj.s.vert.at(i + 1).y + obj.s.vert.at(i + 1).x * obj.s.vert.at(i).y) * (obj.s.vert.at(i).x * obj.s.vert.at(i + 1).y - obj.s.vert.at(i + 1).x * obj.s.vert.at(i).y);
    }

    obj.moment = fabsf((1/24) * obj.moment);
}

void Impulse::setMass(Body& obj) {
    obj.mass = obj.material.density * obj.area;
}