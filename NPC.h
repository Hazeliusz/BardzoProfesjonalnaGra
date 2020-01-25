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
	short int choice;
	bool quit; //1-tak, 0-nie


public:
	Non_Character(bool first = 0, std::string n = "wiesniak", char type = 'N', short int cho = 0, bool end_talk = 0)
	{
		first_time = first;
		choice = cho;
		npc_name = n;
		quit = end_talk;
	}


	void options(Character* player);									//opcje do wyboru
	void buy(Character* player);					//kupno
	void repair(Character* player);					//naprawa zbroi
	bool pay(int cost, Character* player);			//zaplata
	void opening_talk(char npc_world[3][3][15][15], Character* player);//gadka wst�pna
	void talk(Character* player);									//info jakie�
};