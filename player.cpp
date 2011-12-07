#include<iostream>
#include <SDL/SDL.h>
#include "player.h"
#include "sprite.h"
#include "game_object.h"
#include "score.h"
#include "game_state.h"
#include "game_engine.h"
#include "bullet.h"
#include "special_bullet.h"

using namespace std;


Player::Player (string typein, vector<Bullet*>* b_ptr, vector <Game_object*>* score_vec_in)
{
  score_vec = score_vec_in;
	life = 3;
	up = false;
	down = false;
	shoot_cooldown = 10;
	shoot_cnt = shoot_cooldown;
	shooting = false;
	number_of_bullets = 5;
    bullet_cooldown = 50;
    bullet_cnt = bullet_cooldown;
	bullets = b_ptr;
	type = typein;
	hp = 1;
	y = 0;
	h = 0.1;
	w = 0.1;
	spd = 0.01;
	dead = false;
    spec_cnt = 0;
    spec_shooting = false;


	if(type == "player1")
	{
		x=-1.2;
		player_img = "images/p1.png";
	}
	else //if player2
	{
		x=1.2;
		player_img = "images/p2.png";
	}
	img = new Sprite(player_img, h, w);
	img->create_texture();
}

Player::~Player()
{
  delete img;
}

void Player :: move_up()
{
    if (y + spd<0.85)
    {
        y=y+spd;
    }
    else
    {
        y=0.85;
    }
}



void Player :: move_down()
{
    if (y - spd>-0.95)
      {
        y=y-spd;
      }
    else
      {
	y = -0.95;
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
                    case SDLK_2:
                        spec_shooting = true;
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
                    case SDLK_2:
                        spec_shooting = false;
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
                    case SDLK_RCTRL:
                        spec_shooting = true;
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
                    case SDLK_RCTRL:
                        spec_shooting = false;
                    default:
                        break;
                }
        }
    }
}


void Player :: update()
{
	shoot_cnt--;
	if(number_of_bullets <= 5 )
    {
        if(not bullet_cnt--)
        {
            number_of_bullets++;
            bullet_cnt = bullet_cooldown;
        }
    }

    if(up)
        move_up();
    if(down)
        move_down();
	if(shooting && shoot_cnt <= 0 && number_of_bullets && not spec_shooting)
	{
        number_of_bullets--;
		shoot();
		shoot_cnt = shoot_cooldown;
	}
    if(spec_shooting and spec_cnt == 180)
    {
        spec_cnt = 0;
        spec_shoot();
    }
    else if (spec_shooting)
    {
        ++spec_cnt;
    }
}

void Player :: render()
{
    img->render(x, y, -5);
}


void Player::remove_objects()
{
}

void Player::shoot()
{
	if(type == "player2")
	{
	  bullets->push_back(new Bullet(x-0.5*w,y,"player2", 1, 0.01, 3.14159, score_vec));
	}
	else
	{
	  bullets->push_back(new Bullet(x+0.5*w,y,"player1", 1, 0.01, 0, score_vec));
	}
}

void Player::spec_shoot()
{
    if (type == "player2")
    {
        bullets->push_back(new Special_bullet(x-0.5*w, y, "player2", 0, 0.005, 3.14159, score_vec, bullets));
    }
    else
    {
        bullets->push_back(new Special_bullet(x+0.5*w, y, "player1", 0, 0.005, 0, score_vec, bullets));
    }
}

