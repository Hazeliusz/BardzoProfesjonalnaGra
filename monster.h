#pragma once
#include <stdlib.h>
#include "statistics.h"
#include <string>
#include "character.h"

class Monster : public Character, public Statistics
{
	int name_draw;

public:
	Monster(std::string nazwa, bool sex, Statistics statystyki = Statistics(), Proffesion CharClass = PROFF_MONSTER, int name_dr);// p³eæ moze byæ u¿ywana w celu okreœlenia poprawnej formy

	void name_give();								//daje nazwê potwotkowi
	void wyswietl_karte_postaci();					//wyœwietla kartê potwora
	void wylosuj_statytyki(int level);				//losowanie statystyk
};
