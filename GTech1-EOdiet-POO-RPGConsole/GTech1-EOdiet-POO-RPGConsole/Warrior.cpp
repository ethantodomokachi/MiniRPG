#include "Warrior.h"

void Warrior::BasicAttack(Character* target) {
	std::cout << GetName() << " frappe avec son epee..." << std::endl;
	
	if (rageCountdown)
		target->TakeDmg(GetAttack() * 2);
	else
		target->TakeDmg(GetAttack());
}

void Warrior::Skill(Character* target) {
	std::cout << GetName() << " s'enrage..." << std::endl;
	rageCountdown = 3;
}
