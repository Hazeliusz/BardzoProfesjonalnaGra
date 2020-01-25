#pragma once
#include "character.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

int Level::getLevelThreshold(int lvl) {
	if (lvl == 1)
		return 50;
	else
		return (lvl * 10) + getLevelThreshold(lvl - 1);
}

Level::Level(int lvl){
	this->level = lvl;
	this->currentEXP = 0;
	this->thresholdEXP = getLevelThreshold(lvl);
}

int Level::getLevel() {
	return level;
}

void Level::setLevel(int lvl) {
	this->level = lvl;
}

int Level::getCurrentEXP() {
	return currentEXP;
}

bool Level::checkLevelUp() {
	if (currentEXP >= thresholdEXP) {
		this->levelUp();
		return true;
	}
	else
		return false;
}

void Level::addEXP(int exp) {
	this->currentEXP += exp;
}

void Character::addEXP(int exp) {
	this->lvl.addEXP(exp);
	checkLevelUp();
} //sprawdza automatycznie, czy pr�g zosta� osi�gni�ty

void Level::levelUp() {
	this->level++;
	thresholdEXP = getLevelThreshold(level);
	currentEXP = 0;
}

void Character::checkLevelUp() {
	if (lvl.checkLevelUp()) {
		std::cout << (sex ? "Awansowa�a�" : "Awansowa�e�") << " na poziom" << lvl.getLevel() << "!" << std::endl;
		for (int i = 5; i > 0;) {
			std::cout << "Wybierz statystyki, kt�re chcesz ulepszy�: " << std::endl;
			std::cout << "Dost�pne punkty: " << i << std::endl;
			int choice = 0;
			std::cout << "1. Si�a" << std::endl;
			std::cout << "2. Percepcja" << std::endl;
			std::cout << "3. Wytzyma�o��" << std::endl;
			std::cout << "4. Charyzma" << std::endl;
			std::cout << "5. Inteligencja" << std::endl;
			std::cout << "6. Zr�czno��" << std::endl;
			std::cout << "7. Szcz�cie" << std::endl;
			std::cin >> choice;
			switch (choice) {
			case 1:
				this->special.advanceStatsByEnum(Strength, 1);
				i--;
				break;
			case 2:
				this->special.advanceStatsByEnum(Perception, 1);
				i--;
				break;
			case 3:
				this->special.advanceStatsByEnum(Endurance, 1);
				i--;
				break;
			case 4:
				this->special.advanceStatsByEnum(Charisma, 1);
				i--;
				break;
			case 5:
				this->special.advanceStatsByEnum(Intelligence, 1);
				i--;
				break;
			case 6:
				this->special.advanceStatsByEnum(Agility, 1);
				i--;
				break;
			case 7:
				this->special.advanceStatsByEnum(Luck, 1);
				i--;
				break;
			default:
				std::cout << "Niepoprawny wyb�r! Wybierz ponownie." << std::endl;
			}
			if (lvl.getLevel() == 5)
				addSkillAt5();
			/*if (lvl.getLevel() == 10)
				addSkillAt10();
			if (lvl.getLevel() == 20)
				addSkillAt20();*/

		}
	}

}

int Character::getGold() {
	return gold;
}

void Character::addGold(int added) {
	this->gold += added;
}

void Character::lostGold(int lost) {
	this->gold -= lost;
}

void Character::addSkillAt5() {

}

void Character::displayInventory(){
	std::cout << "Bronie: " << std::endl;
	for (int i = 0; i < weapon_eq.size(); i++) {
		std::cout << i + 1 << ". " << weapon_eq[i].we_name << " ma " << weapon_eq[i].dmg_counter(this) << " DMG." << std::endl;
	}
	std::cout << "Cz�ci zbroi: " << std::endl;
	for (int i = 0; i < armor_eq.size(); i++) {
		std::cout << i + 1 << ". " << armor_eq[i].armor_name << " ma wsp�czynnik pancerza na poziomie " << armor_eq[i].def << std::endl;
		std::cout << "Jej wytrzyma�o�� to obecnie " << armor_eq[i].durability_cur << "/" << armor_eq[i].durability_max << std::endl;
	}
	/*std::cout << "Przedmioty jednorazowy: " << std::endl;
	for (int i = 0; i < equipment_eq.size(); i++) {
		std::cout << i + 1 << ". " << equipment_eq[i].eq_name << 
	}*/
}

void Character::addWeapon(Weapon added) {
	weapon_eq.push_back(added);
}

void Character::addArmor(Armor added) {
	armor_eq.push_back(added);
}

void Character::addEquipment(Equipment added) {
	equipment_eq.push_back(added);
}

Character::Character(std::string name, bool sex, Statistics stats, int lvls) {
	this->name = name;
	this->sex = sex;
	this->special = stats;
	skills["Atak fizyczny"] = [](Character* character1, Character* character2, bufor& bf) {
		int dmg = character1->GetStats().getByEnum(Strength) * 0.5 +
			rand() % character1->GetStats().getByEnum(Luck);
		character2->hp -= dmg;
		std::cout << character2->GetName() << " oberwal za " << dmg << " HP." << std::endl;
	};
	skills["Atak magiczny"] = [](Character* character1, Character* character2, bufor& bf) {
		int dmg = character1->GetStats().getByEnum(Intelligence) * 0.5 +
			rand() % character1->GetStats().getByEnum(Luck);
		character2->hp -= dmg;
		std::cout << character2->GetName() << " zostal zaatakowany magicznie za " << dmg << " HP." << std::endl;
	};
	this->lvl.setLevel(lvls);
}

void Character::writeStatistics() {
	std::cout << "Sila: " << special.strength << std::endl;
	std::cout << "Percepcja: " << special.perception << std::endl;
	std::cout << "Wytrzymalosc: " << special.endurance << std::endl;
	std::cout << "Charyzma: " << special.charisma << std::endl;
	std::cout << "Inteligencja: " << special.intelligence << std::endl;
	std::cout << "Zrecznosc: " << special.agility << std::endl;
	std::cout << "Szczescie: " << special.luck << std::endl;
}

//Constructors

Knight::Knight(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	CharClass = PROFF_KNIGHT;
	skills["Mocny cios"] = [](Character* p1, Character* p2, bufor& bf) {
		if (p2->GetStats().agility < 5)
		{
			p2->hp -= 50;
			std::cout << p1->GetName() << " zadaje pot�ny cios mieczem, zabieraj�c 50 HP " << p2->GetName() << "." << std::endl;
		}
		else
		{
			std::cout << p2->GetName() << " unika ciosu " << p1->GetName() << "." << std::endl;
		}
		bf[p1->GetName() + "_Mocny cios_cooldown"] = 5;
		};
	
}
Archer::Archer(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	CharClass = PROFF_ARCHER;
	skills["Strza� z �uku"] = [](Character* p1, Character* p2, bufor& bf) {
		int dmg = p1->GetStats().getByEnum(Agility) +
			(rand() % p1->GetStats().getByEnum(Luck));
		p2->hp -= dmg;
		std::cout << p2->GetName() << (p2->GetSex() ? " zosta�a postrzelona " : " zosta� postrzelony ")  <<"za " << dmg << " HP." << std::endl;
		bf[p1->GetName() + "_Strza� z �uku_cooldown"] = 2;
		};
} // <-

Bard::Bard(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	CharClass = PROFF_BARD;
	skills["Pie�� Apolla"] = [](Character* p1, Character* p2, bufor& bf) {
		int dmg = p2->GetStats().getByEnum(Strength) +
			(rand() % p1->GetStats().getByEnum(Luck));
		p2->hp -= dmg;
		std::cout << p2->GetName() << " w wyniku pie�ni zaatakowa� sam siebie za " << dmg << " HP!" << std::endl;
		bf[p1->GetName() + "_Pie�� Apolla_cooldown"] = 3;
	};
}
Dark_Knight::Dark_Knight(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	CharClass = PROFF_DARK_KNIGHT;
	skills["Blu�niercze leczenie"] = [](Character* p1, Character* p2, bufor& bf) {
		int dmg = p1->GetStats().getByEnum(Intelligence) * 0.7 +
			rand() % p1->GetStats().getByEnum(Luck);
		p1->hp += dmg;
		p2->hp -= dmg;
		std::cout << p1->GetName() << (p1->GetSex() ? " ukrad�a " : " ukrad� ") << p2->GetName() << " " << dmg << " HP." << std::endl;
		bf[p1->GetName() + "_Blu�niercze leczenie_cooldown"] = 5;
	};

}

Cleric::Cleric(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	CharClass = PROFF_CLERIC;
	skills["Leczenie"] = [](Character* p1, Character* p2, bufor& bf) {
		int heal = p1->GetStats().getByEnum(Intelligence) +
			rand() % p1->GetStats().getByEnum(Luck);
		p1->hp += heal;
		std::cout << p1->GetName() << " uleczy� si� za " << heal << " HP." << std::endl;
		bf[p1->GetName() + "_Leczenie_cooldown"] = 5;
	};
}
Mage::Mage(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	CharClass = PROFF_MAGE;
	skills["Kula ognia"] = [](Character* p1, Character* p2, bufor& bf) {
		int dmg = p1->GetStats().getByEnum(Intelligence) * 1.5 +
			rand() % p1->GetStats().getByEnum(Luck);
		p2->hp -= dmg;
		std::cout << p2->GetName() << " zosta� trafiony kul� ognia za " << dmg << " HP." << std::endl;
		bf[p1->GetName() + "_Kula ognia_cooldown"] = 5;
	};
}

//Randomizing statistics

void Knight::randomizeStatistics() {
	special.strength = rand() % 10 + 10;
	special.perception = rand() % 10 + 5;
	special.endurance = rand() % 10 + 20;
	special.charisma = rand() % 5 + 5;
	special.intelligence = rand() % 5 + 7;
	special.agility = rand() % 4 + 5;
	special.luck = rand() % 20 + 1;
}

void Archer::randomizeStatistics() {
	special.strength = rand() % 5 + 5;
	special.perception = rand() % 10 + 15;
	special.endurance = rand() % 10 + 10;
	special.charisma = rand() % 5 + 7;
	special.intelligence = rand() % 5 + 7;
	special.agility = rand() % 10 + 25;
	special.luck = rand() % 20 + 1;
}

void Bard::randomizeStatistics() {
	special.strength = rand() % 5 + 5;
	special.perception = rand() % 10 + 5;
	special.endurance = rand() % 10 + 10;
	special.charisma = rand() % 10 + 25;
	special.intelligence = rand() % 5 + 15;
	special.agility = rand() % 5 + 3;
	special.luck = rand() % 20 + 1;
}

void Dark_Knight::randomizeStatistics() {
	special.strength = rand() % 10 + 30;
	special.perception = rand() % 10 + 5;
	special.endurance = rand() % 5 + 15;
	special.charisma = 1;
	special.intelligence = rand() % 5 + 10;
	special.agility = rand() % 5 + 10;
	special.luck = 1;
}

void Cleric::randomizeStatistics() {
	special.strength = rand() % 5 + 5;
	special.perception = rand() % 10 + 5;
	special.endurance = rand() % 5 + 10;
	special.charisma = rand() % 10 + 15;
	special.intelligence = rand() % 5 + 25;
	special.agility = rand() % 5 + 3;
	special.luck = rand() % 20 + 1;
}

void Mage::randomizeStatistics() {
	special.strength = rand() % 5 + 5;
	special.perception = rand() % 10 + 5;
	special.endurance = rand() % 10 + 10;
	special.charisma = rand() % 10 + 10;
	special.intelligence = rand() % 5 + 25;
	special.agility = rand() % 5 + 3;
	special.luck = rand() % 20 + 1;
}

//Draw character cards

void Character::drawCharacterCard()
{
	std::cout << "Imie: " << this->name << std::endl;
	std::cout << "Klasa: " << this->GetProffesionName() << std::endl;
	std::cout << "Poziom: " << lvl.getLevel() << std::endl;
	std::cout << "Do�wiadczenie: " << lvl.getCurrentEXP() << "/" << lvl.getLevelThreshold(lvl.getLevel()) << std::endl;
	std::cout << "Plec: ";
	std::cout << (sex ? "kobieta":"mezczyzna") << std::endl;
	writeStatistics();
}