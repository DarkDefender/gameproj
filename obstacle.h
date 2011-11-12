#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

using namespace std;

class Obstacle : public Game_object
{
    public:
        void update();
        void render();
   //   void remove_objects();   Skall troligtvis bort!
   //   void handle_key_events(SDL_Event keyevent);
        Obstacle(GLfloat x_pos, GLfloat y_pos, string obj_type, int health);
   //   TODO
   //   Eventuellt lägga till destruktor
   //   Hoppa
};

#endif
