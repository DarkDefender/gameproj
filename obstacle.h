#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <vector>

using namespace std;

class Obstacle : public Game_object
{
    public:
        bool half_life;
        void update();
        void render();
        void set_dead();
   //   void remove_objects();   Skall troligtvis bort!
   //   void handle_key_events(SDL_Event keyevent);
        Obstacle(GLfloat x_pos, GLfloat y_pos, string obj_type, int health);
   //   TODO
   //   Eventuellt lägga till destruktor
   //   Hoppa
};

vector<Obstacle> create_obs(GLfloat x, GLfloat y, int type = 0);

#endif
