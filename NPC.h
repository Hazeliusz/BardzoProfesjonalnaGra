#pragma once
#include <iostream>
#include "ekwipunek.h"
#include "Square.h"

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


	void options();									//opcje do wyboru
	void buy();										//kupno
	void sell();									//sprzedarz
	void repair();									//naprawa zbroi
	bool pay(int cost);								//zaplata
	void opening_talk(char npc_world[3][3][15][15]);//gadka wstêpna
	void talk();									//info jakieœ
};