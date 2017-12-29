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
		std::cout << "NEW" << std::endl;
	}
	else {
		lastObject->next = temp;
		lastObject = lastObject->next;
		lastObject->unit = unitToAdd;
		listSize++;
		std::cout << "ADDON" << std::endl;
	}
}

bool storageList::isColliding(int testX, int testY) {
	storageUnit* currentPointer = firstObject;
	int i = 0;
	while (currentPointer != lastObject) {
		if (currentPointer->unit->collision(testX, testY)) {
			std::cout << i << std::endl;
			return true;
		}
		currentPointer = currentPointer->next;
	}
	if (currentPointer->unit->collision(testX, testY)) {
		std::cout << i << std::endl;
		return true;
	}
	return false;
}