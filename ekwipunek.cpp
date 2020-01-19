#include <iostream>
#include <stdlib.h>
#include "ekwipunek.h"
#include "character.h"

//87-43.5; 62-31; 53-26.5; 34-17; 25-12.5
void Armor::type_def()
{
	srand(time(NULL));
	Character* player;
	if (Eq == "helm")  //przypisanie wartoœci zbroi
	{
		switch (player->GetProffesion()) 
		{
		case PROFF_KNIGHT:		//maks 29
			durability_max = 9.0 + player->GetLevel.getLevel() * 1;
			break;
		case PROFF_ARCHER:		//21.3
			durability_max = 7.3 + player->GetLevel.getLevel() * 0.7;
			break;
		case PROFF_BARD:		//18.3
			durability_max = 4.3 + player->GetLevel.getLevel() * 0.7;
			break;
		case PROFF_CLERIC:		//10.7
			durability_max = 4.7 + player->GetLevel.getLevel() * 0.3;
			break;
		case PROFF_DARK_KNIGHT:	//29
			durability_max = 9.0 + player->GetLevel.getLevel() * 1;
			break;
		case PROFF_MAGE:		//10.7
			durability_max = 4.7 + player->GetLevel.getLevel() * 0.3;
			break;
		default:				//7.7
			durability_max = 1.7 + player->GetLevel.getLevel() * 0.3;
		}
	}
	else if (Eq == "napiersnik")
	{
		switch (player->GetProffesion())
		{
		case PROFF_KNIGHT:		//maks 43.5
			durability_max = 13.5 + player->GetLevel.getLevel() * 1.5;
			break;
		case PROFF_ARCHER:		//29.1
			durability_max = 11.1 +	player->GetLevel.getLevel() * 0.9;
			break;
		case PROFF_BARD:		//24.6
			durability_max =  6.6 +	player->GetLevel.getLevel() * 0.9;
			break;
		case PROFF_CLERIC:		//17
			durability_max =  7.0 +	player->GetLevel.getLevel() * 0.5;
			break;
		case PROFF_DARK_KNIGHT:	//43.5
			durability_max = 13.5 + player->GetLevel.getLevel() * 1.5;
			break;
		case PROFF_MAGE:		//17
			durability_max =  7.0 +	player->GetLevel.getLevel() * 0.5;
			break;
		default:				//12.5
			durability_max =  2.5 +	player->GetLevel.getLevel() * 0.5;
		}
	}
	else if (Eq == "buty")
	{
		switch (player->GetProffesion())
		{
		case PROFF_KNIGHT:		//maks 14.5
			durability_max = 4.5 + player->GetLevel.getLevel() * 0.5;
			break;
		case PROFF_ARCHER:		//11.6
			durability_max = 3.6 + player->GetLevel.getLevel() * 0.4;
			break;
		case PROFF_BARD:		//10.1
			durability_max = 2.1 + player->GetLevel.getLevel() * 0.4;
			break;
		case PROFF_CLERIC:		//6.3
			durability_max = 2.3 + player->GetLevel.getLevel() * 0.2;
			break;
		case PROFF_DARK_KNIGHT:	//14.5
			durability_max = 4.5 + player->GetLevel.getLevel() * 0.5;
			break;
		case PROFF_MAGE:		//6.3
			durability_max = 2.3 + player->GetLevel.getLevel() * 0.2;
			break;
		default:				//4.8
			durability_max = 0.8 + player->GetLevel.getLevel() * 0.2;
		}
	}
	else
	{
		std::cout << "\njakiœ b³¹d w Armorze typedef ;-;\n";
	}
	durability_max /= 2;
	durability_cur = durability_max;
	switch (player->GetProffesion())
	{
	case PROFF_KNIGHT:
		strength = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		endurance = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		charisma = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		intelligence = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		agility = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		luck = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		break;
	case PROFF_ARCHER:
		strength = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		endurance = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		charisma = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		intelligence = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		agility = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		luck = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		break;
	case PROFF_BARD:
		strength = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		endurance = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		charisma = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		intelligence = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		agility = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		luck = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		break;
	case PROFF_CLERIC:
		strength = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		endurance = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		charisma = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		intelligence = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		agility = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		luck = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		break;
	case PROFF_DARK_KNIGHT:
		strength = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		endurance = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		charisma = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		intelligence = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		agility = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		luck = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		break;
	case PROFF_MAGE:
		strength = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		endurance = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		charisma = rand() % (3 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		intelligence = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		agility = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		luck = rand() % (4 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		break;
	default:
		strength = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		endurance = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		charisma = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		intelligence = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		agility = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
		luck = rand() % (2 * player->GetLevel().getLevel()) - player->GetLevel().getLevel();
	}

}

void Armor::damage_taken(int hp_cur)
{
	durability_cur = durability_cur - (durability_cur*hp_cur)/ (endurance*10); //hp_cur - po walce?
	if (durability_cur <= 0)
	{
		durability_cur = 1;
	}

	if (durability_max * 0.25 < durability_cur && durability_cur < durability_max * 0.5)
	{
		std::cout << Eq << std::endl << "jest srednio uszkodzony";
	}
	else if (durability_max * 0.25 > durability_cur)
	{
		std::cout << Eq << std::endl << "jest powaznie uszkodzony";
	}
}

float Armor::defending()
{
	return durability_cur*0.01;
}

//--------------------

void Equipment::give_statistics()
{
	srand(time(NULL));
	if (name == "eliksir")
	{
		for (int number = 0; number != 1;)
		{
			if (number == 0)
			{
				strength = rand() % 2;
				if (strength == 1)		number++;

				endurance = rand() % 2;
				if (endurance == 1)		number++;

				charisma = rand() % 2;
				if (charisma == 1)		number++;

				intelligence = rand() % 2;
				if (intelligence == 1)	number++;

				agility = rand() % 2;
				if (agility == 1)		number++;

				luck = rand() % 2;
				if (luck == 1)			number++;

			}
			else
			{
				if (strength == 1)
				{
					strength = rand() % 2;
					if (strength == 0) number--;
				}
				if (endurance == 1)
				{
					endurance = rand() % 2;
					if (endurance == 0) number--;
				}
				if (charisma == 1)
				{
					charisma = rand() % 2;
					if (charisma == 0) number--;
				}
				if (intelligence == 1)
				{
					intelligence = rand() % 2;
					if (intelligence == 0) number--;
				}
				if (agility == 1)
				{
					agility = rand() % 2;
					if (agility == 0) number--; 
				}
				if (luck == 1)
				{
					luck = rand() % 2;
					if (luck == 0) number--;
				}
			}
		}

		if (strength == 1)			strength = rand() % 5 + 1;
		else if(endurance == 1)		endurance = rand() % 5 + 1;
		else if (charisma == 1)		charisma = rand() % 5 + 1;
		else if (intelligence == 1) intelligence = rand() % 5 + 1;
		else if (agility == 1)		agility = rand() % 5 + 1;
		else if (luck == 1)			luck = rand() % 5 + 1;
	}
}

void Equipment::usage()
{
	Character* player2;
	if (name == "eliksir")
	{
		usability = 0;
		if (strength != 0)  		name = "eliksir Galow";
		else if (endurance != 0)	name = "wywar z czerwonego byka";
		else if (charisma != 0)		name = "retoryka w butelce";
		else if (intelligence != 0)	name = "roztwor wronskianinu potasu";
		else if (agility != 0)		name = "sok z gumijagod";
		else if (luck != 0)			name = "wywar z totolotka";
	}
	else if (name == "klucz")
	{
		usability = 0;
		if () //skrzynia na mapie w odleg³oœci 1 kratki w pionie lub poziomie
		{
			//skrzynia = open; 
		}
		
	}
	else if (name == "special")
	{
		usability = 1;
		switch (player2->GetProffesion())
		{
		case PROFF_KNIGHT:
			name = "bandana";
			strength = 2;
			luck = -1;
			break;
		case PROFF_ARCHER:
			name = "wkladka do butow";
			agility = 2;
			charisma = -1;
			break;
		case PROFF_BARD:
			name = "kostka do gitary";
			charisma = 2;
			strength = -1;
			break;
		case PROFF_CLERIC:
			name = "poœwiêcona figurka";
			endurance = 1;
			luck = 1;
			intelligence = -1;
			break;
		case PROFF_DARK_KNIGHT:
			name = "skaza przeszlosci";
			charisma = -1;
			if (player2->GetLevel().getLevel() > 10) agility = -1;
			strength = 2;
			endurance = 1;
			break;
		case PROFF_MAGE:
			name = "krucha maskotka na kostur";
			intelligence = 2;
			agility = -1;
			break;
		default:
			name = "kolczyk bez nadziei";
			endurance = 1;
			charisma = -2;
		}
	}
	else if (name == "ciasto")
	{
		usability = 0;
		endurance = 1;
	}
}

void Equipment::take_buff()
{
	if (used == 0)
	{
		//wp³ywanie na staty bohatera;
		if (usability == 0) used = 1;
		disappear();
	}
	else std::cout << "\nprzedmiot jest zuzyty, nie nadaje sie juz do niczego\n";
}

void Equipment::disappear()
{
	if (used == 1)
	{
		//znikanie z plecaka;
	}
}
