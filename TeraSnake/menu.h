#pragma once
#include <fstream>
#include "Window.h"
#include <Windows.h>
#include "Grid.h"
#include "text.h"
#include <iostream>
#include <SDL.h>
#include <string>

struct playerStat {
	playerStat* next = nullptr;
	std::string totalString;
	std::string name;
	int score;
};

class menu
{
public:
	menu(Window *window);
	~menu();
	void pollEvent(SDL_Event &evnt, int menu = 0);
	int switchFunction(int menu, int score = 0);
	void startMenu();
	void deathMenu(int score);
	void highScoreMenu();
private:
	Window * _window = nullptr;
	Grid* menuGrid = nullptr;
	Grid* menuGridTwo = nullptr;
	Grid* menuGridThree = nullptr;
	Text* menuTitle = nullptr;

	std::string scoreText = "";

	int titleWidth;
public:
	bool ready = false;
};
