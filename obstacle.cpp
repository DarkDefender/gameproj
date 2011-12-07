#include "obstacle.h"
#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <math.h>

#include <vector>

#include <iostream>
using namespace std;

Obstacle::Obstacle(GLfloat x_pos, GLfloat y_pos, string obj_type, int health)
{
    x = x_pos;
    y = y_pos;
    type = obj_type;
    hp = health;
    dead = false;
    w = 0.01;
    h = 0.01;
}

void Obstacle::update()
{
}

void Obstacle::render()
{
    glLoadIdentity( );
    glTranslatef(x, y, -5);

    glBegin(GL_QUADS);
    glVertex3f(-0.005, 0.005, 0);
    glVertex3f(0.005, 0.005, 0);
    glVertex3f(0.005, -0.005, 0);
    glVertex3f(-0.005, -0.005, 0);
    glEnd();
}

vector<Obstacle> create_obs(GLfloat x, GLfloat y, int type)
{
    vector<Obstacle> obs_vec;
    switch (type)
    {
        case 0:
            for(int i = 0; i < 5; i++)
            {
                obs_vec.push_back(Obstacle(x, y+(15-i)/100.0, "obs", 1));
                obs_vec.push_back(Obstacle(x, y-(15-i)/100.0, "obs", 1));
                obs_vec.push_back(Obstacle(x+0.01, y+(15-i)/100.0, "obs", 1));
                obs_vec.push_back(Obstacle(x+0.01, y-(15-i)/100.0, "obs", 1));
            }
            if (x < 0)
            {
                for(int i = 0; i < 5; i++)
                    for(int j = 15-i; j > 0; j--)
                    {
                        obs_vec.push_back(Obstacle(0.01*(100*x+2+i), y+j/100.0, "obs", 1));
                        obs_vec.push_back(Obstacle(0.01*(100*x+2+i), y-j/100.0, "obs", 1));
                    }
                if (y == 0)
                    for(int i = 0; i < 5; i++)
                        for(int j = 16+i; j > 15; j--)
                        {
                            obs_vec.push_back(Obstacle(x-0.01*(i-1), y+0.01*j, "obs", 1));
                            obs_vec.push_back(Obstacle(x-0.01*(i-1), y-0.01*j, "obs", 1));
                        }
            }
            else
            {
                for(int i = 0; i < 5; i++)
                    for(int j = 15-i; j > 0; j--)
                    {
                        obs_vec.push_back(Obstacle(0.01*(100*x-1-i), y+j/100.0, "obs", 1));
                        obs_vec.push_back(Obstacle(0.01*(100*x-1-i), y-j/100.0, "obs", 1));
                    }
                 if (y == 0)
                    for(int i = 0; i < 5; i++)
                        for(int j = 16+i; j > 15; j--)
                        {
                            obs_vec.push_back(Obstacle(x+0.01*i, y+0.01*j, "obs", 1));
                            obs_vec.push_back(Obstacle(x+0.01*i, y-0.01*j, "obs", 1));
                        }   
            }

            break;
    }
    return obs_vec;
}
     
