#pragma once
#include <stdlib.h>
#include "statistics.h"
#include <string>
#include "character.h"

class Monster : public Character{
public:
	Monster(std::string nazwa, bool sex, Statistics statystyki = Statistics(), Proffesion CharClass = PROFF_MONSTER); // p³eæ moze byæ u¿ywana w celu okreœlenia poprawnej formy
	void wyswietl_karte_postaci();
	virtual void wylosuj_statytyki(int level);
};
