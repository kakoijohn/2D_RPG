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
std::vector<char*> activeEvents;

int InputEvent::EventFilter(void* userData, SDL_Event* event) {
    if (!checkValues.empty())
        for (int i = 0; i < checkValues.size(); i++) {
            if (event->type == checkValues.at(i).key_binding)
                if (strncmp(checkValues.at(i).modifier, "", 0) == 0)

                std::cout << "Event Handled: " << checkValues.at(i).action << "\n";
        }

    return 1;
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

        checkValues.at(i).action        = event["action"].GetString();
        checkValues.at(i).key_binding   = event["key_binding"].GetInt();
        checkValues.at(i).normalization = event["normalization"].GetInt();
        checkValues.at(i).modifier      = event["modifier"].GetString();
    }
}

