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
    SDL_AddEventWatch(EventLog::EventFilter, nullptr);
    SDL_AddEventWatch(MouseInput::MouseEventFilter, nullptr);
    SDL_Event event;
	
	//display loop
    bool done = false;
    while (!done) {
        SDL_PumpEvents();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = true;
                break;
            }
        }
        
        render->updateDisplay();
    }
    
	render->freeResources();
	
	//close window and clean up
    SDL_DestroyWindow(window);
    SDL_Quit();
}

