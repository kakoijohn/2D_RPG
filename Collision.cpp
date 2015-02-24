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
    if (shapeA.vert.size() > 1 && shapeB.vert.size() > 1) {
        if (!oneCollide(shapeA, shapeB))
            return false;
        if (!oneCollide(shapeB, shapeA))
            return false;
    } else if (shapeA.vert.size() > 1 && shapeB.vert.size() <= 1) {
        if (!isColliding(shapeB.vert.at(0), shapeA))
            return false;
    } else if (shapeB.vert.size() > 1 && shapeA.vert.size() <= 1) {
        if (!isColliding(shapeA.vert.at(0), shapeB))
            return false;
    }

    return true;
}

bool Collision::isColliding(Point point, Polygon shape) {
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
        float TAmax = -std::numeric_limits<float>::max();

        for (int i = 0; i < shape.vert.size(); i++) {
            float TAv = (shape.vert.at(i).x * Vx + shape.vert.at(i).y * Vy) / (powf(Vx, 2) + powf(Vy, 2));
            float TAvx = TAv * Vx;
            float TAvy = TAv * Vy;

            float TAval = TAvx * Vx + TAvy * Vy;

            TAmin = fminf(TAmin, TAval);
            TAmax = fmaxf(TAmax, TAval);
        }

        float TBv = (point.x * Vx + point.y * Vy) / (powf(Vx, 2) + powf(Vy, 2));
        float TBvx = TBv * Vx;
        float TBvy = TBv * Vy;

        float TBval = TBvx * Vx + TBvy * Vy;

        if (!(TBval <= TAmax && TBval >= TAmin))
            return false;
    }
    
    return true;
}

bool Collision::oneCollide(Polygon shapeA, Polygon shapeB) {
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

        float TAmin = std::numeric_limits<float>::max();
        float TAmax = -std::numeric_limits<float>::max();
        
        for (int i = 0; i < shapeA.vert.size(); i++) {
            float TAv = (shapeA.vert.at(i).x * Vx + shapeA.vert.at(i).y * Vy) / (powf(Vx, 2) + powf(Vy, 2));
            float TAvx = TAv * Vx;
            float TAvy = TAv * Vy;
            
            float TAval = TAvx * Vx + TAvy * Vy;

            TAmin = fminf(TAmin, TAval);
            TAmax = fmaxf(TAmax, TAval);
        }
        
        float TBmin = std::numeric_limits<float>::max();
        float TBmax = -std::numeric_limits<float>::max();
        
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
