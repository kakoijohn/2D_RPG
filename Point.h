//
//  Point.h
//  2D_RPG
//
//  Created by John Damits on 1/21/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef ___D_RPG__Point__
#define ___D_RPG__Point__

#include <stdio.h>

#endif /* defined(___D_RPG__Point__) */

class Point {
public:
    Point();
    Point(int, int);
    
    float getX();
    float getY();
    
    void setX(float);
    void setY(float);
    void setPoint(float, float);
private:
    float x, y;
};