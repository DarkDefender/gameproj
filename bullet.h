#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>

using namespace std;

class Bullet : public Game_object
{
    private:
        int dmg;

    public:
        void update();
        void render();
   //   void remove_objects();   Skall troligtvis bort!
   //   void handle_key_events(SDL_Event keyevent);
        int get_dmg();
        Bullet(GLfloat x_pos, GLfloat y_pos, string obj_type, int damage, GLfloat speed, int start_angle);
   //   TODO
   //   Eventuellt lägga till destruktor
   //   Hoppa
}

