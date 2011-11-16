/*
 *  Menu_state.cpp
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "game_state.h"
#include "game_engine.h"
#include "game_object.h"
#include "player.h"
#include "alien.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <iostream>
#include <vector>

using namespace std;

Game_state::Game_state(bool run) : State(run)
{	

	//Starting level
	current_level = 1;
	
  images.push_back(new Player("player1", "player1.png"));
  images.push_back(new Player("player2", "player2.png"));
  images.push_back(new  Aliens("player1", "ufo.png", 
			       -0.2, 0, true, false));
  images.push_back(new  Aliens("player1", "ufo.png", 
			       -0.2, 0.2, true, false));
  images.push_back(new  Aliens("player1", "ufo.png", 
			       -0.2, 0.4, true, false));
  images.push_back(new  Aliens("player1", "ufo.png", 
			       -0.2, 0.6, true, false));
  images.push_back(new  Aliens("player1", "ufo.png", 
			       -0.2, 0.8, true, false));

  images.push_back(new  Aliens("player2", "ufo.png", 
			       0.2, 0, true, false));
  images.push_back(new  Aliens("player2", "ufo.png", 
			       0.2, 0.2, true, false));
  images.push_back(new  Aliens("player2", "ufo.png", 
			       0.2, 0.4, true, false));
  images.push_back(new  Aliens("player2", "ufo.png", 
			       0.2, 0.6, true, false));
  images.push_back(new  Aliens("player2", "ufo.png", 
			       0.2, 0.8, true, false));

	
	//Timer
	timer = new Game_timer(-0.4,0.8);
	
	
  /*for(int it = 0, it < 5, ++it)
    {
      aliens.push_back(new Alien ("player1", "ufo.bmp", 
      double xin, double yin, bool up_in, bool down_in));
    }
  images.push_back(new Alien("player1", "player2.bmp"));
  images.push_back(new Alien("player1", "player2.bmp"));
  images.push_back(new Alien("player2", "player2.bmp"));
  images.push_back(new Alien("player2", "player2.bmp"));*/


	
}

void Game_state::init()
{
	
}

void Game_state::update()
{
	for (unsigned int it = 0;
		 it < images.size(); it++ )
	{
		images[it]->update();
	}
	
	
	timer->update();
	
	//New level
	if(timer->get_level() != current_level)
	{
		current_level = timer->get_level();
	}
	
}

void Game_state::render()
{
	
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    //cursor_obj->render();
	
	
	// Render all menu items
	for (unsigned int it = 0;
		 it < images.size(); it++ )
	{
		images[it]->render();
	}
	
	timer->render();
	
	// Render all highscore items
	/*for (unsigned int it = 0;
		 it < highscore.size(); it++ )
	{
		highscore[it]->render();
		}*/

    /* Draw it to the screen */
    SDL_GL_SwapBuffers( );

}

void Game_state::move_cursor_up()
{	
	menu_item = menu_item - 1;
	
	if(menu_item < 0)
	{
		menu_item = images.size() - 1;
	}
	
	cursor_obj->set_y(images[menu_item]->get_y());
}

void Game_state::move_cursor_down()
{	
	menu_item = menu_item + 1;
	
	if(menu_item > (int)images.size() - 1)
	{
		menu_item = 0;
	}
	
	cursor_obj->set_y(images[menu_item]->get_y());
}

void Game_state::remove_objects()
{
  for (unsigned int it = 0;
       it < images.size(); it++ )
    {
      images[it]->remove_objects();
    }
}

//Handles keyboard input
void Game_state::handle_key_events(SDL_Event keyevent)
{
	for (unsigned int it = 0;
		 it < images.size(); it++ )
	{
		images[it]->handle_key_events(keyevent);
	}

}
