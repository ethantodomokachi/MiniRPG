#pragma once
#include "Utilitaire.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Ennemi.h"

class CharacterManager
{
private :
	Character* hero;
	std::vector<Ennemi*> ennemyTeam;
public :
	CharacterManager(Character* hero)
		: hero(hero) {}

	void initEnnemyTeam();

	void initEnnemyTeam(Ennemi* boss);

	Character* HeroSelectTarget();

	void PlayerAttack();

	void EnnemiesAttack();

	std::vector<Ennemi*> GetEnnemyTeam();

	void AttackAll();

	bool IsHeroDead();

	bool IsEnnemiesDead();

	void CheckIfDead(Character* Target);

	void resetEnnemyTeam();


	Character* GetHero();

	~CharacterManager() {}
};

