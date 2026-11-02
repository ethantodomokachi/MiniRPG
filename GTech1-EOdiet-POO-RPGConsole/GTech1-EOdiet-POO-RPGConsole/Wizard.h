#pragma once
#include "Character.h"
#include "Utilitaire.h"

class Wizard : public Character
{
private :
	int SpellsLeft = 2;
	int maxSpells = 2;
public :
	Wizard(std::string name, Inventory* inventory)
		: Character(name, 25, 10, inventory, 25) {}

	void BasicAttack(Character* target) override;

	void Skill(Character* target) override;

	void LevelUp();
};

