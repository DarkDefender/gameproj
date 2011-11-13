#ifndef BULLET_H
#define BULLET_H

#include "game_object.h"
#include "obstacle.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

using namespace std;

class Bullet : public Game_object
{
    private:

    public:
        void update();
        void collision(Game_object&);
        void render();
	void reverse_speed() {spd = -spd;}
   //   void remove_objects();   Skall troligtvis bort!
   //   void handle_key_events(SDL_Event keyevent);
        Bullet(GLfloat x_pos, GLfloat y_pos, string obj_type, int damage, GLfloat speed, int start_angle);
   //   TODO
   //   Eventuellt lägga till destruktor
   //   Hoppa
};

#endif
