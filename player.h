#ifndef PLAYER_H
#define PLAYER_H
#include <SDL/SDL.h>
#include<iostream>
#include "sprite.h"
#include "game_object.h"
#include "score.h"
#include "bullet.h"

using namespace std;


class Player : public Game_object
{
    private:
        int life;
        vector<Bullet>* bullets;
	vector <Game_object*>* score_vec;
        // vector<SpecialBullet*> spbullets;
        bool up;
        bool down;
		bool shooting;
		int shoot_cooldown;
		int shoot_cnt;
        Score* score_;
		string player_img;
        int number_of_bullets;
        //Sprite* im9;
		void shoot();

    public:
		Player(string typein, vector<Bullet>* b_ptr, vector <Game_object*>* score_vec_in);

        // game-loop funktions
        void handle_key_events(SDL_Event keyevent);
        void update();
        void render();
        void remove_objects();

        void move_up();
        void move_down();
        int get_life() {return life;}
        void set_dead(bool d) {dead=d;}
        void change_life(int liv){life=life+liv;}
        void set_number_of_bullets(int nbr){number_of_bullets=nbr;}

};

#endif
