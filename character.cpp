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
} //sprawdza automatycznie, czy próg zosta³ osi¹gniêty

void Level::levelUp() {
	this->level++;
	thresholdEXP = getLevelThreshold(level);
	currentEXP = 0;
}

void Character::checkLevelUp() {
	if (lvl.checkLevelUp()) {
		std::cout << (sex ? "Awansowa³aœ" : "Awansowa³eœ") << " na poziom" << lvl.getLevel() << "!" << std::endl;
		for (int i = 5; i > 0;) {
			std::cout << "Wybierz statystyki, które chcesz ulepszyæ: " << std::endl;
			std::cout << "Dostêpne punkty: " << i << std::endl;
			int choice = 0;
			std::cout << "1. Si³a" << std::endl;
			std::cout << "2. Percepcja" << std::endl;
			std::cout << "3. Wytzyma³oœæ" << std::endl;
			std::cout << "4. Charyzma" << std::endl;
			std::cout << "5. Inteligencja" << std::endl;
			std::cout << "6. Zrêcznoœæ" << std::endl;
			std::cout << "7. Szczêœcie" << std::endl;
			std::cin >> choice;
			switch (choice) {
			case 1:
				this->special.advanceStatsByEnum(Strength);
				i--;
				break;
			case 2:
				this->special.advanceStatsByEnum(Perception);
				i--;
				break;
			case 3:
				this->special.advanceStatsByEnum(Endurance);
				i--;
				break;
			case 4:
				this->special.advanceStatsByEnum(Charisma);
				i--;
				break;
			case 5:
				this->special.advanceStatsByEnum(Intelligence);
				i--;
				break;
			case 6:
				this->special.advanceStatsByEnum(Agility);
				i--;
				break;
			case 7:
				this->special.advanceStatsByEnum(Luck);
				i--;
				break;
			default:
				std::cout << "Niepoprawny wybór! Wybierz ponownie." << std::endl;
			}
			if (lvl.getLevel() == 5)
				addSkillAt5();
			if (lvl.getLevel() == 10)
				addSkillAt10();
			if (lvl.getLevel() == 20)
				addSkillAt20();

		}
	}
}

void Character::addSkillAt5() {

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
			std::cout << p1->GetName() << " zadaje potê¿ny cios mieczem, zabieraj¹c 50 HP " << p2->GetName() << "." << std::endl;
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
	skills["Strza³ z ³uku"] = [](Character* p1, Character* p2, bufor& bf) {
		int dmg = p1->GetStats().getByEnum(Agility) +
			(rand() % p1->GetStats().getByEnum(Luck));
		p2->hp -= dmg;
		std::cout << p2->GetName() << (p2->GetSex() ? " zosta³a postrzelona " : " zosta³ postrzelony ")  <<"za " << dmg << " HP." << std::endl;
		bf[p1->GetName() + "_Strza³ z ³uku_cooldown"] = 2;
		};
}

Bard::Bard(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	CharClass = PROFF_BARD;
	skills["Pieœñ Apolla"] = [](Character* p1, Character* p2, bufor& bf) {
		int dmg = p2->GetStats().getByEnum(Strength) +
			(rand() % p1->GetStats().getByEnum(Luck));
		p2->hp -= dmg;
		std::cout << p2->GetName() << " w wyniku pieœni zaatakowa³ sam siebie za " << dmg << " HP!" << std::endl;
		bf[p1->GetName() + "_Pieœñ Apolla_cooldown"] = 3;
	};
}
Dark_Knight::Dark_Knight(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	CharClass = PROFF_DARK_KNIGHT;
	skills["BluŸniercze leczenie"] = [](Character* p1, Character* p2, bufor& bf) {
		int dmg = p1->GetStats().getByEnum(Intelligence) * 0.7 +
			rand() % p1->GetStats().getByEnum(Luck);
		p1->hp += dmg;
		p2->hp -= dmg;
		std::cout << p1->GetName() << (p1->GetSex() ? " ukrad³a " : " ukrad³ ") << p2->GetName() << " " << dmg << " HP." << std::endl;
		bf[p1->GetName() + "_BluŸniercze leczenie_cooldown"] = 5;
	};

}

Cleric::Cleric(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	CharClass = PROFF_CLERIC;
	skills["Leczenie"] = [](Character* p1, Character* p2, bufor& bf) {
		int heal = p1->GetStats().getByEnum(Intelligence) +
			rand() % p1->GetStats().getByEnum(Luck);
		p1->hp += heal;
		std::cout << p1->GetName() << " uleczy³ siê za " << heal << " HP." << std::endl;
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
		std::cout << p2->GetName() << " zosta³ trafiony kul¹ ognia za " << dmg << " HP." << std::endl;
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
	std::cout << "Doœwiadczenie: " << lvl.getCurrentEXP() << "/" << lvl.getLevelThreshold(lvl.getLevel()) << std::endl;
	std::cout << "Plec: ";
	std::cout << (sex ? "kobieta":"mezczyzna") << std::endl;
	writeStatistics();
}