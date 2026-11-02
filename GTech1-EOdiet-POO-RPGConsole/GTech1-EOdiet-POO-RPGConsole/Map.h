#pragma once
#include "Utilitaire.h"
#include "Cell.h"

class Map
{
private :
	Cell*** grid;
	int rowNbr;
	int colNbr;
public :
	Map(int rowNbr, int colNbr)
		: rowNbr(rowNbr), colNbr(colNbr) {}

	void CreateGrid();

	void InitMap();

	void SetupCells(int nbrToChange, CellType typeToSet);

	void SetupTreasures();

	void DisplayMap();

	void SetGrid(Cell*** array);

	int GetRowNbr();

	int GetColNbr();

	Cell* GetCell(int row, int col);

	~Map() {}
};

