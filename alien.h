#ifndef ALIEN_H
#define ALIEN_H

#include <iostream>
#include <string>
#include "player.h"
#include "game_object.h"
#include "score.h"

using namespace std;

class Aliens : public Game_object
{

    private:
        vector<Bullet>* bullets;
	vector<Game_object*>* pointer_score_vec;
        // vector<SpecialBullet*> spbullets;
        bool up;
        bool down;
        double x_step;
        double moved_x_dir;
        int fire_time;
		int current_lvl;
		string ufo_img;
		void init_alien();
        // ev. Bullets       

    public:
		Aliens(string typein, GLfloat xin, GLfloat yin, 
		       int lvl, vector<Bullet>* b_ptr, vector<Game_object*>*);
		~Aliens();

        // game-loop funktions
        void handle_key_events(SDL_Event keyevent);
        void update();
        void render();
        void remove_objects();

        void move_up();
        void move_down();
		void set_fire_time(int fire);


};

#endif
