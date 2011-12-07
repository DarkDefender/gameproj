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
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

using namespace std;

class Sprite
{
    private:

    string img_path;
    GLuint texture;
    GLfloat h,w, r,g,b,a;

    public:
    Sprite(string image_path, GLfloat, GLfloat);
    bool create_texture();
    void render(GLfloat, GLfloat, GLfloat, GLfloat = 0);
    void render(GLfloat x, GLfloat y, GLfloat z, GLfloat height, GLfloat width);
    void change_img(string image_path, GLfloat, GLfloat);
    GLuint get_texture();
    void set_color(GLfloat, GLfloat, GLfloat, GLfloat);
};

#endif
