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
#include "score.h"
#include "game_timer.h"
#include <SDL/SDL.h>
#include <vector>

class Game_engine;

class Game_state : public State
{
	private:
		bool new_game;
		Game_timer* timer;
		int current_level;
		vector<Bullet> bullet_vec;
		vector<Game_object*> aliens;
		vector<Game_object*> players;
		vector<Game_object*> score;
		vector<int> highscore;
		void new_lvl();
		void clean();
		
	public:
        void init();
		void update();
		void render();
		void remove_objects();
		void handle_key_events(SDL_Event keyevent);
		vector<int> get_scores();
		
		Game_state(bool run);
		~Game_state();
		
		
};

#endif
