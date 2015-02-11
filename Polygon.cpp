//
//  Polygon.cpp
//  2D_RPG
//
//  Created by John Damits on 2/6/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Polygon.h"

Polygon::Polygon(int vertecies) {
    vert = new Point[vertecies];
    this->vertecies = vertecies;
}

void Polygon::freeResources() {
    delete vert;
}

void Polygon::rotate(float rad, Point point) {
    for (int i = 0; i < vertecies; i++) {
        float distance = sqrtf(powf((point.x - vert[i].x), 2) + powf((point.y - vert[i].y), 2));
        float theta = atan2f((vert[i].y - point.y), (vert[i].x - point.x));

        theta += rad;
        
        vert[i].x = point.x + distance * cosf(theta);
        vert[i].y = point.y + distance * sinf(theta);
    }
}
\
void Polygon::move(Point delta) {
    for (int i = 0; i < vertecies; i++) {
        vert[i].x += delta.x;
        vert[i].y += delta.y;
    }
}

void Polygon::render(SDL_Renderer *SDLRender) {
    for (int i = 0; i < vertecies; i++)
        if (i == vertecies - 1)
            SDL_RenderDrawLine(SDLRender, vert[i].x, vert[i].y, vert[0].x, vert[0].y);
        else
            SDL_RenderDrawLine(SDLRender, vert[i].x, vert[i].y, vert[i + 1].x, vert[i + 1].y);
}