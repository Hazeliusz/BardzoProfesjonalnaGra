#include <iostream>
#include "character.h"

class Armor : public Statistics //�le, bo nie mo�e dziedziczy� po Character
{
	float durability_max, durability_cur, def; //wytrzyma�o�� zbroi, ochrona
	std::string Eq; // typ (he�m, napier�nik, butki itd.)
	char part; //
	

	Armor(char p = 'n', float dur_m = 10, float dur_c = 10, int defen = 1, std::string eq = "none")
	{
		part = p;
		durability_max = dur_m;
		durability_cur = dur_c;
		def = defen;
		Eq = eq;
	}

	void type_def(); //w zale�no�ci od wybranej klasy inne staty armoru b�d�
	void damage_taken(); //zmiana durability przedmiotu po walce (czym wi�cej hp wzi�o, tym bardziej si� psuje)
	void defending(); //system ochrony przed dmg w zale�no�ci od ilo�ci def w zbroi

};

class Equipment: public Statistics
{
	std::string thing; // potka, klucze, itd.
	bool usability, used; //0 - zu�ywa si� po 1 u�yciu, 1 - nie;    0-nie,1-tak
	int buffs;

	Equipment(short int th = 1, bool use = 0, bool usd = 0, int buf = 1);

	void usage(); //wykorzystanie przedmiotu
	void take_buff(); //co robi dany przedmiot
	void disappear(); // znikni�cie po u�yciu

};