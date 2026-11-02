 #include "MapManager.h"

void MapManager::SetCurrentCell(int row, int col) {
	currentCell = map->GetCell(row, col);
}

Map* MapManager::GetMap() { 
	return map; 
}

void MapManager::PlayerMove() {
	bool isMovePossible = false;
	while (!isMovePossible) {
		char move = AskLetter("Ou voulez-vous aller ? (haut : w, bas : s, gauche : a, droite : d)");
		isMovePossible = CheckMove(move);
		currentCell->ChangeDisplayedChar('X');
	}
}

Cell* MapManager::GetCurrentCell() {
	return currentCell;
}

bool MapManager::CheckMove(char move) {
	bool isValid = false;
	switch (move) {
	case 'w':
		if (currentCell->rowPlace > 0) {
			currentCell->Explore();
			currentCell = map->GetCell(currentCell->rowPlace - 1, currentCell->colPlace);
			isValid = true;
		}
		else {
			std::cout << "Impossible d'aller en haut, reessayez..." << std::endl;
		}
		break;
	case 's':
		if (currentCell->rowPlace < map->GetRowNbr()) {
			currentCell->Explore();
			currentCell = map->GetCell(currentCell->rowPlace + 1, currentCell->colPlace);
			isValid = true;
		}
		else {
			std::cout << "Impossible d'aller en bas, reessayez..." << std::endl;
		}
		break;
	case 'a':
		if (currentCell->colPlace > 0) {
			currentCell->Explore();
			currentCell = map->GetCell(currentCell->rowPlace, currentCell->colPlace - 1);
			isValid = true;
		}
		else {
			std::cout << "Impossible d'aller a gauche, reessayez..." << std::endl;
		}
		break;
	case 'd':
		if (currentCell->rowPlace < map->GetColNbr()) {
			currentCell->Explore();
			currentCell = map->GetCell(currentCell->rowPlace, currentCell->colPlace + 1);
			isValid = true;
		}
		else {
			std::cout << "Impossible d'aller a droite, reessayez..." << std::endl;
		}
		break;
	default:
		std::cout << "Veuillez entrer w, a, s ou d..." << std::endl;
	}

	return isValid;
}

void MapManager::DisplayEnnemyTeam(CharacterManager* CM) {
	std::cout << "Se trouvent devant vous :" << std::endl;
	for (Ennemi* i : CM->GetEnnemyTeam()) {
		std::cout << i->GetName() << " - " << i->GetCurrentHP() << " HP." << std::endl;
	}
}

void MapManager::FightManager(CharacterManager* CM) {
	system("cls");
	std::cout << "Depuis les profondeurs de la piece, des ennemis approchent..." << std::endl;
	int turnCount = 1;
	bool isFighting = true;
	CM->initEnnemyTeam();
	DisplayEnnemyTeam(CM);
	while (isFighting) {
		std::cout << "============= tour " << turnCount << " =============" << std::endl << std::endl;
		CM->AttackAll();
		if (CM->IsHeroDead() || CM->IsEnnemiesDead()) {
			isFighting = false;
		}
		turnCount++;
	}
	std::cout << "Le combat se termine..." << std::endl;
}

void MapManager::MarketManager(CharacterManager* CM) {
	system("cls");
	std::cout << "un marchand se tient devant vous : " << std::endl;
	Inventory market;
	market.TakeItem(new Potion("Potion de poison", 1, POISON, 5));
	market.TakeItem(new Potion("Potion de soin", 1, SOIN, 15));
	market.TakeItem(new Potion("Potion de force", 1, FORCE, 30));
	market.TakeItem(new Potion("Potion d'immortalite", 1, IMMORTALITE, 50));

	bool isFinished = false;
	while (!isFinished) {
		std::cout << "Vous avez " << CM->GetHero()->GetGold() << " d'or..." << std::endl
			<<"Que voulez vous acheter ?" << std::endl;

		int j = 0;
		for (Potion* i : *market.GetList()) {
			std::cout << j << " - " << i->GetPotionName() << " - " << i->GetPrice() << std::endl;
			j++;
		}
		std::cout << j << " - quitter" << std::endl;
		int choice = AskInt(0, j);
		
		if(choice == j) {
			isFinished = true;
			continue;
		}
		if (CM->GetHero()->GetGold() >= market.GetList()->at(choice)->GetPrice()) {
			CM->GetHero()->GetInvent()->TakeItem(market.GetList()->at(choice));
			market.DiscardItem(choice);
		}
		else {
			std::cout << "Pas assez d'argent..." << std::endl;
		}

		std::cout << "Voulez-vous acheter autre chose ? (0 = non, 1 = oui)" << std::endl;
		choice = AskInt(0, 1);
		if (choice == 0) {
			isFinished = true;
		}
	}
}

void MapManager::FountainManager(CharacterManager* CM) {
	system("cls");
	std::cout << "Vous arrivez devant une grande fontaine, vous vous sentez revigore..." << std::endl;
	CM->GetHero()->LevelUp();
}

void MapManager::BossManager(CharacterManager* CM) {
	system("cls");
	std::cout << "Vous arrivez dans la Derniere salle du donjon... Le boss se tient devant vous..." << std::endl;
	int turnCount = 1;
	bool isFighting = true;
	CM->initEnnemyTeam(new Ennemi("Dragon noir", 100, 20, {}, 3000, DRAGON));
	DisplayEnnemyTeam(CM);
	while (isFighting) {
		std::cout << "============= tour " << turnCount << " =============" << std::endl << std::endl;
		CM->AttackAll();
		if (CM->IsHeroDead() || CM->IsEnnemiesDead()) {
			isFighting = false;
		}
		turnCount++;
	}
	std::cout << "Le combat se termine..." << std::endl;
}

void MapManager::TreasureManager(CharacterManager* CM) {
	system("cls");
	std::cout << "Devant vous se trouve un tresor..." << std::endl
		<< "vous obtenez ";
	switch (GenerateRandomNbr(1, 4))
	{
	case 1 :
		std::cout << "une potion de soin !" << std::endl;
		CM->GetHero()->GetInvent()->TakeItem(new Potion("Potion de soin", 1, SOIN, 15));
		break;
	case 2:
		std::cout << "une potion de poison !" << std::endl;
		CM->GetHero()->GetInvent()->TakeItem(new Potion("Potion de poison", 1, POISON, 5));
		break;
	case 3:
		std::cout << "une potion de force !" << std::endl;
		CM->GetHero()->GetInvent()->TakeItem(new Potion("Potion de force", 1, FORCE, 30));
		break;
	case 4:
		std::cout << "une potion d'immortalite !" << std::endl;
		CM->GetHero()->GetInvent()->TakeItem(new Potion("Potion d'immortalite", 1, IMMORTALITE, 50));
		break;
	default:
		std::cout << "une potion de soin !" << std::endl;
		CM->GetHero()->GetInvent()->TakeItem(new Potion("Potion de soin", 1, SOIN, 15));
		break;
	}
}