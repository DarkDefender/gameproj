#include<iostream>
#include <SDL/SDL.h>
#include "player.h"
#include "sprite.h"
#include "game_object.h"
#include "score.h"

using namespace std;


void Player :: move_up()
{
  if (y + spd<1)
    {
      y=y+spd;
    }
  else
    {
      y=1;
    }
}



void Player :: move_down()
{
  if (y - spd>-1)
    {
      y=y-spd;
    }
  
}



void Player::handle_key_events(SDL_Event keyevent)
{
  if (type=="player1")
    {
      switch(keyevent.type)
	{
	case SDL_KEYDOWN:
	  switch(keyevent.key.keysym.sym)
	    {
	    case SDLK_s:
	      y = y + 0.1;
	      //up=true;
	      break;
	    case SDLK_x:
	      y = y - 0.1;
	      //down=true;
	      break;
	    default:
	      break;
	      /*      case SDLK_LEFT:
		      break;
		      case SDLK_RIGHT:
		      break;
		      case SDLK_RETURN:
		      cout << "Return" << endl;
		      break;
		      case SDLK_ESCAPE:
		      set_running(false);
		      break;
		      default:
		      break;*/
	    }
	  break;
	case SDL_KEYUP:
	  switch(keyevent.key.keysym.sym)
	    {
	    case SDLK_s:
	      up=false;
	      break;
	    case SDLK_x:
	      down=false;
	      break;
	    default:
	      break;
	    }
	}
    }
  else  //if player2
    {
      switch(keyevent.type)
	{
	case SDL_KEYUP:
	  switch(keyevent.key.keysym.sym)
	    {
	    case SDLK_k:
	      x=x+0.1;
	      //up=false;
	      break;
	    case SDLK_m:
	      x=x-0.1;
	      //down=false;
	      break;
	    default:
	      break;
	    }
	case SDL_KEYDOWN:
	  switch(keyevent.key.keysym.sym)
	    {
	      case SDLK_k:
		y=y+0.1;
		//cout << "k trycktes " << endl;
	      //up=true;
	      break;
	    case SDLK_m:
	      y=y-0.1;
	      //down=true;
	      break;
	      //case SDLK_ESCAPE:
	      //set_running(false);
	    default:
	      break;
	      /*      case SDLK_LEFT:
		      break;
		      case SDLK_RIGHT:
		      break;
		      case SDLK_RETURN:
		      cout << "Return" << endl;
		      break;
		      case SDLK_ESCAPE:
		      set_running(false);
		      break;
		      default:
		      break;*/
	    }
	  break;
	  /*case SDL_KEYUP:
	  switch(keyevent.key.keysym.sym)
	    {
	    case SDLK_k:
	       x=x+0.1;
	       //up=false;
	      break;
	    case SDLK_m:
	      x=x-0.1;
	      //down=false;
	      break;
	    default:
	      break;
	      }*/
	}
    }
}


void Player :: update()
{
  if(up)
    move_up();
  //if(!up)
  //  x=x+0.001;
  if(down)
    move_down();
}



void Player :: render()
{
  img->render(x, y, -5);
  score_ -> render();
}