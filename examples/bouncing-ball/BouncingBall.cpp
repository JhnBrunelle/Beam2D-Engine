#include "BouncingBall.h"
#include "../../src/Core/Utils/Debug.hpp"

BouncingBall::BouncingBall(){

}

BouncingBall::BouncingBall(const char* fileName, int x_pos, int y_pos, int sp) {
    x = x_pos;
    y = y_pos;
    speed = sp;
    SetTextureFromPath(fileName);

}

void BouncingBall::Update(){

    // Change Direction
    if(( x >= boundX - texture.width/2) || (x <= 0)){
        xDir *= -1;
    }

    if(( y >= boundY - texture.height/2) || (y <= 0 )){
        yDir *= -1;
    }

    IncX(speed*xDir);
    IncY(speed*yDir);

}

void BouncingBall::Draw(){

    Vector2 position = { float(x), float(y) };
    Rectangle frameRec = { float(x), float(y), 128 / 2, 128 / 2 };

    //DrawTextureRec(texture, frameRec, position, WHITE);
    DrawTextureEx(texture, position, 0.f, 0.5f, WHITE);

    if(debugOutline == true){
        std::cout << "Debug Me" << std::endl;
        DrawRectangleLinesEx(this->GetBoundingBox(),1, RED);
    }
}