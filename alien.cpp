#include <iostream>
#include "player.h"
#include "alien.h"
#include "game_object.h"

using namespace std;


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
            bullets->push_back(Bullet(x,y,"p1",1,-0.01,0));
        }
        else
        {
            bullets->push_back(Bullet(x,y,"p2",1,0.01,0));
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
