#pragma once
#include "definitions.h"
#include <iostream>
#include "Snake.h"

struct storageUnit {
	storageUnit* next = nullptr;
	Snake* unit = nullptr;
};

class storageList {
public:
	storageList();
	~storageList();
	void addNewUnit(Snake* unitToAdd);
	bool isColliding(int testX, int testY);
public:
	storageUnit *firstObject = nullptr;
	storageUnit *lastObject = nullptr;

	int listSize = 0;
};