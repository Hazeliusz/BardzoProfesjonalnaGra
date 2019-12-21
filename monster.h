#pragma once
#include <stdlib.h>
#include "statistics.h"
#include <string>

class Monster {
	std::string nazwa;
	Statistics statystyki;
public:
	Monster(std::string n, Statistics statystyki);
};
