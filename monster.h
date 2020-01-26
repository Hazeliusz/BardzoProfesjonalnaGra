#pragma once
#include <stdlib.h>
#include "statistics.h"
#include <string>
#include "character.h"

class Monster : public Character
{
public:
	Monster(int monsterNumber = 1, bool sexy = false, Statistics statystyki = Statistics(), std::string nazwa = "non");// p�e� moze by� u�ywana w celu okre�lenia poprawnej formy

	void name_give(int monster_number);						//daje nazw� potwotkowi
	void wyswietl_karte_postaci();							//wy�wietla kart� potwora
	void randomizeStatistics(int monster_number);				//losowanie statystyk
	virtual void randomizeStatistics();

};
//monster_number -> mapka