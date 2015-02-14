//
//  InputEvent.h
//  2D_RPG
//
//  Created by John Damits on 2/12/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#ifndef ___D_RPG__InputEvent__
#define ___D_RPG__InputEvent__

#include <stdio.h>
#include "iostream"

#include "SDL2/SDL.h"
#include "document.h"

#endif /* defined(___D_RPG__InputEvent__) */

class InputEvent {
public:
    static int EventFilter(void*, SDL_Event*);
    static void loadInputContext(char*);
};