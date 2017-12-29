#include "Game.h"

void pollEvents(Window &window, player &player) {
	SDL_Event evnt;

	if (SDL_PollEvent(&evnt)) {
		window.pollEvent(evnt);
		player.pollEvent(evnt);
	}
}

Game::Game(Window* mainWindow) : window(mainWindow) {
	setup();
}


Game::~Game()
{
}

int Game::loop() {
	textAddOn->setColor(150, 20, 75);
	std::cout << "Start" << std::endl;
	while (true) {
		pollEvents(*window, *playerSnake);

		mainGrid->drawDefaults();
		textGrid->drawDefaults();

		scoreText = "Score:" + std::to_string(score);
		textAddOn->createText(textGrid->dot(2, 1), scoreText);
		textAddOn->drawText();

		if (playerSnake->update(playerExpectedLength, &score, collisionObjects)) {
			break;
		}

		wall->draw();
		window->refresh();

		if (window->isClosed()) {
			break;
		}
		SDL_Delay(75);
	}
	return score;
}

int Game::reset() {
	delete mainGrid;
	delete textGrid;
	delete playerSnake;
	delete wall;
	//delete enemySnake;
	//delete textAddOn;

	score = 0;
	playerExpectedLength = startLength;
	//expectedEnemyLength = 3;
	scoreText = "";
	return 1;
}

int Game::setup() {

	mainGrid = new Grid(gridSize_x, gridSize_y);
	mainGrid->setColor(255, 255, 255);
	mainGrid->setSpacing(0);
	mainGrid->setDotSize(15);

	textGrid = new Grid(75, 10);
	textGrid->setColor(0, 0, 255);
	textGrid->setSpacing(0);
	textGrid->setOffset(0, 750);
	textGrid->setDotSize(10);

	playerSnake = new player(mainGrid, 20, 20, 10);

	wall = new walls(mainGrid, 0, 0);
	wall->createWallFrame(mainGrid, gridSize_x, gridSize_y);
	wall->setColor(0, 0, 255);

	textAddOn = new Text();

	collisionObjects = new storageList;
	collisionObjects->addNewUnit(playerSnake);
	collisionObjects->addNewUnit(wall);
	return 1;
}