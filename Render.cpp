//
//  Render.cpp
//  RPGGameEngine
//
//  Created by John Damits on 8/15/14.
//  Copyright (c) 2014 Squirrely Brace. All rights reserved.
//

#include "Render.h"

SDL_Renderer *SDLRender;
SDL_Surface *bmp;
Polygon triangle1(3);
Polygon triangle2(3);

Render::Render() {

}

int Render::init(SDL_Window *window) {
    InputEvent::loadState("default");

    triangle1.vert[0] = {150, 150};
    triangle1.vert[1] = {250, 250};
    triangle1.vert[2] = {250, 150};
    
    triangle2.vert[0] = {150, 150};
    triangle2.vert[1] = {250, 250};
    triangle2.vert[2] = {250, 150};
    
    triangle2.move({50, 50});
    
    SDLRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    bmp = SDL_LoadBMP("BaltImage.bmp");
    
    return 0;
}

void Render::updateDisplay() {
    SDL_RenderClear(SDLRender);
    
    if (Collision::isColliding(triangle1, triangle2))
        SDL_SetRenderDrawColor(SDLRender, 255, 0, 0, 255);
    else
        SDL_SetRenderDrawColor(SDLRender, 0, 255, 0, 255);
    
    triangle1.render(SDLRender);
    triangle1.rotate(.01, {160, 200});
    
    triangle2.render(SDLRender);
    triangle2.rotate(-.01, {250, 250});
    
    SDL_SetRenderDrawColor(SDLRender, 0, 0, 0, 255);
    
    SDL_RenderPresent(SDLRender);
}

void Render::freeResources() {
    SDL_DestroyRenderer(SDLRender);
    SDL_FreeSurface(bmp);
}

