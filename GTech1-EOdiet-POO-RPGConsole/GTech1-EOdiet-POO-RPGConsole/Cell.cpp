#include "Cell.h"

void Cell::ChangeCellType(CellType Newtype) {
	type = Newtype;
	ChangeDisplayedChar();
}

CellType Cell::GetCellType() {
	return type;
}

void Cell::ChangeDisplayedChar() {
	switch (type) {
	case EMPTY : 
		displayChar = ' ';
		break;
	case MARKET:
		displayChar = 'M';
		break;
	case FIGHT:
		displayChar = 'F';
		break;
	case FOUNTAIN :
		displayChar = '+';
		break;
	case BOSS:
		displayChar = '!';
		break;
	case TREASURE:
		displayChar = 'T';
	}
}

void Cell::ChangeDisplayedChar(char newChar) {
	displayChar = newChar;
}

void Cell::Explore() {
	isExplored = true;
	ChangeCellType(EMPTY);
}

void Cell::DisplayCell() {
	switch (displayChar) {
	case 'M':
		std::cout << BLUE;
		break;
	case 'F':
		std::cout << RED;
		break;
	case '+':
		std::cout << GREEN;
		break;
	case '!':
		std::cout << PURPLE;
		break;
	case 'T':
		std::cout << YELLOW;
	}

	std::cout << displayChar << RESET;
}