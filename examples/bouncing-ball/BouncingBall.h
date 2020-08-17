//
// Created by John on 8/10/2020.
//
#include "../../src/Core/GameObject.h"

class BouncingBall : public GameObject {

public:
    BouncingBall();
    BouncingBall(const char* fileName, int x_pos, int y_pos, int sp);
    void Update();
    void Draw();
private:
    int boundX = 800;
    int boundY = 450;
    int xDir = 1;
    int yDir = 1;
    int speed;

};