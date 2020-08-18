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
#include "Core/Scenes/SceneManager.h"


#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

int main(void) {


    // Define game settings
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(120);                        // Set FPS

    // Import input manager
    InputManager *im = new InputManager();

    // Define Scenes
    Scene *s1 = new Scene();
    Scene *s2 = new Scene();

    int ballcount = 0;

    // Add objects to scene 1
    s1->AddObject("ball1", new BouncingBall("../assets/ball.png", 800 / 2, 450 / 2, 2));
    s1->AddObject("ball2", new BouncingBall("../assets/ball.png", 800 / 2, 450 / 2, 4));

    // Add Objects to Scene 2
    s2->AddObject("S1", new BouncingBall("../assets/dog.png", 800 / 2, 450 / 2, 2));

    // new scene manager
    SceneManager *sm = new SceneManager();

    sm->AddScene("first", s1);
    sm->AddScene("second", s2);
    // Main Game Loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Scenes test
        if(IsKeyPressed(KEY_SPACE)) {
            sm->LoadScene("second");
        } else if(IsKeyPressed(KEY_ENTER)){
            sm->LoadScene("first");

        } else if(IsKeyPressed(KEY_S)){

        }

        sm->ActiveSceneLoop();

    }

    // De-init OpenGL + Raylib
    CloseWindow();        // Close window and OpenGL context

    return 0;
}