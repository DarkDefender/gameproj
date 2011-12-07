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
    img = new Sprite("images/skott/skott_01.png", 0.1, 0.1);
    img_cnt = 1;
}

void Special_bullet::update()
{                                                         
    x = x + cos(angle) * spd;
    if (fabs(x) <= 0.4)
    {
        string owner;            //This shouldn't be required, but couldn't pass on obj_type for some reason
        if (x < 0)
            owner = "player1";
        else
            owner = "player2";
        for (int i = 0; i < 12; i++)
        {
            bullets->push_back(new Bullet(x, y, owner, 1, 0.01, 2*3.14159*(rand() % 101)/100, &score_vec));
        }
        dead = true;
    }
}

void Special_bullet::render()
{
    stringstream out;
    string buffer;
    if (++img_cnt != 10)
    {
        out << img_cnt;
        buffer = out.str();
        buffer = "0" + buffer;
        img->change_img("images/skott/skott_"+buffer+".png", 0.1, 0.1);
    }
    else
        img_cnt = 1;
    if (x < 0)
        img->render(x, y, -5, 0);
    else
        img->render(x, y, -5, 180);
}

void Special_bullet::collision(Game_object& obj)
{}

Special_bullet::~Special_bullet() { delete img; }
