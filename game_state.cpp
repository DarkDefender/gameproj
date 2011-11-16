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
	
  images.push_back(new Player("player1", "player1.bmp", &bullet_vec));
  images.push_back(new Player("player2", "player2.bmp", &bullet_vec));
  images.push_back(new  Aliens("p1", "ufo.bmp", -0.2, 0, true, false, &bullet_vec));
  images.push_back(new  Aliens("p1", "ufo.bmp", -0.2, 0.2, true, false, &bullet_vec));
  images.push_back(new  Aliens("p1", "ufo.bmp", 
			       -0.2, 0.4, true, false, &bullet_vec));
  images.push_back(new  Aliens("p1", "ufo.bmp", 
			       -0.2, 0.6, true, false, &bullet_vec));
  images.push_back(new  Aliens("p1", "ufo.bmp", 
			       -0.2, 0.8, true, false, &bullet_vec));

  images.push_back(new  Aliens("p2", "ufo.bmp", 
			       0.2, 0, true, false, &bullet_vec));
  images.push_back(new  Aliens("p2", "ufo.bmp", 
			       0.2, 0.2, true, false, &bullet_vec));
  images.push_back(new  Aliens("p2", "ufo.bmp", 
			       0.2, 0.4, true, false, &bullet_vec));
  images.push_back(new  Aliens("p2", "ufo.bmp", 
			       0.2, 0.6, true, false, &bullet_vec));
  images.push_back(new  Aliens("p2", "ufo.bmp", 
			       0.2, 0.8, true, false, &bullet_vec));

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
    for (unsigned int it = 0;
            it < bullet_vec.size(); it++ )
    {
        bullet_vec[it].update();
    }	    
    for (unsigned int i = 0; i < bullet_vec.size(); i++)
    {
        for (unsigned int j = 0; j < images.size(); j++)
        {
            bullet_vec[i].collision(*images[j]);
        }
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
	for (unsigned int it = 0;
		 it < bullet_vec.size(); it++ )
	{
		bullet_vec[it].render();
	}  
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
    for(int i = 0; i < (int)bullet_vec.size(); i++)
    {
        if( bullet_vec[i].get_dead() )
        {
            bullet_vec.erase (bullet_vec.begin()+i);
            --i;
        }
    }
    for(int i = 0; i < (int)images.size(); i++)
    {
        if( images[i]->get_dead() )
        {
            images.erase (images.begin()+i);
            --i;
        }
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
