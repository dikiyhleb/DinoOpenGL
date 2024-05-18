#include "cactus.h"

void Cactus::show()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureCactusTemp);

    glColor3f(1, 1, 1);
    glPushMatrix();

    glTranslatef(1.2f + this->x, 0.0f + this->y, 0.0f);
    if (textureCactusTemp == textureCactus1 || textureCactusTemp == textureCactus2)
    {
        glScalef(0.5f, 1.0f, 1.0f);
    }


    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexCactus);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glPopMatrix();
}

void Cactus::move()
{
    if (this->x > -2.5)
    {
        this->x -= moveSpeed;
    }
    else
    {
        int randomNum;

        this->x = 0;
        this->y = 0;
        
        randomNum = 1 + rand() % 5;

        switch (randomNum)
        {
        case(1):
            textureCactusTemp = textureCactus1;
            break;
        case(2):
            textureCactusTemp = textureCactus2;
            break;
        case(3):
            textureCactusTemp = textureCactus3;
            break;
        case(4):
            textureCactusTemp = textureCactus4;
            break;
        case(5):
            textureCactusTemp = textureCactus5;
            break;
        default:
            break;
        }
    }
}
