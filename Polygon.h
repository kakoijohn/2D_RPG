//
//  Polygon.h
//  2D_RPG
//
//  Created by John Damits on 2/6/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef ___D_RPG__Polygon__
#define ___D_RPG__Polygon__

#include <stdio.h>
#include "SDL2/SDL.h"

#include "math.h"
#include "vector"

#include "Structures.h"
#include "InputEvent.h"
#include "Identifiers.h"

#endif /* defined(___D_RPG__Polygon__) */

class Polygon {
public:
    Polygon(int);

    void rotate(float, Point);
    void move(Point);
    void set(Point);
    Point centroid();
    void render(SDL_Renderer*);
    void pollEvents();

    std::vector<Point> vert;
private:
    Point oPolyPos;
    Point oMousePos;
};