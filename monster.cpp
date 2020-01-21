#include "monster.h"
#include "statistics.h"
#include "character.h"
#include <iostream>
#include <stdlib.h>
#include "Square.h"

Monster::Monster(std::string nazwa = "non", bool sex = 0, Statistics statystyki = Statistics(), Proffesion prof = PROFF_MONSTER, int name_dr) : Character(nazwa, sex, statystyki)
{
	Character* player; //==================
	name_give(1);
	wylosuj_statytyki(player->GetLevel.getLevel());
}

void Monster::name_give(int monster_number)
{
	srand(time(NULL));

	name_draw = rand() % 2;
	switch  (monster_number)//obszar mapki
	{
	case 1: // to 1. kwadrat
		if(name_draw==1)	name = "Skrzat";
		else				name = "Slime";
		break;
	case 2:// 2. kwadrat
		if (name_draw == 1)	name = "Gobol";
		else				name = "Goblin";
		break;
	case 3: 
		if (name_draw == 1) name = "Harpia";
		else				name = "Kamienny Golem";
		break;
	case 4:
		if (name_draw == 1) name = "Meduza";
		else				name = "Goblinowa";
		break;
	case 5:
		if (name_draw == 1) name = "Gorgona";
		else				name = "Troll";
		break;
	case 6:
		if (name_draw == 1) name = "Duch";
		else				name = "Cyklop";
		break;
	case 7:
		if (name_draw == 1) name = "Bazyliszek";
		else				name = "Wiwerna";
		break;
	case 8:
		if (name_draw == 1) name = "Mantykora";
		else				name = "Behemot";
		break;
	case 9:
		if (name_draw == 1) name = "Smok";
		else				name = "Diabel";
		break;
	default:
		name = "problem z monster.cpp";
	}
}

void Monster::wyswietl_karte_postaci()
{
	std::cout << std::endl << "Nazwa: " << name;
	std::cout << std::endl << "Sila: " << strength;
	std::cout << std::endl << "Wytrzymalosc: " << endurance;
	std::cout << std::endl << "Inteligencja: " << intelligence;
	std::cout << std::endl << "Zwinnosc: " << agility;
	std::cout << std::endl << "Szczescie: \n" << luck;
}

void Monster::wylosuj_statytyki(int monster_number)
{
	srand(time(NULL));

	strength	= rand() % monster_number + monster_number;
	endurance	= rand() % monster_number + monster_number;
	intelligence= rand() % monster_number + monster_number;
	agility		= rand() % monster_number + monster_number;
	luck		= rand() % monster_number + monster_number;

	switch (monster_number) //obszary mapy
	{

	case 1: case 2: //1. i 2. kwadrat
		if (strength > 1.4 * monster_number)			strength = 1.4 * monster_number;
		if (endurance > 1.4 * monster_number)		endurance = 1.4 * monster_number;
		if (intelligence > 1.4 * monster_number)		intelligence = 1.4 * monster_number;
		if (agility > 1.4 * monster_number)			agility = 1.4 * monster_number;
		if (luck > 1.4 * monster_number)				luck = 1.4 * monster_number;
		break;
	case 3: case 4: //2.
		if (strength > 1.6 * monster_number)			strength = 1.6 * monster_number;
		else if (strength < 1.2 * monster_number)	strength = 1.2 * monster_number;
		if (endurance > 1.6 * monster_number)		endurance = 1.6 * monster_number;
		else if (endurance < 1.2 * monster_number)	endurance = 1.2 * monster_number;
		if (intelligence > 1.6 * monster_number)		intelligence = 1.6 * monster_number;
		else if (intelligence < 1.2 * monster_number)intelligence = 1.2 * monster_number;
		if (agility > 1.6 * monster_number)			agility = 1.6 * monster_number;
		else if (agility < 1.2 * monster_number)		agility = 1.2 * monster_number;
		if (luck > 1.6 * monster_number)				luck = 1.6 * monster_number;
		else if (luck < 1.2 * monster_number)		luck = 1.2 * monster_number;
		break;
	case 5: case 6:
		if (strength > 1.8 * monster_number)			strength = 1.8 * monster_number;
		else if (strength < 1.4 * monster_number)	strength = 1.4 * monster_number;
		if (endurance > 1.8 * monster_number)		endurance = 1.8 * monster_number;
		else if (endurance < 1.4 * monster_number)	endurance = 1.4 * monster_number;
		if (intelligence > 1.8 * monster_number)		intelligence = 1.8 * monster_number;
		else if (intelligence < 1.4 * monster_number)intelligence = 1.4 * monster_number;
		if (agility > 1.8 * monster_number)			agility = 1.8 * monster_number;
		else if (agility < 1.4 * monster_number)		agility = 1.4 * monster_number;
		if (luck > 1.8 * monster_number)				luck = 1.8 * monster_number;
		else if (luck < 1.4 * monster_number)		luck = 1.4 * monster_number;
		break;
	case 7: case 8:
		if (strength > 2 * monster_number)			strength = 2 * monster_number;
		else if (strength < 1.6 * monster_number)	strength = 1.6 * monster_number;
		if (endurance > 2 * monster_number)			endurance = 2 * monster_number;
		else if (endurance < 1.6 * monster_number)	endurance = 1.6 * monster_number;
		if (intelligence > 2 * monster_number)		intelligence = 2 * monster_number;
		else if (intelligence < 1.6 * monster_number)intelligence = 1.6 * monster_number;
		if (agility > 2 * monster_number)			agility = 2 * monster_number;
		else if (agility < 1.6 * monster_number)		agility = 1.6 * monster_number;
		if (luck > 2 * monster_number)				luck = 2 * monster_number;
		else if (luck < 1.6 * monster_number)		luck = 1.6 * monster_number;
		break;
	case 9:
		strength += monster_number;
		endurance += monster_number;
		intelligence += monster_number;
		agility += monster_number;
		luck += monster_number;
		break;
	default:
		std::cout << "\nproblem w monster.bpp, welp\n";
	}

	
}
