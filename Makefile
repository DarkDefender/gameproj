CC = g++ -Wall

all:
	$(CC) -o space-invaders -lGL -lGLU `sdl-config --cflags --libs` main.cpp game_engine.cpp state.cpp menu_state.cpp sprite.cpp

clean:
	@echo Cleaning up...
	@rm space-invaders
	@echo Done.
