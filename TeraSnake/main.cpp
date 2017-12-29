#include "Game.h"
#include "menu.h"
#include "Window.h"
#include <iostream>

Window* window = new Window("SnakeTitan", 750, 840);
int playerScore = 0;

int main(int argc, char** argv) {
	//FreeConsole();
	menu mainMenu(window);
	Game game(window);
	mainMenu.loop(1);
	while (true) {
		playerScore = game.loop();
		game.reset();

		if (mainMenu.loop(2, playerScore) == -1) {
			break;
		}
		game.setup();
	}

	return 0;
}