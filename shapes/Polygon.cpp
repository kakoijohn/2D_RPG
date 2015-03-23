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

void Polygon::set(Point location) {
    Point original = vert.at(0);
    if (vert.size() > 1)
        for (int i = 1; i < vert.size(); i++) {
            vert.at(i).x = (vert.at(i).x - original.x) + location.x;
            vert.at(i).y = (vert.at(i).y - original.y) + location.y;
        }
    vert.at(0) = location;
}

void Polygon::resize(float percent) {
    for (int i = 0; i < vert.size(); i++) {
        vert.at(i).x *= percent;
        vert.at(i).y *= percent;
    }
}

Point Polygon::centroid() {
    float Cx;
    float Cy;

    for (int i = 0; i < vert.size(); i++) {
        Cx += vert.at(i).x;
        Cy += vert.at(i).y;
    }

    Cx = Cx / vert.size();
    Cy = Cy / vert.size();

    return {Cx, Cy};
}

void Polygon::pollEvents() {
    std::vector<eventData> &events = InputEvent::events;
    for (int i  = 0; i < events.size(); i++) {
        if (events.at(i).active == true) {
            if (events.at(i).identifier == polygon_drag_start) {
                oMousePos = {events.at(i).x, events.at(i).y};
                oPolyPos = vert.at(0);
            } else if (events.at(i).identifier == polygon_move)
                set({(events.at(i).x - oMousePos.x) + oPolyPos.x, (events.at(i).y - oMousePos.y) + oPolyPos.y});
            else if (events.at(i).identifier == polygon_rotate_right)
                rotate(.1, centroid());
            else if (events.at(i).identifier == polygon_rotate_left)
                rotate(-.1, centroid());
        }
    }
}

void Polygon::render(SDL_Renderer *SDLRender) {
    for (int i = 0; i < vert.size(); i++)
        if (i == vert.size() - 1)
            SDL_RenderDrawLine(SDLRender, vert.at(i).x, vert.at(i).y, vert[0].x, vert[0].y);
        else
            SDL_RenderDrawLine(SDLRender, vert.at(i).x, vert.at(i).y, vert[i + 1].x, vert[i + 1].y);
}
