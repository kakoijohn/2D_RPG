//
//  Render.h
//  RPGGameEngine
//
//  Created by John Damits on 8/15/14.
//  Copyright (c) 2014 Squirrely Brace. All rights reserved.
//

#ifndef __RPGGameEngine__Render__
#define __RPGGameEngine__Render__

#endif /* defined(__RPGGameEngine__Render__) */

#include "iostream"
#include "SDL2/SDL.h"
#include "Polygon.h"

class Render {
public:
	Render();
    int init(SDL_Window*);
	void updateDisplay(int, int);
	void freeResources();
};