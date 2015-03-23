//
//  Body.cpp
//  2D_RPG
//
//  Created by John Damits on 3/3/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Body.h"

Body::Body(int vertecies) : Polygon(vertecies) {
    
}

void Body::initializeObject() {
    setArea();
    setMoment();
    setMass();
}

void Body::setArea() {
    //http://mathworld.wolfram.com/PolygonArea.html

    for (int i = 0; i < vert.size(); i++) {
        if (i == vert.size() - 1)
            area += vert.at(i).x * vert.at(0).y - vert.at(0).x - vert.at(i).y;
        else
            area += vert.at(i).x * vert.at(i + 1).y - vert.at(i + 1).x - vert.at(i).y;
    }

    area = fabsf(0.5f * area);
}

void Body::setMoment() {
    //http://en.wikipedia.org/wiki/Second_moment_of_area#Any_polygon

    for (int i = 0; i < vert.size(); i++) {
        if (i == vert.size() - 1)
            moment += (vert.at(i).x * vert.at(0).y + 2 * vert.at(0).x * vert.at(0).y + vert.at(0).x * vert.at(i).y) * (vert.at(i).x * vert.at(0).y - vert.at(0).x * vert.at(i).y);
        else
            moment += (vert.at(i).x * vert.at(i + 1).y + 2 * vert.at(i + 1).x * vert.at(i + 1).y + vert.at(i + 1).x * vert.at(i).y) * (vert.at(i).x * vert.at(i + 1).y - vert.at(i + 1).x * vert.at(i).y);
    }

    moment = fabsf((1/24) * moment);
}

void Body::setMass() {
    mass = density * area;
    if (mass == 0)
        invMass = 0;
    else
        invMass = 1 / mass;
}
