#include "Game.h"
#include "menu.h"
#include <Window.h>
#include <Windows.h>
#include <iostream>

Window* window = new Window("TeraSnake", 750, 840);
int playerScore = 0;

int main(int argc, char** argv) {
	//FreeConsole();
	menu mainMenu(window);
	Game game(window);
	mainMenu.switchFunction(0);
	while (true) {
		playerScore = game.loop();
		if (playerScore == -1) {
			break;
		}
		game.reset();

		if (mainMenu.switchFunction(1, playerScore) == -1) {
			break;
		}
		game.setup();
	}

	return 0;
}