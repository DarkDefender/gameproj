
#include "game_engine.h"
#include "game_exception.h"
#include <iostream>

using namespace std;


int main( int argc, char* args[] )
{
	Game_engine* ge = new Game_engine();
	
	try
	{
		ge->run();
	}
	catch (Game_exception &e)
	{
		cerr << e.what();
		delete ge;
		return 1;
	}
	
	delete ge;
    return 0;
}

