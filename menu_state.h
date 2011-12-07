/*
 *  Menu_state.h
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "state.h"
#include "sprite.h"
#include "name.h"
#include "game_object.h"
#include "highscore.h"
#include <SDL/SDL.h>
#include <vector>

class Game_engine;

class Menu_state : public State
{
	private:
		int menu_item;
		int letter_item;
		bool show_help;
		bool player1_name;
		bool player2_name;
		Highscore* hscore;
		vector<Game_object*> images;
		vector<Name*> letters1;
		vector<Name*> letters2;
		vector<Game_object*> help;
		Game_object* cursor_obj;
		void menu_select();
		void move_cursor_up();
		void move_cursor_down();
		
	public:
        void init();
		void update();
		void render();
		void remove_objects();
		void handle_key_events(SDL_Event keyevent);
		void set_scores(vector<int> highscore);
		Menu_state(bool run);
		~Menu_state();
		
		
};

#endif
