#include "player.h"

player::player(Grid* mainGrid, int start_x, int start_y, int collisionListSize) {
	_mainGrid = mainGrid;
	_snakeHead_x = start_x;
	_snakeHead_y = start_y;
	color.g = 255;	
}

player::~player(){

}

void player::deathAnimation(Window* window, storageList* allObjects, Grid* textGrid, Text* textAddOn) {
	Node* temp = getLastNode();
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			_mainGrid->drawDefaults();
			textGrid->drawDefaults();
			textAddOn->drawText();
			
			storageUnit* currentPointer = allObjects->firstObject;

			while (currentPointer != allObjects->lastObject) {
				currentPointer->unit->draw();
				currentPointer = currentPointer->next;
			}
			temp->link->setColor(140, 0, 0);
			temp->link->draw();
			window->refresh();
		}
		else {
			_mainGrid->drawDefaults();
			textGrid->drawDefaults();
			textAddOn->drawText();

			storageUnit* currentPointer = allObjects->firstObject;

			while (currentPointer != allObjects->lastObject) {
				currentPointer->unit->draw();
				currentPointer = currentPointer->next;
			}
			temp->link->setColor(100, 100, 100);
			temp->link->draw();
			window->refresh();
		}
		SDL_Delay(100);
	}
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

bool player::update(int* expectedLength, int* playerScore, storageList* collisions, lengthPoints* lengthAmplifier) {
	move(direction);

	if (collisions->isColliding(_snakeHead_x, _snakeHead_y)) {
		addNewLastPart();
		return 1;
	}
	
	if (lengthAmplifier != nullptr) {
		if (lengthAmplifier->collision(_snakeHead_x, _snakeHead_y)) {
			lengthAmplifier->removeSpecificPart(_snakeHead_x, _snakeHead_y);
			lengthAmplifier->findNewSpawnPosition(collisions, _mainGrid->getGridSize().w);
			(*expectedLength)++;
			(*playerScore)++;
		}
	}
	
	addNewLastPart();

	if (snakeLength > *expectedLength) {
		removeFirstPart();
	}

	draw();
	_lastNode->link->setColor(140, 0, 0);
	_lastNode->link->draw();

	return false;
}
