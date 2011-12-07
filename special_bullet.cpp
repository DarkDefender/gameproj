#include "bullet.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <math.h>
#include "special_bullet.h"
#include <iostream>

using namespace std;   

Special_bullet::Special_bullet(GLfloat x_pos, GLfloat y_pos, string obj_type, int damage, GLfloat speed, GLfloat start_angle, vector<Game_object*>* pointer_score_vec_in, vector<Bullet>* b_ptr) : Bullet(x_pos,y_pos,obj_type,damage,speed,start_angle,pointer_score_vec_in)
{
    bullets = b_ptr;
}

void Special_bullet::update()
{                                                         
    x = x + cos(angle) * spd;
    if (fabs(x) == 0.4)
        dead = true;
}

override void Special_bullet::collision(Game_object&) { cerr << "hej"; }

void Special_bullet::render()
{
    if (dead)
    {
        for (int i = 0; i < 12; i++)
        {
            bullets->push_back(Bullet(x, y, obj_type, 1, 0.01, (rand() % 101)/100, &score_vec));
        }
    }                                
}
