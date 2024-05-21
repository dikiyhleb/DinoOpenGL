#pragma once
#include "common.h"

using namespace std;

#ifndef GROUND_H
#define GROUND_H

extern unsigned int textureGround;
extern float texCoord[], gameSpeed;
extern float vertexGround[];

class Ground
{
private:
public:
    float x, y;
    float moveSpeed = 0.00065f * gameSpeed;

    Ground()
    {
        x = 0.0f;
        y = 0.0f;
    }

    void show();
    void move();
};

#endif