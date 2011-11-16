#ifndef ALIEN_H
#define ALIEN_H

#include<iostream>
#include "player.h"
#include "game_object.h"

using namespace std;

class Aliens : public Game_object
{

    private:
        vector<Bullet>* bullets;
        // vector<SpecialBullet*> spbullets;
        bool up;
        bool down;
        double x_step;
        double moved_x_dir;
        int fire_time;
        // ev. Bullets       

    public:
        Aliens (string typein, string ufo_picture, double xin, 
                double yin, bool up_in, bool down_in, vector<Bullet>* b_ptr)
            : up(up_in), down(down_in), moved_x_dir(0),fire_time(990)
        {
            bullets = b_ptr;
            type = typein;
            hp = 1;
            y = yin;
            x = xin;
            w = 0.1;
            h = 0.1;
            dead = false;
            spd = 0.005;

            if(typein == "player1")
            {
                img = new Sprite(ufo_picture, h, w);
                img->create_texture();
                x_step=-0.1;
            }
            else //if player2
            {
                img = new Sprite(ufo_picture, h, w);
                img->create_texture();
                x_step=0.1;
            }
        }

        // game-loop funktions
        void handle_key_events(SDL_Event keyevent);
        void update();
        void render();
        void remove_objects();

        void move_up();
        void move_down();
        void set_fire_time(int fire){fire_time=fire;}


};

#endif
