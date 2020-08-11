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
}

GameObject::GameObject(const char* fileName, int x_pos, int y_pos) {
    x = x_pos;
    y = y_pos;
    SetTextureFromPath(fileName);

}

GameObject::~GameObject() {

}

void GameObject::SetTextureFromPath(const char* path) {
    texture = LoadTexture(path);
}

Texture2D GameObject::GetTexture(){
    return texture;
}

void GameObject::Draw(){
    // Draw texture on screen
    DrawTextureRec(texture, Rectangle{float(x), float(y), 64, 64}, Vector2{20, 20}, WHITE);

}

void GameObject::DrawInstance(){
    BeginDrawing();
    DrawTexture(texture, x, y, WHITE);
    EndDrawing();
}

void GameObject::SetX(int x_pos) {
    x = x_pos;
}

void GameObject::SetY(int y_pos) {
    x = y_pos;
}

void GameObject::IncX(int val) {
    x = x + val;
}

void GameObject::IncY(int val) {
    y = y + val;
}

int GameObject::GetX() {
    return x;
}

int GameObject::GetY() {
    return x;
}


