#pragma once
#include "Utilitaire.h"

class Potion
{
private :
	std::string name;
	int usesLeft;
	PotionType type;
	int price;
public :
	Potion(std::string name, int usesLeft, PotionType type, int price)
		: name(name), usesLeft(usesLeft), type(type), price(price) {}

	std::string GetPotionName();

	int GetUsesLeft();

	int GetPrice();

	PotionType GetPotionType();

	void DecreasePotionUses();

	~Potion() {}
};

