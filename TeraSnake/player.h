#pragma once
#include "functions.h"
#include <SDL.h>
#include "Snake.h"

class player : public Snake
{
public:
	player(Grid* mainGrid, int start_x, int start_y, int collisionListSize);
	~player();
	void pollEvent(SDL_Event &evnt);
	bool update(int expectedLength, int* playerScore, storageList* collisions);
	//void deathAnimation(Window* window, ObjectList);
};

