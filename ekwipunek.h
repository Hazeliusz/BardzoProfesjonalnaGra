#pragma once
#include <iostream>
#include <stdlib.h>
#include "character.h"
#include "NPC.h"



//------------------------------------

class Equipment 
{
public:
	std::string eq_name;						// nazwa przedmiotu
	int eq_stats[6];							// 0-str, 1-end, 2-char, 3-int, 4-agi, 5-lck
	int eq_cost;

	Equipment (Character* player = nullptr, int c = 0, std::string naming = "nothing")
	{
		for (int i = 0; i < 6; i++)
		{
			eq_stats[i] = 0;
		}
		eq_name = naming;
		eq_cost = c;
		if(eq_name == "eliksir")
			this->give_statistics();
		this->usage(player);
	}


	void give_statistics();						//daje staty potkom
	void usage(Character* player);								//wykorzystanie przedmiotu
	void take_buff(Statistics* staty);							//co robi dany przedmiot							//znikniêcie po u¿yciu
};

//------------------------------------

class Weapon
{
public:
	bool we_wear;
	std::string we_name;
	int weapon_stats[6];						// 0-str, 1-end, 2-char, 3-int, 4-agi, 5-lck
	int we_cost;

	Weapon(std::string w_name = "stick", int stats = 0, bool w = 0, int c = 0)
	{
		we_wear = w;
		we_name = w_name;
		we_cost = c;
		for (int i = 0; i < 6; i++)
		{
			weapon_stats[i] = stats;
		}
	}

	void weapon_statistics_name(Character* player);				//daje staty i nazwê
	float dmg_counter(Character* player);						//mno¿nik do zadawannego dmg
};


class Armor
{
public:
	bool ar_wear;
	short int randomise;
	float durability_max, durability_cur, def;  //wytrzyma³oœæ zbroi, ochrona
	std::string armor_name;						// typ (he³m, napierœnik, butki itd.)
	int ar_cost;

	int armor_stats[6];							// 0-str, 1-end, 2-char, 3-int, 4-agi, 5-lck
//------------!!!
	Armor(float dur_m = 10, float dur_c = 10, int defen = 1, std::string eq = "none", int s = 0, bool w = 0, int c = 0)
	{
		srand(time_t(NULL));
		for (int i = 0; i < 6; i++)
		{
			armor_stats[i] = s;
		}
		ar_wear = w;
		durability_max = dur_m;
		durability_cur = dur_c;
		def = defen;
		ar_cost = c;

		randomise = rand() % 3;
		if (randomise == 0) armor_name = "He³m";
		else if (randomise == 1) armor_name = "Napierœnik";
		else if (randomise == 2) armor_name = "Buty";
		else armor_name = eq;
	}

	void type_def(Character* player);							//w zale¿noœci od wybranej klasy inna obrona bêdzie
	void type_stats(Character* player);							//w zale¿noœci od wybranej klasy inne staty
	void damage_taken(int hp_cur, Character* player);				//zmiana durability przedmiotu po walce (czym wiêcej hp wziê³o, tym bardziej siê psuje)
	float defending();							//system ochrony przed dmg w zale¿noœci od iloœci def w zbroi
};
