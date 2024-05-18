#pragma once
#include "common.h"

#ifndef BIRD_H
#define BIRD_H

extern unsigned int textureBirdUp, textureBirdDown;
extern int frameCounter;
extern float texCoord[], gameSpeed;
extern float vertexBird[];

class Bird
{
private:
	unsigned int textureBirdTemp;
public:
	float x, y;
	float moveSpeed = 0.0007f * gameSpeed;

	Bird() 
	{
		x = 0.0f;
		y = 0.0f;
	}

	void show();
	void move();
};

#endif // !BIRD_H