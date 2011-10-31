/*
 *  Menu_state.cpp
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "menu_state.h"
#include "game_engine.h"
#include "game_object.h"
#include <string>
#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>

using namespace std;

Menu_state::Menu_state(Game_engine* game) : State(game)
{
	cursor = 1;
	
	cursor_obj = new Game_object(-1, 1, "cursor", "test_img.bmp");
	new_game_obj = new Game_object(1,1,"new game","test_img.bmp");
}

//Only for testing purposes
void Menu_state::move_cursor(int move)
{

}

void Menu_state::init()
{
    // You have to init textures AFTER you have started the GL context

}

void Menu_state::update()
{
	
}

void Menu_state::render()
{
	
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    cursor_obj->render();
	new_game_obj->render();

    /* Draw it to the screen */
    SDL_GL_SwapBuffers( );

}

void Menu_state::remove_objects()
{
	
}

//Handles keyboard input
void Menu_state::handle_key_events(SDL_Event keyevent)
{
	switch(keyevent.type){
		case SDL_KEYDOWN:
			switch(keyevent.key.keysym.sym)
			{
				case SDLK_LEFT:
					//charxvel = -1;
					break;
				case SDLK_RIGHT:
					//charxvel = 1;
					break;
				case SDLK_UP:
					cursor_obj->set_y(cursor_obj->get_y() + 1);
					break;
				case SDLK_DOWN:
					cursor_obj->set_y(cursor_obj->get_y() - 1);
					break;
				case SDLK_ESCAPE:
					//ge->set_running(false);
					break;
				default:
					break;
			}
			break;
		case SDL_KEYUP:
			switch(keyevent.key.keysym.sym)
			{
				case SDLK_LEFT:
					//charxvel = 0;
					break;
				case SDLK_RIGHT:
					//charxvel = 0;
					break;
				case SDLK_UP:
					//charyvel = 0;
					break;
				case SDLK_DOWN:
					//charyvel = 0;
					break;
				default:
					break;
			}
	}
}
