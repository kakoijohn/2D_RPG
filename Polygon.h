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

#include "InputEvent.h"
#include "Identifiers.h"
#include "PhysicsConstants.h"

#endif /* defined(___D_RPG__Polygon__) */

class Polygon {
public:
    Polygon(int);

    void rotate(float, Vect);
    void move(Vect);
    void set(Vect);
    void resize(float);
    Vect centroid();
    Vect normalFace(int);
    void render(SDL_Renderer*);
    void pollEvents();

    std::vector<Vect> vert;
private:
    Vect oPolyPos;
    Vect oMousePos;
};