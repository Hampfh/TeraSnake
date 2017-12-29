#pragma once
#include "definitions.h"
#include <iostream>
#include "Snake.h"

class storageList {
public:
	storageList();
	~storageList();
	void addNewUnit(Snake* unitToAdd);
	bool isColliding(int testX, int testY);
private:
	struct storageUnit {
		storageUnit* next = nullptr;
		Snake* unit = nullptr;
	};

	storageUnit *firstObject = nullptr;
	storageUnit *lastObject = nullptr;

	int listSize = 0;
};