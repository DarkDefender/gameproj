/*
 *  State.cpp
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "state.h"
#include "game_engine.h"

void State::set_running(bool run)
{
	running = run;
	change_state = false;
}
bool State::get_running()
{
	return running;
}

bool State::swap_state()
{
	return change_state;
}


State::State(bool run)
{
	running = run;
}

State::~State()
{

}

void State::clean()
{

}