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
Polygon triangle(2);

Render::Render() {

}

void Render::freeResources() {
    SDL_DestroyRenderer(SDLRender);
    SDL_FreeSurface(bmp);
    
    triangle.freeResources();
}

int Render::init(SDL_Window *window) {
    triangle.vert[0] = {150, 150};
    triangle.vert[1] = {250, 250};
    
    SDLRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    bmp = SDL_LoadBMP("BaltImage.bmp");
    
    return 0;
}

void Render::updateDisplay(int width, int height) {
    SDL_RenderClear(SDLRender);
    
    SDL_SetRenderDrawColor(SDLRender, 255, 0, 0, 255);
    
    triangle.render(SDLRender);
    triangle.rotate(.1, {200, 200});
    triangle.move({1, 1});
    
    SDL_SetRenderDrawColor(SDLRender, 0, 0, 0, 255);
    
    SDL_RenderPresent(SDLRender);
}

