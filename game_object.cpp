/*
 *  game_object.cpp
 *  
 *
 *  Created by Jacob Sundqvist on 10/31/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "game_object.h"
#include "sprite.h"
#include <string>
#include <SDL_opengl.h>
#include <iostream>

using namespace std;

void Game_object::init()
{
	
}
void Game_object::update()
{
	
}
void Game_object::render()
{
	img->render(x,y,-5);
}

void Game_object::remove_objects()
{
	
}

void Game_object::handle_key_events(SDL_Event keyevent)
{
	
}

Game_object::Game_object(GLfloat x_pos, GLfloat y_pos, string obj_type, string img_path)
{
	x = x_pos;
	y = y_pos;
	height = 0.1;
	width = 0.1;
	dead = false;
	type = obj_type;
	img = new Sprite(img_path, height, width);
	img->create_texture();
}

int Game_object::get_x()
{
	return x;
}

int Game_object::get_y()
{
	return y;
}

void Game_object::set_x(int new_x)
{
	x = new_x;
}

void Game_object::set_y(int new_y)
{
	y= new_y;
}

Game_object::Game_object()
{

}