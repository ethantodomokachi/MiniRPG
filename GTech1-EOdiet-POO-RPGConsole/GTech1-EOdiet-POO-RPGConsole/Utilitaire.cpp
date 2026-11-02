#include "Utilitaire.h"

int GenerateRandomNbr(int min, int max) {
	int randomNumber = 0;
	randomNumber = rand() % (max + 1 - min);
	randomNumber += min;
	return randomNumber;
}

char AskLetter(std::string msg) {
	bool isValid = false;
	char input;
	while (!isValid) {
		std::cout << msg << std::endl;
		std::cin >> input;

		if (input < 'a' || input > 'z') {
			std::cout << "Saisie invalide, reessayez..." << std::endl;
		}
		else {
			isValid = true;
		}
	}
	return input;
}

int AskInt(int min, int max) {
	int input;
	bool isValid = false;
	while (!isValid) {
		std::cin >> input;
		if (input < min || input > max) {
			std::cout << "Invalide, reessayez..." << std::endl;
		}
		else {
			isValid = true;
		}
	}
	return input;
}