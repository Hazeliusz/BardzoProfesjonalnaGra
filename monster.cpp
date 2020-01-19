#include "monster.h"
#include "statistics.h"
#include "character.h"
#include <iostream>
#include <stdlib.h>

Monster::Monster(std::string nazwa = "non", bool sex = 0, Statistics statystyki = Statistics(), Proffesion prof = PROFF_MONSTER, int name_dr) : Character(nazwa, sex, statystyki)
{
	Character* player; //!
	name_give();
	wylosuj_statytyki(player->GetLevel.getLevel());
}

void Monster::name_give()
{
	srand(time(NULL));
	name_draw = rand() % 2;
	switch () //obszar mapki
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

void Monster::wylosuj_statytyki(int level)
{
	srand(time(NULL));
	int i = level;

	strength	= rand() % i + i;
	endurance	= rand() % i + i;
	intelligence= rand() % i + i;
	agility		= rand() % i + i;
	luck		= rand() % i + i;

	switch () //obszary mapy
	{
	case 1: case 2: //1. i 2. kwadrat
		if (strength > 1.4 * i)			strength = 1.4 * i;
		if (endurance > 1.4 * i)		endurance = 1.4 * i;
		if (intelligence > 1.4 * i)		intelligence = 1.4 * i;
		if (agility > 1.4 * i)			agility = 1.4 * i;
		if (luck > 1.4 * i)				luck = 1.4 * i;
		break;
	case 3: case 4: //2.
		if (strength > 1.6 * i)			strength = 1.6 * i;
		else if (strength < 1.2 * i)	strength = 1.2 * i;
		if (endurance > 1.6 * i)		endurance = 1.6 * i;
		else if (endurance < 1.2 * i)	endurance = 1.2 * i;
		if (intelligence > 1.6 * i)		intelligence = 1.6 * i;
		else if (intelligence < 1.2 * i)intelligence = 1.2 * i;
		if (agility > 1.6 * i)			agility = 1.6 * i;
		else if (agility < 1.2 * i)		agility = 1.2 * i;
		if (luck > 1.6 * i)				luck = 1.6 * i;
		else if (luck < 1.2 * i)		luck = 1.2 * i;
		break;
	case 5: case 6:
		if (strength > 1.8 * i)			strength = 1.8 * i;
		else if (strength < 1.4 * i)	strength = 1.4 * i;
		if (endurance > 1.8 * i)		endurance = 1.8 * i;
		else if (endurance < 1.4 * i)	endurance = 1.4 * i;
		if (intelligence > 1.8 * i)		intelligence = 1.8 * i;
		else if (intelligence < 1.4 * i)intelligence = 1.4 * i;
		if (agility > 1.8 * i)			agility = 1.8 * i;
		else if (agility < 1.4 * i)		agility = 1.4 * i;
		if (luck > 1.8 * i)				luck = 1.8 * i;
		else if (luck < 1.4 * i)		luck = 1.4 * i;
		break;
	case 7: case 8:
		if (strength > 2 * i)			strength = 2 * i;
		else if (strength < 1.6 * i)	strength = 1.6 * i;
		if (endurance > 2 * i)			endurance = 2 * i;
		else if (endurance < 1.6 * i)	endurance = 1.6 * i;
		if (intelligence > 2 * i)		intelligence = 2 * i;
		else if (intelligence < 1.6 * i)intelligence = 1.6 * i;
		if (agility > 2 * i)			agility = 2 * i;
		else if (agility < 1.6 * i)		agility = 1.6 * i;
		if (luck > 2 * i)				luck = 2 * i;
		else if (luck < 1.6 * i)		luck = 1.6 * i;
		break;
	case 9:
		strength += i;
		endurance += i;
		intelligence += i;
		agility += i;
		luck += i;
		break;
	default:
		std::cout << "\nproblem w monster.bpp, welp\n";
	}

}
