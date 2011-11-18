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
	
	init();
	new_lvl();
	
	//Timer
	timer = new Game_timer(-0.4,0.8);
	
}

void Game_state::new_lvl()
{
	//Player1 aliens
	aliens.push_back(new  Aliens("p1", -0.2, 0, current_level, &bullet_vec));
	aliens.push_back(new  Aliens("p1", -0.2, 0.2, current_level, &bullet_vec));
	aliens.push_back(new  Aliens("p1", -0.2, 0.4, current_level, &bullet_vec));
	aliens.push_back(new  Aliens("p1", -0.2, 0.6, current_level, &bullet_vec));
	aliens.push_back(new  Aliens("p1", -0.2, 0.8, current_level, &bullet_vec));
	
	//Player2 aliens
	aliens.push_back(new  Aliens("p2", 0.2, 0, current_level, &bullet_vec));
	aliens.push_back(new  Aliens("p2", 0.2, 0.2, current_level, &bullet_vec));
	aliens.push_back(new  Aliens("p2", 0.2, 0.4, current_level, &bullet_vec));
	aliens.push_back(new  Aliens("p2", 0.2, 0.6, current_level, &bullet_vec));
	aliens.push_back(new  Aliens("p2", 0.2, 0.8, current_level, &bullet_vec));
}

void Game_state::init()
{
	players.push_back(new Player("player1", "images/p1.png", &bullet_vec));
	players.push_back(new Player("player2", "images/p2.png", &bullet_vec));
}

void Game_state::update()
{
	//Update players
	for (unsigned int it = 0;
		 it < players.size(); it++ )
    {
        players[it]->update();
    }	
	
	//Update aliens
    for (unsigned int it = 0;
            it < aliens.size(); it++ )
    {
        aliens[it]->update();
    }	
	
	//Update bullets
    for (unsigned int it = 0;
            it < bullet_vec.size(); it++ )
    {
        bullet_vec[it].update();
    }	
    
	//Handle collisions
    for (unsigned int i = 0; i < bullet_vec.size(); i++)
    {
        for (unsigned int j = 0; j < aliens.size(); j++)
        {
            bullet_vec[i].collision(*aliens[j]);
        }
    }
	
	
	
	timer->update();
	
	//New level
	if(timer->get_level() != current_level)
	{
		current_level = timer->get_level();
		new_lvl();
	}

}

void Game_state::render()
{
	
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );	
	
	
	// Render all players
	for (unsigned int it = 0;
		 it < players.size(); it++ )
	{
		players[it]->render();
	}
	
	// Render all aliens
	for (unsigned int it = 0;
		 it < aliens.size(); it++ )
	{
		aliens[it]->render();
	}
	
	
	timer->render();
	
	// Render all bullets
	for (unsigned int it = 0;
		 it < bullet_vec.size(); it++ )
	{
		bullet_vec[it].render();
	}  

    /* Draw it to the screen */
    SDL_GL_SwapBuffers( );

}

void Game_state::remove_objects()
{
	//Remove dead players
    for(int i = 0; i < (int)players.size(); i++)
    {
        if( players[i]->get_dead() )
        {
            players.erase (players.begin()+i);
            --i;
        }
    }
	
	//Remove dead bullets
    for(int i = 0; i < (int)bullet_vec.size(); i++)
    {
        if( bullet_vec[i].get_dead() )
        {
            bullet_vec.erase (bullet_vec.begin()+i);
            --i;
        }
    }
	
	//Remove dead aliens
    for(int i = 0; i < (int)aliens.size(); i++)
    {
        if( aliens[i]->get_dead() )
        {
            aliens.erase (aliens.begin()+i);
            --i;
        }
    }
}

//Handles keyboard input
void Game_state::handle_key_events(SDL_Event keyevent)
{
	for (unsigned int it = 0;
		 it < players.size(); it++ )
	{
		players[it]->handle_key_events(keyevent);
	}

}
