/**
 * File used to manage the user keyboard input
 */

#include "Utils/Debug.hpp"
#include "raylib.h"

class InputManager {
static InputManager *instance;
public:
    InputManager();
    ~InputManager();

    void TakeInput();

    static InputManager *getInstance(){
        if(!instance){
            instance = new InputManager;
        }
        return instance;
    }
};