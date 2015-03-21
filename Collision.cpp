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

bool Collision::isColliding(Body& shapeA, Body& shapeB) {
    if (shapeA.p.vert.size() > 1 && shapeB.p.vert.size() > 1) {
        if (findAxisLeastPenetration(shapeA, shapeB) >= 0)
            return false;
        if (findAxisLeastPenetration(shapeB, shapeA) >= 0)
            return false;
    } else if (shapeA.p.vert.size() > 1 && shapeB.p.vert.size() <= 1) {
        if (!isColliding(shapeB.p.vert.at(0), shapeA))
            return false;
    } else if (shapeB.p.vert.size() > 1 && shapeA.p.vert.size() <= 1) {
        if (!isColliding(shapeA.p.vert.at(0), shapeB))
            return false;
    }

    return true;
}

bool Collision::isColliding(Vect& point, Body& shape) {
    for (int a = 0; a < shape.p.vert.size(); a++) {
        float Vx;
        float Vy;

        if (a == shape.p.vert.size() - 1) {
            Vx = -(shape.p.vert.at(a).y - shape.p.vert.at(0).y);
            Vy = shape.p.vert.at(a).x - shape.p.vert.at(0).x;
        } else {
            Vx = -(shape.p.vert.at(a + 1).y - shape.p.vert.at(a).y);
            Vy = shape.p.vert.at(a + 1).x - shape.p.vert.at(a).x;
        }

        float TAmin = std::numeric_limits<float>::max();
        float TAmax = -TAmin;

        for (int i = 0; i < shape.p.vert.size(); i++) {
            float TAv = (shape.p.vert.at(i).x * Vx + shape.p.vert.at(i).y * Vy) / (Vx * Vx + Vy * Vy);
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

bool Collision::isCollidingMouse(Body& shape) {
    int mX, mY;
    SDL_GetMouseState(&mX, &mY);
    Vect p = {(float)mX, (float)mY};

    return isColliding(p, shape);
}

Vect Collision::getSupport(Body& shape, Vect direction) {
    float bestProjection = -std::numeric_limits<float>::max();
    Vect bestVertex;

    for (int i = 0; i < shape.p.vert.size(); i++) {
        Vect v = shape.p.vert[i];
        float projection = v.x * direction.x + v.y * direction.y;

        if (projection > bestProjection) {
            bestVertex = v;
            bestProjection = projection;
        }
    }

    return bestVertex;
}

float Collision::findAxisLeastPenetration(Body& shapeA, Body& shapeB) {
    float bestDistance = -std::numeric_limits<float>::max();
    int bestIndex = 0;

    for (int i = 0; i < shapeA.p.vert.size(); i++) {
        Vect n = shapeA.p.normalFace(i);

        Vect support = getSupport(shapeB, {-n.x, -n.y});

        Vect v = shapeA.p.vert[i];
        float d = n.x * (support.x - v.x) + n.y * (support.y - v.y);

        if (d > bestDistance) {
            bestDistance = d;
            bestIndex = i;
        }
    }

    shapeA.collisionIndex = bestIndex;
    shapeA.collisionDepth = bestDistance;

//    std::cout << shapeA.collisionDepth << " " << shapeA.collisionIndex << "\n";

    return bestDistance;
}

