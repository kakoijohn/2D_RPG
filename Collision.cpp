//
//  Collision.cpp
//  2D_RPG
//
//  Created by John Damits on 2/5/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Collision.h"

bool Collision::isColliding(Body& shapeA, Body& shapeB) {
    if (shapeA.s.vert.size() > 1 && shapeB.s.vert.size() > 1) {
        if (!oneCollide(shapeA, shapeB))
            return false;
        if (!oneCollide(shapeB, shapeA))
            return false;
    } else if (shapeA.s.vert.size() > 1 && shapeB.s.vert.size() <= 1) {
        if (!isColliding(shapeB.s.vert.at(0), shapeA))
            return false;
    } else if (shapeB.s.vert.size() > 1 && shapeA.s.vert.size() <= 1) {
        if (!isColliding(shapeA.s.vert.at(0), shapeB))
            return false;
    }

    return true;
}

bool Collision::isColliding(Point& point, Body& shape) {
    for (int a = 0; a < shape.s.vert.size(); a++) {
        float Vx;
        float Vy;

        if (a == shape.s.vert.size() - 1) {
            Vx = -(shape.s.vert.at(a).y - shape.s.vert.at(0).y);
            Vy = shape.s.vert.at(a).x - shape.s.vert.at(0).x;
        } else {
            Vx = -(shape.s.vert.at(a + 1).y - shape.s.vert.at(a).y);
            Vy = shape.s.vert.at(a + 1).x - shape.s.vert.at(a).x;
        }

        float TAmin = std::numeric_limits<float>::max();
        float TAmax = -TAmin;

        for (int i = 0; i < shape.s.vert.size(); i++) {
            float TAv = (shape.s.vert.at(i).x * Vx + shape.s.vert.at(i).y * Vy) / (Vx * Vx + Vy * Vy);
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

bool Collision::oneCollide(Body& shapeA, Body& shapeB) {
    for (int a = 0; a < shapeA.s.vert.size(); a++) {
        float Vx;
        float Vy;
        
        if (a == shapeA.s.vert.size() - 1) {
            Vx = -(shapeA.s.vert.at(a).y - shapeA.s.vert.at(0).y);
            Vy = shapeA.s.vert.at(a).x - shapeA.s.vert.at(0).x;
        } else {
            Vx = -(shapeA.s.vert.at(a + 1).y - shapeA.s.vert.at(a).y);
            Vy = shapeA.s.vert.at(a + 1).x - shapeA.s.vert.at(a).x;
        }

        float TAmin = std::numeric_limits<float>::max();
        float TAmax = -TAmin;
        
        for (int i = 0; i < shapeA.s.vert.size(); i++) {
            float TAv = (shapeA.s.vert.at(i).x * Vx + shapeA.s.vert.at(i).y * Vy) / (Vx * Vx + Vy * Vy);
            float TAvx = TAv * Vx;
            float TAvy = TAv * Vy;
            
            float TAval = TAvx * Vx + TAvy * Vy;

            TAmin = fminf(TAmin, TAval);
            TAmax = fmaxf(TAmax, TAval);
        }
        
        float TBmin = std::numeric_limits<float>::max();
        float TBmax = -TBmin;
        
        for (int i = 0; i < shapeB.s.vert.size(); i++) {
            float TBv = (shapeB.s.vert.at(i).x * Vx + shapeB.s.vert.at(i).y * Vy) / (Vx * Vx + Vy * Vy);
            float TBvx = TBv * Vx;
            float TBvy = TBv * Vy;
            
            float TBval = TBvx * Vx + TBvy * Vy;

            TBmin = fminf(TBmin, TBval);
            TBmax = fmaxf(TBmax, TBval);
        }

        if (!(TBmin <= TAmax && TBmax >= TAmin))
            return false;
    }
    
    return true;
}

bool Collision::isCollidingMouse(Body& shape) {
    int mX, mY;
    SDL_GetMouseState(&mX, &mY);
    Point p = {(float)mX, (float)mY};

    return isColliding(p, shape);
}

