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

bool Collision::isColliding(Polygon shapeA, Polygon shapeB) {
    if (!oneCollide(shapeA, shapeB))
        return false;
    if (!oneCollide(shapeB, shapeA))
        return false;
    
    return true;
}

bool Collision::oneCollide(Polygon shapeA, Polygon shapeB) {
    for (int a = 0; a < shapeA.vert.size(); a++) {
        float Vx;
        float Vy;
        
        if (a == shapeA.vert.size() - 1) {
            Vx = shapeA.vert.at(a).x - shapeA.vert.at(0).x;
            Vy = shapeA.vert.at(a).y - shapeA.vert.at(0).y;
        } else {
            Vx = shapeA.vert.at(a).x - shapeA.vert.at(a + 1).x;
            Vy = shapeA.vert.at(a).y - shapeA.vert.at(a + 1).y;
        }

        float TAmin = std::numeric_limits<float>::max();
        float TAmax = std::numeric_limits<float>::min();
        
        for (int i = 0; i < shapeA.vert.size(); i++) {
            float TAv = (shapeA.vert.at(i).x * Vx + shapeA.vert.at(i).y * Vy) / (powf(Vx, 2) + powf(Vy, 2));
            float TAvx = TAv * Vx;
            float TAvy = TAv * Vy;
            
            float TAval = TAvx * Vx + TAvy * Vy;
            
            TAmin = fminf(TAmin, TAval);
            TAmax = fmaxf(TAmax, TAval);
        }
        
        float TBmin = std::numeric_limits<float>::max();
        float TBmax = std::numeric_limits<float>::min();
        
        for (int i = 0; i < shapeB.vert.size(); i++) {
            float TBv = (shapeB.vert.at(i).x * Vx + shapeB.vert.at(i).y * Vy) / (powf(Vx, 2) + powf(Vy, 2));
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

