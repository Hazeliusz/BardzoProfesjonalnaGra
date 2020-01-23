#include <iostream>
#include <stdlib.h>
#include "character.h"
#include "NPC.h"

class Armor		
{
	short int randomise;
	float durability_max, durability_cur, def;  //wytrzyma³oœæ zbroi, ochrona
	std::string Armor_name;						// typ (he³m, napierœnik, butki itd.)
	char part;
public:
	int armor_stats[6];							// 0-str, 1-end, 2-char, 3-int, 4-agi, 5-lck
//------------!!!
public:
	Armor(char p = 'n', float dur_m = 10, float dur_c = 10, int defen = 1, std::string eq = "none", int s=0)
	{
		srand(time_t(NULL));
		for (int i = 0; i < 6; i++)
		{
			armor_stats[i] = s;
		}
		part = p;
		durability_max = dur_m;
		durability_cur = dur_c;
		def = defen;

		randomise = rand() % 3;
		if (randomise == 0) Armor_name = "He³m";
		else if (randomise == 1) Armor_name = "Napierœnik";
		else if (randomise == 2) Armor_name = "Buty";
		else Armor_name = eq;
	}

	void type_def();							//w zale¿noœci od wybranej klasy inna obrona bêdzie
	void type_stats();							//w zale¿noœci od wybranej klasy inne staty
	void damage_taken(int hp_cur);				//zmiana durability przedmiotu po walce (czym wiêcej hp wziê³o, tym bardziej siê psuje)
	float defending();							//system ochrony przed dmg w zale¿noœci od iloœci def w zbroi

	friend void Non_Character::repair();
	friend void Weapon::weapon_statistics_name();
};

//------------------------------------

class Equipment
{
	std::string eq_name;						// nazwa przedmiotu
	bool usability, used;						//1 - zu¿ywa siê po u¿yciu, 0 - nie;    0-nie u¿yty ,1-u¿yty
	int buffs;
	int eq_stats[6];							// 0-str, 1-end, 2-char, 3-int, 4-agi, 5-lck

public:
	Equipment (std::string naming = "nothing", bool usb = 0, bool usd = 0, int buf = 1, int s=0)
	{
		for (int i = 0; i < 6; i++)
		{
			eq_stats[i] = s;
		}
		eq_name = naming;
		usability = usb;
		used = usd;
		buffs = buf;
	}


	void give_statistics();						//daje staty potkom
	void usage();								//wykorzystanie przedmiotu
	void take_buff();							//co robi dany przedmiot
	void disappear();							//znikniêcie po u¿yciu

	friend void Non_Character::buy();
};

class Weapon
{
	std::string weap_name;
	int weapon_stats[6];						// 0-str, 1-end, 2-char, 3-int, 4-agi, 5-lck

public:
	Weapon(std::string w_name = "stick", int stats = 0)
	{
		weap_name = w_name;
		weapon_statistics_name();
		for (int i = 0; i < 6; i++)
		{
			weapon_stats[i] = stats;
		}
	}

	void weapon_statistics_name();				//daje staty i nazwê
	float dmg_counter();						//mno¿nik do zadawannego dmg

};

//plecak w character