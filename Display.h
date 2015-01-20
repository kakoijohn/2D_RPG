//
//  Display.h
//  RPGGameEngine
//
//  Created by John Damits on 8/15/14.
//  Copyright (c) 2014 Squirrely Brace. All rights reserved.
//

#ifndef __RPGGameEngine__Display__
#define __RPGGameEngine__Display__

#include <iostream>
#include <SDL2/SDL.h>

#endif /* defined(__RPGGameEngine__Display__) */

class Display {
public:
    Display(int, int);
    void destroyWindow();
private:
    void createWindow(int, int);
};