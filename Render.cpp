//
//  Render.cpp
//  RPGGameEngine
//
//  Created by John Damits on 8/15/14.
//  Copyright (c) 2014 Squirrely Brace. All rights reserved.
//

#include "Render.h"

SDL_Renderer *SDLRender;
Body triangle(6);
Body base(2);

Render::Render() {

}

int Render::init(SDL_Window *window) {
    InputEvent::loadState("default");

    triangle.s.vert[0] = {2, 1};
    triangle.s.vert[1] = {4, 1};
    triangle.s.vert[2] = {5, 3};
    triangle.s.vert[3] = {4, 5};
    triangle.s.vert[4] = {2, 5};
    triangle.s.vert[5] = {1, 3};

    triangle.s.resize(10);
    triangle.s.set({200, 50});

    triangle.material.density = .5;
    triangle.material.restitution = -0.5;
//    Impulse::initializeObject(triangle);

    base.s.vert[0] = {0, 490};
    base.s.vert[1] = {500, 490};
    
    SDLRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    return 0;
}

void Render::updateDisplay() {
    SDL_RenderClear(SDLRender);

    if (Collision::isColliding(triangle, base))
        SDL_SetRenderDrawColor(SDLRender, 255, 0, 0, 255);
    else
        SDL_SetRenderDrawColor(SDLRender, 0, 255, 0, 255);

    if (Collision::isCollidingMouse(triangle))
        triangle.s.pollEvents();

//    Impulse::applyPhysics(triangle, Collision::isColliding(triangle, base));

    triangle.s.render(SDLRender);
    
    base.s.render(SDLRender);
    
    SDL_SetRenderDrawColor(SDLRender, 0, 0, 0, 255);
    
    SDL_RenderPresent(SDLRender);
}

void Render::freeResources() {
    SDL_DestroyRenderer(SDLRender);
}

