#include "raylib.h"
#include <iostream>
#include "Core/Utils/Debug.hpp"
#include <string.h>

#include "Core/InputManager.h"
#include "Core/GameObject.h"
#include "../examples/bouncing-ball/BouncingBall.h"

#include <list>

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

// Change this depending on the path of your executable relative to the assets folder
#define ASSET_PATH "../assets/"

int main(void) {

    // Define game settings
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    Debug::Log("Game settings initialized");

    // Import input manager
    InputManager *im = new InputManager();


    // Draw Ball
    BouncingBall *bb = new BouncingBall("../assets/ball.png", 800 / 2, 450 / 2, 2);

    // Define scene objects & add objects to the scene
    std::list<GameObject *> sceneObjects;
    sceneObjects.push_back(bb);


    // Main Game Loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update Objects
        std::list<GameObject *>::iterator it;
        for (it = sceneObjects.begin(); it != sceneObjects.end(); ++it) {
            (*it)->Update();
        }


        // Input
        im->TakeInput();


        // Draw
        BeginDrawing();

        // Background Clear
        ClearBackground(RAYWHITE);

        // Draw items
        std::list<GameObject *>::iterator it2;
        for (it2 = sceneObjects.begin(); it2 != sceneObjects.end(); ++it2) {
            (*it2)->Draw();
        }

        EndDrawing();


        im->TakeInput();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context

    return 0;
}