/*
 *  game_Game_timer.cpp
 *  
 *
 *  Created by Jacob Sundqvist on 11/16/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "game_timer.h"
#include <SDL/SDL.h>
#include <iostream>

using namespace std;

Game_timer::Game_timer(GLfloat x_pos, GLfloat y_pos) : Game_object(x_pos, y_pos, "Game_timer")
{	
	//Initate time
	max_second1 = 0;
	max_second2 = 5;
	second1 = max_second1;
	second2 = max_second2;
	lvl_cnt1 = 0;
	lvl_cnt2 = 1;
	
	time_to_update = 60;
	current_level = 1;
	
	x = x_pos;
	y = y_pos;
	h = 0.1;
	w = 0.1;
	dead = false;
	images.push_back("images/0.png");
	images.push_back("images/1.png");
	images.push_back("images/2.png");
	images.push_back("images/3.png");
	images.push_back("images/4.png");
	images.push_back("images/5.png");
	images.push_back("images/6.png");
	images.push_back("images/7.png");
	images.push_back("images/8.png");
	images.push_back("images/9.png");
	
	
	//Game_timer
	img1 = new Sprite(images[second1], h, w);
	img1->create_texture();	
	
	img2 = new Sprite(images[second2], h, w);
	img2->create_texture();	
	
	
	
	// Current level
	level_img = new Sprite("images/continue.png", h, 0.5);
	level_img->create_texture();
	
	level_counter1 = new Sprite(images[lvl_cnt1], h, w);
	level_counter1->create_texture();
	
	level_counter2 = new Sprite(images[lvl_cnt2], h, w);
	level_counter2->create_texture();

}

void Game_timer::render()
{
	img1->render(x,y,-5);
	img2->render(x+0.1,y,-5);
	level_img->render(x+0.5,y,-5);
	level_counter1->render(x+0.8,y,-5);
	level_counter2->render(x+1,y,-5);
	
}

void Game_timer::update()
{
	time_to_update--;
	
	if(time_to_update <= 0)
	{
		update_img();
		time_to_update = 60;
	}
	
}

int Game_timer::get_level()
{
	return current_level;
}

void Game_timer::update_img()
{
	--second2;
	
	if(second2 < 0)
	{
		second2 = 9;
		second1--;
		
		//New level
		if(second1 < 0)
		{
			current_level++;
			second1 = max_second1;
			second2 = max_second2;
			
			// Changes displayed level
			lvl_cnt1 = current_level/10;
			lvl_cnt2 = current_level%10;
			level_counter1->change_img(images[lvl_cnt1],h,w);
			level_counter2->change_img(images[lvl_cnt2],h,w);
		}
		
	}
	
	img1->change_img(images[second1], h, w);
	img2->change_img(images[second2], h, w);
	
}
