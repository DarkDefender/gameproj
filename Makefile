CC = g++ -Wall -Wextra 

OS = $(shell uname -s)

#Default Linux
LIBS = -lGL -lGLU

# MAC OS X
ifeq ($(OS),Darwin)
LIBS = -framework OpenGL -framework GLUT -lstdc++
endif

# Windows
ifeq ($(OS),Windows)
LIBS = -lGL - lGLU
endif





all:
	$(CC) $(LIBS) -o space-invaders `sdl-config --cflags --libs` main.cpp game_engine.cpp state.cpp menu_state.cpp intro_state.cpp sprite.cpp timer.cpp

clean:
	@echo Cleaning up...
	@rm space-invaders
	@echo Done.
