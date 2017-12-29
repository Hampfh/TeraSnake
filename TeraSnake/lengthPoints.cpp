#include "lengthPoints.h"

lengthPoints::lengthPoints(Grid* mainGrid, int start_x, int start_y){
	_mainGrid = mainGrid;
	_snakeHead_x = start_x;
	_snakeHead_y = start_y;
}


lengthPoints::~lengthPoints(){

}

void lengthPoints::findNewSpawnPosition(storageList* collisions, int gridSize) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, gridSize - 2);

	for (int i = 0; i < 1000; i++) {
		int xPos = dist(gen) + 1;
		int yPos = dist(gen) + 1;

		if (!collisions->isColliding(xPos, yPos) && !collision(xPos, yPos)) {
			Node* temp = new Node();

			if (_firstNode == nullptr) {
				_firstNode = temp;
				_lastNode = temp;
				_firstNode->link = _mainGrid->dot(xPos, yPos);
			}
			else {
				_lastNode->next = temp;
				_lastNode = _lastNode->next;
				_lastNode->link = _mainGrid->dot(xPos, yPos);
			}
			return;
		}
	}
}