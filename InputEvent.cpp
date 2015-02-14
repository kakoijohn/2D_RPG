//
//  InputEvent.cpp
//  2D_RPG
//
//  Created by John Damits on 2/12/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "InputEvent.h"

int InputEvent::EventFilter(void* userData, SDL_Event* event) {
    switch (event->type) {
        case SDL_MOUSEMOTION:
            SDL_Log("Mouse Moved. X=%d, Y=%d, Relative Y=%d", event->motion.x, event->motion.y, event->motion.yrel);
            return 0;
        case SDL_MOUSEBUTTONDOWN:
            SDL_Log("Mouse Button Down %d, %d", event->button.clicks, SDL_MOUSEBUTTONDOWN);
            return 0;
        case SDL_MOUSEBUTTONUP:
            SDL_Log("Mouse Button Up %d", event->button.button);
            return 0;
        case SDL_MOUSEWHEEL:
            SDL_Log("Mouse Wheel");
            return 0;
    }

    return 1;
}

void InputEvent::loadInputContext(char* fileName) {
    rapidjson::Document document;
    document.Parse<0>(fileName);
}

