//
//  Display.cpp
//  RPGGameEngine
//
//  Created by John Damits on 8/15/14.
//  Copyright (c) 2014 Squirrely Brace. All rights reserved.
//

#include "Display.h"

Display::Display(int width, int height) {
    createWindow(width, height);
}

//Event Filter
//Polls events earlier in the thread so that it updates immediately each frame with no buffer. Much more efficient than using SDL_Event.
int EventFilter(void* userData, SDL_Event* event) {
    switch (event->type) {
        case SDL_KEYDOWN:
            SDL_Log("Key Down %d", event->key.keysym.sym);
            return 0;
        case SDL_KEYUP:
            SDL_Log("Key Up %d", event->key.keysym.sym);
            return 0;
        case SDL_MOUSEMOTION:
            SDL_Log("Mouse Moved. X=%d, Y=%d, Relative Y=%d", event->motion.x, event->motion.y, event->motion.yrel);
            return 0;
        case SDL_MOUSEBUTTONDOWN:
            SDL_Log("Mouse Button Down %d", event->button.button);
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

//create window
void Display::createWindow(int width, int height) {
    //initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
    
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
    
    //create window
    SDL_Window *window = SDL_CreateWindow("RPG Game Engine", 4, 4, width, height, SDL_WINDOW_SHOWN);
    
    if (window == 0)
        SDL_Quit();
    
    std::unique_ptr<Render> render = std::unique_ptr<Render>(new Render());
    render->init(window);
    
	//event handlers
	SDL_AddEventWatch(EventFilter, nullptr);
    SDL_Event event;
	
	//display loop
    bool done = false;
    while (!done) {
        SDL_PumpEvents();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = true;
                    break;
            }
        }
		
		render->updateDisplay(width, height);
    }
    
	render->freeResources();
	
	//close window and clean up
    SDL_DestroyWindow(window);
    SDL_Quit();
}

