//
//  InputEvent.cpp
//  2D_RPG
//
//  Created by John Damits on 2/12/15.
//  Copyright (c) 2015 Squirrely Brace. All rights reserved.
//

#include "InputEvent.h"

rapidjson::Document InputEvent::KeyBindings;
std::vector<eventData> InputEvent::checkValues;
std::vector<eventData> InputEvent::activeEvents;

int InputEvent::EventFilter(void* userData, SDL_Event* event) {
    activeEvents.clear();

    if (!checkValues.empty())
        for (int i = 0; i < checkValues.size(); i++)
            if (event->type == checkValues.at(i).key_binding)
                if (checkEvent(checkValues.at(i), event) == 0)
                    return 0;

    return 1;
}

int InputEvent::checkEvent(eventData& data, SDL_Event* event) {
    switch (data.key_binding) {
        case SDL_KEYDOWN:
            if (event->key.keysym.sym == data.modifier)
                addActiveEvent(data, event);
            return 0;
        case SDL_KEYUP:
            if (event->key.keysym.sym == data.modifier)
                addActiveEvent(data, event);
            return 0;
        case SDL_MOUSEBUTTONDOWN:
            if (event->button.button == data.modifier)
                addActiveEvent(data, event);
            return 0;
        case SDL_MOUSEBUTTONUP:
            if (event->button.button == data.modifier)
                addActiveEvent(data, event);
            return 0;
        case SDL_MOUSEMOTION:
            if (event->button.button == data.modifier)
                addActiveEvent(data, event);
            return 0;
        case SDL_MOUSEWHEEL:
            addActiveEvent(data, event);
            return 0;
    }

    return 1;
}

void InputEvent::addActiveEvent(eventData& data, SDL_Event* event) {
    std::cout << "Event Handled: " << data.action << "\n";

    data.clicks = event->button.clicks;

    data.x = event->motion.x * data.normalization;
    data.y = event->motion.y * data.normalization;

    data.xrel = event->motion.xrel * data.normalization;
    data.yrel = event->motion.yrel * data.normalization;

    data.xwheel = event->wheel.x * data.normalization;
    data.ywheel = event->wheel.y * data.normalization;

    activeEvents.resize(activeEvents.size() + 1);
    activeEvents.back() = data;
}

void InputEvent::loadInputContext(const char* fileName) {
    FILE* file = fopen(fileName, "r"); //"r" is for read.
    rapidjson::FileStream inputStream(file);

    KeyBindings.ParseStream<0>(inputStream);

    fclose(file);
}

void InputEvent::loadState(const char* state) {
    const rapidjson::Value& currState = KeyBindings[state];

    checkValues.resize(currState.Size());
    SDL_Log("%d", currState.Size());
    for (int i = 0; i < currState.Size(); i++) {
        const rapidjson::Value& event = currState[i];
        eventData& data = checkValues.at(i);

        data.action        = event["action"].GetString();
        data.key_binding   = event["key_binding"].GetInt();
        data.normalization = event["normalization"].GetDouble();
        data.modifier      = event["modifier"].GetInt();

        data.clicks = 0;
        data.x      = 0;
        data.y      = 0;
        data.xrel   = 0;
        data.yrel   = 0;
        data.xwheel = 0;
        data.ywheel = 0;
    }
}

