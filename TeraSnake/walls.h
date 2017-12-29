#pragma once
#include "definitions.h"
#include "Grid.h"
#include "Snake.h"
class walls : public Snake
{
public:
	walls(Grid* mainGrid, int start_x, int start_y);
	~walls();
	void createWallFrame(Grid* mainGrid, int gridWidth, int gridHeight);
};

