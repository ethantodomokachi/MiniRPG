#include "Character.h"

void Character::Heal(int amount) {
	std::cout << name << " recupere ";
	if (currentHp + amount <= hpMax) {
		std::cout << amount << " PV...";
		currentHp += amount;
	}
	else {
		std::cout << " tous ses PV...";
		currentHp = hpMax;
	}
	std::cout << std::endl;
}

void Character::TakeDmg(int amount) {
	currentHp -= amount;
	std::cout << name << " perd " << amount << " PV..." << std::endl;
	if (currentHp < 0) {
		currentHp = 0;
	}
}

void Character::TakeXP(int amount) {
	std::cout << name << " recupere " << amount << " XP..." << std::endl;
	if (xp + amount <= 100) {
		xp += amount;
	}
	else {
		int leftover = xp + amount - 100;
		LevelUp();
		xp = leftover;
	}
}

void Character::LevelUp() {
	std::cout << name << " passe au niveau " << level + 1 << " !" << std::endl;
	SetMaxHp(10);
	Heal(hpMax);
	SetAttack(5);
	level += 1;
}

std::string Character::GetName() {
	return name;
}

void Character::SetLevel(int toSet) {
	level += toSet;
}

int Character::GetAttack() {
	return attack;
}

int Character::GetCurrentHP() {
	return currentHp;
}

void Character::SetAttack(int toAdd) {
	attack += toAdd;
}

void Character::SetMaxHp(int toAdd) {
	hpMax += toAdd;
}

int Character::GetPoisonCountdown() {
	return poisonCountdown;
}

int Character::GetStrenghtCountdown() {
	return strenghtCountdown;
}

int Character::GetImmortalityCountdown() {
	return immortalityCountdown;
}

void Character::SetPoisonCountdown(int toAdd) {
	poisonCountdown += toAdd;
}

void Character::SetStrenghtCountdown(int toAdd) {
	strenghtCountdown += toAdd;
}

void Character::SetImmortalityCountdown(int toAdd) {
	immortalityCountdown += toAdd;
}

void Character::UseItem(Potion* toUse) {
	std::cout << GetName() << "Boit " << toUse->GetPotionName() << std::endl;
	switch (toUse->GetPotionType()) {
	case SOIN :
		Heal(20);
		break;
	case FORCE:
		SetStrenghtCountdown(3);
		break;
	case POISON:
		SetPoisonCountdown(3);
		break;
	case IMMORTALITE:
		SetImmortalityCountdown(2);
		break;
	}
}

void Character::SetGold(int toAdd) {
	gold += toAdd;
}

Inventory* Character::GetInvent() {
	return inventory;
}

int Character::GetGold() {
	return gold;
}

int Character::GetLevel() {
	return level;
}

Potion* Character::SelectPotion() {
	std::cout << "Que voulez-vous utiliser ?" << std::endl;
	int j = 0;
	std::vector<Potion*>* list = inventory->GetList();
	for (Potion* i : *list) {
		std::cout << j << " - " << i->GetPotionName() << std::endl;
		j++;
	}

	int input = AskInt(0, j - 1);

	return list->at(input);
}