#include "score.h"
#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <vector>

using namespace std;

Score::Score (string typein) : score_number(8630)
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
  spd = 0;

  img = new Sprite("number1.bmp", h, w);

  img->create_texture();
}

void Score :: render()
{
  int skore = score_number;
  int i = skore%10;
  int numbers_wroten = 0;
  
  while(skore !=0)
    {
      
      switch (i) 
	{
	case 0: numbers[0] -> render(x-numbers_wroten*w,y,-5);
	  //numbers[0]-> create_texture();
	    //cout << 0 << endl;
	  break;
	case 1: numbers[1] -> render(x-numbers_wroten*w,y,-5);
	  //cout << 1 << endl;
	  break;
	case 2: numbers[2] -> render(x-numbers_wroten*w,y,-5);
	    //cout << 2 << endl;
	  break;
	case 3: numbers[3] -> render(x-numbers_wroten*w,y,-5);
	    //cout << 3 << endl;
	  break;
	case 4: numbers[4] -> render(x-numbers_wroten*w,y,-5);
	    //cout << 4 << endl;
	  break;
	case 5: numbers[5] -> render(x-numbers_wroten*w,y,-5);
	    //cout << 5 << endl;
	  break;
	case 6: numbers[6] -> render(x-numbers_wroten*w,y,-5);
	    //cout << 6 << endl;
	  break;
	case 7: numbers[7] -> render(x-numbers_wroten*w,y,-5);
	    //cout << 7 << endl;
	  break;
	case 8: numbers[8] -> render(x-numbers_wroten*w,y,-5);
	    //cout << 8 << endl;
	  break;
	case 9: numbers[9] -> render(x-numbers_wroten*w,y,-5);
	    //cout << 9 << endl;
	  break;
	}
      
      skore = skore/10;
      i = skore%10;
      numbers_wroten = numbers_wroten +1;
      //ändra position när vi har bilder.
    
    }
      
}
