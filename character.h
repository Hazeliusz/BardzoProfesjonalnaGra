#pragma once
#include "statistics.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <map>
#include <fstream>

 class Character;

typedef std::map<std::string, int> bufor;
typedef void(*skill)(Character* uzywajacy, Character* atakowany, bufor& bf);


enum Proffesion {
	PROFF_KNIGHT, PROFF_ARCHER, PROFF_BARD, PROFF_DARK_KNIGHT, PROFF_CLERIC, PROFF_MAGE
};

class Character {
protected:
	std::string imie;
	Proffesion klasa;
	std::map<std::string, skill> umiejetnosci;
	bool plec; //true - kobieta, false - mezczyzna
	Statistics special;
public:
	Character(std::string imie, bool plec, Statistics statystyki = Statistics());
	int hp;
	Statistics GetStats()
	{
		return special;
	}

	Proffesion GetProffesion() {
		return klasa;
	}

	std::map<std::string, skill> GetSkills()
    {
		return umiejetnosci;
	}

	std::string GetName()
	{
		return imie;
	}
	std::string GetProffesionName() {
		switch (klasa) {
		case PROFF_KNIGHT:
			return "rycerz";
		case PROFF_ARCHER:
			return "lucznik";
		case PROFF_BARD:
			return "bard";
		case PROFF_CLERIC:
			return "kleryk";
		case PROFF_DARK_KNIGHT:
			return "upadly rycerz";
		case PROFF_MAGE:
			return "mag";
		default:
			return "nieznana";
		}
	}

	//haffff-> character.h to plik naglowkowy, w tym pliku
	//najlepiej opisywac rzecy. wiec lepiej dawac tutaj nazwy zmiennych aby osoba piszaca potem kod wiedziala co oznaczaja te inty


	void wypisz_karte_postaci();
	virtual void wylosuj_statystyki() = 0;
	void wypisz_statystyki();
	/*void zapisz_do_pliku();
	void odczytaj_z_pliku();*/ 
};

class Knight : public Character {
public:
	virtual void wylosuj_statystyki();
	Knight(std::string, bool, Statistics statystyki = Statistics());
};

class Archer : public Character {
public:
	virtual void wylosuj_statystyki();
	Archer(std::string, bool, Statistics statystyki = Statistics());
};

class Bard : public Character {
public:
	virtual void wylosuj_statystyki();
	Bard(std::string, bool, Statistics statystyki = Statistics());
};

class Dark_Knight : public Character {
public:
	virtual void wylosuj_statystyki();
	Dark_Knight(std::string, bool, Statistics statystyki = Statistics());
};

class Cleric : public Character {
public:
	virtual void wylosuj_statystyki();
	Cleric(std::string, bool, Statistics statystyki = Statistics());
};

class Mage : public Character {
public:
	virtual void wylosuj_statystyki();
	Mage(std::string, bool, Statistics statystyki = Statistics());
};

class Magic_Item {
	std::string nazwa;
	std::string opis;
	int moc;
	int rzadkosc; // 1 - 10
public:
	Magic_Item(std::string, std::string = "opps", int = 0, int = 1);
};