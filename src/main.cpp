#include "raylib.h"
#include <iostream>
#include "Core/Utils/Debug.hpp"
#include <string.h>

#include "Core/InputManager.h"
#include "Core/GameObject.h"
#include "BouncingBall.h"

#include <list>

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

// Change this depending on the path of your executable relative to the assets folder
#define ASSET_PATH "../assets/"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");

    Texture2D texture = LoadTexture(ASSET_PATH"test.png");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

     Debug::Log("Hello");
     //Debug::Log(3);

    InputManager* im = new InputManager();


    // Draw Ball
    BouncingBall* bb = new BouncingBall("../assets/ball.png", 800/2 , 450/2, 2);
    BouncingBall* bb2 = new BouncingBall("../assets/ball.png", 100 , 20, 3);
    BouncingBall* bb3 = new BouncingBall("../assets/ball.png", 100 , 60, 5);
    BouncingBall* bb4 = new BouncingBall("../assets/ball.png", 100 , 120, 2);

    std::list<BouncingBall*> objects;
    objects.push_back(bb);
    objects.push_back(bb2);
    objects.push_back(bb3);
    objects.push_back(bb4);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
          // Update
          bb->Update();
          bb2->Update();
          bb3->Update();
          bb4->Update();

          // Input
           im->TakeInput();


          // Draw
          BeginDrawing();
          ClearBackground(RAYWHITE);

          // Draw items
          std::list<BouncingBall*>::iterator it;
          for (it = objects.begin(); it != objects.end(); ++it){
              (*it)->Draw();
          }
//          bb->Draw();
//          bb2->Draw();
          const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
          const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;


            const char* text = "IT WORKS!";
            const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
            DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);

          EndDrawing();



        im->TakeInput();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context

    return 0;
}