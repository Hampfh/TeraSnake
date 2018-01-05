#pragma once
#include "functions.h"
#include <Grid.h>
#include "lengthPoints.h"
#include "Snake.h"
#include "player.h"
#include "probability.h"

class enemy : public Snake
{
public:
	enemy(Grid* mainGrid, int start_x, int start_y);
	~enemy();
	bool AI(storageList* collision);
	bool killed();
	bool update(int* expectedLength, storageList* collisions, lengthPoints* lengthAmplifier, player* playerSnake);
};

