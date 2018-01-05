#pragma once
#include "functions.h"
#include "lengthPoints.h"
#include <SDL.h>
#include "Snake.h"
#include "Text.h"

class player : public Snake
{
public:
	player(Grid* mainGrid, int start_x, int start_y);
	~player();
	void pollEvent(SDL_Event &evnt);
	bool update(int* expectedLength, int* playerScore, storageList* collisions, lengthPoints* lengthAmplifier);
	void deathAnimation(Window* window, storageList* allObjects, Grid* textGrid, Text* textAddOn);
};

