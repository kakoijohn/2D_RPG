//
//  Collision.cpp
//  2D_RPG
//
//  Created by John Damits on 2/5/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Collision.h"

Collision::Collision() {
    
}

bool Collision::isColliding(Polygon& shapeA, Polygon& shapeB) {
    if (shapeA.vert.size() > 1 && shapeB.vert.size() > 1) {
        float minOverlap = oneCollide(shapeA, shapeB).MTV;
        if (minOverlap <= 0)
            return false;
        minOverlap = fminf(minOverlap, oneCollide(shapeB, shapeA).MTV);
        if (minOverlap <= 0)
            return false;

        shapeA.MTV = minOverlap;
        shapeB.MTV = minOverlap;
    } else if (shapeA.vert.size() > 1 && shapeB.vert.size() <= 1) {
        if (!isCollidingPoint(shapeB.vert.at(0), shapeA))
            return false;
    } else if (shapeB.vert.size() > 1 && shapeA.vert.size() <= 1) {
        if (!isCollidingPoint(shapeA.vert.at(0), shapeB))
            return false;
    }

    return true;
}

CollData Collision::isCollidingMTV(Polygon& shapeA, Polygon& shapeB) {
    CollData dataA = oneCollide(shapeA, shapeB);
    if (dataA.MTV < 0)
        return {{0, 0}, -1};
    CollData dataB = oneCollide(shapeB, shapeA);
    if (dataB.MTV < 0)
        return {{0, 0}, -1};

    if (dataA.MTV < dataB.MTV)
        return dataA;
    else
        return dataB;
}

CollData Collision::oneCollide(Polygon& shapeA, Polygon& shapeB) {
    float minOverlap = std::numeric_limits<float>::max();
    Vect collNormal;

    for (int a = 0; a < shapeA.vert.size(); a++) {
        float Vx;
        float Vy;
        
        if (a == shapeA.vert.size() - 1) {
            Vx = -(shapeA.vert.at(a).y - shapeA.vert.at(0).y);
            Vy = shapeA.vert.at(a).x - shapeA.vert.at(0).x;
        } else {
            Vx = -(shapeA.vert.at(a + 1).y - shapeA.vert.at(a).y);
            Vy = shapeA.vert.at(a + 1).x - shapeA.vert.at(a).x;
        }

        float Vmag = sqrtf(Vx * Vx + Vy * Vy);
        Vx = Vx / Vmag;
        Vy = Vy / Vmag;

        float TAmin = std::numeric_limits<float>::max();
        float TAmax = -TAmin;
        
        for (int i = 0; i < shapeA.vert.size(); i++) {
            float TAv = (shapeA.vert.at(i).x * Vx + shapeA.vert.at(i).y * Vy) / (Vx * Vx + Vy * Vy);
            float TAvx = TAv * Vx;
            float TAvy = TAv * Vy;
            
            float TAval = TAvx * Vx + TAvy * Vy;

            TAmin = fminf(TAmin, TAval);
            TAmax = fmaxf(TAmax, TAval);
        }
        
        float TBmin = std::numeric_limits<float>::max();
        float TBmax = -TBmin;
        
        for (int i = 0; i < shapeB.vert.size(); i++) {
            float TBv = (shapeB.vert.at(i).x * Vx + shapeB.vert.at(i).y * Vy) / (Vx * Vx + Vy * Vy);
            float TBvx = TBv * Vx;
            float TBvy = TBv * Vy;
            
            float TBval = TBvx * Vx + TBvy * Vy;

            TBmin = fminf(TBmin, TBval);
            TBmax = fmaxf(TBmax, TBval);
        }

        if (!(TBmin <= TAmax && TBmax >= TAmin))
            return {{0, 0}, -1};

        float overlap = fminf(fabsf(TAmax - TBmin), fabsf(TBmax - TAmin));
        if (minOverlap > overlap) {
            minOverlap = overlap;
            collNormal = {Vx, Vy};
        }
    }

    return {collNormal, minOverlap};
}

bool Collision::isCollidingPoint(Point& point, Polygon& shape) {
    for (int a = 0; a < shape.vert.size(); a++) {
        float Vx;
        float Vy;

        if (a == shape.vert.size() - 1) {
            Vx = -(shape.vert.at(a).y - shape.vert.at(0).y);
            Vy = shape.vert.at(a).x - shape.vert.at(0).x;
        } else {
            Vx = -(shape.vert.at(a + 1).y - shape.vert.at(a).y);
            Vy = shape.vert.at(a + 1).x - shape.vert.at(a).x;
        }

        float TAmin = std::numeric_limits<float>::max();
        float TAmax = -TAmin;

        for (int i = 0; i < shape.vert.size(); i++) {
            float TAv = (shape.vert.at(i).x * Vx + shape.vert.at(i).y * Vy) / (Vx * Vx + Vy * Vy);
            float TAvx = TAv * Vx;
            float TAvy = TAv * Vy;

            float TAval = TAvx * Vx + TAvy * Vy;

            TAmin = fminf(TAmin, TAval);
            TAmax = fmaxf(TAmax, TAval);
        }

        float TBv = (point.x * Vx + point.y * Vy) / (Vx * Vx + Vy * Vy);
        float TBvx = TBv * Vx;
        float TBvy = TBv * Vy;

        float TBval = TBvx * Vx + TBvy * Vy;

        if (!(TBval <= TAmax && TBval >= TAmin))
            return false;
    }
    
    return true;
}

bool Collision::isCollidingMouse(Polygon& shape) {
    int mX, mY;
    SDL_GetMouseState(&mX, &mY);
    Point p = {(float)mX, (float)mY};

    return isCollidingPoint(p, shape);
}

