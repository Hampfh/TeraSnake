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
	bool draw();
	bool isColliding(int testX, int testY);
	bool switchContent(int ID, Snake* newObject);
public:
	storageUnit *firstObject = nullptr;
	storageUnit *lastObject = nullptr;

	int listSize = 0;
};