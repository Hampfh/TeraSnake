#pragma once
#include "functions.h"
#include <random>
#include "Snake.h"

class lengthPoints : public Snake
{
public:
	lengthPoints(Grid* mainGrid, int start_x, int start_y);
	~lengthPoints();
	void findNewSpawnPosition(storageList* collisions, int gridSize);
};

