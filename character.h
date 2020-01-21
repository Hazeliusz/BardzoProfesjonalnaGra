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
typedef void(*skill)(Character* user, Character* target, bufor& bf);


enum Proffesion {
	PROFF_KNIGHT, PROFF_ARCHER, PROFF_BARD, PROFF_DARK_KNIGHT, PROFF_CLERIC, PROFF_MAGE, PROFF_MONSTER
};

class Level {
	int level;
	int currentEXP;
	int thresholdEXP;
public:
	void setLevel(int lvl);
	int getCurrentEXP();
	int getLevel();
	int getLevelThreshold(int lvl);
	void levelUp();
	bool checkLevelUp();
	void addEXP(int exp);
	Level(int lvl = 1);
};

class Character {
protected:
	std::string name;
	Proffesion CharClass;
	std::map<std::string, skill> skills;
	bool sex; //true - kobieta, false - mezczyzna
	Statistics special;
	Level lvl;
public:
	Character(std::string name, bool sex, Statistics statystyki = Statistics(), int lvls = 1);
	int hp;
	Statistics GetStats()
	{
		return special;
	}

	Proffesion GetProffesion() {
		return CharClass;
	}

	std::map<std::string, skill> GetSkills()
    {
		return skills;
	}

	std::string GetName()
	{
		return name;
	}
	std::string GetProffesionName() {
		switch (CharClass) {
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
	bool GetSex() {
		return sex;
	}

	void checkLevelUp();
	void addEXP(int exp);
	void drawCharacterCard();
	virtual void randomizeStatistics() = 0;
	void writeStatistics();
	void addSkillAt5();
	void addSkillAt10();
	void addSkillAt20();
	/*void zapisz_do_pliku();
	void odczytaj_z_pliku();*/ 
};

class Knight : public Character {
public:
	virtual void randomizeStatistics();
	Knight(std::string, bool, Statistics stats = Statistics());
};

class Archer : public Character {
public:
	virtual void randomizeStatistics();
	Archer(std::string, bool, Statistics stats = Statistics());
};

class Bard : public Character {
public:
	virtual void randomizeStatistics();
	Bard(std::string, bool, Statistics stats = Statistics());
};

class Dark_Knight : public Character {
public:
	virtual void randomizeStatistics();
	Dark_Knight(std::string, bool, Statistics stats = Statistics());
};

class Cleric : public Character {
public:
	virtual void randomizeStatistics();
	Cleric(std::string, bool, Statistics stats = Statistics());
};

class Mage : public Character {
public:
	virtual void randomizeStatistics();
	Mage(std::string, bool, Statistics stats = Statistics());
};

class Magic_Item {
	std::string name;
	std::string description;
	int power;
	int rarity; // 1 - 10
public:
	Magic_Item(std::string, std::string = "opps", int = 0, int = 1);
};