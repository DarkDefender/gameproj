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
#include <string>

using namespace std;

class Game_object
	{
	private:
		int x;
		int y;
		int height;
		int width;
		string type;
		bool dead;
		int speed;
		Sprite* img;
		
	public:
		int get_x();
		int get_y();
		void set_x(int new_x);
		void set_y(int new_y);
        void init();
		virtual void update();
		virtual void render();
		virtual void remove_objects();
		virtual void handle_key_events(SDL_Event keyevent);
		Game_object(int x_pos, int y_pos, string obj_type, string img_path);
		Game_object();
		
	};

#endif