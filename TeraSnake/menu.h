#pragma once
#include <fstream>
#include <Window.h>
#include <Windows.h>
#include "Grid.h"
#include "text.h"
#include <iostream>
#include <SDL.h>
#include <string>
#include "sortingTree.h"

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
	Text* menuTitle = nullptr;

	std::string scoreText = "";
	int nameLengthLimit = 10;
	std::string name;

	int titleWidth;

	// Highscore menu
	int segmentCounter = 0;
	int row = 0;
public:
	bool ready = false;
	bool insideHighScoreButton = false;
	int mouseX, mouseY;
};
