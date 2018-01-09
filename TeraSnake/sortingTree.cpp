#include "sortingTree.h"

sortingTree::sortingTree(Grid* menuGrid, Text* text) : _menuGrid(menuGrid), _text(text) {

}


sortingTree::~sortingTree(){

}

void sortingTree::addSegment(playerStat* newSegment) {
	root = addNewSegment(root, newSegment);
}

playerStat* sortingTree::addNewSegment(playerStat* currentPointer, playerStat* newSegment) {

	if (currentPointer == nullptr) {
		currentPointer = newSegment;
		return currentPointer;
	}
	else if (newSegment->score < currentPointer->score) {
		currentPointer->left = addNewSegment(currentPointer->left, newSegment);
		return currentPointer;
	}
	else if (newSegment->score > currentPointer->score) {
		currentPointer->right = addNewSegment(currentPointer->right, newSegment);
		return currentPointer;
	}
	else if (newSegment->score == currentPointer->score) {
		playerStat* tempPointer = currentPointer;
		while (tempPointer->nextEqual != nullptr) {
			tempPointer = tempPointer->nextEqual;
		}
		tempPointer->nextEqual = newSegment;
		return currentPointer;
	}
}

void sortingTree::printHighScores(std::string name, int score) {
	int placeingCoord = row * 6;
	if (placeingCoord > 0 && placeingCoord < _menuGrid->getGridSize().h - 6) {
		_text->createText(_menuGrid->dot(0, placeingCoord), std::to_string(place) + ". " + name + " : " + std::to_string(score));
		_text->drawText();
	}
	place++;
	row++;
}

void sortingTree::readAndPrint(int offset) {
	readSegment(root);
	place = 1;
	row = 1 - offset;
}

playerStat* sortingTree::readSegment(playerStat* currentObject) {
	playerStat* temp = currentObject;
	if (currentObject != NULL) {
		readSegment(currentObject->right);
		
		while (temp != nullptr) {
			printHighScores(temp->name, temp->score);
			temp = temp->nextEqual;
		}

		readSegment(currentObject->left);
	}
	return currentObject;
}

bool sortingTree::exists(playerStat* currentObject, playerStat* checkingObject) {
	if (currentObject != NULL) {
		if (currentObject == checkingObject) {
			return(true);
		}
		if (checkingObject->score < currentObject->score) {
			return(exists(currentObject->left, checkingObject));
		}
		else {
			return(exists(currentObject->right, checkingObject));
		}
	}
	else {
		return(false);
	}
}