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
	while (true) {
		pollEvents(*window, *playerSnake);

		mainGrid->drawDefaults();
		textGrid->drawDefaults();

		scoreText = "Score:" + std::to_string(score);
		textAddOn->createText(textGrid->dot(2, 1), scoreText);
		textAddOn->drawText();

		if (playerSnake->update(&playerExpectedLength, &score, collisionObjects, lengthAmplifier)) {
			playerSnake->deathAnimation(window, allObjects, textGrid, textAddOn);
			break;
		}

		if (enemySnake->update(&enemyExpectedLength, collisionObjects, lengthAmplifier, playerSnake)) {
			enemySnake->killed();
		}

		wall->draw();
		lengthAmplifier->draw();

		window->refresh();

		if (window->isClosed()) {
			return -1;
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
	delete textAddOn;
	delete lengthAmplifier;
	delete enemySnake;

	score = 0;
	playerExpectedLength = startLength;
	enemyExpectedLength = enemyStartLength;
	scoreText = "";
	return 1;
}

int Game::setup() {

	mainGrid = new Grid(gridSize_x, gridSize_y);
	mainGrid->setSpacing(0);
	mainGrid->setDotSize(15);

	textGrid = new Grid(75, 10);
	textGrid->setSpacing(0);
	textGrid->setOffset(0, 750);
	textGrid->setDotSize(10);

	textAddOn = new Text;

	playerSnake = new player(mainGrid, 20, 20);
	playerSnake->SNAKE_ID = 1;

	wall = new walls(mainGrid, 0, 0);
	wall->createWallFrame(mainGrid, gridSize_x, gridSize_y);
	wall->SNAKE_ID = 1;

	enemySnake = new enemy(mainGrid, 30, 30);
	enemySnake->SNAKE_ID = 2;

	lengthAmplifier = new lengthPoints(mainGrid, 0, 0);
	lengthAmplifier->SNAKE_ID = 3;

	collisionObjects = new storageList;
	collisionObjects->addNewUnit(playerSnake);
	collisionObjects->addNewUnit(wall);
	collisionObjects->addNewUnit(enemySnake);

	allObjects = new storageList;
	allObjects->addNewUnit(playerSnake);
	allObjects->addNewUnit(wall);
	collisionObjects->addNewUnit(enemySnake);
	allObjects->addNewUnit(lengthAmplifier);

	for (int i = 0; i < 3; i++) {
		lengthAmplifier->findNewSpawnPosition(collisionObjects, gridSize_x);
	}

	setup_colors();

	return 1;
}

int Game::setup_colors() {
	mainGrid->setColor(50, 50, 50);
	textAddOn->setColor(15, 128, 140);
	playerSnake->setColor(0, 120, 0);
	enemySnake->setColor(0, 90, 0);
	wall->setColor(30, 30, 30);
	lengthAmplifier->setColor(204, 102, 0);
	textGrid->setColor(wall->getColor().r, wall->getColor().g, wall->getColor().b);
	return 1;
}