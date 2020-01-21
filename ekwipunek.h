#include <iostream>
#include "character.h"
#include "NPC.h"

class Armor : public Statistics					//Ÿle, bo nie mo¿e dziedziczyæ po Character
{
	float durability_max, durability_cur, def;  //wytrzyma³oœæ zbroi, ochrona
	std::string Armor_name;								// typ (he³m, napierœnik, butki itd.)
	char part; 

public:
	Armor(char p = 'n', float dur_m = 10, float dur_c = 10, int defen = 1, std::string eq = "none")
	{
		part = p;
		durability_max = dur_m;
		durability_cur = dur_c;
		def = defen;
		Armor_name = eq;
	}

	void type_def();				//w zale¿noœci od wybranej klasy inne staty armoru bêd¹
	void damage_taken(int hp_cur);  //zmiana durability przedmiotu po walce (czym wiêcej hp wziê³o, tym bardziej siê psuje)
	float defending();				//system ochrony przed dmg w zale¿noœci od iloœci def w zbroi

	friend void Non_Character::repair();
};

//------------------------------------

class Equipment: public Statistics
{
	std::string eq_name;				// nazwa przedmiotu
	bool usability, used;			//0 - zu¿ywa siê po 1 u¿yciu, 1 - nie;    0-nie u¿yty ,1-u¿yty
	int buffs;

public:
	Equipment(std::string naming = "nothing", bool usb = 0, bool usd = 0, int buf = 1)
	{
		eq_name = naming;
		usability = usb;
		used = usd;
		buffs = buf;
	}


	void give_statistics();			//daje staty potkom
	void usage();					//wykorzystanie przedmiotu
	void take_buff();				//co robi dany przedmiot
	void disappear();				//znikniêcie po u¿yciu

	friend void Non_Character::buy();
};

class Weapon : public Statistics
{
	float dmg;
	std::string Weap_name;
};
//plecak w character