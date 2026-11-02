#include "Wizard.h"

void Wizard::BasicAttack(Character* target) {
	std::cout << GetName() << " Lance une boule de feu..." << std::endl;
	target->TakeDmg(GetAttack());
}

void Wizard::Skill(Character* target) {
	std::cout << GetName() << " utilise un sort et se soigne..."<< std::endl;
	SpellsLeft -= 1;
	target->Heal(GetAttack() * 2);
}

void Wizard::LevelUp() {
	std::cout << GetName() << " passe au niveau " << GetLevel() + 1 << " !" << std::endl;
	SetAttack(5);
	SetMaxHp(10);
	Heal(3000);
	maxSpells += 1;
	SpellsLeft = maxSpells;
	SetLevel(1);
}