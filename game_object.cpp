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
#include <SDL/SDL_opengl.h>
#include <iostream>

using namespace std;

void Game_object::update()
{
	
}

void Game_object::handle_key_events(SDL_Event keyevent)
{
	
}

void Game_object::render()
{
	img->render(x,y,-5);
}

void Game_object::remove_objects()
{
	
}

Game_object::Game_object(GLfloat x_pos, GLfloat y_pos, string obj_type)
{
	x = x_pos;
	y = y_pos;
	h = 0.1;
	w = 0.1;
	dead = false;
	type = obj_type;
}

Game_object::Game_object(GLfloat x_pos, GLfloat y_pos, string obj_type, string img_path)
{
	x = x_pos;
	y = y_pos;
	h = 0.1;
	w = 0.1;
	dead = false;
	type = obj_type;
	img = new Sprite(img_path, h, w);
	img->create_texture();	
}

Game_object::Game_object(GLfloat x_pos, GLfloat y_pos, GLfloat height, GLfloat width, string obj_type, string img_path)
{
	x = x_pos;
	y = y_pos;
	h = height;
	w = width;
	dead = false;
	type = obj_type;
	img = new Sprite(img_path, h, w);
	img->create_texture();	
}



void Game_object::init()
{

}

GLfloat Game_object::get_x() { return x; }

GLfloat Game_object::get_y() { return y; }

GLfloat Game_object::get_h() { return h; }

GLfloat Game_object::get_w() { return w; } 

void Game_object::set_x(GLfloat new_x) { x = new_x; }

void Game_object::set_y(GLfloat new_y) { y= new_y; }

Game_object::Game_object()
{

}

bool Game_object::get_dead() { return dead; }
void Game_object::set_dead() { dead = true; }

int Game_object::get_hp() { return hp; }
void Game_object::set_hp(int health) { hp = health; }

string Game_object::get_type() { return type; }
