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
#include "name.h"
#include "highscore.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <iostream>
#include <vector>

using namespace std;

Menu_state::Menu_state(bool run) : State(run)
{	
	
	change_state = false;
    show_help = false;
	player1_name = false;
	player2_name = false;
	menu_item = 0;
	letter_item = 0;
	
	hscore = new Highscore();
	
	//Cursor
	cursor_obj = new Game_object(-1.0, 0.8, "cursor", "images/pil.png");
	
	//New game image
	images.push_back(new Game_object(-0.6,0.8,0.2,0.5,"new game","images/newgame.png"));
	// Player 1 image
	images.push_back(new Game_object(-0.6,0.4,0.2,0.5,"player 1","images/player1.png"));
	// Player 2 image
	images.push_back(new Game_object(-0.6,0,0.2,0.5,"player 2","images/player2.png"));
	//Help image
	images.push_back(new Game_object(-0.6,-0.4,0.2,0.5,"help","images/help.png"));
	//Quit image
	images.push_back(new Game_object(-0.6,-0.8,0.2,0.5,"quit","images/quit.png"));
	
	
	//Letters
	//Player1
	letters1.push_back(new Name(-0.3,0.4,"1"));
	letters1.push_back(new Name(-0.15,0.4,"2"));
	letters1.push_back(new Name(0,0.4,"3"));
	//Player2
	letters2.push_back(new Name(-0.3,0,"1"));
	letters2.push_back(new Name(-0.15,0,"2"));
	letters2.push_back(new Name(0,0,"3"));
	
	//Help
	//Player 1
	help.push_back(new Game_object(-0.5,0.8,0.2,0.5,"player 1","images/player1.png"));
	help.push_back(new Game_object(0.5,0.6,0.2,0.2,"up","images/up-arrow.png"));
	help.push_back(new Game_object(0.5,0.4,0.2,0.2,"down","images/down-arrow.png"));
	help.push_back(new Game_object(0.5,0.2,0.2,0.2,"shift","images/shift.png"));
	//Player 2
	help.push_back(new Game_object(0.5,0.8,0.2,0.5,"player 2","images/player2.png"));
	help.push_back(new Game_object(-0.5,0.6,0.2,0.2,"w","images/alphabet-w.png"));
	help.push_back(new Game_object(-0.5,0.4,0.2,0.2,"s","images/alphabet-s.png"));
	help.push_back(new Game_object(-0.5,0.2,0.2,0.2,"1","images/number-1.png"));
	//Menu buttons
	help.push_back(new Game_object(0.15,0,0.2,0.5,"Menu","images/menu.png"));
	help.push_back(new Game_object(-0.1,-0.2,0.2,0.2,"left","images/left-arrow.png"));
	help.push_back(new Game_object(0.1,-0.2,0.2,0.2,"right","images/right-arrow.png"));
	help.push_back(new Game_object(0,-0.4,0.2,0.2,"enter","images/enter.png"));
	help.push_back(new Game_object(0,-0.6,0.2,0.2,"esc","images/esc.png"));
	
	
}

void Menu_state::set_scores(vector<int> scores)
{
	if(!scores.size() <= 0)
	{
		vector<string> player_names;
		player_names.push_back(letters1[0]->get_letter());
		player_names.push_back(letters1[1]->get_letter());
		player_names.push_back(letters1[2]->get_letter());
		player_names.push_back(letters2[0]->get_letter());
		player_names.push_back(letters2[1]->get_letter());
		player_names.push_back(letters2[2]->get_letter());
		
		hscore->add_score(scores,player_names);
	}
}

Menu_state::~Menu_state()
{
	hscore->create_file();
	help.clear();
	delete hscore;
	letters2.clear();
	letters1.clear();
	images.clear();
	delete cursor_obj;
	cursor_obj = 0;
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

	
	
	if(show_help)
	{
		// Render all help items
		for (unsigned int it = 0;
			 it < help.size(); it++ )
		{
			help[it]->render();
		}
	}
	else
	{
	
		cursor_obj->render();
	
	
		// Render all menu items
		for (unsigned int it = 0;
			it < images.size(); it++ )
		{
			images[it]->render();
		}
	
		//Render all letters for player1			  
		for (unsigned int it = 0;
			it < letters1.size(); it++ )
		{
			letters1[it]->render();
		}
		//Render all letters for player2
		for (unsigned int it = 0;
			 it < letters2.size(); it++ )
		{
			letters2[it]->render();
		}
	}
	
	hscore->render();
	
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
	
	if(menu_item > (int)images.size() - 1)
	{
		menu_item = 0;
	}
	
	cursor_obj->set_y(images[menu_item]->get_y());
}

void Menu_state::remove_objects()
{
	
}



void Menu_state::menu_select()
{
	
	switch(menu_item)
	{
		case 0:
			//New game
			change_state = true;
			break;
		case 1:
			//player 1
			player1_name = true;
			break;
		case 2:
			//player 2
			player2_name = true;
			break;
		case 3:
			//help
			show_help = true;
			break;
		case 4:
			//Quit
			running = false;
			break;
						
	}
	
	
}

//Handles keyboard input
void Menu_state::handle_key_events(SDL_Event keyevent)
{
	switch(keyevent.type){
		case SDL_KEYDOWN:
			switch(keyevent.key.keysym.sym)
			{
				case SDLK_UP:
					if(player1_name)
					{
						letters1[letter_item]->change_letter_up();
					}
					else if(player2_name)
					{
						letters2[letter_item]->change_letter_up();
					}
					else if(!show_help)
					{
						move_cursor_up();
					}
					break;
				case SDLK_DOWN:
					if(player1_name)
					{
						letters1[letter_item]->change_letter_down();
					}
					else if(player2_name)
					{
						letters2[letter_item]->change_letter_down();
					}
					else if(!show_help)
					{
						move_cursor_down();
					}
					break;
				case SDLK_LEFT:
					//Move to previous letter object
					if(player1_name || player2_name)
					{
						letter_item--;
						if(letter_item < 0)
						{
							letter_item = letters1.size() - 1;
						}
						
					}
					break;
				case SDLK_RIGHT:
					//Move to next letter object
					if(player1_name || player2_name)
					{
						letter_item++;
						if(letter_item > (int)letters1.size() - 1)
						{
							letter_item = 0;
						}	
					}
					break;
				case SDLK_RETURN:
					if(show_help)
					{
						show_help = false;
					}
					else if(player1_name || player2_name)
					{
						player1_name = false;
						player2_name = false;
						letter_item = 0;
					}
					else
					{
						menu_select();
					}
					break;
				case SDLK_ESCAPE:
					change_state = true;
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
