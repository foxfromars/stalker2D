CC=g++
N=main
F=./src/*.cpp
INCLUDE= -I ./include

compile:
	$(CC) -o $(N) $(F) `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_image

link:
