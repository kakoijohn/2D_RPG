//
//  Polygon.cpp
//  2D_RPG
//
//  Created by John Damits on 2/6/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Polygon.h"

Point *vert;

Polygon::Polygon(int vertecies) {
    vert = new Point[vertecies];
}

void Polygon::freeResources() {
    delete vert;
}

void Polygon::rotate(float rad, Point point) {
    for (int i = 0; i < sizeof(vert); i++) {
        float distance = sqrtf(powf((point.x - vert[i].x), 2) + powf((point.y - vert[i].y), 2));
        float theta = atan2f(vert[i].y, vert[i].y);

        theta += rad;
        
        vert[i].x = point.x + distance * cosf(theta);
        vert[i].y = point.y + distance * sinf(theta);
    }
}

void Polygon::move(Point delta) {
    for (int i = 0; i < sizeof(vert); i++) {
        vert[i].x += delta.x;
        vert[i].y += delta.y;
    }
}