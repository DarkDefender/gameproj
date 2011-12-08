#include "highscore.h"
#include "highscore_item.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

Highscore::Highscore()
{
	h = 0.2;
	w = 0.5;
	x = 1;
	y = 0.8;
	
	
	//Test
	score_string = "jak 768";
	
	highscore_img = new Sprite("images/highscore.png", h,w);	
	open_file();
	
	
}

Highscore::~Highscore()
{
	delete highscore_img;
	items.clear();
}

void Highscore::open_file()
{	
	string line;
	ifstream myfile ("highscore.txt");
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
			getline (myfile,line);
			if(line != "")
			{
				items.push_back(Highscore_item(line));
			}
		}
		myfile.close();
	}
	
	myfile.close();
	
}

void Highscore::create_file()	
{
	ofstream myfile;
	myfile.open ("highscore.txt");
	for( unsigned int i = 0; i<items.size(); i++)
	{
		myfile << items[i].get_name() << " " << items[i].get_score() << "\n";
	}
	myfile.close();
}

void Highscore::add_score(vector<int> scores, vector<string> player_names)
{
	int player1_score = scores[1];
	int player2_score = scores[0];
	string player1_name;
	string player2_name;
	
	stringstream ss;
	
	ss << player_names[0] << player_names[1] << player_names[2];
	ss >> player1_name;
	
	ss.str("");
	ss.clear();
	
	ss << player_names[3] << player_names[4] << player_names[5];
	ss >> player2_name;
	
	ss.str("");
	ss.clear();
	
	//Player 1
	if(items.size() <= 0)
	{
		items.push_back(Highscore_item(player1_name,player1_score));
	}
	else
	{
		for(unsigned int i = 0; i<items.size();i++)
		{

			if(items.size() == 10)
			{
				if(items[i].get_score() < player1_score)
				{
					items[items.size()-1].set_score(player1_score);
					items[items.size()-1].set_name(player1_name);
					break;
				}
			}
			else
			{
				items.push_back(Highscore_item(player1_name,player1_score));
				break;
			}
		}
	}
	
	highscore_sort();
	
	//Player 2
	for(unsigned int i = 0; i<items.size();i++)
	{
		
		if(items.size() == 10)
		{
			if(items[i].get_score() < player2_score)
			{
				items[items.size()-1].set_score(player2_score);
				items[items.size()-1].set_name(player2_name);
				break;
			}
		}
		else
		{
			items.push_back(Highscore_item(player2_name,player2_score));
			break;
		}
	}
	
	highscore_sort();
}

void Highscore::highscore_sort()
{
	
	sort(items.begin(),items.end());
}

void Highscore::render()
{
	highscore_img->render(x,y,-5);
	GLfloat y_pos = y - 0.2;
	for( unsigned int i = 0; i<items.size(); i++)
	{
		items[i].render(x,y_pos);
		y_pos = y_pos - 0.15;
	}	
}

bool score_compare(const Highscore_item& first, const Highscore_item& second)
{
	return (first.get_score() > second.get_score());	
}