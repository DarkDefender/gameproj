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
#include "game_object.h"
#include <SDL.h>
#include <vector>

class Game_engine;

class Menu_state : public State
{
	private:
		int x;
		int y;
		vector<Game_object*> images;
		Game_object* cursor_obj;
		
	public:
        void init();
		void update();
		void render();
		void remove_objects();
		void handle_key_events(SDL_Event keyevent);
		Menu_state(bool run);
		
		
};

#endif
