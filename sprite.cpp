/*
 *  Sprite.cpp
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sprite.h"
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL_image.h>
#include "game_exception.h"
#include <iostream>

using namespace std;

Sprite::Sprite(string image_path, GLfloat height, GLfloat width)
{
	img_path = image_path;
    h = height;
    w = width;
    r = 1;
    g = 1;
    b = 1;
    a = 1;
}	

void Sprite::render(GLfloat x, GLfloat y, GLfloat z)
{
    /* Move Into The Screen 5 Units */
    glLoadIdentity( );
    glTranslatef( x, y, z );

    glEnable( GL_TEXTURE_2D );


    /* Select Our Texture */
    glBindTexture( GL_TEXTURE_2D, texture[0] );

    // Enable transparency (blending textures/colors)
    glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
      glColor4f( r, g, b, a );
      /* Front Face */
      /* Bottom Left Of The Texture and Quad */
      glTexCoord2f( 0.0f, 1.0f ); glVertex3f( -0.5f * w, -0.5f * h, 0 );
      /* Bottom Right Of The Texture and Quad */
      glTexCoord2f( 1.0f, 1.0f ); glVertex3f(  0.5f * w, -0.5f * h, 0 );
      /* Top Right Of The Texture and Quad */
      glTexCoord2f( 1.0f, 0.0f ); glVertex3f(  0.5f * w,  0.5f * h, 0 );
      /* Top Left Of The Texture and Quad */
      glTexCoord2f( 0.0f, 0.0f ); glVertex3f( -0.5f * w,  0.5f * h, 0 );
    glEnd();
}

void Sprite::render(GLfloat x, GLfloat y, GLfloat z, GLfloat height, GLfloat width)
{
    GLfloat temp_h = h;
    GLfloat temp_w = w;
    h = height;
    w = width;
    render(x,y,z);

    h = temp_h;
    w = temp_w;
}

void Sprite::change_img(string image_path, GLfloat height, GLfloat width)
{
	img_path = image_path;
    h = height;
    w = width;
	create_texture();
}

bool Sprite::create_texture()
{
    /* Create storage space for the texture */
    SDL_Surface *TextureImage[1]; 

    /* Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit */
    if ( ( TextureImage[0] = IMG_Load( img_path.c_str() ) ) )
    {

        glPixelStorei(GL_UNPACK_ALIGNMENT,4);

        /* Create The Texture */
        glGenTextures( 1, &texture[0] );

        /* Typical Texture Generation Using Data From The Bitmap */
        glBindTexture( GL_TEXTURE_2D, texture[0] );
		
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        /* Nearest neighbour Filtering */
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

		/* TODO - Fix GL_RGBA with texture->format */
        if (TextureImage[0]->format->Amask)
        {
		
        /* Generate The Texture */
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, TextureImage[0]->w, TextureImage[0]->h,
                0, GL_BGRA, GL_UNSIGNED_BYTE, TextureImage[0]->pixels);
        }
        else // Texture without alpha channel
        {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, TextureImage[0]->w, TextureImage[0]->h,
                0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->pixels);
        }
        
    }
	
    /* Free up any memory we may have used */
    if ( TextureImage[0] )
        SDL_FreeSurface( TextureImage[0] ); 

    return 0;
}

GLuint* Sprite::get_texture() { return texture; }

void Sprite::set_color(GLfloat red, GLfloat green, GLfloat blue, GLfloat alfa)
{
    r = red;
    g = green;
    b = blue;
    a = alfa;
}
