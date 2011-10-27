/*
 *  Game_engine.cpp
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "game_engine.h"
#include "state.h"
#include "menu_state.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include "game_exception.h"

using namespace std;

//Default constructor
Game_engine::Game_engine()
{
	running = true;
	menu = new Menu_state(this);
	SCREEN_HEIGHT = 600;
	SCREEN_WIDTH = 800;
	SCREEN_BPP = 32;
}

//Keeps the game running
void Game_engine::run()
{
    // Load textures
    init_sdl();
    menu->init();

    while(running)
    {
        //Handle key and/or other events. Pass them on if needed
        handle_events();

        //Update
        menu->update();

        //Remove objects
        menu->remove_objects();

        //Render
        menu->render();

    }

    clean();
}

void Game_engine::handle_events()
{
    SDL_Event event;

    //While there are events to handle
    while(SDL_PollEvent(&event))
    {
        switch( event.type )
        {
            case SDL_VIDEORESIZE:
                /* handle resize event */
                surface = SDL_SetVideoMode( event.resize.w, event.resize.h, SCREEN_BPP, surface->flags );
                if ( !surface )
                {
                    fprintf( stderr, "Could not get a surface after resize: %s\n", SDL_GetError( ) );
                    // TODO: Fix a cleanup function if all goes to hell
                    //Quit( 1 );
                }
                resizeWindow( event.resize.w, event.resize.h );
                break;

                //Handle user quit
            case SDL_QUIT:
                //Stop program
                running = false;
                break;
            case SDL_KEYDOWN:
                menu->handle_key_events(event);
                break;
            default:
                break;
        }
    }
}

//Testing purposes only
void Game_engine::show(int x, int y)
{

}

//Init opengl
bool Game_engine::init_gl()
{
    /* Enable Texture Mapping ( NEW ) */
    glEnable( GL_TEXTURE_2D );

    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );

    /* Depth buffer setup */
    glClearDepth( 1.0f );

    /* Enables Depth Testing */
    glEnable( GL_DEPTH_TEST );

    /* The Type Of Depth Test To Do */
    glDepthFunc( GL_LEQUAL );

    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );   

    //If there was any errors
    if( glGetError() != GL_NO_ERROR )
    {
        return false;
    }

    //If everything initialized
    return true;
}

bool Game_engine::resizeWindow( int width, int height )
    {
        /* Height / width ration */
        GLfloat ratio;

        /* Protect against a divide by zero */
        if ( height == 0 )
            height = 1;

        ratio = ( GLfloat )width / ( GLfloat )height;

        /* Setup our viewport. */
        glViewport( 0, 0, ( GLint )width, ( GLint )height );

        /*
         * change to the projection matrix and set
         * our viewing volume.
         */
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity( );

        /* Set our perspective */
        gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

        /* Make sure we're chaning the model view and not the projection */
        glMatrixMode( GL_MODELVIEW );

        /* Reset The View */
        glLoadIdentity( );

        return true;
    }

//Init SDL
bool Game_engine::init_sdl()
{
    /* This is our SDL surface */
    SDL_Surface *surface;
    /* Flags to pass to SDL_SetVideoMode */
    int videoFlags;
    /* this holds some info about our display */
    const SDL_VideoInfo *videoInfo;

    /* initialize SDL */
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        fprintf( stderr, "Video initialization failed: %s\n",
                SDL_GetError( ) );
        return false;
    }

    /* Fetch the video info */
    videoInfo = SDL_GetVideoInfo( );

    if ( !videoInfo )
    {
        fprintf( stderr, "Video query failed: %s\n",
                SDL_GetError( ) );
        return false;
    }

    printf ("Res is %d x %d\n", videoInfo->current_w, videoInfo->current_h);

    /* the flags to pass to SDL_SetVideoMode */
    videoFlags  = SDL_OPENGL;          /* Enable OpenGL in SDL */
    videoFlags |= SDL_GL_DOUBLEBUFFER; /* Enable double buffering */
    videoFlags |= SDL_HWPALETTE;       /* Store the palette in hardware */
    videoFlags |= SDL_RESIZABLE;       /* Enable window resizing */

    /* This checks to see if surfaces can be stored in memory */
    if ( videoInfo->hw_available )
        videoFlags |= SDL_HWSURFACE;
    else
        videoFlags |= SDL_SWSURFACE;

    /* This checks if hardware blits can be done */
    if ( videoInfo->blit_hw )
        videoFlags |= SDL_HWACCEL;

    /* Sets up OpenGL double buffering */
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /* get a SDL surface */
    surface = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
            videoFlags );

    /* Verify there is a surface */
    if ( !surface )
    {
        fprintf( stderr,  "Video mode set failed: %s\n", SDL_GetError( ) );
        return false;
    }

    //Initialize OpenGL
    if( init_gl() == false )
    {
        return false;
    }

     /* resize the initial window */
    resizeWindow( SCREEN_WIDTH, SCREEN_HEIGHT );

    //Set caption
    SDL_WM_SetCaption( "Most awesome game ever", NULL );

    return true;
}



//Removes objects
void Game_engine::clean()
{

}

//Stop/run game
void Game_engine::set_running(bool run)
{
    running = run;
}

//get running status
bool Game_engine::get_running()
{
    return running;
}
