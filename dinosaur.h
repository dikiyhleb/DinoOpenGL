#pragma once
#include "common.h"

#ifndef DINOSAUR_H
#define DINOSAUR_H

extern unsigned int textureDinoStand, textureDinoLeftUp, textureDinoRightUp, textureDinoBelowLeftUp, textureDinoBelowRightUp;
extern int frameCounter;
extern float texCoord[], gameSpeed;
extern float vertexDino[];
extern GLFWwindow* window;

class Dinosaur
{
private:
    unsigned int textureTemp;
public:
    float x, y, jumpHeight;
    float gravity = 0.00065f * gameSpeed;

    Dinosaur()
    {
        x = 0.0f;
        y = 0.0f;
        jumpHeight = 0;
        textureTemp = textureDinoStand;
    }
    ~Dinosaur()
    {

    }

    void show();
    void move();
    bool bend();
    void jump(float height);
};
#endif