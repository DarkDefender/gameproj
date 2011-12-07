
#ifndef NAME_H
#define NAME_H

#include "sprite.h"
#include "game_object.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <vector>

using namespace std;

class Name : public Game_object
	{
	protected:
		vector<string> images;
		int it;
		
	public:
		void update();
		void change_letter_down();
		void change_letter_up();
		Name(GLfloat x_pos, GLfloat y_pos, string obj_type);
		~Name();
	};

#endif
