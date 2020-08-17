#pragma once
#include <string.h>
#include <iostream>
#include "raylib.h"

/**
 * A drawable object on screen
 */
class GameObject {
protected:
    std::string id;                 // Id of the object
    int x;                          // x value on screen
    int y;                          // y value on screen
    int width;                      // objects width
    int length;                     // objects height
    Texture2D texture;              // Texture of the object
    bool debugOutline = false;      // Toggle debug rectangle for shape

public:
    // Constructors
    GameObject();
    GameObject(const char* fileName, const int &x_pos,const int &y_pos);

    // Deconstructor
    ~GameObject();

    // Set Textures
    void SetTextureFromPath(const char* path);

    // Draw on screen
    virtual void Draw();                            // Function called by scene drawer
    void DrawInstance();                            // Draw a single instance (out of draw loop)

    // Update method, must be overridden
    virtual void Update() = 0;                      // pure virtual function to be overriden

    // Get Texture
    Texture2D GetTexture();                         // Texture of the GameObject

    // Getters
    int GetX();                                     // Gets the current X
    int GetY();                                     // Get the current Y
    Rectangle GetBoundingBox();                     // Bounding rectangle

    // Setters
    void SetX(const int &x_pox);                    // Sets the X Position
    void SetY(const int &y_pos);                    // Sets the Y Position
    void IncX(const int &val);                      // Increments the X position by val
    void IncY(const int &val);                      // Increments the Y position by val
    void SetDebugOutline(const bool &debug);        // Sets the debug outline
};