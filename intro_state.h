/*
 *  Menu_state.h
 *  space-invaders
 *
 *  Created by Jacob Sundqvist on 10/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "state.h"
#include "sprite.h"
#include "timer.h"
#include <SDL/SDL.h>
#include <vector>
using namespace std;

class Star;

class Intro_state : public State
{
    private:
    GLfloat planet_off;
    GLfloat alien_width;

    vector<Star> stars;
    Sprite* alien;
    Sprite* planet;
    Timer timer;

    public:
    void init();
    void update();
    void render();
    void remove_objects();
    void handle_key_events(SDL_Event keyevent);
    Intro_state(bool run);

};

#endif
