#ifndef SCORE_H
#define SCORE_H

#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <vector>

using namespace std;

//TODO clean this to only be definitions
//as it should be in .h files...
class Score : public Game_object
{
 public:
	Score (string typein);
	~Score();

	//void print_score();
	void change_score(int c) {score_number += c;}
	void add_score(int added_score);
	void update(){}
	void render();
	void remove_objects() {};
	int get_score();
  


 private:
  // bildmedlem + - teckenbild om negativa po�ng
  // bildmelemmar siffror t.ex 4 f�r po�ng 1632
  // alla siffror 0-9 beh�vs som bilder
 
  int score_number;
  vector<Sprite*> numbers;
};

#endif
