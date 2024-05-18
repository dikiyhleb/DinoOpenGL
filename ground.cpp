#include "ground.h"

void Ground::move()
{
    if (this->x > -2)
    {
        this->x -= moveSpeed;
    }
    else
    {
        this->x = 2;
    }
}

void Ground::show()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureGround);

    glColor3f(1, 1, 1);
    glPushMatrix();

    glTranslatef(x, y - 0.1, 0.0);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexGround);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glPopMatrix();
}
