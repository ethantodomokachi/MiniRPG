#include "Map.h"

void Map::CreateGrid() {
	Cell*** array = (Cell***) malloc(sizeof(Cell**) * rowNbr);
	if (array == nullptr) {
		exit(1);
	}
	for (int row = 0; row < rowNbr; row++) {
		array[row] = (Cell**)malloc(sizeof(Cell*) * colNbr);
		if (array[row] == nullptr) {
			exit(1);
		}
		for (int col = 0; col < colNbr; col++) {
			array[row][col] = new Cell(row, col);
		}
	}
	grid = array;
}

void Map::InitMap() {
	grid[0][0]->ChangeCellType(FIRST);
	grid[rowNbr - 1][colNbr - 1]->ChangeCellType(BOSS);
	SetupCells(rowNbr * colNbr / 2, FIGHT);
	SetupCells(3, FOUNTAIN);
	SetupCells(4, MARKET);
	SetupTreasures();
}

void Map::SetupTreasures() {
	for (int row = 0; row < rowNbr; row++) {
		for (int col = 0; col < colNbr; col++) {
			if (grid[row][col]->GetCellType() == EMPTY) {
				grid[row][col]->ChangeCellType(TREASURE);
			}
		}
	}
}

void Map::SetupCells(int nbrToChange, CellType typeToSet) {
	for (int i = 0; i < nbrToChange; i++) {
		bool isValid = false;
		while (!isValid) {
			int randRow = GenerateRandomNbr(0, rowNbr - 1);
			int randCol = GenerateRandomNbr(0, colNbr - 1);
			if (grid[randRow][randCol]->GetCellType() == EMPTY) {
				grid[randRow][randCol]->ChangeCellType(typeToSet);
				isValid = true;
			}
		}
	}
}

void Map::DisplayMap() {
	for (int row = 0; row < rowNbr; row++) {
		for (int col = 0; col < colNbr; col++) {
			std::cout << '[';
			grid[row][col]->DisplayCell();
			std::cout << ']';
		}
		std::cout << std::endl;
	}
}

int Map::GetRowNbr() {
	return rowNbr;
}

int Map::GetColNbr() {
	return colNbr;
}

Cell* Map::GetCell(int row, int col) {
	return grid[row][col];
}

void Map::SetGrid(Cell*** array) {
	grid = array;
}