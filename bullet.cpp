#include "bullet.h"
#include "obstacle.h"
#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

Bullet::Bullet(GLfloat x_pos, GLfloat y_pos, string obj_type, int damage, GLfloat speed, int start_angle)
{
    x = x_pos;
    y = y_pos;
    type = obj_type;
    hp = damage;
    spd = speed;
    angle = start_angle;
    dead = false;
}

void Bullet::update()
{
    x = x + cos(angle) * spd;
    y = y + sin(angle) * spd;
    if (fabs(x) >= 1 or fabs(y) >= 1)
        dead = true;
}

void Bullet::collision(Game_object& obj)
{
    if ( fabs(obj.get_x() - x) < obj.get_w() && fabs(obj.get_y() -y) < obj.get_h() )
    {
        int cur_hp = obj.get_hp() - hp;
        if (cur_hp <= 0)
        {
            obj.set_dead();
            hp = abs(cur_hp);
            if (hp == 0)
                dead = true;
        }
        else
        {
            obj.set_hp(cur_hp);
            dead = true;
        }
    }
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


