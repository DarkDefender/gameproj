/*
 *  Menu_state.h
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state.h"
#include "sprite.h"
#include "game_object.h"
#include "player.h"
#include "alien.h"
#include "game_timer.h"
#include <SDL/SDL.h>
#include <vector>

class Game_engine;

class Game_state : public State
{
	private:
		Game_timer* timer;
		int menu_item;
		int current_level;
		vector<Game_object*> highscore;
		//vector<Bullet> bullet_vec;
		vector<Game_object*> images;
		//vector<Game_object*> images;
		//vector{Game_object*> aliens;
		Game_object* cursor_obj;
		void move_cursor_up();
		void move_cursor_down();
		
	public:
        void init();
	//vector<Bullet> bullet_vec;
	//vector<Game_object*> images;
		void update();
		void render();
		void remove_objects();
		void handle_key_events(SDL_Event keyevent);
		Game_state(bool run);
		
		
};

#endif
