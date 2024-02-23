#include "pch.h"

#include "House.h"
#include "Landscape.h"
#include <iostream>

#define PI  3.14159265358979323846
float WINDOW_HEIGHT_DIVIDE_WIDTH{ 0.75 };

using namespace std;


int main(void)
{
    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */

    int windowScale{1 };
    window = glfwCreateWindow(640 * windowScale, 480 * windowScale, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    

    House house1(-1.0f, -0.2f, -0.5f, 0.5f);
    House house2(-0.5f, -0.2f, -0.1f, 0.3f);
    House house3(0, -0.2f, 0.6f, 0.4f);
    House house4(0.63f, -0.2f, 1.0f, 0.6f);
    House house5(-0.9f, -1.0f, -0.2f, -0.3f);
    
    int time = 0;
    float color = -1.0;
    bool isDay = true;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);



        time += 1;
        color += 0.0001;

       
        drawLandScape(time % 20000 / 10000.0 - 1, isDay);
        drawShine(time % 20000 / 10000.0 - 1, isDay);
        glPushMatrix();

        house1.setRoofRGB(std::sin(time/10000. * PI / 2) * 255, 45, 20);
        house2.setRoofRGB(std::sin(time / 10000. * PI / 2) * 255, 215, 245);
        house3.setRoofRGB(std::sin(time / 10000. * PI / 2) * 255, 87, 178);
        house4.setRoofRGB(std::sin(time / 10000. * PI / 2) * 255, 234, 67);
        house5.setRoofRGB(std::sin(time / 10000. * PI / 2) * 255, 199, 87);
        
        house1.draw();
        house2.draw();
        house3.draw();
        house4.draw();
        house5.draw();
        glPopMatrix();
        
        if (time % 20000 == 0)
            isDay = !isDay;

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}