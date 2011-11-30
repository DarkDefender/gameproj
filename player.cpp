#include<iostream>
#include <SDL/SDL.h>
#include "player.h"
#include "sprite.h"
#include "game_object.h"
#include "score.h"
#include "game_state.h"
#include "game_engine.h"
#include "bullet.h"

using namespace std;


Player::Player (string typein, vector<Bullet>* b_ptr)
{
	life = 3;
	number_of_bullets = 5;
	up = false;
	down = false;
	shoot_cooldown = 30;
	shoot_cnt = shoot_cooldown;
	shooting = false;
	bullets = b_ptr;
	type = typein;
	hp = 1;
	y = 0;
	h = 0.1;
	w = 0.1;
	spd = 0.01;
	dead = false;

	if(type == "player1")
	{
		x=-1;
		player_img = "images/p1.png";
	}
	else //if player2
	{
		x=1;
		player_img = "images/p2.png";
	}
	score_ = new Score(type);
	img = new Sprite(player_img, h, w);
	img->create_texture();
}


void Player :: move_up()
{
    if (y + spd<1)
    {
        y=y+spd;
    }
    else
    {
        y=1;
    }
}



void Player :: move_down()
{
    if (y - spd>-1)
    {
        y=y-spd;
    }

}



void Player::handle_key_events(SDL_Event keyevent)
{
    if (type=="player1")
    {
        switch(keyevent.type)
        {
            case SDL_KEYDOWN:
                switch(keyevent.key.keysym.sym)
                {
                    case SDLK_w:
                        //y = y + 0.1;
                        up=true;
                        break;
                    case SDLK_s:
                        //y = y - 0.1;
                        down=true;
                        break;
                    case SDLK_1:
                        shooting = true;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(keyevent.key.keysym.sym)
                {
                    case SDLK_w:
                        up=false;
                        break;
                    case SDLK_s:
                        down=false;
                        break;
					case SDLK_1:
						shooting = false;
						break;
                    default:
                        break;
                }
        }
    }
    else  //if player2
    {
        switch(keyevent.type)
        {
            case SDL_KEYDOWN:
                switch(keyevent.key.keysym.sym)
                {
                    case SDLK_UP:
                        //y=y+0.1;
                        //cout << "k trycktes " << endl;
                        up=true;
                        break;
                    case SDLK_DOWN:
                        //y=y-0.1;
                        down=true;
                        break;
                    case SDLK_RSHIFT:
                        shooting = true;
                        break;
                        //case SDLK_ESCAPE:
                        //set_running(false);
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(keyevent.key.keysym.sym)
                {
                    case SDLK_UP:
                        //x=x+0.1;
                        up=false;
                        break;
                    case SDLK_DOWN:
                        //x=x-0.1;
                        down=false;
                        break;
					case SDLK_RSHIFT:
						shooting = false;
						break;
                    default:
                        break;
                }
        }
    }
}


void Player :: update()
{
	shoot_cnt--;
	
	
    if(up)
        move_up();
    if(down)
        move_down();
	if(shooting && shoot_cnt <= 0)
	{
		shoot();
		score_->add_score(5);
		shoot_cnt = shoot_cooldown;
	}
}

void Player :: render()
{
    img->render(x, y, -5);
    score_ -> render();
}


void Player::remove_objects()
{
}

void Player::shoot()
{
	if(type == "player2")
	{
		bullets->push_back(Bullet(x-0.5*w,y,type, 1, 0.01, 3.14159));
	}
	else
	{
		bullets->push_back(Bullet(x+0.5*w,y,type, 1, 0.01, 0));
	}
}
