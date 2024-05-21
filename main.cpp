#include "common.h"
//#include "ground.h"
#include "Object.h"
#include "score.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

GLFWwindow* window;

int screenWidth = 500;
int screenHeight = 500;
int frameCounter;

int width, height, cnt;

unsigned int textureDinoStand, textureDinoLeftUp, textureDinoRightUp, textureDinoBelowLeftUp, textureDinoBelowRightUp,
textureGround, textureCactus1, textureCactus2, textureCactus3, textureCactus4, textureCactus5, number0, number1,
number2, number3, number4, number5, number6, number7, number8, number9, textureBirdUp, textureBirdDown;

float gameSpeed = 1.25f;

float vertexNum[] = { -0.05,-0.05,0 , 0.05,-0.05,0 , 0.05,0.05,0 , -0.05,0.05,0 };

float texCoord[] = { 0,1 , 1,1 , 1,0 , 0,0 };

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void checkCollision(Dinosaur &dino, Bird& bird, Cactus &cactus1, Cactus& cactus2) {
    if (dino.getY() < 0.2)
    {
        if (cactus1.getX() > dino.getX())
        {
            if (cactus1.getX() - dino.getX() < 0.125)
            {
                glfwSetWindowShouldClose(window, GL_TRUE);
            }
        }
        if (cactus2.getX() > dino.getX())
        {
            if (cactus2.getX() - dino.getX() < 0.125)
            {
                glfwSetWindowShouldClose(window, GL_TRUE);
            }
        }
    }
    if (!dino.bend())
    {
        if (dino.getY() < 0.2)
        {
            if (bird.getX() > dino.getX())
            {
                if (bird.getX() - dino.getX() < 0.125)
                {
                    glfwSetWindowShouldClose(window, GL_TRUE);
                }
            }
        }
    }
}

void initGame()
{
    unsigned char* data = stbi_load("images/Cactus-1.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureCactus1);
    glBindTexture(GL_TEXTURE_2D, textureCactus1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);

    unsigned char* data1 = stbi_load("images/Cactus-2.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureCactus2);
    glBindTexture(GL_TEXTURE_2D, textureCactus2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data1);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data1);

    unsigned char* data2 = stbi_load("images/Cactus-3.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureCactus3);
    glBindTexture(GL_TEXTURE_2D, textureCactus3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data2);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data2);

    unsigned char* data3 = stbi_load("images/Cactus-4.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureCactus4);
    glBindTexture(GL_TEXTURE_2D, textureCactus4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data3);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data3);

    unsigned char* data4 = stbi_load("images/Cactus-5.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureCactus5);
    glBindTexture(GL_TEXTURE_2D, textureCactus5);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data4);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data4);

    unsigned char* data5 = stbi_load("images/Dino-stand.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureDinoStand);
    glBindTexture(GL_TEXTURE_2D, textureDinoStand);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data5);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data5);

    unsigned char* data6 = stbi_load("images/Dino-left-up.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureDinoLeftUp);
    glBindTexture(GL_TEXTURE_2D, textureDinoLeftUp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data6);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data6);

    unsigned char* data7 = stbi_load("images/Dino-right-up.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureDinoRightUp);
    glBindTexture(GL_TEXTURE_2D, textureDinoRightUp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data7);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data7);

    unsigned char* data8 = stbi_load("images/NewGround.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureGround);
    glBindTexture(GL_TEXTURE_2D, textureGround);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data8);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data8);

    unsigned char* num0 = stbi_load("images/0.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number0);
    glBindTexture(GL_TEXTURE_2D, number0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num0);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num0);

    unsigned char* num1 = stbi_load("images/1.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number1);
    glBindTexture(GL_TEXTURE_2D, number1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num1);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num1);

    unsigned char* num2 = stbi_load("images/2.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number2);
    glBindTexture(GL_TEXTURE_2D, number2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num2);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num2);

    unsigned char* num3 = stbi_load("images/3.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number3);
    glBindTexture(GL_TEXTURE_2D, number3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num3);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num3);

    unsigned char* num4 = stbi_load("images/4.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number4);
    glBindTexture(GL_TEXTURE_2D, number4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num4);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num4);

    unsigned char* num5 = stbi_load("images/5.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number5);
    glBindTexture(GL_TEXTURE_2D, number5);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num5);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num5);

    unsigned char* num6 = stbi_load("images/6.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number6);
    glBindTexture(GL_TEXTURE_2D, number6);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num6);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num6);

    unsigned char* num7 = stbi_load("images/7.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number7);
    glBindTexture(GL_TEXTURE_2D, number7);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num7);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num7);

    unsigned char* num8 = stbi_load("images/8.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number8);
    glBindTexture(GL_TEXTURE_2D, number8);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num8);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num8);

    unsigned char* num9 = stbi_load("images/9.png", &width, &height, &cnt, 0);
    glGenTextures(1, &number9);
    glBindTexture(GL_TEXTURE_2D, number9);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, num9);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(num9);

    unsigned char* data9 = stbi_load("images/Dino-below-left-up.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureDinoBelowLeftUp);
    glBindTexture(GL_TEXTURE_2D, textureDinoBelowLeftUp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data9);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data9);

    unsigned char* data10 = stbi_load("images/Dino-below-right-up.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureDinoBelowRightUp);
    glBindTexture(GL_TEXTURE_2D, textureDinoBelowRightUp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data10);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data10);

    unsigned char* data11 = stbi_load("images/Bird-up.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureBirdUp);
    glBindTexture(GL_TEXTURE_2D, textureBirdUp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data11);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data11);

    unsigned char* data12 = stbi_load("images/Bird-down.png", &width, &height, &cnt, 0);
    glGenTextures(1, &textureBirdDown);
    glBindTexture(GL_TEXTURE_2D, textureBirdDown);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data12);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data12);
}

int main(void)
{
    char user_key;
    Dinosaur dino;
    Bird bird;
    Cactus cactus1, cactus2;
    Ground field1, field2;


    Score points;
  
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(screenWidth, screenHeight, "Dinosaur", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    initGame();
    field2.setX(2.0);
    cactus2.setX(2.3);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        field1.show();
        field2.show();
        points.show();
        bird.show();

        if (dino.getY() <= 0.01)
        {
            if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
            {
                dino.jump(0.4);
            }
        }
        
        field1.move();
        field2.move();

        dino.move();
        bird.move();
        cactus1.move();
        cactus2.move();

       
        dino.show();
        cactus1.show();
        cactus2.show();

        if (dino.jumpOverObstacle(cactus1.getX(), cactus1.getY()) || dino.jumpOverObstacle(cactus2.getX(), cactus2.getY()))
        {
            points.result += 1;
        }

        checkCollision(dino, bird, cactus1, cactus2);

        glfwSwapBuffers(window);
        glfwPollEvents();
        frameCounter++;
    }
    glfwTerminate();
    return 0;
}