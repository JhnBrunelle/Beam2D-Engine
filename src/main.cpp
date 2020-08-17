#include "raylib.h"
#include <iostream>
#include "Core/Utils/Debug.hpp"
#include <string.h>
#include <sstream>

#include "Core/InputManager.h"
#include "Core/GameObject.h"
#include "../examples/bouncing-ball/BouncingBall.h"
#include "Core/Scenes/Scene.h"

#include <list>

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

// Change this depending on the path of your executable relative to the assets folder
#define ASSET_PATH "../assets/"

int main(void) {

    // Define game settings
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(240);               // Set our game to run at 60 frames-per-second

    Debug::Log("Game settings initialized");

    // Import input manager
    InputManager *im = new InputManager();

    // Define Scenes
    Scene *s = new Scene();

    // Draw Ball
    BouncingBall *bb = new BouncingBall("../assets/ball.png", 800 / 2, 450 / 2, 2);
    BouncingBall *bb2 = new BouncingBall("../assets/ball.png", 800 / 2, 450 / 2, 4);

    s->AddObject("ball", bb);
    s->AddObject("ball-", bb2);

    int ballcount = 0;

    // Main Game Loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        s->BatchUpdate();

        // Input
        im->TakeInput();

        // Scene test
        if(IsKeyPressed(KEY_SPACE)) {
            std::string toAdd = "ball" + std::to_string(ballcount);
            s->AddObject(toAdd, new BouncingBall{"../assets/ball.png", 800 / 2, 450 / 2, 2});
            ballcount++;
        } else if(IsKeyPressed(KEY_ENTER)){
            std::string toAdd = "ball" + std::to_string(ballcount);
            s->RemoveObject(toAdd);
            ballcount--;
        }

        // Draw
        BeginDrawing();

        // Background Clear
        ClearBackground(RAYWHITE);

        // Draw items
        s->BatchDraw();

        EndDrawing();


        im->TakeInput();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context

    return 0;
}