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
    setMass();
    setMoment();
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

void Body::setMass() {
    mass = density * area;
    if (mass == 0)
        invMass = 0;
    else
        invMass = 1 / mass;
}

void Body::setMoment() {
    //http://en.wikipedia.org/wiki/Second_moment_of_area#Any_polygon

    float momN, momD;
    for (int i = 0; i < p.vert.size() - 1; i++) {
        float momDP = (p.vert.at(i).x * p.vert.at(i + 1).y - p.vert.at(i + 1).x * p.vert.at(i).y);

        momN += (p.vert.at(i).x * p.vert.at(i).x + p.vert.at(i).y * p.vert.at(i).y + p.vert.at(i).x * p.vert.at(i + 1).x + p.vert.at(i).y * p.vert.at(i + 1).y + p.vert.at(i + 1).x * p.vert.at(i + 1).x + p.vert.at(i + 1).y * p.vert.at(i + 1).y) * momDP;

        momD += momDP;
    }

    moment = (mass / 6) * (momN / momD);
}
