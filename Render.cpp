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
SDL_Texture *tex;

Render::Render() {
    
}

int Render::init(SDL_Window *window) {
    SDLRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    bmp = SDL_LoadBMP("BaltImage.bmp");
    
    tex = SDL_CreateTextureFromSurface(SDLRender, bmp);
    
    return 0;
}

void Render::updateDisplay(int width, int height) {
    SDL_RenderClear(SDLRender);
    SDL_RenderCopy(SDLRender, tex, NULL, NULL);
    SDL_RenderPresent(SDLRender);
}

void Render::freeResources() {
    SDL_DestroyRenderer(SDLRender);
}
