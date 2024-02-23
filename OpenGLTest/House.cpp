#include "pch.h"
#include "House.h"


void House::drawRoof()
{
    glPushMatrix();
    glScalef(scale_X, scale_Y, 1);
    glBegin(GL_TRIANGLES);


    glColor3f(roofColor.R / 255.f, roofColor.G / 255.f, roofColor.B /255.f);

    glVertex2d(min_X, wallCeilingY);
    glVertex2d((max_X + min_X) / 2, max_Y);
    glVertex2d(max_X, wallCeilingY);

    glEnd();


    glPopMatrix();
}

void House::drawWalls()
{
    glPushMatrix();

    glScalef(scale_X, scale_Y, 1);
    glColor3f(wallColor.R, wallColor.G / 255.f, wallColor.B / 255.f);
    glBegin(GL_QUADS);

    glVertex2d(min_X, min_Y);
    glVertex2d(min_X, wallCeilingY);
    glVertex2d(max_X, wallCeilingY);
    glVertex2d(max_X, min_Y);

    glEnd();
    glPopMatrix();
}

void House::drawPipe()
{
    glPushMatrix();
    glScalef(scale_X, scale_Y, 1);
    glColor3f(128 / 255.f, 128 / 255.f, 128 / 255.f);
    glBegin(GL_QUADS);

    glVertex2f(max_X - (max_X - min_X) / 4, wallCeilingY);
    glVertex2f(max_X - (max_X - min_X) / 5, wallCeilingY);
    glVertex2f(max_X - (max_X - min_X) / 5, wallCeilingY + (max_Y - wallCeilingY) *1.2);
    glVertex2f(max_X - (max_X - min_X) / 4, wallCeilingY + (max_Y - wallCeilingY) * 1.2);


    glEnd();

    glPopMatrix();
}

void House::drawWindow()
{
    glPushMatrix();

    glScalef(scale_X, scale_Y, 1);
    glColor3f(0, 0, 1.0f);
    glBegin(GL_QUADS);

    glVertex2d(min_X + (max_X - min_X) / 5, min_Y + (wallCeilingY - min_Y) / 3);
    glVertex2d(min_X + (max_X - min_X) / 5, min_Y + 2 * (wallCeilingY - min_Y) / 3);
    glVertex2d(min_X + 2 * (max_X - min_X) / 5, min_Y + 2 * (wallCeilingY - min_Y) / 3);
    glVertex2d(min_X + 2 * (max_X - min_X) / 5, min_Y + (wallCeilingY - min_Y) / 3);

    glEnd();
    glPopMatrix();
}

void House::drawDoor()
{
    glPushMatrix();
    glColor3b(100., 61., 17.);
    glScalef(scale_X, scale_Y, 1);
    glBegin(GL_QUADS);

    glVertex2d(min_X + 3 * (max_X - min_X) / 5, min_Y);
    glVertex2d(min_X + 3 * (max_X - min_X) / 5, min_Y + 3 * (wallCeilingY - min_Y) / 5);
    glVertex2d(min_X + 4 * (max_X - min_X) / 5, min_Y + 3 * (wallCeilingY - min_Y) / 5);
    glVertex2d(min_X + 4 * (max_X - min_X) / 5, min_Y);

    glEnd();
    glPopMatrix();
}

void House::setRoofRGB(float R, float G, float B)
{
    roofColor.R = R;
    roofColor.G = G;
    roofColor.B = B;
}

void House::setWallsRGB(float R, float G, float B)
{
    wallColor.R = R;
    wallColor.G = G;
    wallColor.B = B;
}

