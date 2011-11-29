#include "state.h"
#include "sprite.h"
#include "intro_state.h"
#include "timer.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <time.h>
#include <vector>
#include <ostream>
#include <iostream>
using namespace std;

class Star
{
    private:
        GLfloat x, y, z, speed;
        Star();

    public:
        void update(GLfloat time)
        {
            if (time <= 15000)
                y += speed * 0.5 * (15 - time/1000);
            if (y >= 1.0)
                y = -1.0;
        }

        void render()
        {
            glLoadIdentity( );
            glTranslatef( x, y , z);
            glDisable( GL_TEXTURE_2D );
            // Enable transparency (blending textures/colors)
            glEnable (GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

            glBegin(GL_QUADS);
            glColor4f( 1, 1, 1, 0.2*-z );
            glVertex3f(0, 0.009, 0);
            glVertex3f(0.005, 0, 0);
            glVertex3f(0, -0.009, 0);
            glVertex3f(-0.005, 0, 0);
            glEnd();
        }
        Star(GLfloat u, GLfloat v, GLfloat w)
        {
            speed = 0;
            x = u;
            y = v;
            z = w;
            if (z >= 0)
                speed += 0.05;
            else
                speed -= (0.05/z);
        }
};

Intro_state::Intro_state(bool run) : State(run)
{
    alien = new Sprite("alien.png", 0.8, 0.8);
    planet = new Sprite("glob.png", 0.7, 0.7);
    alien->create_texture();
    planet->create_texture();

    planet_off = -1;
    alien_width = -0.8;

    for(int i = 0; i <= 50; i++)
    {
        GLfloat x, y, z;
        /* initialize random seed: */
        srand ( time(0) + i );

        x = (rand() % 25 - 12) * 0.1; //-1.0 to 1.0
        srand ( time(0) - i );
        y = (rand() % 20 - 10) * 0.1; //-1.0 to 1.0

        srand ( time(0) + i );
        z = (rand() % -10 - 40) * 0.1;

        stars.push_back(Star(x,y,z));
    }
    timer.start();
}

void Intro_state::init()
{
}

void Intro_state::update()
{
    for(int i = 0; i < (int)stars.size(); i++)
    {
        stars[i].update(timer.get_ticks());
    }
    if ( timer.get_ticks() >= 12000 && timer.get_ticks() < 15000)
    {
        planet_off *= 0.98;
    }
    if ( timer.get_ticks() > 15000 && timer.get_ticks() < 15300)
    {
        planet->set_color(0,0,0,1);
        alien->set_color(0,0,0,1);
        alien_width *= 0.8;
    }
    if (timer.get_ticks() > 15300)
    {
        planet->set_color(1,1,1,1);
        alien->set_color(1,1,1,1);
    }
}

void Intro_state::render()
{
    /* Clear The Screen And The Depth Buffer */
    if (timer.get_ticks() >= 15000 && timer.get_ticks() < 15300)
        glClearColor( 1.0f, 1.0f, 1.0f, 0.5f );
    else
        glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    for(int i = 0; i < (int)stars.size(); i++)
    {
        stars[i].render();
    }
    if (timer.get_ticks() >= 15000)
    {
        alien->render(0,-0.1, -2, 0.8 + alien_width, 0.8);
    }
    if ( timer.get_ticks() >= 12000 )
    {
        planet->render(0,-0.7 + planet_off ,-1);
    }

    /* Draw it to the screen */
    SDL_GL_SwapBuffers( );
}

void Intro_state::handle_key_events(SDL_Event keyevent)
{
//TODO Check for esc to cancel the intro... Place holder.
}

void Intro_state::remove_objects()
{

}
