#include "Potion.h"

std::string Potion::GetPotionName() {
	return name;
}

int Potion::GetUsesLeft() {
	return usesLeft;
}

PotionType Potion::GetPotionType() {
	return type;
}

int Potion::GetPrice() {
	return price;
}

void Potion::DecreasePotionUses() {
	usesLeft -= 1;
}