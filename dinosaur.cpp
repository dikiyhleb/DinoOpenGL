#include "dinosaur.h"

void Dinosaur::show()
{
    if (this->y <= 0.1)
    {
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        {
            if (frameCounter % 100 == 0)
            {
                (textureTemp == textureDinoBelowLeftUp) ? (textureTemp = textureDinoBelowRightUp) : (textureTemp = textureDinoBelowLeftUp);
            }
        }
        else
        {
            if (frameCounter % 100 == 0)
            {
                (textureTemp == textureDinoLeftUp) ? (textureTemp = textureDinoRightUp) : (textureTemp = textureDinoLeftUp);
            }
        }
    }
    else
    {
        textureTemp = textureDinoStand;
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureTemp);

    glColor3f(1, 1, 1);
    glPushMatrix();

    if (textureTemp == textureDinoBelowLeftUp || textureTemp == textureDinoBelowRightUp)
    {
        glScalef(1.0f, 0.65f, 1.0f);
    }

    glTranslatef(-0.7f + this->x, 0.0f + this->y, 0.0f);

    if (textureTemp == textureDinoBelowLeftUp || textureTemp == textureDinoBelowRightUp)
    {
        glScalef(1.2f, 1.0f, 1.0f);
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexDino);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glPopMatrix();
}

void Dinosaur::move()
{
    if (this->y < this->jumpHeight)
    {
        this->y += gravity;
    }
    if (this->y >= this->jumpHeight)
    {
        this->y -= gravity;
    }
    if (this->y + 0.02 > this->jumpHeight)
    {
        this->jumpHeight = 0;
    }
}

bool Dinosaur::bend()
{
    if (textureTemp == textureDinoBelowLeftUp || textureTemp == textureDinoBelowRightUp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Dinosaur::jump(float height)
{
    this->jumpHeight = height;
}
