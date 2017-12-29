#include "menu.h"

void pollEvents(Window &window, menu* menuClass) {
	SDL_Event evnt;
	if (SDL_PollEvent(&evnt)) {
		window.pollEvent(evnt);
		menuClass->pollEvent(evnt);
	}
}

menu::menu(Window *window) : _window(window) {

	menuGrid = new Grid(75, 50);
	menuGrid->setColor(30, 30, 30);
	menuGrid->setSpacing(0);
	menuGrid->setDotSize(10);
	menuGrid->setOffset(0, 160);

	menuGridTwo = new Grid(170, 5);
	menuGridTwo->setColor(30, 30, 30);
	menuGridTwo->setSpacing(0);
	menuGridTwo->setDotSize(4);
	menuGridTwo->setOffset(0, 350);

	menuGridThree = new Grid(90, 5);
	menuGridThree->setColor(30, 30, 30);
	menuGridThree->setSpacing(0);
	menuGridThree->setDotSize(4);
	menuGridThree->setOffset(350, 775);

	menuTitle = new Text();
	menuTitle->setColor(100, 100, 100);
}

menu::~menu() {

}

int menu::loop(int menu, int score) {

	while (menu == 1) {
		pollEvents(*_window, this);

		menuGrid->drawDefaults();
		menuGridTwo->drawDefaults();
		menuGridThree->drawDefaults();

		menuTitle->createText(menuGrid->dot(10, 0), "Tera");
		menuTitle->drawText();
		menuTitle->createText(menuGrid->dot(20, 7), "Snake");
		menuTitle->drawText();
		menuTitle->createText(menuGridTwo->dot(16, 0), "Press space to start...");
		menuTitle->drawText();
		menuTitle->createText(menuGridThree->dot(0, 0), "Made by: Hampfh");
		menuTitle->drawText();

		_window->refresh(30, 30, 30);

		SDL_Delay(100);

		if (_window->isClosed() == true || ready == true) {
			ready = false;
			return 0;
		}
	}
	while (menu == 2) {

		pollEvents(*_window, this);

		menuGrid->drawDefaults();
		menuGridTwo->drawDefaults();

		menuTitle->createText(menuGrid->dot(6, 0), "Your Score:");
		menuTitle->drawText();
		menuTitle->createText(menuGrid->dot(8, 7), std::to_string(score));
		menuTitle->drawText();
		menuTitle->createText(menuGridTwo->dot(16, 0), "Press space to try again...");
		menuTitle->drawText();

		_window->refresh(30, 30, 30);

		SDL_Delay(100);

		if (_window->isClosed() == true || ready == true) {
			ready = false;
			break;
		}
	}
	if (_window->isClosed() == true) {
		return -1;
	}
	return 0;
}

void menu::pollEvent(SDL_Event &evnt) {

	switch (evnt.type) {
	case SDL_KEYDOWN:
		switch (evnt.key.keysym.sym) {
		case SDLK_SPACE:
			ready = true;
			break;
		}
		break;
	}
}