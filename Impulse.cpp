//
//  Impulse.cpp
//  2D_RPG
//
//  Created by John Damits on 3/2/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Impulse.h"

Spring Impulse::spring = {{200, 0}, 0.5, -1};

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
        obj.p.move({0, -20});
    }
}

void Impulse::applyTorque(Body& obj) {
    float dt = Clock::dt();

    Vect f = {0, 0};
    float torque = 0;

    Vect dr = add(scalar(obj.vel, dt), scalar(obj.accel, 0.5 * dt * dt));
    obj.p.move(scalar(dr, 100));

    f = add(f, scalar(PhysConst::gravity, obj.mass));

    f = add(f, scalar(obj.vel, spring.b));

    Vect springForce = scalar(sub(obj.p.vert[0], spring.location), -1 * spring.stiffness);

    Vect r = sub(obj.p.centroid(), obj.p.vert[0]);

    float rxf = cross(r, springForce);

    torque += -1 * rxf;
    f = add(f, springForce);

    Vect new_a = scalar(f, obj.mass);
    Vect dv = scalar(add(obj.accel, new_a), 0.5 * dt);
    obj.vel = add(obj.vel, dv);

    torque += obj.omega * obj.angularB;
    obj.alpha = torque / obj.moment;
    obj.omega += obj.alpha * dt;

    float deltaTheta = obj.omega * dt;
    obj.p.rotate(deltaTheta, obj.p.centroid());
}

Vect Impulse::add(Vect v, Vect w) {
    return {v.x + w.x, v.y + w.y};
}

Vect Impulse::sub(Vect v, Vect w) {
    return {v.x - w.x, v.y - w.y};
}

Vect Impulse::scalar(Vect v, float s) {
    return {v.x * s, v.y * s};
}

float Impulse::dot(Vect v, Vect w) {
    return (v.x * w.x + v.y * w.y);
}

float Impulse::cross(Vect v, Vect w) {
    return (v.x * w.y - v.y * w.x);
}
