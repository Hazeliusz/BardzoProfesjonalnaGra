#pragma once
#include <iostream>
#include "Square.h"
#include "ekwipunek.h"

class Character;

class Non_Character
{
	std::string npc_name;
	char npc_type;
	bool first_time; //1-tak, 0-nie

public:
	Non_Character(bool first = 0, std::string n = "Wieœniak", char type = 'W')
	{
		first_time = first;
		npc_name = n;
		npc_type = type;
	}


	void options(Character* player);									//opcje do wyboru
	void buy(Character* player);					//kupno
	void repair(Character* player);					//naprawa zbroi
	bool pay(int cost, Character* player);			//zaplata
	void opening_talk(Character* player);//gadka wstêpna
	void talk(Character* player);									//info jakieœ
};