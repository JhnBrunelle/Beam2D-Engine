#include "raylib.h"
#include <iostream>
#include <string.h>
#include <sstream>

// Core engine Imports
#include "Core/InputManager.h"
#include "Core/GameObject.h"
#include "Core/Scenes/Scene.h"

// Game Object imports
#include "../examples/bouncing-ball/BouncingBall.h"


#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

int main(void) {


    // Define game settings
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(120);                        // Set FPS

    // Import input manager
    InputManager *im = new InputManager();

    // Define Scenes
    Scene *s = new Scene();

    int ballcount = 0;

    s->AddObject("ball1", new BouncingBall("../assets/ball.png", 800 / 2, 450 / 2, 2));
    s->AddObject("ball2", new BouncingBall("../assets/ball.png", 800 / 2, 450 / 2, 4));

    // Main Game Loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update each item
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
        } else if(IsKeyPressed(KEY_S)){

        }

        // Draw
        BeginDrawing();

        // Background Clear
        ClearBackground(RAYWHITE);

        // Draw item
        DrawFPS(10,0);
        s->BatchDraw();


        EndDrawing();

    }

    // De-init OpenGL + Raylib
    CloseWindow();        // Close window and OpenGL context

    return 0;
}