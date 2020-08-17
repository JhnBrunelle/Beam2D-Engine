//
// Created by John on 8/10/2020.
//

#include "GameObject.h"


/**
 * Default constructor for A game object on screen
 */
GameObject::GameObject() {
    x = 0;
    y = 0;
    width = 0;
    length = 0;
}

/**
 * Parameterized constructor for a Game Object
 * @param fileName file location of the texture
 * @param x_pos initial x position
 * @param y_pos intital y position
 */
GameObject::GameObject(const char* fileName, const int &x_pos, const int &y_pos) {
    // Position
    x = x_pos;
    y = y_pos;

    // Load texture
    SetTextureFromPath(fileName);
}


/**
 * Deconstructor for GameObject
 */
GameObject::~GameObject() {
    // Free texture from memory
    UnloadTexture(texture);
}

/**
 * Loads a texture from file path
 * @param path file location of the texture
 */
void GameObject::SetTextureFromPath(const char* path) {
    texture = LoadTexture(path);

    // Set width and length
    width = this->texture.width / 2;
    length = this->texture.height / 2;
}

/**
 * Loads a texture from file path
 * @return Texture2D
 */
Texture2D GameObject::GetTexture(){
    return texture;
}

/**
 * Draws to the screen. Call required to be wrapped in OpenGL draw frame
 */
void GameObject::Draw(){
    // Draw debugging outline
    if(debugOutline == true){
        DrawRectangleLinesEx(this->GetBoundingBox(), 1, RED);
    }

}

/**
 * Draws to the screen. Call NOT required to be wrapped in OpenGL draw frame
 */
void GameObject::DrawInstance(){
    BeginDrawing();
    DrawTexture(texture, x, y, WHITE);
    EndDrawing();
}

/**
 * Sets the X position
 * @param x_pos reference to the new x position
 */
void GameObject::SetX(const int &x_pos) {
    x = x_pos;
}

/**
 * Sets the Y position
 * @param y_pos reference to the new y position
 */
void GameObject::SetY(const int &y_pos) {
    x = y_pos;
}

/**
 * Increments the X position by val amount
 * @param val amount to increment by
 */
void GameObject::IncX(const int &val) {
    x = x + val;
}

/**
 * Increments the Y position by val amount
 * @param val amount to increment by
 */
void GameObject::IncY(const int &val) {
    y = y + val;
}

/**
 * Returns the X value
 * @return x position
 */
int GameObject::GetX() {
    return x;
}

/**
 * Returns the Y value
 * @return y position
 */
int GameObject::GetY() {
    return y;
}

/**
 * Returns the bounding box of the object
 * @return Rectangle
 */
Rectangle GameObject::GetBoundingBox(){
    return Rectangle{float(x), float(y), float(width), float(length)};
}

/**
 * Sets the debug outline of the shape
 * @params debug true or false
 */
void GameObject::SetDebugOutline(const bool &debug){
    debugOutline = debug;
}


