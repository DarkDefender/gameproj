CC = g++ -Wall

all:
	$(CC) -o space-invaders -lGL -lGLU `sdl-config --cflags --libs` main.cpp game_engine.cpp state.cpp menu_state.cpp intro_state.cpp sprite.cpp timer.cpp

clean:
	@echo Cleaning up...
	@rm space-invaders
	@echo Done.
