#pragma once
#include <iostream>
#include <stdlib.h>
#include "ekwipunek.h"



//87-43.5; 62-31; 53-26.5; 34-17; 25-12.5
void Armor::type_def(Character* player)
{
	if (armor_name == "He�m")  //przypisanie warto�ci zbroi
	{
		switch (player->GetProffesion()) 
		{
		case PROFF_KNIGHT:		//maks 29
			durability_max = 9.0 + player->GetLevel() * 1;
			break;
		case PROFF_ARCHER:		//21.3
			durability_max = 7.3 + player->GetLevel() * 0.7;
			break;
		case PROFF_BARD:		//18.3
			durability_max = 4.3 + player->GetLevel() * 0.7;
			break;
		case PROFF_CLERIC:		//10.7
			durability_max = 4.7 + player->GetLevel() * 0.3;
			break;
		case PROFF_DARK_KNIGHT:	//29
			durability_max = 9.0 + player->GetLevel() * 1;
			break;
		case PROFF_MAGE:		//10.7
			durability_max = 4.7 + player->GetLevel() * 0.3;
			break;
		default:				//7.7
			durability_max = 1.7 + player->GetLevel() * 0.3;
		}
	}
	else if (armor_name == "Napier�nik")
	{
		switch (player->GetProffesion())
		{
		case PROFF_KNIGHT:		//maks 43.5
			durability_max = 13.5 + player->GetLevel() * 1.5;
			break;
		case PROFF_ARCHER:		//29.1
			durability_max = 11.1 +	player->GetLevel() * 0.9;
			break;
		case PROFF_BARD:		//24.6
			durability_max =  6.6 +	player->GetLevel() * 0.9;
			break;
		case PROFF_CLERIC:		//17
			durability_max =  7.0 +	player->GetLevel() * 0.5;
			break;
		case PROFF_DARK_KNIGHT:	//43.5
			durability_max = 13.5 + player->GetLevel() * 1.5;
			break;
		case PROFF_MAGE:		//17
			durability_max =  7.0 +	player->GetLevel() * 0.5;
			break;
		default:				//12.5
			durability_max =  2.5 +	player->GetLevel() * 0.5;
		}
	}
	else if (armor_name == "Buty")
	{
		switch (player->GetProffesion())
		{
		case PROFF_KNIGHT:		//maks 14.5
			durability_max = 4.5 + player->GetLevel() * 0.5;
			break;
		case PROFF_ARCHER:		//11.6
			durability_max = 3.6 + player->GetLevel() * 0.4;
			break;
		case PROFF_BARD:		//10.1
			durability_max = 2.1 + player->GetLevel() * 0.4;
			break;
		case PROFF_CLERIC:		//6.3
			durability_max = 2.3 + player->GetLevel() * 0.2;
			break;
		case PROFF_DARK_KNIGHT:	//14.5
			durability_max = 4.5 + player->GetLevel() * 0.5;
			break;
		case PROFF_MAGE:		//6.3
			durability_max = 2.3 + player->GetLevel() * 0.2;
			break;
		default:				//4.8
			durability_max = 0.8 + player->GetLevel() * 0.2;
		}
	}
	else
	{
		std::cout << "\njaki� b��d w Armorze typedef ;-;\n";
	}

	durability_max /= 2;
	durability_cur = durability_max;

}

void Armor::type_stats(Character* player)
{
	switch (player->GetProffesion())
	{
	case PROFF_KNIGHT:
		armor_stats[0] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		armor_stats[1] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		armor_stats[2] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[3] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[4] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[5] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		break;
	case PROFF_ARCHER:
		armor_stats[0] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		armor_stats[1] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		armor_stats[2] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		armor_stats[3] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[4] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		armor_stats[5] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		break;
	case PROFF_BARD:
		armor_stats[0] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[1] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[2] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		armor_stats[3] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		armor_stats[4] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		armor_stats[5] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		break;
	case PROFF_CLERIC:
		armor_stats[0] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[1] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[2] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		armor_stats[3] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		armor_stats[4] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		armor_stats[5] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		break;
	case PROFF_DARK_KNIGHT:
		armor_stats[0] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		armor_stats[1] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		armor_stats[2] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[3] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[4] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[5] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		break;
	case PROFF_MAGE:
		armor_stats[0] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[1] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		armor_stats[2] = rand() % (3 * player->GetLevel()) - player->GetLevel();
		armor_stats[3] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		armor_stats[4] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[5] = rand() % (4 * player->GetLevel()) - player->GetLevel();
		break;
	default:
		armor_stats[0] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[1] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[2] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[3] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[4] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		armor_stats[5] = rand() % (2 * player->GetLevel()) - player->GetLevel();
		break;
	}
}

void Armor::damage_taken(int hp_cur, Character* player)
{
	durability_cur = durability_cur - (durability_cur*hp_cur)/ (player->GetStats().getByEnum(Endurance)*10); //hp_cur - po walce? endurance gracza po��czony z endurance wszystkich cz�ci zbroi 
	if (durability_cur <= 0)
	{
		durability_cur = 1;
	}

	if (durability_max * 0.25 < durability_cur && durability_cur < durability_max * 0.5)
	{
		std::cout << armor_name << std::endl << "jest srednio uszkodzony";
	}
	else if (durability_max * 0.25 > durability_cur)
	{
		std::cout << armor_name << std::endl << "jest powaznie uszkodzony";
	}
}

float Armor::defending()
{
	return durability_cur*0.01;
}


//------------------------------------------------------------------------------------------------

void Equipment::give_statistics()
{
	if (eq_name == "eliksir")
	{
		for (int number = 0; number != 1; 0)
		{
			if (number == 0) //pocz�tek lub brak dodatku dla kt�rejkolwiek ze statystyk
			{
				for (int i = 0; i < 6; i++)
				{
					eq_stats[i] = rand() % 2;
					if (eq_stats[i] == 1)	number++;
				}
			}
			else if (number > 1) //losowanie ponowne statystyk spo�r�d tych, kt�re maj� co� innego ni� 0
			{
				for (int i = 0; i < 6; i++)
				{
					if (eq_stats[i] == 1)
					{
						eq_stats[i] = rand() % 2;
						if (eq_stats[i] == 0)	number--;
					}
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (eq_stats[i] == 1)			eq_stats[i] = rand() % 5 + 1;
		}
	}
	else if (eq_name == "Eliksir Gal�w")
	{
		eq_stats[0] = rand() % 5 + 1;
	}
	else if (eq_name == "Wywar z czerwonego byka")
	{
		eq_stats[1] = rand() % 5 + 1;
	}
	else if (eq_name == "Retoryka w butelce")
	{
		eq_stats[2] = rand() % 5 + 1;
	}
	else if (eq_name == "Roztwor wronskianinu potasu")
	{
		eq_stats[3] = rand() % 5 + 1;
	}
	else if (eq_name == "Sok z gumijag�d")
	{
		eq_stats[4] = rand() % 5 + 1;
	}
	else if (eq_name == "Wywar z totolotka")
	{
		eq_stats[5] = rand() % 5 + 1;
	}
}

void Equipment::usage(Character* player)
{
	if (eq_name == "eliksir")
	{
		if (eq_stats[0] != 0)  		eq_name = "Eliksir Gal�w";
		else if (eq_stats[1] != 0)	eq_name = "Wywar z czerwonego byka";
		else if (eq_stats[2] != 0)	eq_name = "Retoryka w butelce";
		else if (eq_stats[3] != 0)	eq_name = "Roztw�r wronskianu potasu";
		else if (eq_stats[4] != 0)	eq_name = "Sok z gumijag�d";
		else if (eq_stats[5] != 0)	eq_name = "Wywar z totolotka";
	}
	else if (eq_name == "special")
	{
		switch (player->GetProffesion())
		{
		case PROFF_KNIGHT:
			eq_name = "bandana";
			eq_stats[0] = 2;
			eq_stats[5] = -1;
			break;
		case PROFF_ARCHER:
			eq_name = "wk�adka do but�w";
			eq_stats[4] = 2;
			eq_stats[2] = -1;
			break;
		case PROFF_BARD:
			eq_name = "kostka do gitary";
			eq_stats[2] = 2;
			eq_stats[0] = -1;
			break;
		case PROFF_CLERIC:
			eq_name = "krzy�yk na drog�";
			eq_stats[1] = 1;
			eq_stats[5] = 1;
			eq_stats[3] = -1;
			break;
		case PROFF_DARK_KNIGHT:
			eq_name = "brudy przesz�o�ci";
			eq_stats[2] = -1;
			if (player->GetLevel() > 10) eq_stats[4] = -1;
			eq_stats[0] = 2;
			eq_stats[1] = 1;
			break;
		case PROFF_MAGE:
			eq_name = "prawo jazdy na miotle";
			eq_stats[3] = 2;
			eq_stats[4] = -1;
			break;
		default:
			eq_name = "kolczyk bez nadziei";
			eq_stats[1] = 1;
			eq_stats[2] = -2;
		}
	}
	else if (eq_name == "ciasto")
	{
		eq_stats[1] = 1;
	}
}

void Equipment::take_buff(Statistics* staty)
{
		staty->advanceStatsByEnum(Strength, eq_stats[0]);
		staty->advanceStatsByEnum(Endurance, eq_stats[1]);
		staty->advanceStatsByEnum(Charisma, eq_stats[2]);
		staty->advanceStatsByEnum(Intelligence, eq_stats[3]);
		staty->advanceStatsByEnum(Agility, eq_stats[4]);
		staty->advanceStatsByEnum(Luck, eq_stats[5]);
}


//---------------------------------------------------------------------------------------------------

void Weapon::weapon_statistics_name(Character* player)
{

	Armor stats_base;
	stats_base.type_stats(player);

	for (int i = 0; i < 6; i++)
	{
		weapon_stats[i] = stats_base.armor_stats[i] + (rand() % player->GetLevel() - rand() % player->GetLevel()) / 2;
	}

	int draw = rand() % 4;
	if (draw < 3)
	{
		switch (player->GetProffesion())
		{
		case PROFF_KNIGHT:
			we_name = "Miecz";
			break;
		case PROFF_ARCHER:
			we_name = "�uk";
			break;
		case PROFF_BARD:
			we_name = "Lutnia";
			break;
		case PROFF_CLERIC:
			we_name = "Ksi�ga";
			break;
		case PROFF_DARK_KNIGHT:
			we_name = "Maczuga";
			break;
		case PROFF_MAGE:
			we_name = "Kostur";
			break;
		default:
			we_name = "Jojo";
			break;
		}
	}
	else if (draw == 3)
	{
		switch (player->GetProffesion())
		{
		case PROFF_KNIGHT:
			we_name = "Top�r";
			break;
		case PROFF_ARCHER:
			we_name = "Kusza";
			break;
		case PROFF_BARD:
			we_name = "Sztylet";
			break;
		case PROFF_CLERIC:
			we_name = "Kostur";
			break;
		case PROFF_DARK_KNIGHT:
			we_name = "Miecz dwur�czny";
			break;
		case PROFF_MAGE:
			we_name = "R�d�ka";
			break;
		default:
			we_name = "Patyk";
			break;
		}
	}
}

float Weapon::dmg_counter(Character* player)
{
	switch (player->GetProffesion())
	{
	case PROFF_KNIGHT:
		return weapon_stats[0] * 1.5;
		break;
	case PROFF_ARCHER:
		return weapon_stats[1] * 1.5;
		break;
	case PROFF_BARD:
		return weapon_stats[2] * 1.5;
		break;
	case PROFF_CLERIC:
		return weapon_stats[3] * 1.5;
		break;
	case PROFF_DARK_KNIGHT:
		return weapon_stats[4] * 1.5;
		break;
	case PROFF_MAGE:
		return weapon_stats[5] * 1.5;
		break;
	default:
		return 1;
		break;
	}
}
