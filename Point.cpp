//
//  Point.cpp
//  2D_RPG
//
//  Created by John Damits on 1/21/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

float Point::getX() {
    return x;
}

float Point::getY() {
    return y;
}

void Point::setX(float x) {
    this->x = x;
}

void Point::setY(float y) {
    this->y = y;
}

void Point::setPoint(float x, float y) {
    this->x = x;
    this->y = y;
}