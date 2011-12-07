#include "bullet.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>

using namespace std;

class Special_bullet : public Bullet
{
    private:

    public:
        vector<Bullet*>* bullets;
        void update();
        void render();
        void collision(Game_object&);
        string obj_type;
        Special_bullet(GLfloat x_pos, GLfloat y_pos, string obj_type, int damage, GLfloat speed, GLfloat start_angle, vector <Game_object*>* score_vec_in, vector<Bullet*>* b_ptr);
};
          
