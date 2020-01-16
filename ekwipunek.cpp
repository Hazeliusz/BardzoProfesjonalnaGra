#include <iostream>
#include <stdlib.h>
#include "ekwipunek.h"
#include "character.h"


void Armor::type_def()
{
	srand(time(NULL));
	if (Eq == "helm")  //wytrzyma³oœæ zbroi na start
	{
		switch (character->GetProffesion())
		{
		case PROFF_KNIGHT:
			durability_max = 20 + character->lvl.getLevel() *2;
			break;
		case PROFF_ARCHER:
			durability_max = 15 + character->lvl.getLevel();
			break;
		case PROFF_BARD:
			durability_max = 10 + character->lvl.getLevel();
			break;
		case PROFF_CLERIC:
			durability_max = 10 + character->lvl.getLevel();
			break;
		case PROFF_DARK_KNIGHT:
			durability_max = 20 + character->lvl.getLevel() *2;
			break;
		case PROFF_MAGE:
			durability_max = 10 + character->lvl.getLevel();
			break;
		default:
			durability_max = 10 + character->lvl.getLevel();
		}
	}
	else if (Eq == "napiersnik")
	{
		switch (character->GetProffesion())
		{
		case PROFF_KNIGHT:
			durability_max = 30 +3* character->lvl.getLevel();
			break;
		case PROFF_ARCHER:
			durability_max = 20 +2* character->lvl.getLevel();
			break;
		case PROFF_BARD:
			durability_max = 15 + character->lvl.getLevel();
			break;
		case PROFF_CLERIC:
			durability_max = 15 + character->lvl.getLevel();
			break;
		case PROFF_DARK_KNIGHT:
			durability_max = 30 +3* character->lvl.getLevel();
			break;
		case PROFF_MAGE:
			durability_max = 15 + character->lvl.getLevel();
			break;
		default:
			durability_max = 15 + character->lvl.getLevel();
		}
	}
	else if (Eq == "buty")
	{
		switch (character->GetProffesion())
		{
		case PROFF_KNIGHT:
			durability_max = 15;
			break;
		case PROFF_ARCHER:
			durability_max = 10;
			break;
		case PROFF_BARD:
			durability_max = 5;
			break;
		case PROFF_CLERIC:
			durability_max = 5;
			break;
		case PROFF_DARK_KNIGHT:
			durability_max = 10;
			break;
		case PROFF_MAGE:
			durability_max = 5;
			break;
		default:
			durability_max = 5;
		}
		durability_max += character->lvl.getLevel();
	}
	else
	{
		std::cout << "\njakiœ b³¹d ;-;\n";
	}

	switch (character->GetProffesion())
	{
	case PROFF_KNIGHT:
		strength = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		endurance = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		charisma = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		intelligence = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		agility = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		luck = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		break;
	case PROFF_ARCHER:
		strength = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		endurance = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		charisma = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		intelligence = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		agility = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		luck = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		break;
	case PROFF_BARD:
		strength = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		endurance = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		charisma = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		intelligence = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		agility = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		luck = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		break;
	case PROFF_CLERIC:
		strength = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		endurance = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		charisma = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		intelligence = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		agility = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		luck = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		break;
	case PROFF_DARK_KNIGHT:
		strength = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		endurance = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		charisma = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		intelligence = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		agility = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		luck = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		break;
	case PROFF_MAGE:
		strength = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		endurance = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		charisma = rand() % (3 * character->lvl.getLevel()) - character->lvl.getLevel();
		intelligence = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		agility = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		luck = rand() % (4 * character->lvl.getLevel()) - character->lvl.getLevel();
		break;
	default:
		strength = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		endurance = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		charisma = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		intelligence = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		agility = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
		luck = rand() % (2 * character->lvl.getLevel()) - character->lvl.getLevel();
	}

}

void Armor::damage_taken()
{
	durability_cur -= (durability_cur*hp_cur)/hp; //hp_cur - po walce? //hp - hp w trakcie walki
	if (durability_cur <= 0)
	{
		durability_cur = 1;
	}

	if (durability_max * 0.25 < durability_cur < durability_max * 0.5)
	{
		std::cout << Eq << std::endl << "jest srednio uszkodzony";
	}
	else if (durability_max * 0.25 > durability_cur)
	{
		std::cout << Eq << std::endl << "jest powaznie uszkodzony";
	}
}

void Armor::defending()
{
	def = 0.01 * durability_cur;
}

//--------------------

void Equipment::usage()
{
	if (thing == "eliksir") ////
	{
		usability = 0;
		if (strength != 0)  		thing = "eliksir Galow";
		else if (endurance != 0)	thing = "wywar z czerwonego byka";
		else if (charisma != 0)		thing = "retoryka w butelce";
		else if (intelligence != 0)	thing = "roztwor wronskianinu potasu";
		else if (agility != 0)		thing = "sok z gumijagod";
		else if (luck != 0)			thing = "wywar z totolotka";
	}
}

void Equipment::take_buff()
{
}

void Equipment::disappear()
{
}
