//
//  Impulse.cpp
//  2D_RPG
//
//  Created by John Damits on 3/2/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Impulse.h"

void Impulse::applyPhysics(Body& obj, CollData& cData) {
    if (obj.mass == 0)
        return;

    //http://buildnewgames.com/gamephysics/

    float torque = 0;
    float dt = Clock::dt();

    //weight force y direction
    Vect f = scalar(PhysConst::gravity, obj.mass);
    //air resistance
    f = add(f, scalar({obj.vel.x * obj.vel.x, obj.vel.y * obj.vel.y}, -1 * 0.5 * PhysConst::rhoAir * obj.dragCoef * obj.area));

    //verlet integration
    Vect dr = scalar(obj.vel, dt + (0.5 * obj.accel.x * dt * dt));
    obj.move(scalar(dr, 100));

    if (cData.collisionPoints.size() > 0) {
        Vect collision;
        for (int i = 0; i < cData.collisionPoints.size(); i++)
            collision = add(collision, cData.collisionPoints[i]);
        collision = scalar(collision, 1 / cData.collisionPoints.size());

        Vect N = subtract(obj.centroid(), collision);
        N = scalar(N, 1 / sqrtf(N.x * N.x + N.y * N.y));
        Vect Vr = obj.angVel;
        Vect I = scalar(N, dot(Vr, N));
        obj.angVel = I;
        if (obj.omega != 0)
            obj.omega = -1 * 0.2 * (obj.omega / fabsf(obj.omega) * cross(subtract(obj.centroid(), collision), Vr));
        else
            obj.omega = -1 * 0.2 * cross(subtract(obj.centroid(), collision), Vr);
    }

    Vect new_a = {f.x / obj.mass, f.y / obj.mass};
    Vect dv = scalar(add(new_a, obj.accel), 0.5 * dt);
    obj.vel = add(obj.vel, dv);

    torque += obj.omega * obj.angDamp;
    obj.alpha = torque / obj.density;
    obj.omega += obj.alpha * dt;
    float deltaTheta = obj.omega * dt;
    obj.rotate(deltaTheta, obj.centroid());
}

void Impulse::resolveCollision(Body& objA, Body& objB, CollData& cData) {
    if (objA.mass == 0 && objB.mass == 0)
        return;

    if (objA.mass != 0)
        objA.move(scalar(cData.normal, -cData.MTV));
    else if (objB.mass != 0)
        objB.move(scalar(cData.normal, cData.MTV));

    Vect relVel = subtract(objB.vel, objA.vel);
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

void Impulse::positionalCorrection(Body& objA, Body& objB, CollData& cData) {
    //Still a work in progress. Will come back if deemed necessary.

    float percent = 0.2; // 20% to 80%
    float slop = 0.01; // .01 to .1
    float magnitude = fmaxf(cData.MTV - slop, 0.0f) / (objA.invMass + objB.invMass) * percent;
    Vect correction = {magnitude * cData.normal.x, magnitude * cData.normal.y};

    if (objA.mass != 0)
        objA.move({-objA.invMass * correction.x, -objA.invMass * correction.y});
    if (objB.mass != 0)
        objB.move({objB.invMass * correction.x, objB.invMass * correction.y});
}

Vect Impulse::add(Vect a, Vect b) {
    return {a.x + b.x, a.y + b.y};
}

Vect Impulse::subtract(Vect a, Vect b) {
    return {a.x - b.x, a.y - b.y};
}

Vect Impulse::scalar(Vect a, float s) {
    return {a.x * s, a.y * s};
}

float Impulse::dot(Vect a, Vect b) {
    return a.x * b.x + a.y * b.y;
}

float Impulse::cross(Vect a, Vect b) {
    return a.x * b.y - a.y * b.x;
}

float Impulse::distance(Vect a, Vect b) {
    return sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2));
}