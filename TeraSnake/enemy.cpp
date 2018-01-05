#include "enemy.h"

enemy::enemy(Grid* mainGrid, int start_x, int start_y){
	_mainGrid = mainGrid;
	_snakeHead_x = start_x;
	_snakeHead_y = start_y;
}

enemy::~enemy(){

}


bool enemy::AI(storageList* collision) {

	Snake* player = collision->firstObject->unit;

	int x = _snakeHead_x;
	int y = _snakeHead_y;
	
	int tempX = x;
	int tempY = y;

	int tempDirection = direction;

	int playerX = collision->firstObject->unit->getLastNode()->link->getCoords().x;
	int playerY = collision->firstObject->unit->getLastNode()->link->getCoords().y;

	player->getDirection() == DIRECTION_UP ? playerY-- : playerY;
	player->getDirection() == DIRECTION_RIGHT ? playerX++ : playerX;
	player->getDirection() == DIRECTION_DOWN ? playerY++ : playerY;
	player->getDirection() == DIRECTION_LEFT ? playerX-- : playerX;

	// If true, enemy is farthest away on the x-axis
	if (abs(x - playerX) > abs(y - playerY)) {
		// Snake is under the player
		x < playerX ? tempDirection = DIRECTION_RIGHT : tempDirection = DIRECTION_LEFT;
		x < playerX ? tempX++ : tempX--;
	}
	else {
		y < playerY ? tempDirection = DIRECTION_DOWN : tempDirection = DIRECTION_UP;
		y < playerY ? tempY++ : tempY--;
	}

	if (chance("80%") && !collision->isColliding(tempX, tempY)) {
		direction = tempDirection;
		return false;
	} 
	else {
		for (int i = 0; i < 100; i++) {
			if (chance("50%")) {
				if (chance("50%") && !collision->isColliding(x + 1, y) && direction != DIRECTION_LEFT) {
					direction = DIRECTION_RIGHT;
					return false;
				}
				else if (chance("50%") && !collision->isColliding(x - 1, y) && direction != DIRECTION_RIGHT) {
					direction = DIRECTION_LEFT;
					return false;
				}
			}
			else {
				if (chance("50%") && !collision->isColliding(x, y + 1) && direction != DIRECTION_UP) {
					direction = DIRECTION_DOWN;
					return false;
				}
				else if (chance("50%") && !collision->isColliding(x, y - 1) && direction != DIRECTION_DOWN) {
					direction = DIRECTION_UP;
					return false;
				}
			}
		}
		// Crash
		return true;
	}
	return false;
}

bool enemy::killed() {
	Node* currentNode = _firstNode;

	while (currentNode != _lastNode) {
		currentNode = currentNode->next;
		delete _firstNode;
		_firstNode = currentNode;
	}
	delete _lastNode;
	_firstNode = nullptr;
	_lastNode = nullptr;
	_snakeHead_x = 1;
	_snakeHead_y = 1;
	addNewLastPart();
	snakeLength = 1;
	return true;
}

bool enemy::update(int* expectedLength, storageList* collisions, lengthPoints* lengthAmplifier, player* playerSnake) {

	if (AI(collisions)) {
		return 1;
	}
	
	if (lengthAmplifier != nullptr) {
		if (lengthAmplifier->collision(_snakeHead_x, _snakeHead_y)) {
			lengthAmplifier->removeSpecificPart(_snakeHead_x, _snakeHead_y);
			lengthAmplifier->findNewSpawnPosition(collisions, _mainGrid->getGridSize().w);
			(*expectedLength)++;
		}
	}
	move(direction);

	addNewLastPart();

	if (snakeLength > *expectedLength) {
		removeFirstPart();
	}

	draw();
	_lastNode->link->setColor(0, 0, 140);
	_lastNode->link->draw();

	return false;
}
