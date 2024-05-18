#pragma once
#include "common.h"

#ifndef CACTUS_H
#define CACTUS_H

extern unsigned int textureCactus1, textureCactus2, textureCactus3, textureCactus4, textureCactus5;
extern float texCoord[], gameSpeed;
extern float vertexCactus[];

class Cactus
{
private:
    unsigned int textureCactusTemp = 1;
public:
    float x, y;
    float moveSpeed = 0.00065f * gameSpeed;

    Cactus()
    {
        x = 0.0f;
        y = 0.0f;
    }
    void show();
    void move();
};
#endif