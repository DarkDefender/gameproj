/*
 *  game_object.h
 *  
 *
 *  Created by Jacob Sundqvist on 10/31/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */



#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "sprite.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <string>

using namespace std;

class Game_object
	{
	private:
		GLfloat x;
		GLfloat y;
		GLfloat h;
		GLfloat w;
		string type;
		bool dead;
		int speed;
		Sprite* img;
		void init();
		
	public:
		GLfloat get_x();
		GLfloat get_y();
		void set_x(GLfloat new_x);
		void set_y(GLfloat new_y);
		virtual void update();
		virtual void render();
		virtual void remove_objects();
		virtual void handle_key_events(SDL_Event keyevent);
		Game_object(GLfloat x_pos, GLfloat y_pos, string obj_type, string img_path);
		Game_object(GLfloat x_pos, GLfloat y_pos, GLfloat height, GLfloat width, string obj_type, string img_path);
		Game_object();
		
	};

#endif