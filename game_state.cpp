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
#include "score.h"
#include "obstacle.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <iostream>
#include <vector>

using namespace std;

Game_state::Game_state(bool run) : State(run)
{	
	
	init();
	new_lvl();
	

	//Timer
	timer = new Game_timer(-0.4,0.9);
}

void Game_state::new_lvl()
{
	//Player1 aliens
  aliens.push_back(new  Aliens("p1", -0.2, 0, current_level, &bullet_vec, &score));
	aliens.push_back(new  Aliens("p1", -0.2, 0.2, current_level, &bullet_vec, &score));
	aliens.push_back(new  Aliens("p1", -0.2, 0.4, current_level, &bullet_vec, &score));
	aliens.push_back(new  Aliens("p1", -0.2, 0.6, current_level, &bullet_vec, &score));
	aliens.push_back(new  Aliens("p1", -0.2, 0.8, current_level, &bullet_vec, &score));
	
	//Player2 aliens
	aliens.push_back(new  Aliens("p2", 0.2, 0, current_level, &bullet_vec, &score));
	aliens.push_back(new  Aliens("p2", 0.2, 0.2, current_level, &bullet_vec, &score));
	aliens.push_back(new  Aliens("p2", 0.2, 0.4, current_level, &bullet_vec, &score));
	aliens.push_back(new  Aliens("p2", 0.2, 0.6, current_level, &bullet_vec, &score));
	aliens.push_back(new  Aliens("p2", 0.2, 0.8, current_level, &bullet_vec, &score));
}

void Game_state::init()
{
	//Starting level
	current_level = 1;
	
	players.push_back(new Player("player1", &bullet_vec, &score));
	players.push_back(new Player("player2", &bullet_vec, &score));
	score.push_back(new Score("player1"));
	score.push_back(new Score("player2"));
	
	//Timer
	timer = new Game_timer(-0.4,0.8);

    //Obstacle
    vector<Obstacle> test = create_obs(1.1, 0, 0);
    obstacle.insert(obstacle.end(), test.begin(), test.end());
    test = create_obs(1.1, 0.75, 0);
    obstacle.insert(obstacle.end(), test.begin(), test.end());
    test = create_obs(1.1, -0.75, 0);
    obstacle.insert(obstacle.end(), test.begin(), test.end());
    test = create_obs(-1.1, 0);
    obstacle.insert(obstacle.end(), test.begin(), test.end());
    test = create_obs(-1.1, 0.75, 0);
    obstacle.insert(obstacle.end(), test.begin(), test.end());
    test = create_obs(-1.1, -0.75, 0);
    obstacle.insert(obstacle.end(), test.begin(), test.end());
}

Game_state::~Game_state()
{
	clean();
}

void Game_state::clean()
{
	aliens.clear();
	players.clear();
	bullet_vec.clear();
	score.clear();
    obstacle.clear();
	delete timer;
	timer = 0;
}

void Game_state::update()
{
	//If both players are dead
	if(players.size() <= 0)
	{
		change_state = true;
		clean();
		init();
		new_lvl();
	}
	
	
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
    
	//Handle collisions between bullets and aliens
    for (unsigned int i = 0; i < bullet_vec.size(); i++)
    {
        for (unsigned int j = 0; j < aliens.size(); j++)
        {
            bullet_vec[i].collision(*aliens[j]);
        }
    }
	
	//Handle collisions between bullets and players
    for (unsigned int i = 0; i < bullet_vec.size(); i++)
    {
        for (unsigned int j = 0; j < players.size(); j++)
        {
            bullet_vec[i].collision(*players[j]);
        }
    }

	  	//Handle collisions between bullets and obstacles
    for (unsigned int i = 0; i < bullet_vec.size(); i++)
    {
        for (unsigned int j = 0; j < obstacle.size(); j++)
        {
            bullet_vec[i].collision(obstacle[j]);
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

	// Render all the obstacles, from the vector<Game_object(!NO STAR)> obstacle
    for (unsigned int it = 0;
            it < obstacle.size(); it++)
    { 
        obstacle[it].render();
    }

	// Render all scorez0r
	for (unsigned int it = 0;
		 it < score.size(); it++ )
	{
		score[it]->render();
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
    for(int i = 0; i < (int)obstacle.size(); i++)
    {
        if( obstacle[i].get_dead() )
        {
            obstacle.erase (obstacle.begin()+i);
            --i;
        }
    }   
}

//Handles keyboard input
void Game_state::handle_key_events(SDL_Event keyevent)
{
	switch(keyevent.type){
		case SDL_KEYDOWN:
			switch(keyevent.key.keysym.sym)
			{
			case SDLK_ESCAPE:
					change_state = true;
					break;
				default:
					break;
			}
		default:
			break;
	}
	
	
	for (unsigned int it = 0;
		 it < players.size(); it++ )
	{
		players[it]->handle_key_events(keyevent);
	}

}
