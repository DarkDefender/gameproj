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


State::State(Game_engine* game)
{
	ge = game;
}

State::State()
{

}

State::~State()
{

}

void State::clean()
{

}