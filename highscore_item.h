#ifndef HIGHSCORE_ITEM_H
#define HIGHSCORE_ITEM_H

#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <vector>
#include <string>

using namespace std;

class Highscore_item
	{
	public:
		Highscore_item(string hscore);
		Highscore_item(string player_name,int player_score);
		~Highscore_item();
		int get_score() const;
		void set_score(int new_score);
		string get_name() const;
		void set_name(string new_name);
		void render(GLfloat x_pos, GLfloat y_pos);
		bool operator<(const Highscore_item& copy) const;
		
	private:
		void set_images();
		string name;
		GLfloat h;
		GLfloat w;
		vector<Sprite*> sprites;
		int score;
	};

#endif