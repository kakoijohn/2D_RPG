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
#include "Structures.h"
#include "math.h"

#endif /* defined(___D_RPG__Polygon__) */

class Polygon {
public:
    Point *vert;
    
    Polygon(int);
    void freeResources();
    void rotate(float, Point);
    void move(Point);
    void render(SDL_Renderer*);
private:
    int vertecies;
};