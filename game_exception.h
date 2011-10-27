/*
 *  Game_exception.h
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <exception>
using namespace std;

class Game_exception: public exception
{
	public:	
		virtual const char* what() const throw()
		{
			return "My exception happened";
		}
};