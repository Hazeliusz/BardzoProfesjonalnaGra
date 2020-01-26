#include "monster.h"
#include "statistics.h"
#include "character.h"
#include <iostream>
#include <stdlib.h>
#include "Square.h"

Monster::Monster(int monsterNumber, bool sexy, Statistics statystyki, std::string nazwa) : Character(nazwa, sexy, statystyki)
{
	CharClass = PROFF_MONSTER;
	this->name_give(monsterNumber);
	this->randomizeStatistics(monsterNumber);
}

void Monster::name_give(int monster_number)
{
	srand(time(NULL));

	sex = rand() % 2;
	switch  (monster_number)
	{
	case 1: // to 1. kwadrat
		if(sex == true)			name = "Skrzat";
		else				name = "Slime";
		break;
	case 2:// 2. kwadrat
		if (sex == true)		name = "Gobol";
		else				name = "Goblin";
		break;
	case 3: 
		if (sex == true)		name = "Harpia";
		else				name = "Kamienny Golem";
		break;
	case 4:
		if (sex == true)		name = "Goblinowa";
		else				name = "Meduza";
		break;
	case 5:
		if (sex == true)		name = "Gorgona";
		else				name = "Troll";
		break;
	case 6:
		if (sex == true)		name = "Duch";
		else				name = "Cyklop";
		break;
	case 7:
		if (sex == true)		name = "Bazyliszek";
		else				name = "Wiwerna";
		break;
	case 8:
		if (sex == true)		name = "Mantykora";
		else				name = "Behemot";
		break;
	case 9:
		if (sex == true)		name = "Smok";
		else				name = "Diabe³";
		break;
	default:
		name = "B³¹d";
	}
}

void Monster::wyswietl_karte_postaci()
{
	std::cout << std::endl << "Nazwa: " << name;
	std::cout << std::endl << "Si³a: " << this->special.strength;
	std::cout << std::endl << "Wytrzymaloœæ: " << this->special.endurance;
	std::cout << std::endl << "Inteligencja: " << this->special.intelligence;
	std::cout << std::endl << "Zwinnoœæ: " << this->special.agility;
	std::cout << std::endl << "Szczêœcie: " << this->special.luck << std::endl;
}

void Monster::randomizeStatistics(int monster_number)
{
	srand(time(NULL));

	this->special.strength	= rand() % monster_number + monster_number;
	this->special.endurance	= rand() % monster_number + monster_number;
	this->special.intelligence = rand() % monster_number + monster_number;
	this->special.agility		= rand() % monster_number + monster_number;
	this->special.luck		= rand() % monster_number + monster_number;

	switch (monster_number) 
	{

	case 1: case 2: //1. i 2. si³a
		if (this->special.strength < 1.4 * monster_number)			this->special.strength = 7 * monster_number;
		if (this->special.endurance < 1.4 * monster_number)			this->special.endurance = 10 * monster_number;
		if (this->special.intelligence < 1.4 * monster_number)		this->special.intelligence = 7 * monster_number;
		if (this->special.agility < 1.4 * monster_number)				this->special.agility = 7 * monster_number;
		if (this->special.luck < 1.4 * monster_number)				this->special.luck = 7 * monster_number;
		break;
	case 3: case 4: //2.
		if (this->special.strength > 1.6 * monster_number)			this->special.strength = 10 * monster_number;
		else if (this->special.strength < 1.2 * monster_number)		this->special.strength = 12 * monster_number;
		if (this->special.endurance > 1.6 * monster_number)			this->special.endurance = 12 * monster_number;
		else if (this->special.endurance < 1.2 * monster_number)		this->special.endurance = 8 * monster_number;
		if (this->special.intelligence > 1.6 * monster_number)		this->special.intelligence = 8 * monster_number;
		else if (this->special.intelligence < 1.2 * monster_number)	this->special.intelligence = 6 * monster_number;
		if (this->special.agility > 1.6 * monster_number)				this->special.agility = 8 * monster_number;
		else if (this->special.agility < 1.2 * monster_number)		this->special.agility = 6 * monster_number;
		if (this->special.luck > 1.6 * monster_number)				this->special.luck = 8 * monster_number;
		else if (this->special.luck < 1.2 * monster_number)			this->special.luck = 6 * monster_number;
		break;
	case 5: case 6:
		if (this->special.strength > 1.8 * monster_number)			this->special.strength = 6 * monster_number;
		else if (this->special.strength < 1.4 * monster_number)		this->special.strength = 7 * monster_number;
		if (this->special.endurance > 1.8 * monster_number)			this->special.endurance = 13 * monster_number;
		else if (this->special.endurance < 1.4 * monster_number)		this->special.endurance = 9 * monster_number;
		if (this->special.intelligence > 1.8 * monster_number)		this->special.intelligence = 9 * monster_number;
		else if (this->special.intelligence < 1.4 * monster_number)	this->special.intelligence = 7 * monster_number;
		if (this->special.agility > 1.8 * monster_number)				this->special.agility = 9 * monster_number;
		else if (this->special.agility < 1.4 * monster_number)		this->special.agility = 7 * monster_number;
		if (this->special.luck > 1.8 * monster_number)				this->special.luck = 9 * monster_number;
		else if (this->special.luck < 1.4 * monster_number)			this->special.luck = 7 * monster_number;
		break;
	case 7: case 8:
		if (this->special.strength > 2 * monster_number)				this->special.strength = 12 * monster_number;
		else if (this->special.strength < 1.6 * monster_number)		this->special.strength = 8 * monster_number;
		if (this->special.endurance > 2 * monster_number)				this->special.endurance = 14 * monster_number;
		else if (this->special.endurance < 1.6 * monster_number)		this->special.endurance = 12 * monster_number;
		if (this->special.intelligence > 2 * monster_number)			this->special.intelligence = 10 * monster_number;
		else if(this->special.intelligence < 1.6 * monster_number)	this->special.intelligence = 8 * monster_number;
		if (this->special.agility > 2 * monster_number)				this->special.agility = 10 * monster_number;
		else if (this->special.agility < 1.6 * monster_number)		this->special.agility = 8 * monster_number;
		if (this->special.luck > 2 * monster_number)					this->special.luck = 10 * monster_number;
		else if (this->special.luck < 1.6 * monster_number)			this->special.luck = 8 * monster_number;
		break;
	case 9:
		this->special.strength += monster_number;
		this->special.endurance += monster_number;
		this->special.intelligence += monster_number;
		this->special.agility += monster_number;
		this->special.luck += monster_number;
		break;
	case 10: //boss
		this->special.strength = 35 * monster_number;
		this->special.endurance = 40 * monster_number;
		this->special.intelligence = 35 * monster_number;
		this->special.agility = 35 * monster_number;
		this->special.luck = 35 * monster_number;
	default:
		std::cout << "\nproblem w monster.cpp, welp\n";
	}

}

void Monster::randomizeStatistics(){
}
