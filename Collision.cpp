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
    for (int a = 0; a < shapeA.vertecies; a++) {
        float Vx;
        float Vy;
        
        Vx = shapeA.vert[a].x - shapeA.vert[a + 1].x;
        Vy = shapeA.vert[a].y - shapeA.vert[a + 1].y;
        
        float TAmin = std::numeric_limits<float>::max();
        float TAmax = std::numeric_limits<float>::min();
        
        for (int i = 0; i < shapeA.vertecies; i++) {
            float TAv = (shapeA.vert[i].x * Vx + shapeA.vert[i].y * Vy) / (powf(Vx, 2) + powf(Vy, 2));
            float TAvx = TAv * Vx;
            float TAvy = TAv * Vy;
            
            float TAval = TAvx * Vx + TAvy * Vy;
            
            TAmin = fminf(TAmin, TAval);
            TAmax = fmaxf(TAmax, TAval);
        }
        
        float TBmin = std::numeric_limits<float>::max();
        float TBmax = std::numeric_limits<float>::min();
        
        for (int i = 0; i < shapeB.vertecies; i++) {
            float TBv = (shapeB.vert[i].x * Vx + shapeB.vert[i].y * Vy) / (powf(Vx, 2) + powf(Vy, 2));
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

