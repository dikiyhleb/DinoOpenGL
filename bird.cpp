#include "bird.h"

void Bird::show()
{
    if (frameCounter % 150 == 0)
    {
        (textureBirdTemp == textureBirdUp) ? (textureBirdTemp = textureBirdDown) : (textureBirdTemp = textureBirdUp);
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureBirdTemp);

    glColor3f(1, 1, 1);
    glPushMatrix();

    glTranslatef(2.0f + this->x, 0.12f + this->y, 0.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexBird);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glPopMatrix();
}

void Bird::move()
{
    if (this->x > -3.0f)
    {
        this->x -= moveSpeed;
    }
    else
    {
        this->x = 0.3f;
    }
}
