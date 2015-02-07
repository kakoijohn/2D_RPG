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