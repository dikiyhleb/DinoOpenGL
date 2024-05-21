#include "Object.h"

Object::Object(float startX, float startY)
{
    this->x = startX;
    this->y = startY;
}

void Object::show()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glColor3f(1, 1, 1);
    glPushMatrix();

    if (texture == textureDinoBelowLeftUp || texture == textureDinoBelowRightUp)
    {
        glScalef(1.0f, 0.65f, 1.0f);
    }

    glTranslatef(this->x, this->y, 0.0f);

    if (texture == textureCactus1 || texture == textureCactus2)
    {
        glScalef(0.5f, 1.0f, 1.0f);
    }

    if (texture == textureDinoBelowLeftUp || texture == textureDinoBelowRightUp)
    {
        glScalef(1.2f, 1.0f, 1.0f);
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexTemp);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glPopMatrix();
}