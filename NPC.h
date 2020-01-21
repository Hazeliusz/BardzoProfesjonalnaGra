#pragma once
#include <iostream>
#include "ekwipunek.h"
#include "Square.h"

class Non_Character
{
	std::string npc_name;
	bool first_time; //1-tak, 0-nie
	short int choice;
	bool quit; //1-tak, 0-nie


public:
	Non_Character(bool first = 0, std::string n = "wiesniak", short int cho = 0, bool end_talk = 0)
	{
		Square mapka;
		first_time = first;
		choice = cho;
		npc_name = n;
		quit = end_talk;
		function(mapka.tab[mapka.b][mapka.a][mapka.y][mapka.x]);
	}


	void function(char npc_word[3][3][15][15]);	//nadanie konkretnemu miejscowi odpowiedniej nazwy NPC
	void talk();		//gatka
	void options();		//opcje do wyboru
	void buy();			//kupno
	void sell();		//sprzedarz
	void repair();		//naprawa zbroi
	bool pay(int cost); //zaplata
};