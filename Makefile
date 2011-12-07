CC = g++ -Wall -Wextra -pedantic

OBJECTS = main game_engine state menu_state intro_state game_state bullet \
		  game_object sprite timer name obstacle player score alien game_timer highscore highscore_item

OFILES = $(OBJECTS:%=%.o)

IFLAGS = `sdl-config --cflags`

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

LIBS += `sdl-config --libs`

all : space-invaders

space-invaders : $(OFILES)
	@echo Linking...
	$(CC) -o space-invaders $(OFILES) `sdl-config --cflags --libs` $(LIBS)

#Define a rule for building .o from .C files
# the o-files depend on the respectively-named C-file
# # the "$<" refers to the current .C file
%.o : %.cpp
	$(CC) $(COMPILEFLAGS) $(IFLAGS) -c $< 

# All .cpp files depend on their headers...
%.cpp : %.h  

clean:
	$(RM) $(OFILES)
	@echo Cleaning up...
	@rm space-invaders
	@echo Done.
