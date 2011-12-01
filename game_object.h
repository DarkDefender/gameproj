/*
 *  game_object.h
 *  
 *
 *  Created by Jacob Sundqvist on 10/31/11.
 *  Copyright 2011 . All rights reserved.
 *
 */



#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>

using namespace std;

class Game_object
	{
	protected:
		GLfloat x;
		GLfloat y;
		GLfloat h;
		GLfloat w;
		string type;
		bool dead;
		GLfloat spd;
        GLfloat angle;
        GLfloat goalx, goaly;
		Sprite* img;
		void init();
		int hp;
		int score;

	public:
		
		GLfloat get_x();
		GLfloat get_y();
		void set_x(GLfloat new_x);
		void set_y(GLfloat new_y);
 		GLfloat get_h();
		GLfloat get_w();
		virtual void update();
		virtual void render(); 
		virtual void remove_objects();
		virtual void handle_key_events(SDL_Event keyevent);
		virtual void add_score(int){}

		Game_object(GLfloat x_pos, GLfloat y_pos, string obj_type);
		Game_object(GLfloat x_pos, GLfloat y_pos, string obj_type, string img_path);
		Game_object(GLfloat x_pos, GLfloat y_pos, GLfloat height, GLfloat width, string obj_type, string img_path);
		Game_object();
		//virtual ~Game_object();
        bool get_dead();
        void set_dead();
		int get_hp();
        void set_hp(int);
        string get_type();

	};

#endif
