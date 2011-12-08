/*
 *  Game_engine.h
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include "state.h"
#include "game_state.h"
#include "menu_state.h"
#include <SDL/SDL.h>

class Game_engine
{
private:

    void clean();
    void handle_events(SDL_Surface*&);
	void change_state();
    bool resize_window(int, int);
	bool init_sdl(SDL_Surface*&);
	bool init_gl();	
	bool running;
    bool is_active;
	int SCREEN_HEIGHT;
	int SCREEN_WIDTH;
	int SCREEN_BPP;
	SDL_Surface *surface;
    State* intro;
    Menu_state* menu;
	Game_state* game;
	State* current_state;
	
public:
	void run();
	Game_engine();
	~Game_engine();


};

#endif
