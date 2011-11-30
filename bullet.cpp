#include "bullet.h"
#include "obstacle.h"
#include "game_object.h"
#include "sprite.h"
#include "score.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

Bullet::Bullet(GLfloat x_pos, GLfloat y_pos, string obj_type, int damage, GLfloat speed, GLfloat start_angle,  vector <Game_object*>* pointer_score_vec_in)
{
  
    score_vec = *pointer_score_vec_in;
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
    if (fabs(x) >= 1.3 or fabs(y) >= 1.3)
        dead = true;
}

void Bullet::collision(Game_object& obj)
{ 
    if (type != obj.get_type() and fabs(obj.get_x() - x) < obj.get_w()/2 and fabs(obj.get_y() -y) < obj.get_h()/2 )
    {
        int cur_hp = obj.get_hp() - hp;
        if (cur_hp <= 0)
        {
            obj.set_dead();
            hp = abs(cur_hp);
            if (hp == 0)
	      dead = true;

	    for (unsigned int it = 0;
		 it < score_vec.size(); it++ )
	      {
		if (type == score_vec[it] -> get_type())
		  score_vec[it] -> add_score(1);
	      }

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

    glDisable( GL_TEXTURE_2D );
    glBegin(GL_QUADS);
    glColor4f(1,1,1,1);
    glVertex3f(0, 0.009, 0);
    glVertex3f(0.005, 0, 0);
    glVertex3f(0, -0.009, 0);
    glVertex3f(-0.005, 0, 0);
    glEnd();
}


