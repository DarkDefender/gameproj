#ifndef SCORE_H
#define SCORE_H

#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <vector>

using namespace std;


class Score : public Game_object
{
 public:
  Score (string typein): score_number(1632) 
{
  numbers.push_back( new Sprite("siffra0.bmp",0.1, 0.1));
  numbers[0]->create_texture();
  numbers.push_back( new Sprite("siffra1.bmp",0.1, 0.1));
  numbers[1]->create_texture();
  numbers.push_back( new Sprite("siffra2.bmp",0.1, 0.1));
  numbers[2]->create_texture();
  numbers.push_back( new Sprite("siffra3.bmp",0.1, 0.1));
  numbers[3]->create_texture();
  numbers.push_back( new Sprite("siffra4.bmp",0.1, 0.1));
  numbers[4]->create_texture();

  numbers.push_back( new Sprite("siffra5.bmp",0.1, 0.1));
  numbers[5]->create_texture();
  numbers.push_back( new Sprite("siffra6.bmp",0.1, 0.1));
  numbers[6]->create_texture();
  numbers.push_back( new Sprite("siffra7.bmp",0.1, 0.1));
  numbers[7]->create_texture();
  numbers.push_back( new Sprite("siffra8.bmp",0.1, 0.1));
  numbers[8]->create_texture();
  numbers.push_back( new Sprite("siffra9.bmp",0.1, 0.1));
  numbers[9]->create_texture();

  type = typein;
  if(typein == "player1")
    {
      x = -0.8;
    }
  else
    {
      x = 0.8;
    }

  y = 0.8;
  w = 0.1;
  h = 0.1;
  dead = false;
  speed = 0;

  img = new Sprite("number1.bmp", h, w);

  img->create_texture();
}
  //void print_score();
  void change_score(int c) {score_number += c;}

  void handle_key_events(SDL_Event keyevent) {}
  void update(){}
  void render();
  void remove_objects() {};
  


 private:
  // bildmedlem + - teckenbild om negativa poäng
  // bildmelemmar siffror t.ex 4 för poäng 1632
  // alla siffror 0-9 behövs som bilder
 
  int score_number;
  vector<Sprite*> numbers;
};

#endif
