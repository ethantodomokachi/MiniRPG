#pragma once
#include "Utilitaire.h"

class Cell
{
private :
	bool isExplored = false;
	CellType type = EMPTY;
public :

	char displayChar = ' ';
	int rowPlace;
	int colPlace;

	Cell(int row, int col) 
		: rowPlace(row), colPlace(col) {}

	void ChangeCellType(CellType Newtype);

	CellType GetCellType();

	void ChangeDisplayedChar();

	void ChangeDisplayedChar(char newChar);

	void Explore();

	void DisplayCell();
	
	~Cell() {}
};

