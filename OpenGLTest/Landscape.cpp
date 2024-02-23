#include "pch.h"
#include "Landscape.h"


extern float WINDOW_HEIGHT_DIVIDE_WIDTH;

void drawLandScape(float time, bool isDay)
{
    glPushMatrix();
    glColor3b(0.5f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(-1.0f, -0.1f);

    float r, g, b;
    if (isDay)
    {
        r = 79. * time * time + 176.0;
        g = -51. * time * time + 255;
        b = -18. * time * time + 247;
    }
    else
    {
        r = 248.0 * time * time + 6.;
        g = 189 * time * time + 15.;
        b = 155 * time * time + 74.;
    }

    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);

    glEnd();
    glPopMatrix();
}


void drawShine(float time, bool isDay)
{
    float diameter = 0.25;
    auto y_center = [&time]() {return 0.8 - 0.3 * time * time; };

    glPushMatrix();

    if (isDay)
        glColor3f(1.0f, 1.0f, 102 / 255.0f);
    else
        glColor3f(238 / 255.0f, 252 / 255.0f, 1.0f);

    glTranslatef(time, y_center(), 0);
    glBegin(GL_POLYGON);

    float x = 0;
    float y = 0;
    glVertex2f(x * WINDOW_HEIGHT_DIVIDE_WIDTH, y);
    for (int i{ 1 }; i < int(diameter * 100); ++i)
    {
        x = i / 100.;
        y = std::sqrt(std::pow(diameter / 2, 2) - std::pow(x - diameter / 2, 2));
        glVertex2f(x * WINDOW_HEIGHT_DIVIDE_WIDTH, y);
    }
    glVertex2f(diameter * WINDOW_HEIGHT_DIVIDE_WIDTH, 0);
    for (int i = int(diameter * 100) - 1; i > 0; --i)
    {
        x = i / 100.;
        y = -std::sqrt(std::pow(diameter / 2, 2) - std::pow(x - diameter / 2, 2));
        glVertex2f(x * WINDOW_HEIGHT_DIVIDE_WIDTH, y);
    }

    glEnd();
    glPopMatrix();

}
