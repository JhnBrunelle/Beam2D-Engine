#include "raylib.h"
#include <iostream>
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

    // Define Debug Console

    // Define game settings
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(120);               // Set our game to run at 60 frames-per-second

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

        // Update each item
        s->BatchUpdate();

        // Input
        im->TakeInput();

        // Scene test
        if(IsKeyPressed(KEY_SPACE)) {
            s->GetDebugConsole()->FatalErrorMessage("[!] Oh No! - " + std::to_string(ballcount));
            std::string toAdd = "ball" + std::to_string(ballcount);
            s->AddObject(toAdd, new BouncingBall{"../assets/ball.png", 800 / 2, 450 / 2, 2});
            ballcount++;
        } else if(IsKeyPressed(KEY_ENTER)){
            std::string toAdd = "ball" + std::to_string(ballcount);
            s->RemoveObject(toAdd);
            ballcount--;
        } else if(IsKeyPressed(KEY_S)){
            s->GetDebugConsole()->ClearConsole();
        }

        // Draw
        BeginDrawing();

        // Background Clear
        ClearBackground(RAYWHITE);

        // Draw item
        DrawFPS(10,0);
        s->BatchDraw();


        EndDrawing();

        //db->ErrorMessage("Oh NO!");

        //db->DrawErrorText("OH NO");
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context

    return 0;
}