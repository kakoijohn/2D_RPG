//
//  MouseInput.h
//  2D_RPG
//
//  Created by John Damits on 2/8/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef ___D_RPG__MouseInput__
#define ___D_RPG__MouseInput__

#include <stdio.h>
#include "SDL2/SDL.h"

#endif /* defined(___D_RPG__MouseInput__) */

class MouseInput {
public:
    static int MouseEventFilter(void*, SDL_Event*);
};