#pragma once
#include "enemy.h"
#include "functions.h"
#include "Grid.h"
#include "lengthPoints.h"
#include "player.h"
#include "walls.h"
#include "Window.h"
#include "Text.h"

class Game
{
public:
	Game(Window* mainWindow);
	~Game();
	int loop();
	int reset();
	int setup();
private:
	std::string scoreText;
	int gridSize_x = 50, gridSize_y = 50;

	Window* window = nullptr;

	Grid* mainGrid = nullptr;
	Grid* textGrid = nullptr;
	Text* textAddOn = nullptr;


	player* playerSnake = nullptr;
	walls* wall = nullptr;
	lengthPoints* lengthAmplifier = nullptr;

	storageList* collisionObjects = nullptr;

	int score = 0;
	int playerExpectedLength = 10;
	const int startLength = 10;
};

