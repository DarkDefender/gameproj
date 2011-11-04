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

#include "bullet.h"

#include "state.h"
#include <SDL/SDL.h>
#include <vector>

class Game_state : public State
{
	private:
        vector<Bullet> bullet_vec;
		
	public:
        void init();
		void update();
		void render();
		void remove_objects();
		void handle_key_events(SDL_Event keyevent);
		Game_state(bool run);
		
};

#endif
