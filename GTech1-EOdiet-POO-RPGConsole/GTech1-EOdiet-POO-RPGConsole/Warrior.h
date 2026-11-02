#pragma once
#include "Utilitaire.h"
#include "Character.h"

class Warrior : public Character
{
private :
	int rageCountdown = 0;

public :
	Warrior(std::string name, Inventory* inventory)
		: Character(name, 25, 10, inventory, 15) {}

	void BasicAttack(Character* target) override;

	void Skill(Character* target) override;
};

