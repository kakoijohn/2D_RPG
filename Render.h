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

#include "PlatformerPlaneRender.h"

class Render {
public:
	Render();
	void updateDisplay(int, int);
	void freeResources();
private:
	int init();
};