CC = g++ -Wall -Wextra -pedantic

OS = $(shell uname -s)

#Default Linux
LIBS = -lGL -lGLU -lSDL_image

# MAC OS X
ifeq ($(OS),Darwin)
LIBS = -framework OpenGL -framework GLUT -framework SDL_Image -lstdc++
endif

# Windows
ifeq ($(OS),MINGW32_NT-6.0)
LIBS = -lopengl32 -lglu32 -lSDL_image
endif

all:
	$(CC) -o space-invaders main.cpp game_engine.cpp state.cpp menu_state.cpp intro_state.cpp game_state.cpp bullet.cpp game_object.cpp sprite.cpp timer.cpp name.cpp obstacle.cpp `sdl-config --cflags --libs` $(LIBS)

clean:
	@echo Cleaning up...
	@rm space-invaders
	@echo Done.
