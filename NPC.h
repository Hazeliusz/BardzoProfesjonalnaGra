#pragma once
#include <iostream>
#include "ekwipunek.h"

class Non_Character
{
	std::string name;
	bool first_time; //1-tak, 0-nie
	short int choice;
	bool quit; //1-tak, -0nie

public:
	Non_Character(bool first = 0, std::string n = "wiesniak", short int cho = 0, bool end_talk = 0)
	{
		first_time = first;
		choice = cho;
		name = n;
		quit = end_talk;
	}


	void function();	//nadanie konkretnemu miejscowi odpowiedniej nazwy NPC
	void talk();		//gatka
	void options();		//opcje do wyboru
	void buy();			//kupno
	void sell();		//sprzedarz
	void repair();		//naprawa zbroi
	void pay(int cost);
};