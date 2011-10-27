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
#include "sprite.h"
#include <string>
#include <SDL.h>
#include <SDL_opengl.h>

using namespace std;

Menu_state::Menu_state(Game_engine* game) : State(game)
{
	cursor = 1;
	x = 0;
	y = 0;
	cursor_img = new Sprite("hello.bmp");
}

//Only for testing purposes
void Menu_state::move_cursor(int move)
{
	cursor = cursor + move;
	
	if(cursor < 1)
		cursor = 3;
	else if(cursor > 3)
		cursor = 1;
	
	y = 100*cursor;
}

void Menu_state::init()
{
    // You have to init textures AFTER you have started the GL context
    cursor_img->create_texture();
}

void Menu_state::update()
{
	
}

void Menu_state::render()
{
	
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    cursor_img->render();

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
					move_cursor(-1);
					break;
				case SDLK_DOWN:
					move_cursor(1);
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
