#include "obstacle.h"
#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <math.h>

#include <iostream>
using namespace std;

Obstacle::Obstacle(GLfloat x_pos, GLfloat y_pos, string obj_type, int health)
{
    x = x_pos;
    y = y_pos;
    type = obj_type;
    hp = health;
    dead = false;
    w = 0.005;
    h = 0.005;
}

void Obstacle::update()
{
}

void Obstacle::render()
{
    glLoadIdentity( );
    glTranslatef(x, y, -5);

    glBegin(GL_QUADS);
    glVertex3f(-0.005, 0.005, 0);
    glVertex3f(0.005, 0.005, 0);
    glVertex3f(0.005, -0.005, 0);
    glVertex3f(-0.005, -0.005, 0);
    glEnd();
}

