//
//  Body.cpp
//  2D_RPG
//
//  Created by John Damits on 3/3/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Body.h"

Body::Body(int vertecies) : p(vertecies) {
    
}

void Body::initializeObject() {
    setArea();
    setMoment();
    setMass();
}

void Body::setArea() {
    //http://mathworld.wolfram.com/PolygonArea.html

    for (int i = 0; i < p.vert.size(); i++) {
        if (i == p.vert.size() - 1)
            area += p.vert.at(i).x * p.vert.at(0).y - p.vert.at(0).x - p.vert.at(i).y;
        else
            area += p.vert.at(i).x * p.vert.at(i + 1).y - p.vert.at(i + 1).x - p.vert.at(i).y;
    }

    area = fabsf(0.5f * area);
}

void Body::setMoment() {
    //http://en.wikipedia.org/wiki/Second_moment_of_area#Any_polygon

    for (int i = 0; i < p.vert.size(); i++) {
        if (i == p.vert.size() - 1)
            moment += (p.vert.at(i).x * p.vert.at(0).y + 2 * p.vert.at(0).x * p.vert.at(0).y + p.vert.at(0).x * p.vert.at(i).y) * (p.vert.at(i).x * p.vert.at(0).y - p.vert.at(0).x * p.vert.at(i).y);
        else
            moment += (p.vert.at(i).x * p.vert.at(i + 1).y + 2 * p.vert.at(i + 1).x * p.vert.at(i + 1).y + p.vert.at(i + 1).x * p.vert.at(i).y) * (p.vert.at(i).x * p.vert.at(i + 1).y - p.vert.at(i + 1).x * p.vert.at(i).y);
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
