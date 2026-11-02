#pragma once
#include "Utilitaire.h"
#include "Map.h"
#include "CharacterManager.h"

class MapManager
{
private :
	Map* map;
	Cell* currentCell;
public :
	MapManager(Map* map) 
		: map(map) {}

	Map* GetMap();

	void SetCurrentCell(int row, int col);

	Cell* GetCurrentCell();

	void DisplayEnnemyTeam(CharacterManager* CM);

	void PlayerMove();

	bool CheckMove(char move);

	void FightManager(CharacterManager* CM);

	void MarketManager(CharacterManager* CM);

	void FountainManager(CharacterManager* CM);

	void BossManager(CharacterManager* CM);

	void TreasureManager(CharacterManager* CM);

	~MapManager() {}
};

