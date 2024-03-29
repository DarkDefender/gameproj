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
#include "game_exception.h"
#include "timer.h"
#include "intro_state.h"
#include "game_state.h"
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>


#ifdef __APPLE__
#include <SDL_mixer.h>
#else
#include <SDL/SDL_mixer.h>
#endif


using namespace std;

class FrameScheduler
{
    public:
    FrameScheduler(double fps) {setFPS(fps);}

    void setFPS(double newFPS)
    {
        frame=0;
        lastFrame=firstTick=SDL_GetTicks();
        fps=newFPS;
        msPerFrame=1000.0/fps;
    }

    void reset() {setFPS(fps);}

    void waitNextFrame()
    {
        frame++;
        const unsigned int now=SDL_GetTicks();
        if (now-lastFrame>10000)reset(); //this is so standby mode or hibernation doesn't send the program into a frenzy
        lastFrame=now;
        const unsigned int targetTick=firstTick+frame*msPerFrame; //tick count we want to reach (might have passed already if we're behind schedule)
        if (now<targetTick)SDL_Delay(targetTick-now);
    }

    private:
    unsigned int frame;
    unsigned int firstTick;
    unsigned int lastFrame;
    double fps,msPerFrame;
};

//Default constructor
Game_engine::Game_engine()
{
    is_active = true;
	SCREEN_HEIGHT = 600;
	SCREEN_WIDTH = 800;
	SCREEN_BPP = 32;
	// Load textures
    init_sdl(surface);
	
    intro = new Intro_state(true);
	menu = new Menu_state(false);
    game = new Game_state(false);
	current_state = intro;
}

Game_engine::~Game_engine()
{
	delete menu;
	delete game;
	current_state = 0;
	menu = 0;
	game = 0;
	
	//Quit SDL
    SDL_Quit();
	
}

void Game_engine::change_state()
{
	
	if(current_state == menu)
	{
		current_state = game;
		game->set_running(true);
		menu->set_running(false);
	}
	else if (current_state == intro)
    {
        current_state = menu;
        menu->set_running(true);
        intro->set_running(false);
    }
    else
	{
		current_state = menu;
		menu->set_scores(game->get_scores());
		menu->set_running(true);
		game->set_running(false);
	}
	
}

//Keeps the game running
void Game_engine::run()
{

    FrameScheduler delay(60);

    Timer time;
    int frame = 0;
    time.start();

    while(menu->get_running() || game->get_running() || intro->get_running())
    {
        if(current_state->swap_state())
        {
            change_state();
        }

        //Handle key and/or other events. Pass them on if needed
        handle_events(surface);

        //Update
        current_state->update();

        //Remove objects
        current_state->remove_objects();

        //Render
        if (is_active)
        {
            current_state->render();
        }

        //Cap the frame rate
        delay.waitNextFrame();

        if ( time.get_ticks() > 1000 )
        {
            frame = 0;
            time.start();
        }

        frame++;
    }

    clean();
}

void Game_engine::handle_events(SDL_Surface*& surface)
{
    SDL_Event event;

    //While there are events to handle
    while(SDL_PollEvent(&event))
    {
        switch( event.type )
        {
            case SDL_ACTIVEEVENT:
                /* Something's happend with our focus
                 * If we lost focus or we are iconified, we
                 * shouldn't draw the screen
                 */
                //if ( event.active.gain == 0 )
                //    is_active = false;
                //else
                //    is_active = true;
                break; 
            case SDL_VIDEORESIZE:
                /* handle resize event */

                surface = SDL_SetVideoMode( event.resize.w, event.resize.h, 0, surface->flags );
                if ( !surface )
                {
                    fprintf( stderr, "Could not get a surface after resize: %s\n", SDL_GetError( ) );
                    // TODO: Fix a cleanup function if all goes to hell
                    //Quit( 1 );
                }
                resize_window( event.resize.w, event.resize.h );
                break;

                //Handle user quit
            case SDL_QUIT:
                //Stop program
                intro->set_running(false);
                menu->set_running(false);
				game->set_running(false);
                break;
            default:
				current_state->handle_key_events(event);
                break;
        }
    }
}

//Init opengl
bool Game_engine::init_gl()
{
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

bool Game_engine::resize_window( int width, int height )
    {
        /* Height / width ration */
        GLfloat ratio;

        /* Protect against a divide by zero */
        if ( height == 0 )
            height = 1;

        ratio = 4 / 3;

        /* Setup our viewport. */
        glViewport( 0, 0, ( GLint )width, ( GLint )height );

        /*
         * change to the projection matrix and set
         * our viewing volume.
         */
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity( );

        /* Set our perspective */
        //gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

        if (width <= height) {
            glOrtho(-1.3, 1.3, -1.0 / ratio, 1.0 / ratio, 0.1, 100);  // aspect <= 1
        } else {
            glOrtho(-1.3 * ratio, 1.3 * ratio, -1.0, 1.0, 0.1, 100);  // aspect > 1
        }
        /* Make sure we're chaning the model view and not the projection */
        glMatrixMode( GL_MODELVIEW );

        /* Reset The View */
        glLoadIdentity( );

        return true;
    }

//Init SDL
bool Game_engine::init_sdl(SDL_Surface*& surface)
{
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
    resize_window( SCREEN_WIDTH, SCREEN_HEIGHT );

    //Set caption
    SDL_WM_SetCaption( "Space Invaders", NULL );

    //SOUND
    //
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_Init(MIX_INIT_OGG);
    Mix_Music *music; //TODO clean this upp later
    music = Mix_LoadMUS( "RoboCop_3.ogg" );
    Mix_PlayMusic( music, -1 );


    return true;
}



//Removes objects
void Game_engine::clean()
{

}
