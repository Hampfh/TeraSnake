#include "walls.h"

walls::walls(Grid* mainGrid, int start_x, int start_y){
	_mainGrid = mainGrid;
	_snakeHead_x = start_x;
	_snakeHead_y = start_y;
}

walls::~walls() {
}

void walls::createWallFrame(Grid* mainGrid, int gridWidth, int gridHeight) {

	// TOP HORIZONTAL
	for (int i = 0; i < gridWidth; i++) {
		addNewSpecificPart(i, 0);
	}

	// DOWN HORIZONTAL
	for (int i = 0; i < gridWidth; i++) {
		addNewSpecificPart(i, gridHeight - 1);
	}

	// LEFT VERTICAL
	for (int i = 1; i < gridHeight - 1; i++) {
		addNewSpecificPart(0, i);
	}

	// RIGHT VERTICAL
	for (int i = 1; i < gridHeight - 1; i++) {
		addNewSpecificPart(gridWidth - 1, i);
	}
}