#include "score.h"
#include "game_object.h"
#include "sprite.h"
#include <SDL/SDL.h>
#include <vector>

using namespace std;

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
