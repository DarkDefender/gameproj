#ifndef TIMER
#define TIMER

#include <SDL/SDL.h>
#include <vector>
#include <string>
#include "game_object.h"

class Timer : public Game_object
{
    private:
	
	
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;
	
	void update_img();

    public:
    //Initializes variables
	Timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int get_ticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};

#endif
