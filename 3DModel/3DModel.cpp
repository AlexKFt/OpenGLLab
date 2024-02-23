#include "pch.h"

#include <iostream>

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */

    int windowScale{ 1 };
    window = glfwCreateWindow(640 * windowScale, 480 * windowScale, "3D model", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    //glOrtho(-2, 2, -2, 2, -2, 2);
    glEnable(GL_DEPTH_TEST); //Включить буфер глубины

    glFrustum(-2, 2, -2, 2, 2, 6);
    float vertices[] = {-1, -1, 0, 
                        1, -1, 0, 
                        1, 1, 0, 
                        -1, 1, 0,
                        -1, -1, 1,
                        1, -1, 1,
                        1, 1, 1,
                        -1, 1, 1};
    float angel = 0;

    while (!glfwWindowShouldClose(window))
    {

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Triangle 1
        /*glPushMatrix();
        glTranslatef(0, 0, -3.0f);
        
        glVertexPointer(3, GL_FLOAT, 0, &vertices);
        glEnableClientState(GL_VERTEX_ARRAY);

            glColor3f(0, 1.0f, 0);
            glDrawArrays(GL_QUADS, 0, 3);
        
        glDisableClientState(GL_VERTEX_ARRAY);

        glPopMatrix();*/

        angel += 0.0000001;
        glPushMatrix();
        glTranslatef(0, 0, -3.0f);
        glRotatef(angel * 0.004, 1.0f, 0, 0);
        glColor3f(0, 1.0f, 0);
        glBegin(GL_QUADS);
        /*for (int i{ 0 }; i < 12; i += 3)
        {
            glVertex3f(vertices[i], vertices[i + 1], vertices[i + 2]);
        }*/
        glColor3f(0, 0, 1.0f);
        for (int i{ 12 }; i < 24; i += 3)
        {
            glVertex3f(vertices[i], vertices[i + 1], vertices[i + 2]);
        }

        glEnd();

        glPopMatrix();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
