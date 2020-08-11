// A figurable game object designed to be replaced
#pragma once
#include <string.h>
#include <iostream>
#include "raylib.h"


#define ASSET_PATH "../assets/"


class GameObject {
protected:
    std::string id;
    int x;
    int y;
    Texture2D texture;

public:
    // Constructors
    GameObject();
    GameObject(const char* fileName, int x_pos, int y_pos);

    // Deconstructor
    ~GameObject();

    // Set Textures
    void SetTextureFromPath(const char* path);

    // Draw on screen
    void Draw();
    void DrawInstance();

    // Get Texture
    Texture2D GetTexture();

    // Movement
    void SetX(int x_pox);       // Sets the X Position
    void SetY(int y_pos);       // Sets the Y Position
    void IncX(int val);         // Increments the X position by val
    void IncY(int val);         // Increments the Y position by val
    int GetX();                 // Gets the current X
    int GetY();                 // Get the current Y
};