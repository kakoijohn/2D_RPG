//
//  PlatformerPlaneRender.h
//  2D_RPG
//
//  Created by John Damits on 1/19/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef ___D_RPG__PlatformerPlaneRender__
#define ___D_RPG__PlatformerPlaneRender__

#include <stdio.h>

#endif /* defined(___D_RPG__PlatformerPlaneRender__) */

class PlatformerPlaneRender {
public:
    PlatformerPlaneRender();
    void updateDisplay(bool, int, int);
    void freeResources();
private:
    int init();
};