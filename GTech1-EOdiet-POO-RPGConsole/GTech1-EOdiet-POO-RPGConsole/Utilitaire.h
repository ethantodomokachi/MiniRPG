#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <ctime>

//============consts=============/
const char* const GREEN = "\033[32m";
const char* const YELLOW = "\033[33m";
const char* const RED = "\033[31m";
const char* const BLUE = "\033[36m";
const char* const PURPLE = "\033[35m";
const char* const RESET = "\033[0m";

//============Enums=============/
enum EnnemyType {
	GOBLIN,
	OGRE,
	CHEVALIERNOIR,
	SLIME,
	DRAGON
};

enum PotionType {
	SOIN,
	POISON,
	FORCE,
	IMMORTALITE
};

enum CellType
{
	FIRST,
	EMPTY, // case de base + cases combat explorees
	FIGHT, // 50%
	FOUNTAIN, // 3 case
	MARKET, // 4 cases
	BOSS, // une case
	TREASURE // reste
};

//============Fonctions=============/
int GenerateRandomNbr(int min, int max);

char AskLetter(std::string msg);

int AskInt(int min, int max);