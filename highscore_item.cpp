

#include "highscore_item.h"
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

Highscore_item::Highscore_item(string hscore)
{
	h = 0.15;
	w = 0.15;
	
	
	istringstream iss(hscore);
	
	int i = 0;
	
	do
	{
		if(i == 0)
		{
			iss >> name;
		}
		else
		{
			iss >> score;
		}
		i++;
	} while(iss);
	
	set_images();
	
}

Highscore_item::~Highscore_item()
{
	sprites.clear();
}

bool Highscore_item::operator<(const Highscore_item& copy) const
{
	return copy.get_score() < this->get_score();
}

Highscore_item::Highscore_item(string player_name,int player_score)
{
	h = 0.15;
	w = 0.15;
	
	name = player_name;
	score = player_score;
	
	set_images();
}

void Highscore_item::set_images()
{
	string path = "images/";
	string end = ".png";
	stringstream ss;
	string first;
	string second;
	string third;
	string fourth;
	string fifth;
	string sixth;
	int hundred = score/100;
	int tens = (score%100)/10;
	int ones = (score%100)%10;
	
	//Name manipulation
	ss << path << name[0] << end;
	ss >> first;
	
	ss.str(""); //clear stream
	ss.clear();
	
	ss << path << name[1] << end;
	ss >> second;
	
	ss.str(""); //clear stream
	ss.clear();
	
	ss << path << name[2] << end;
	ss >> third;
	
	ss.str(""); //clear stream
	ss.clear();
	
	ss << path << hundred << end;
	ss >> fourth;
	
	ss.str(""); //clear stream
	ss.clear();
	
	ss << path << tens << end;
	ss >> fifth;
	
	ss.str(""); //clear stream
	ss.clear();
	
	ss << path << ones << end;
	ss >> sixth;
	
	
	if(sprites.size() <= 0)
	{
		sprites.push_back(new Sprite(first, h,w));
		sprites.push_back(new Sprite(second, h,w));
		sprites.push_back(new Sprite(third, h,w));
		sprites.push_back(new Sprite(fourth, h,w));
		sprites.push_back(new Sprite(fifth, h,w));
		sprites.push_back(new Sprite(sixth, h,w));
	}
	else
	{
		sprites[0]->change_img(first,h,w);
		sprites[1]->change_img(second,h,w);
		sprites[2]->change_img(third,h,w);
		sprites[3]->change_img(fourth,h,w);
		sprites[4]->change_img(fifth,h,w);
		sprites[5]->change_img(sixth,h,w);
	}
}

int Highscore_item::get_score() const
{
	return score;	
}

void Highscore_item::set_score(int new_score)
{
	score = new_score;
}

string Highscore_item::get_name() const
{
	return name;
}

void Highscore_item::set_name(string new_name)
{
	name = new_name;
	set_images();
}

void Highscore_item::render(GLfloat x_pos, GLfloat y_pos)
{
	GLfloat k = x_pos - 0.6;
	for( unsigned int i = 0; i<sprites.size(); i++)
	{
		sprites[i]->render(k,y_pos,-5);
		k = k + 0.15;
	}	
}
