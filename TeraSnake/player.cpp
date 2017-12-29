#include "player.h"

player::player(Grid* mainGrid, int start_x, int start_y, int collisionListSize) {
	_mainGrid = mainGrid;
	_snakeHead_x = start_x;
	_snakeHead_y = start_y;
	color.g = 255;

	ifSelf[PLAYER] = true;
	
}

player::~player(){

}

void player::pollEvent(SDL_Event &evnt){
	switch (evnt.type) {
		// This event get triggered when a key is pressed
	case SDL_KEYDOWN:
		switch (evnt.key.keysym.sym) {
		case SDLK_UP:
			direction != DIRECTION_DOWN ? direction = DIRECTION_UP : direction;
			break;
		case SDLK_RIGHT:
			direction != DIRECTION_LEFT ? direction = DIRECTION_RIGHT : direction;
			break;
		case SDLK_DOWN:
			direction != DIRECTION_UP ? direction = DIRECTION_DOWN : direction;
			break;
		case SDLK_LEFT:
			direction != DIRECTION_RIGHT ? direction = DIRECTION_LEFT : direction;
			break;
		}
	default:
		break;
	}
}

bool player::update(int expectedLength, int* playerScore, storageList* collisions) {
	move(direction);

	if (collisions->isColliding(_snakeHead_x, _snakeHead_y)) {
		std::cout << "Player crashed" << std::endl;
		return 1;
	}

	addNewLastPart();

	if (snakeLength > expectedLength) {
		removeFirstPart();
	}

	draw();

	return false;
}
