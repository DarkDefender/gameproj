#include <iostream>
#include "player.h"
#include "alien.h"
#include "score.h"
#include "game_object.h"

using namespace std;


Aliens::Aliens(string typein, GLfloat xin, GLfloat yin,
	       int lvl, vector<Bullet>* b_ptr, vector<Game_object*>* pointer_score_vec_in)
: Game_object(xin,yin,typein)
{
  pointer_score_vec = pointer_score_vec_in;	
	current_lvl = lvl;
	init_alien();
	up = true;
	down = false;
	bullets = b_ptr;

	
	if(typein == "player1")
	{
		x_step=-0.1;
	}
	else //if player2
	{
		x_step=0.1;
	}
}

void Aliens::init_alien()
{
	
	if(current_lvl%2)
	{
		ufo_img = "images/ufo.png";
	}
	else
	{
		ufo_img = "images/ufo1.png";
	}
	fire_time = 990;
	moved_x_dir = 0;
	w = 0.1;
	h = 0.1;
	dead = false;
	spd = 0.005;
	hp = 1;
	
	img = new Sprite(ufo_img, h, w);
	img->create_texture();
}

void Aliens :: move_up()
{
    if (y + spd + h/2<1 && moved_x_dir == 0)
    {
        y=y+spd;
    }
    else
    {
        if( type == "p1")
        {
            x=x-spd;
            moved_x_dir = moved_x_dir - spd;

            if (moved_x_dir<=-w)
            {
                moved_x_dir = 0;
                 spd=spd+0.001;
                up=false;
                down=true;
            }
        } 
        else //player 2
        {
            x=x+spd;
            moved_x_dir = moved_x_dir + spd;

            if (moved_x_dir>=w)
            {
                moved_x_dir = 0;
                spd=spd+0.001;
                up=false;
                down=true;
            }
        }
    }
}



void Aliens :: move_down()
{
    if (y - spd- h/2>-1)
    {
        y=y-spd;
    }
    else
    {
        if( type == "p1")
        {
            x=x-spd;
            moved_x_dir = moved_x_dir - spd;

            if (moved_x_dir<=-w)
            {
                moved_x_dir = 0;
                spd=spd+0.001;
                up=true;
                down=false;
            }
        } 
        else //player 2
        {
            x=x+spd;
            moved_x_dir = moved_x_dir + spd;

            if (moved_x_dir>=w)
            {
                moved_x_dir = 0;
                spd=spd+0.001;
                up=true;
                down=false;
            }
        }
    } 
}

void Aliens::handle_key_events(SDL_Event keyevent)
{
}


void Aliens :: update()
{
    if(up)
        move_up();
    if(down)
        move_down();
    if(rand() % 1000 > fire_time)
    {
        if(type=="p1")
        {
	  bullets->push_back(Bullet(x,y,"p1",1,0.01,3.14159, pointer_score_vec));
        }
        else
        {
	  bullets->push_back(Bullet(x,y,"p2",1,0.01,0, pointer_score_vec));
        }
    }
}


void Aliens :: render()
{
  img->render(x, y, -5);
}


void Aliens::remove_objects()
{
}

void Aliens::set_fire_time(int fire)
{
	fire_time=fire;
}
