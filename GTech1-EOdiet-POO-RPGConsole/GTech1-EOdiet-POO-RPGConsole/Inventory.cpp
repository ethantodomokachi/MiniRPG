#include "Inventory.h"

void Inventory::TakeItem(Potion* toTake) {
	list.push_back(toTake);
}

void Inventory::DiscardItem(int indexToRemove) {
	list.erase(list.begin() + indexToRemove);
}

std::vector<Potion*>* Inventory::GetList() {
	return &list;
}