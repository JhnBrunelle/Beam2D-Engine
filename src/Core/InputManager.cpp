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

