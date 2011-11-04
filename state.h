/*
 *  State.h
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/24/11.
 *  Copyright 2011 . All rights reserved.
 *
 */

#ifndef STATE_H
#define STATE_H

#include <SDL/SDL.h>

class Game_engine;

class State
{
	protected:
		virtual void clean();	
		Game_engine* ge;
		int screen_height;
		int screen_width;
		bool running;
		
		
	public:
		virtual void init() = 0;
        virtual void update() = 0;
		virtual void render() = 0;
		virtual void remove_objects() = 0;
		virtual void handle_key_events(SDL_Event keyevent) = 0;
		void set_running(bool run);
		bool get_running();
		State(bool run);
		~State();
		
		
};

#endif
