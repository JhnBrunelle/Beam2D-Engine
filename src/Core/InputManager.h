#include "raylib.h"

class InputManager {
static InputManager *instance;
public:

    // Constructors
    InputManager();
    ~InputManager();

    // Takes input
    void TakeInput();

    static InputManager *getInstance(){
        if(!instance){
            instance = new InputManager;
        }
        return instance;
    }
};