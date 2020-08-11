//
// Created by John on 8/10/2020.
//

#include "InputManager.h"


InputManager::InputManager() {

}

InputManager::~InputManager() {

}

void InputManager::TakeInput() {
    if(IsKeyDown(KEY_W)){
        Debug::Log("Pressed!");
    }
}

