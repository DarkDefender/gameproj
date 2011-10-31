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
#include <sdl.h>

class Game_engine
{
private:

    void clean();
    void handle_events(SDL_Surface*&);
    bool resizeWindow(int, int);
	bool init_sdl(SDL_Surface*&);
	bool init_gl();	
	bool running;
    bool isActive;
	int SCREEN_HEIGHT;
	int SCREEN_WIDTH;
	int SCREEN_BPP;
	SDL_Surface *surface;
    State* menu;
	State* game;
	State* current_state;
	
public:
	void run();
	bool get_running();
	void set_running(bool run);
	void show(int x, int y);
	Game_engine();


};

#endif
