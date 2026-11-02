#pragma once
#include "Utilitaire.h"
#include "Character.h"

class Ennemi : public Character
{
private :

	EnnemyType type;

public :
	Ennemi(std::string name, int hp, int attack, Inventory* inventory, int gold, EnnemyType type)
		: Character(name, hp, attack, inventory, gold), type(type) {}

	void BasicAttack(Character* target) override;

	void Skill(Character* target) override;
};

