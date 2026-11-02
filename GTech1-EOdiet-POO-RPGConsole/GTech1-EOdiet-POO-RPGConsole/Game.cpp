#include "Game.h"

void Game::InitGame() {
	std::cout << "Bienvenue dans ce RPG Console !" << std::endl;
	mapManager.GetMap()->CreateGrid();
	mapManager.GetMap()->InitMap();
	mapManager.SetCurrentCell(0, 0);
}

void Game::GameLoop() {
	bool isPlaying = true;
	while (isPlaying) {
		mapManager.GetMap()->DisplayMap();
		mapManager.PlayerMove();
		switch (mapManager.GetCurrentCell()->GetCellType()) {
		case FIGHT:
			mapManager.FightManager(&characterManager);
			break;
		case MARKET:
			mapManager.MarketManager(&characterManager);
			break;
		case FOUNTAIN:
			mapManager.FountainManager(&characterManager);
			break;
		case BOSS:
			mapManager.BossManager(&characterManager);
			isPlaying = false;
			break;
		case TREASURE:
			mapManager.TreasureManager(&characterManager);
			break;
		}
		if (characterManager.IsHeroDead()) {
			isPlaying = false;
			std::cout << "Vous etes mort... Game Over." << std::endl;
		}
	}
}