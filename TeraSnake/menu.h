#pragma once
#include "Window.h"
#include "Grid.h"
#include "text.h"
#include <iostream>
#include <SDL.h>
#include <string>

class menu
{
public:
	menu(Window *window);
	~menu();
	int loop(int menu, int score = 0);
	void pollEvent(SDL_Event &evnt);
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

