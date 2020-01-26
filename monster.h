#pragma once
#include <stdlib.h>
#include "statistics.h"
#include <string>
#include "character.h"

class Monster : public Character
{
public:
	Monster(int monsterNumber = 1, bool sexy = false, Statistics statystyki = Statistics(), std::string nazwa = "non");// p³eæ moze byæ u¿ywana w celu okreœlenia poprawnej formy

	void name_give(int monster_number);						//daje nazwê potwotkowi
	void wyswietl_karte_postaci();							//wyœwietla kartê potwora
	void randomizeStatistics(int monster_number);				//losowanie statystyk
	virtual void randomizeStatistics();

};
//monster_number -> mapka