#include "bullet.h"
#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <math.h>

using namespace std;

Bullet::Bullet(GLfloat x_pos, GLfloat y_pos, string obj_type, int damage, GLfloat speed, int start_angle)
{
    x = x_pos;
    y = y_pos;
    type = obj_type;
    dmg = damage;
    spd = speed;
    angle = start_angle;
    dead = false;
}

void Bullet::update()
{
    x = x + cos(angle) * spd;
    y = y + sin(angle) * spd;
    if (abs(x) >= 1 or abs(y) >= 1)
        dead = true;
}

void Bullet::render()
{
    glLoadIdentity( );
    glTranslatef(x, y, -5);

    glBegin(GL_QUADS);
    glVertex3f(0, 0.009, 0);
    glVertex3f(0.005, 0, 0);
    glVertex3f(0, -0.009, 0);
    glVertex3f(-0.005, 0, 0);
    glEnd();
}

int Bullet::get_dmg() { return dmg; }


