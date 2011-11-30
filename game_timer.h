/*
 *  game_timer.h
 *  
 *
 *  Created by Jacob Sundqvist on 11/16/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GAME_TIMER_H
#define GAME_TIMER_H

#include <SDL/SDL.h>
#include <vector>
#include <string>
#include "game_object.h"

class Game_timer : public Game_object
{
    private:
		
		//Vector with imagepaths
		vector<string> images;
		
		//Sprites
		Sprite* img1;
		Sprite* img2;
		Sprite* level_img;
		Sprite* level_counter1;
		Sprite* level_counter2;
		
		//Finds the correct image in the image vector for mins/secs
		int max_second1; 
		int max_second2;
		int second1;
		int second2;
		int lvl_cnt1;
		int lvl_cnt2;
		
		int time_to_update;
		int current_level;
		
		void update_img();
		
    public:
		//Initializes variables
		Game_timer(GLfloat x_pos, GLfloat y_pos);
		~Game_timer();
		
		//Game_object functions
		void render();
		void update();
		
		//Level
		int get_level();
		
};

#endif
