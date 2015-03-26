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
Manifold man;

Render::Render() {

}

int Render::init(SDL_Window *window) {
    InputEvent::loadState("default");

    triangle.vert[0] = {2, 1};
    triangle.vert[1] = {4, 1};
    triangle.vert[2] = {5, 3};
    triangle.vert[3] = {4, 5};
    triangle.vert[4] = {2, 5};
    triangle.vert[5] = {1, 3};

    triangle.resize(10);
    triangle.set({200, 50});

    triangle.density = 1;
    triangle.restitution = 0.5;
    triangle.initializeObject();

    base.vert[0] = {0, 490};
    base.vert[1] = {500, 490};

    base.density = 0;
    base.restitution = 0.5;
    base.initializeObject();

    SDLRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    return 0;
}

void Render::updateDisplay() {
    SDL_RenderClear(SDLRender);

    man.applyInteractions(triangle, base);

    if (man.colliding)
        SDL_SetRenderDrawColor(SDLRender, 255, 0, 0, 255);
    else
        SDL_SetRenderDrawColor(SDLRender, 0, 255, 0, 255);

//    if (Collision::isCollidingMouse(triangle))
        triangle.pollEvents();
//    else
//        Impulse::applyPhysics(triangle, Collision::isColliding(triangle, base));

    triangle.render(SDLRender);
    
    base.render(SDLRender);
    
    SDL_SetRenderDrawColor(SDLRender, 0, 0, 0, 255);
    
    SDL_RenderPresent(SDLRender);
}

void Render::freeResources() {
    SDL_DestroyRenderer(SDLRender);
}

