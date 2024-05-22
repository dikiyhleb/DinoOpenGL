#pragma once
#include "common.h"

#ifndef SCORE_H
#define SCORE_H

extern unsigned int number0, number1, number2, number3, number4, number5, number6, number7, number8, number9;

class Score
{
private:
	int result;
protected:
	float vertexNum[12] = { -0.05,-0.05,0 , 0.05,-0.05,0 , 0.05,0.05,0 , -0.05,0.05,0 };
	float texCoord[8] = { 0,1 , 1,1 , 1,0 , 0,0 };
public:
	Score() 
	{
		result = 0;
	}
	void setResult(int result) { this->result = result; }
	int getResult() { return result; }
	void show();
};

class Num1 : public Score
{
private:
public:
	void show(unsigned int num)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, num);

		glColor3f(1, 1, 1);
		glPushMatrix();

		glTranslatef(0.8f, 0.6f, 0.0);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, vertexNum);
		glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glPopMatrix();
	}
};
class Num2 : public Score
{
private:
public:
	void show(unsigned int num)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, num);

		glColor3f(1, 1, 1);
		glPushMatrix();

		glTranslatef(0.7f, 0.6f, 0.0);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, vertexNum);
		glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glPopMatrix();
	}
};
class Num3 : public Score
{
private:
public:
	void show(unsigned int num)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, num);

		glColor3f(1, 1, 1);
		glPushMatrix();

		glTranslatef(0.6f, 0.6f, 0.0);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, vertexNum);
		glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glPopMatrix();
	}
};
#endif