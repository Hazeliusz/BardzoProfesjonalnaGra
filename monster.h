#pragma once
#include <stdlib.h>
#include "statistics.h"
#include <string>
#include "character.h"

class Monster : public Character, public Statistics
{
	int name_draw;

public:
	Monster(std::string nazwa, bool sex, Statistics statystyki = Statistics(), Proffesion CharClass = PROFF_MONSTER, int name_dr);// p�e� moze by� u�ywana w celu okre�lenia poprawnej formy

	void name_give(int monster_number);						//daje nazw� potwotkowi
	void wyswietl_karte_postaci();							//wy�wietla kart� potwora
	void wylosuj_statytyki(int monster_number);				//losowanie statystyk
};
//monster_number -> mapka