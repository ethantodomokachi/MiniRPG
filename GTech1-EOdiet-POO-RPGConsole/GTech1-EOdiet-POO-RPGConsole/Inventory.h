#pragma once
#include "Utilitaire.h"
#include "Potion.h"


class Inventory
{
private :
	std::vector<Potion*> list;
public :
	Inventory() {}

	void TakeItem(Potion* toTake);

	void DiscardItem(int indexToRemove);

	Potion* SelectPotion();

	std::vector<Potion*>* GetList();

	~Inventory() {}
};

