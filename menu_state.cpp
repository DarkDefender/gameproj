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
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <iostream>
#include <vector>

using namespace std;

Menu_state::Menu_state(bool run) : State(run)
{	
	menu_item = 0;
	
	//Cursor
	cursor_obj = new Game_object(-1.2, 0.8, "cursor", "test_img.png");
	
	//New game image
	images.push_back(new Game_object(-1,0.8,"new game","new_game.bmp"));
	// Player 1 image
	images.push_back(new Game_object(-1,0.6,"player 1","player1.bmp"));
	// Player 2 image
	images.push_back(new Game_object(-1,0.4,"player 2","player2.bmp"));
	//Help image
	images.push_back(new Game_object(-1,0.2,"help","help.bmp"));
	//Quit image
	images.push_back(new Game_object(-1,0,"quit","quit.png"));
	//Highscore image
	highscore.push_back(new Game_object(0.4,0.8,"highscore","test_img.bmp"));
	
}

void Menu_state::init()
{
	
}

void Menu_state::update()
{
	
}

void Menu_state::render()
{
	
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    cursor_obj->render();
	
	
	// Render all menu items
	for (unsigned int it = 0;
		 it < images.size(); it++ )
	{
		images[it]->render();
	}
	
	// Render all highscore items
	for (unsigned int it = 0;
		 it < highscore.size(); it++ )
	{
		highscore[it]->render();
	}

    /* Draw it to the screen */
    SDL_GL_SwapBuffers( );

}

void Menu_state::move_cursor_up()
{	
	menu_item = menu_item - 1;
	
	if(menu_item < 0)
	{
		menu_item = images.size() - 1;
	}
	
	cursor_obj->set_y(images[menu_item]->get_y());
}

void Menu_state::move_cursor_down()
{	
	menu_item = menu_item + 1;
	
	if(menu_item > images.size() - 1)
	{
		menu_item = 0;
	}
	
	cursor_obj->set_y(images[menu_item]->get_y());
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
				case SDLK_UP:
					move_cursor_up();
					break;
				case SDLK_DOWN:
					move_cursor_down();
					break;
				case SDLK_LEFT:
					break;
				case SDLK_RIGHT:
					break;
				case SDLK_RETURN:
					cout << "Return" << endl;
					break;
				case SDLK_ESCAPE:
					set_running(false);
					break;
				default:
					break;
			}
			break;
		case SDL_KEYUP:
			switch(keyevent.key.keysym.sym)
			{
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				default:
					break;
			}
	}
}
