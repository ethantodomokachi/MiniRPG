#pragma once
#include "Utilitaire.h"
#include "Inventory.h"

class Character
{
private :
	std::string name;
	int level = 1;
	int xp = 0;
	int hpMax;
	int currentHp;
	int attack;
	int poisonCountdown = 0;
	int strenghtCountdown = 0;
	int immortalityCountdown = 0;
	Inventory* inventory;
	int gold;
public :
	Character(std::string name, int hp, int attack, Inventory* inventory, int gold) 
		: name(name), hpMax(hp), currentHp(hp), attack(attack), inventory(inventory), gold(gold) {}

	//=====================Getters===================//
	std::string GetName();

	Inventory* GetInvent();

	int GetGold();

	int GetLevel();

	int GetAttack();

	int GetCurrentHP();

	int GetPoisonCountdown();

	int GetStrenghtCountdown();

	int GetImmortalityCountdown();

	//=====================Setters===================//
	void SetAttack(int toAdd);

	void SetMaxHp(int toAdd);

	void SetPoisonCountdown(int toAdd);

	void SetStrenghtCountdown(int toAdd);

	void SetImmortalityCountdown(int toAdd);

	void SetGold(int toAdd);

	void SetLevel(int toSet);

	//=====================Virtual===================//
	virtual void BasicAttack(Character* target) = 0;

	virtual void Skill(Character* target) = 0;

	virtual void LevelUp();

	//=====================Autres===================//
	void Heal(int amount);

	void TakeDmg(int amount);

	void TakeXP(int amout);

	void UseItem(Potion* toUse);

	virtual Potion* SelectPotion();

	virtual ~Character() {}
};

