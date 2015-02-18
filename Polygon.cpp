//
//  Polygon.cpp
//  2D_RPG
//
//  Created by John Damits on 2/6/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "Polygon.h"

Polygon::Polygon(int vertecies) {
    vert.resize(vertecies);
}

void Polygon::rotate(float rad, Point point) {
    for (int i = 0; i < vert.size(); i++) {
        float distance = sqrtf(powf((point.x - vert.at(i).x), 2) + powf((point.y - vert.at(i).y), 2));
        float theta = atan2f((vert.at(i).y - point.y), (vert.at(i).x - point.x));

        theta += rad;
        
        vert.at(i).x = point.x + distance * cosf(theta);
        vert.at(i).y = point.y + distance * sinf(theta);
    }
}

void Polygon::move(Point delta) {
    for (int i = 0; i < vert.size(); i++) {
        vert.at(i).x += delta.x;
        vert.at(i).y += delta.y;
    }
}

void Polygon::render(SDL_Renderer *SDLRender) {
    for (int i = 0; i < vert.size(); i++)
        if (i == vert.size() - 1)
            SDL_RenderDrawLine(SDLRender, vert.at(i).x, vert.at(i).y, vert[0].x, vert[0].y);
        else
            SDL_RenderDrawLine(SDLRender, vert.at(i).x, vert.at(i).y, vert[i + 1].x, vert[i + 1].y);
}