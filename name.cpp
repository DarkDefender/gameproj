
#include "name.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <iostream>

using namespace std;

void Name::update()
{
	
}

Name::Name(GLfloat x_pos, GLfloat y_pos, string obj_type) : Game_object(x_pos, y_pos, obj_type)
{
	h = 0.2;
	w = 0.5;
	images.push_back("new_game.png");
	images.push_back("help.png");
	it = 0;
	img = new Sprite(images[it], h, w);
	img->create_texture();
	
}

void Name::change_letter_up()
{
	it++;
	if(it > images.size() - 1)
	{
		it = 0;
	}	
	img->change_img(images[it], h, w);
}

void Name::change_letter_down()
{
	it--;
	
	if(it < 0)
	{
		it = images.size() - 1;
	}
	img->change_img(images[it], h, w);
}