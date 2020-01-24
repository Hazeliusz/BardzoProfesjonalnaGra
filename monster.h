#pragma once
#include <stdlib.h>
#include "statistics.h"
#include <string>
#include "character.h"

class Monster : public Character, public Statistics
{
public:
	Monster(std::string nazwa, bool sexy, Statistics statystyki, Proffesion CharClass);// p³eæ moze byæ u¿ywana w celu okreœlenia poprawnej formy

	void name_give(int monster_number);						//daje nazwê potwotkowi
	void wyswietl_karte_postaci();							//wyœwietla kartê potwora
	void wylosuj_statytyki(int monster_number);				//losowanie statystyk

};
//monster_number -> mapka