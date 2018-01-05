#include "functions.h"

storageList::storageList() {

}

storageList::~storageList() {

}

void storageList::addNewUnit(Snake* unitToAdd) {
	storageUnit* temp = new storageUnit;
	if (firstObject == nullptr && lastObject == nullptr) {
		firstObject = temp;
		lastObject = firstObject;
		lastObject->unit = unitToAdd;
		listSize++;
	}
	else {
		lastObject->next = temp;
		lastObject = lastObject->next;
		lastObject->unit = unitToAdd;
		listSize++;
	}
}

bool storageList::draw() {
	storageUnit* currentPointer = firstObject;

	while (currentPointer != lastObject) {
		currentPointer->unit->draw();
		currentPointer = currentPointer->next;
	}
	currentPointer->unit->draw();
	return true;
}

bool storageList::isColliding(int testX, int testY) {
	storageUnit* currentPointer = firstObject;
	
	while (currentPointer != lastObject) {
		if (currentPointer->unit->collision(testX, testY)) {
			return true;
		}
		currentPointer = currentPointer->next;
	}
	if (lastObject->unit->collision(testX, testY)) {
		return true;
	}
	return false;
}

bool storageList::switchContent(int ID, Snake* newObject) {
	storageUnit* currentPointer = firstObject;

	while (currentPointer != lastObject) {
		if (currentPointer->unit->SNAKE_ID == ID) {
			delete currentPointer->unit;
			currentPointer->unit = newObject;
			return true;
		}
		currentPointer = currentPointer->next;
	}
	return false;
}