#pragma once
#include "common.h"

#ifndef OBJECT_H
#define OBJECT_H

extern GLFWwindow* window;
extern float gameSpeed;
extern unsigned int textureBirdUp, textureBirdDown, textureDinoStand, textureDinoLeftUp, textureDinoRightUp,
	textureDinoBelowLeftUp, textureDinoBelowRightUp, textureCactus1, textureCactus2, textureCactus3, 
	textureCactus4, textureCactus5, textureGround;
extern int frameCounter;

class Object
{
protected:
	unsigned int texture;
	float vertex[12] = { -0.1,-0.1,0 , 0.1,-0.1,0 , 0.1,0.1,0 , -0.1,0.1,0 };
	float vertexGround[12] = { -1,-1,0 , 1,-1,0 , 1,1,0 , -1,1,0 };
	float vertexTemp[12];
	float texCoord[8] = { 0,1 , 1,1 , 1,0 , 0,0 };
	float moveSpeed = 0.00065f * gameSpeed;
private:
	float x, y;
public:
	Object(float startX, float startY);

	void show();

	void setX(float valueX) { this->x = valueX; }
	void setY(float valueY) { this->y = valueY; }
	float getX() { return this->x; }
	float getY() { return this->y; }

};

class Bird : public Object
{
private:

public:
	Bird(): Object(2.0f, 0.12f) 
	{
		std::memcpy(this->vertexTemp, this->vertex, sizeof(this->vertex));
		this->texture = textureBirdUp;
		this->moveSpeed = 0.0009f * gameSpeed;
	}

	void move()
	{
		if (this->getX() > -1.2f)
		{
			this->setX(this->getX() - moveSpeed);
		}
		else
		{
			this->setX(1.5f);
		}
		//std::cout << this->getX() << "    " << this->getY() << std::endl;
	}
	void show() 
	{
		if (frameCounter % 150 == 0)
		{
			(texture == textureBirdUp) ? (texture = textureBirdDown) : (texture = textureBirdUp);
		}
		Object::show();
	}
};

class Dinosaur : public Object
{
private:
	float jumpHeight;
	float gravity = 0.00065f * gameSpeed;
public:
	Dinosaur() : Object(-0.7, 0.0)
	{
		std::memcpy(this->vertexTemp, this->vertex, sizeof(this->vertex));
		jumpHeight = 0;
		texture = textureDinoStand;
	}

	void move() 
	{
		if (this->getY() < this->jumpHeight)
		{
			this->setY(this->getY() + gravity);
		}
		if (this->getY() >= this->jumpHeight)
		{
			this->setY(this->getY() - gravity);
		}
		if (this->getY() + 0.02 > this->jumpHeight)
		{
			this->jumpHeight = 0;
		}
	}
	void show()
	{
		if (this->getY() <= 0.1)
		{
			if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
			{
				if (frameCounter % 100 == 0)
				{
					(texture == textureDinoBelowLeftUp) ? (texture = textureDinoBelowRightUp) : (texture = textureDinoBelowLeftUp);
				}
			}
			else
			{
				if (frameCounter % 100 == 0)
				{
					(texture == textureDinoLeftUp) ? (texture = textureDinoRightUp) : (texture = textureDinoLeftUp);
				}
			}
		}
		else
		{
			texture = textureDinoStand;
		}

		Object::show();
	}
	bool bend()
	{
		if (this->texture == textureDinoBelowLeftUp || this->texture == textureDinoBelowRightUp)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void jump(float height) 
	{
		this->jumpHeight = height;
	}
	bool jumpOverObstacle(float x, float y)
	{
		if ((this->getX() + 0.0004 >= x) &&
			(this->getX() <= x + 0.0004) &&
			(this->getY() + 0.0004 >= y)) {
			return true;
		}
		return false;
	}
};

class Cactus : public Object
{
private:

public:
	Cactus(float startX = 0.0f, float startY = 0.0f) : Object(1.2f + startX, 0.0f + startY)
	{
		std::memcpy(this->vertexTemp, this->vertex, sizeof(this->vertex));
		texture = 1;
	}
	void move()
	{
		if (this->getX() > -1.5)
		{
			this->setX(this->getX() - moveSpeed);
		}
		else
		{
			int randomNum;

			this->setX(1.8f);
			this->setY(0.0f);

			randomNum = 1 + rand() % 5; 

			switch (randomNum)
			{
			case(1):
				this->texture = textureCactus1;
				break;
			case(2):
				this->texture = textureCactus2;
				break;
			case(3):
				this->texture = textureCactus3;
				break;
			case(4):
				this->texture = textureCactus4;
				break;
			case(5):
				this->texture = textureCactus5;
				break;
			default:
				break;
			}
		}
	}
};

class Ground : public Object
{
private:

public:
	Ground() : Object(0.0, -0.1)
	{
		std::memcpy(this->vertexTemp, this->vertexGround, sizeof(this->vertexGround));
		texture = 9;
	}
	void move()
	{
		if (this->getX() > -2)
		{
			this->setX(this->getX() - moveSpeed);
		}
		else
		{
			this->setX(2);
		}
	}
};
#endif