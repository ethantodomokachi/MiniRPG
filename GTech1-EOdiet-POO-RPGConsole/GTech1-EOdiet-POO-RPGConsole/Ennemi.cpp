#include "Ennemi.h"

void Ennemi::BasicAttack(Character* target) {
	std::cout << GetName() << " attaque..." << std::endl;
	target->TakeDmg(GetAttack());
}

void Ennemi::Skill(Character* target) {
	std::cout << GetName();
	switch (type) {
	case GOBLIN :
		std::cout << " ricane avec amusement...";
		break;
	case OGRE :
		std::cout << " frappe avec son gourdin a deux mains...";
		target->TakeDmg(GetAttack() * 1.5);
		break;
	case CHEVALIERNOIR :
		std::cout << " invoque la magie noire pour se soigner...";
		Heal(GetAttack());
		break;
	case SLIME :
		std::cout << " fretille...";
		break;
	case DRAGON :
		std::cout << " crache du feu...";
		target->TakeDmg(GetAttack() * 2);
		break;
	}
	std::cout << std::endl;
}