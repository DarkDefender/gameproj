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

            glBegin(GL_QUADS);
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
}

void Intro_state::init()
{
    timer.start();
}

void Intro_state::update()
{
    for(int i = 0; i < (int)stars.size(); i++)
    {
        stars[i].update(timer.get_ticks());
    }
}

void Intro_state::render()
{
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    for(int i = 0; i < (int)stars.size(); i++)
    {
        stars[i].render();
    }
    
    /* Draw it to the screen */
    SDL_GL_SwapBuffers( );
}

void Intro_state::handle_key_events(SDL_Event keyevent)
{

}

void Intro_state::remove_objects()
{

}
