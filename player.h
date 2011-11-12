#ifndef PLAYER_H
#define PLAYER_H
#include <SDL/SDL.h>
#include<iostream>
#include "sprite.h"
#include "game_object.h"
#include "score.h"

using namespace std;


class Player : public Game_object
{
 public:
  Player (string typein, string im): life(3), up(false), down(false)
{
  type = typein;
  y = 0;
  h = 0.1;
  w = 0.1;
  spd = 0.01;
  dead = false;
  img = new Sprite(im, h, w);
  img->create_texture();
  if(typein == "player1")
    {
      x=-1;
      score_ = new Score("player1");
    }
  else //if player2
    {
      x=1;
      score_ = new Score("player2");
    }
}

  // game-loop funktions
  void handle_key_events(SDL_Event keyevent);
  void update();
  void render();
  void remove_objects() {};
 
  void move_up();
  void move_down();
  int get_life() {return life;}
  void set_dead(bool d) {dead=d;}
  void change_life(int liv){life=life+liv;}


 private:
  int life;
  // vector<Bullet*> bullets;
  // vector<SpecialBullet*> spbullets;
  bool up;
  bool down;
  Score* score_;
  //Sprite* im9;
};

#endif
