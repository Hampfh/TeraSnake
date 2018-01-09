#include "menu.h"

void pollEvents(Window &window, menu* menuClass) {
	SDL_Event evnt;
	if (SDL_PollEvent(&evnt)) {
		window.pollEvent(evnt);
		menuClass->pollEvent(evnt);
	}
}

menu::menu(Window *window) : _window(window) {
	menuTitle = new Text();
	menuTitle->setColor(100, 100, 100);
}

menu::~menu() {

}


void menu::pollEvent(SDL_Event &evnt, int menu) {
	
	if (evnt.type == SDL_TEXTINPUT || evnt.type == SDL_KEYDOWN){
		switch (evnt.key.keysym.sym) {
		case SDLK_SPACE:
			ready = true;
			break;
		case SDLK_RETURN:
			ready = true;
			break;
		case SDLK_DOWN:
			if (row < segmentCounter - 23) {
				row++;
			}
			break;
		case SDLK_UP:
			if (row > 0) {
				row--;
			}
			break;
		}
		
		if (evnt.type == SDL_KEYDOWN && evnt.key.keysym.sym == SDLK_BACKSPACE && name.length() > 0) {
			name = name.substr(0, name.length() - 1);
		}
		else if (evnt.type == SDL_TEXTINPUT) {
			name += evnt.text.text;
		}

		if (name.length() > 6) {
			name = name.substr(0, nameLengthLimit);
		}
		if (name[0] == ' ') {
			name = name.substr(1, name.length());
		}
	}
	else if (evnt.type == SDL_MOUSEBUTTONDOWN) {
		if (evnt.button.button == SDL_BUTTON_LEFT) {
			switchFunction(2);
		}
	}
}

int menu::switchFunction(int menu, int score) {

	switch (menu) {
	case 0:
		startMenu();
		break;
	case 1:
		deathMenu(score);
		break;
	case 2:
		highScoreMenu();
		break;
	}
	return 1;
}

void menu::startMenu() {
	Grid highScoreButton(57, 7);
	highScoreButton.setDotSize(5);
	highScoreButton.setSpacing(0);
	highScoreButton.setOffset(220, 500);
	highScoreButton.setColor(100, 100, 100);

	Grid menuGrid(40, 15);
	menuGrid.setColor(30, 30, 30);
	menuGrid.setSpacing(0);
	menuGrid.setDotSize(10);
	menuGrid.setOffset(100, 160);

	Grid menuGridTwo(160, 20);
	menuGridTwo.setColor(30, 30, 30);
	menuGridTwo.setSpacing(0);
	menuGridTwo.setDotSize(4);
	menuGridTwo.setOffset(100, 340);

	Grid menuGridThree(85, 5);
	menuGridThree.setColor(30, 30, 30);
	menuGridThree.setSpacing(0);
	menuGridThree.setDotSize(4);
	menuGridThree.setOffset(380, 770);

	while (true) {
		pollEvents(*_window, this);

		menuGrid.drawDefaults();
		menuGridTwo.drawDefaults();
		menuGridThree.drawDefaults();
		highScoreButton.drawDefaults();

		menuTitle->createText(menuGrid.dot(0, 0), "Tera");
		menuTitle->drawText();
		menuTitle->createText(menuGrid.dot(10, 7), "Snake");
		menuTitle->drawText();
		menuTitle->createText(menuGridTwo.dot(0, 0), "Enter name: " + name);
		menuTitle->drawText();
		menuTitle->createText(menuGridTwo.dot(0, 14), "Press space to start...");
		menuTitle->drawText();
		menuTitle->createText(menuGridThree.dot(0, 0), "Made by: Hampfh");
		menuTitle->drawText();

		SDL_GetMouseState(&mouseX, &mouseY);

		if ((mouseX >= highScoreButton.getOffset().x && mouseX < (highScoreButton.getOffset().x + highScoreButton.getGridSize().w * highScoreButton.getDotSize())) &&
			(mouseY >= highScoreButton.getOffset().y && mouseY < (highScoreButton.getOffset().y + highScoreButton.getGridSize().h * highScoreButton.getDotSize()))) {
			highScoreButton.setColor(100, 100, 100);
			insideHighScoreButton = true;
		}
		else {
			highScoreButton.setColor(50, 50, 50);
			insideHighScoreButton = false;
		}

		menuTitle->createText(highScoreButton.dot(1, 1), "HighScores");
		menuTitle->drawText();

		_window->refresh(30, 30, 30);

		SDL_Delay(10);

		if (_window->isClosed() == true || ready == true && name.length() > 0) {
			ready = false;
			break;
		}
		else if (ready == true && name.length() < 1 ) {
			ready = false;
		}
	}
}

void menu::deathMenu(int score) {
	std::string line;
	std::ofstream file;

	Grid highScoreButton(57,7);
	highScoreButton.setDotSize(5);
	highScoreButton.setSpacing(0);
	highScoreButton.setOffset(220, 400);
	highScoreButton.setColor(100, 100, 100);

	Grid menuGrid(60, 12);
	menuGrid.setColor(30, 30, 30);
	menuGrid.setSpacing(0);
	menuGrid.setDotSize(10);
	menuGrid.setOffset(75, 160);

	Grid menuGridTwo(150, 5);
	menuGridTwo.setColor(30, 30, 30);
	menuGridTwo.setSpacing(0);
	menuGridTwo.setDotSize(4);
	menuGridTwo.setOffset(60, 350);

	file.open("scores.txt", std::ofstream::app);

	if (name.length() > 0) {
		file << name + "|" + std::to_string(score) + "\n";
	}
	
	file.close();

	// Makes the file hidden
	DWORD attributes = GetFileAttributes("scores.txt");
	SetFileAttributes("scores.txt", attributes + FILE_ATTRIBUTE_HIDDEN);

	while (true) {
		pollEvents(*_window, this);
		menuGrid.drawDefaults();
		menuGridTwo.drawDefaults();
		highScoreButton.drawDefaults();

		menuTitle->createText(menuGrid.dot(0, 0), "Your Score:");
		menuTitle->drawText();
		menuTitle->createText(menuGrid.dot(2, 7), std::to_string(score));
		menuTitle->drawText();
		menuTitle->createText(menuGridTwo.dot(0, 0), "Press space to try again...");
		menuTitle->drawText();

		SDL_GetMouseState(&mouseX, &mouseY);
	
		if ((mouseX >= highScoreButton.getOffset().x && mouseX < (highScoreButton.getOffset().x + highScoreButton.getGridSize().w * highScoreButton.getDotSize())) && 
			(mouseY >= highScoreButton.getOffset().y && mouseY < (highScoreButton.getOffset().y + highScoreButton.getGridSize().h * highScoreButton.getDotSize()))) {
			highScoreButton.setColor(100, 100, 100);
			insideHighScoreButton = true;
		}
		else {
			highScoreButton.setColor(50, 50, 50);
			insideHighScoreButton = false;
		}

		menuTitle->createText(highScoreButton.dot(1, 1), "HighScores");
		menuTitle->drawText();

		_window->refresh(30, 30, 30);

		SDL_Delay(10);

		if (_window->isClosed() == true || ready == true) {
			ready = false;
			break;
		}
	}
}



void menu::highScoreMenu() {
	Grid scoresGrid(140, 150);
	scoresGrid.setSpacing(0);
	scoresGrid.setDotSize(4);
	scoresGrid.setOffset(100, 75);
	scoresGrid.setColor(30, 30, 30);

	Grid titleGrid(60, 5);
	titleGrid.setSpacing(0);
	titleGrid.setDotSize(10);
	titleGrid.setOffset(100, 20);
	titleGrid.setColor(30, 30, 30);

	sortingTree sorter(&scoresGrid, menuTitle);

	std::ifstream file;
	std::string line;
	std::string tempName;
	std::string tempScore;
	int score = 0;
	int segment = 0;
	int place = 1;

	file.open("scores.txt", std::ifstream::in);

	if (file.is_open()) {
		while (getline(file, line)) {
			for (int i = 0; i < line.length(); i++) {
				if (line[i] != '|') {
					if (segment == 0) {
						tempName += line[i];
					}
					else if (segment == 1) {
						tempScore += line[i];
					}
				}
				else {
					segment++;
				}
			}
			segment = 0;
			score = std::stoi(tempScore);

			playerStat* newSegment = new playerStat;

			newSegment->name = tempName;
			newSegment->score = score;
			sorter.addSegment(newSegment);
			tempName = "";
			tempScore = "";
			segmentCounter++;
		}
	}
	else {
		std::cout << "Fatal error " << std::endl;
		return;
	}

	file.close();

	while (true) {

		pollEvents(*_window, this);

		titleGrid.drawDefaults();
		scoresGrid.drawDefaults();

		menuTitle->createText(titleGrid.dot(0, 0), "Highscores:");
		menuTitle->drawText();

		sorter.readAndPrint(row);

		SDL_Delay(10);

		_window->refresh(30, 30, 30);

		if (_window->isClosed() == true || ready == true) {
			ready = false;
			break;
		}
	}
}