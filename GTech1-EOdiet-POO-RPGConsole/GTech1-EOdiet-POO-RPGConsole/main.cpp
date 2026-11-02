#include "Utilitaire.h"
#include "Game.h"

Character* SelectHero() {
	std::cout << "Comment vous appelez-vous ?" << std::endl;
	std::string name;
	std::cin >> name;

	std::cout << "Selectionnez votre hero :" << std::endl;
	std::cout << "1 - Guerrier" << std::endl;
	std::cout << "2 - Magicien" << std::endl;

	int choice = AskInt(1, 2);
	if (choice == 1) {
		return new Warrior(name, new Inventory());
	}
	else {
		return new Wizard(name, new Inventory());
	}
}


int main(){
	srand(time(NULL));
	MapManager MM(new Map(5, 5));
	CharacterManager CM(SelectHero());

	Game game(MM, CM);
	game.InitGame();
	game.GameLoop();
}
