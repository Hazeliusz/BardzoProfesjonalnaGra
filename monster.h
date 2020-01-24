#pragma once
#include <stdlib.h>
#include "statistics.h"
#include <string>
#include "character.h"

class Monster : public Character, public Statistics
{
public:
	Monster(std::string nazwa, bool sexy, Statistics statystyki, Proffesion CharClass);// p�e� moze by� u�ywana w celu okre�lenia poprawnej formy

	void name_give(int monster_number);						//daje nazw� potwotkowi
	void wyswietl_karte_postaci();							//wy�wietla kart� potwora
	void wylosuj_statytyki(int monster_number);				//losowanie statystyk

};
//monster_number -> mapka