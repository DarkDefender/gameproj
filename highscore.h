#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "game_object.h"
#include "sprite.h"
#include "highscore_item.h"
#include <SDL/SDL.h>
#include <vector>
#include <string>

using namespace std;

//TODO clean this to only be definitions
//as it should be in .h files...
class Highscore
	{
	public:
		Highscore();
		~Highscore();
		void add_score(vector<int> scores, vector<string> player_names);
		void render();
		void create_file();
		
	private:
		void open_file();
		void highscore_sort();
		bool score_compare(const Highscore_item& first, const Highscore_item& second);
		string score_string;
		vector<Highscore_item> items;
		Sprite* highscore_img;
		GLfloat x;
		GLfloat y;
		GLfloat w;
		GLfloat h;
		string filename;
		
	};

#endif