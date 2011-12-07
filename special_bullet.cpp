#include "bullet.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <math.h>
#include "special_bullet.h"
#include <iostream>
#include <sstream>

using namespace std;   

Special_bullet::Special_bullet(GLfloat x_pos, GLfloat y_pos, string obj_type, int damage, GLfloat speed, GLfloat start_angle, vector<Game_object*>* pointer_score_vec_in, vector<Bullet*>* b_ptr) :Bullet(x_pos,y_pos,obj_type,damage,speed,start_angle,pointer_score_vec_in) 
{
    bullets = b_ptr;
    img = new Sprite("images/skott/skott01.png", 0.1, 0.1);
    int img_cnt = 1;
}

void Special_bullet::update()
{                                                         
    x = x + cos(angle) * spd;
    if (fabs(x) <= 0.4)
    {
        for (int i = 0; i < 12; i++)
        {
            bullets->push_back(new Bullet(x, y, obj_type, 1, 0.01, 2*3.14159*(rand() % 101)/100, &score_vec));
        }
        dead = true;
    }
}

void Special_bullet::render()
{
    stringstream out;
    string buffer;
    out << img_cnt;
    buffer = out.str();
    if (++img_cnt != 10)
        buffer = "0" + buffer;
    else
        img_cnt = 1;
    img->change_img("images/skott/skott"+buffer+".png", 0.1, 0.1);
}

void Special_bullet::collision(Game_object& obj)
{}
