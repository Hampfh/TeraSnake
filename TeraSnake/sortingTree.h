#pragma once
#include <string>
#include <iostream>
#include <Grid.h>
#include <Text.h>

struct playerStat {
	playerStat* right = nullptr;
	playerStat* left = nullptr;
	playerStat* nextEqual = nullptr;
	std::string name;
	int score;
};

class sortingTree
{
public:
	sortingTree(Grid* menuGrid, Text* text);
	~sortingTree();
	void addSegment(playerStat* newSegment);
	void readAndPrint(int offset);
	void printHighScores(std::string name, int score);
	bool exists(playerStat* currentObject, playerStat* checkingObject);
private:
	playerStat *addNewSegment(playerStat* root, playerStat* newSegment);
	playerStat* readSegment(playerStat* currentObject);
private:
	playerStat *root = nullptr;
	int place = 1;
	int row = 1;

	Grid* _menuGrid = nullptr;
	Text* _text = nullptr;
};

