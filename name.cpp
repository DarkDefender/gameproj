
#include "name.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <string>
#include <iostream>

using namespace std;

void Name::update()
{
	
}

Name::Name(GLfloat x_pos, GLfloat y_pos, string obj_type) : Game_object(x_pos, y_pos, obj_type)
{
	h = 0.15;
	w = 0.15;
	images.push_back("images/a.png");
	images.push_back("images/b.png");
	images.push_back("images/c.png");
	images.push_back("images/d.png");
	images.push_back("images/e.png");
	images.push_back("images/f.png");
	images.push_back("images/g.png");
	images.push_back("images/h.png");
	images.push_back("images/i.png");
	images.push_back("images/j.png");
	images.push_back("images/k.png");
	images.push_back("images/l.png");
	images.push_back("images/m.png");
	images.push_back("images/n.png");
	images.push_back("images/o.png");
	images.push_back("images/p.png");
	images.push_back("images/q.png");
	images.push_back("images/r.png");
	images.push_back("images/s.png");
	images.push_back("images/t.png");
	images.push_back("images/u.png");
	images.push_back("images/v.png");
	images.push_back("images/x.png");
	images.push_back("images/y.png");
	images.push_back("images/z.png");
	it = 0;
	img = new Sprite(images[it], h, w);
	img->create_texture();
	
}

void Name::change_letter_up()
{
	it++;
	if(it > (int)images.size() - 1)
	{
		it = 0;
	}	
	img->change_img(images[it], h, w);
}

void Name::change_letter_down()
{
	it--;
	
	if(it < 0)
	{
		it = images.size() - 1;
	}
	img->change_img(images[it], h, w);
}
