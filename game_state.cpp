#include "bullet.h"
#include "obstacle.h"

#include "state.h"
#include "game_state.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <time.h>
#include <vector>
#include <ostream>
#include <iostream>
using namespace std;

Game_state::Game_state(bool run) : State(run)
{
    for(int i = 0; i <= 1000; i++)
    {
        GLfloat speed;
        int angle, dmg;
        /* initialize random seed: */
        srand ( time(0) + i );

        speed = (rand() % 100 + 1) * 0.00001; //-1.0 to 1.0
        srand ( time(0) - i );
        angle = (rand() % 360); //-1.0 to 1.0

        dmg = 3;

        bullet_vec.push_back(Bullet(0,0,"bullet", dmg, speed, angle));
    }

    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= 10; j++)
        {
            obs_vec.push_back(Obstacle(0.5 + i*0.01,0.5 + j*0.01,"obs", 1));
        }
    }
}

void Game_state::update()
{
    for(int i = 0; i < (int)bullet_vec.size(); i++)
    {
        bullet_vec[i].update();
        for(int j = 0; j < (int)obs_vec.size(); j++)
            bullet_vec[i].collision(obs_vec[j]);
    }
}

void Game_state::render()
{
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    for(int i = 0; i < (int)bullet_vec.size(); i++)
    {
        bullet_vec[i].render();
    }
    for(int i = 0; i < (int)obs_vec.size(); i++)
        obs_vec[i].render();
    
    /* Draw it to the screen */
    SDL_GL_SwapBuffers( );
}

void Game_state::init()
{
}

void Game_state::handle_key_events(SDL_Event keyevent)
{

}

void Game_state::remove_objects()
{
    for(int i = 0; i < (int)bullet_vec.size(); i++)
    {
        if( bullet_vec[i].get_dead() )
        {
            bullet_vec.erase (bullet_vec.begin()+i);
            --i;
        }
    } 
    for(int i = 0; i < (int)obs_vec.size(); i++)
    {
        if( obs_vec[i].get_dead() )
        {
            obs_vec.erase (obs_vec.begin()+i);
            --i;
        }
    }
}
