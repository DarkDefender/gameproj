/*
 *  Sprite.h
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL.h>
#include <SDL_opengl.h>

using namespace std;

class Sprite
	{
	private:
		
		string img_path;
        GLuint texture[1];
        GLfloat xrot; /* X Rotation ( NEW ) */
        GLfloat yrot; /* Y Rotation ( NEW ) */
        GLfloat zrot; /* Z Rotation ( NEW ) */
	public:
		Sprite(string image_path);
		bool create_texture();
		void render();
		void change_img(string image_path);
        GLuint* get_texture();
	};

#endif
