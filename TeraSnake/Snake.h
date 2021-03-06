#pragma once
#include "definitions.h"
#include "Grid.h"

class Snake
{
public:
	Snake();
	~Snake();
	void addNewLastPart();
	void addNewSpecificPart(int x, int y);
	bool collision(int x, int y);
	void draw();
	void move(int direction);
	void removeFirstPart();
	void removeSpecificPart(int x, int y);
	void setColor(int r, int g, int b);
	inline Node* getFirstNode() { return _firstNode; };
	inline Node* getLastNode() { return _lastNode; };
	inline colorTemplate getColor() { return color; };
	inline int getDirection() { return direction; };
public:
	int SNAKE_ID;
protected:
	colorTemplate color;
	int snakeLength;
	int direction;

	int _snakeHead_x;
	int _snakeHead_y;

	Grid* _mainGrid = nullptr;

	Node* _firstNode = nullptr;
	Node* _lastNode = nullptr;
};

