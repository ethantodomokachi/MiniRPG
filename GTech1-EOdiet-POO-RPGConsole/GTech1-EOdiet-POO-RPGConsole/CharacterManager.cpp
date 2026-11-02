#include "CharacterManager.h"

void CharacterManager::initEnnemyTeam() {
	int ennemyCount = GenerateRandomNbr(1, 3);
	for (int i = 0; i < ennemyCount; i++) {
		switch (GenerateRandomNbr(1, 4))
		{
		case 1:
			ennemyTeam.push_back(new Ennemi("Slime", 5 * hero->GetLevel(), 2, {}, 5, SLIME));
			break;
		case 2:
			ennemyTeam.push_back(new Ennemi("Goblin", 10 * hero->GetLevel(), 5, {}, 20, GOBLIN));
			break;
		case 3:
			ennemyTeam.push_back(new Ennemi("Chevalier Noir", 20 * hero->GetLevel(), 15, {}, 40, CHEVALIERNOIR));
			break;
		case 4:
			ennemyTeam.push_back(new Ennemi("Ogre", 15 * hero->GetLevel(), 10, {}, 15, OGRE));
			break;
		default:
			break;
		}
	}
}

void CharacterManager::initEnnemyTeam(Ennemi* boss) {
	ennemyTeam.push_back(boss);
}

Character* CharacterManager::HeroSelectTarget() {
	int j = 0;
	std::cout << "Choisissez votre cible : " << std::endl;
	for (Ennemi* i : ennemyTeam) {
		std::cout << j << " - " << i->GetName() << " - " << i->GetCurrentHP() << " HP." << std::endl;
		j++;
	}
	std::cout << j << " - " << GetHero()->GetName() << " - " << GetHero()->GetCurrentHP() << " HP." << std::endl;
	int targetIndex = AskInt(0, j);

	if (targetIndex == j) {
		return GetHero();
	}
	else {
		return ennemyTeam.at(targetIndex);
	}
}

void CharacterManager::PlayerAttack() {
	std::cout << "C'est a votre tour de jouer..." << std::endl;
	std::cout << hero->GetName() << " - " << hero->GetCurrentHP() << " HP." << std::endl;
	std::cout << "Que voulez-vous faire ? Attaque normale : 1, Competence : 2, Utiliser un objet : 3" << std::endl;
	int choice = AskInt(1, 3);
	
	bool isValid = false;
	while (!isValid)
	if(choice == 1) {
		Character* target = HeroSelectTarget();
		hero->BasicAttack(target);
		CheckIfDead(target);
		isValid = true;
	}
	else if (choice == 2) {
		Character* target = HeroSelectTarget();
		hero->Skill(target);
		CheckIfDead(target);
		isValid = true;
	}
	else if (choice == 3) {
		if(hero->GetInvent()->GetList()->empty()) {
			std::cout << "Vous n'avez pas d'objet..." << std::endl;
		}
		else {
			Potion* toUse = hero->SelectPotion();
			hero->UseItem(toUse);
			isValid = true;
		}
	}
}

void CharacterManager::CheckIfDead(Character* target) {
	if (target->GetCurrentHP() == 0) {
		auto it = std::find(ennemyTeam.begin(), ennemyTeam.end(), target);
		if (it != ennemyTeam.end()) {
			std::cout << target->GetName() << " est mort !, vous obtenez " << target->GetLevel() * 10
				<< " XP et " << target->GetGold() << " d'or..." << std::endl;
			hero->TakeXP((target->GetLevel() * 10));
			hero->SetGold(target->GetGold());
			ennemyTeam.erase(it);
			delete target;
		}
	}
}

void CharacterManager::EnnemiesAttack() {
	for(Ennemi* i : ennemyTeam) {
		int choice = GenerateRandomNbr(1, 2);

		if (choice == 1) {
			i->BasicAttack(GetHero());
		}
		else {
			i->Skill(GetHero());
		}
		if(GetHero()->GetCurrentHP() == 0) {
			break;
		}
	}
}

std::vector<Ennemi*> CharacterManager::GetEnnemyTeam() {
	return ennemyTeam;
}

void CharacterManager::AttackAll() {
	PlayerAttack();
	EnnemiesAttack();
}

bool CharacterManager::IsHeroDead() {
	return (hero->GetCurrentHP() == 0);
}

bool CharacterManager::IsEnnemiesDead() {
	return ennemyTeam.empty();
}

void CharacterManager::resetEnnemyTeam() {
	for (Ennemi* i : ennemyTeam) {
		ennemyTeam.pop_back();
		delete i;
	}
}

Character* CharacterManager::GetHero() {
	return hero;
}