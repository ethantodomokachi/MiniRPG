#pragma once
#include "Utilitaire.h"
#include "MapManager.h"

class Game
{
private:
	MapManager mapManager;
	CharacterManager characterManager;

public:
	Game(MapManager MM, CharacterManager CM) 
		: mapManager(MM), characterManager(CM) {}

	void InitGame();

	void GameLoop();

	~Game() {}
};

