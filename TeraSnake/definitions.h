#pragma once
#include "Dot.h"

#define DIRECTION_UP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3

#define PLAYER 0
#define WALL 1
#define ENEMY 2

struct Node {
	Node* next = nullptr;
	Dot* link = nullptr;
};

struct recursiveSearchReturn {
	int _preferedDirection;
	float chance = 1;
};