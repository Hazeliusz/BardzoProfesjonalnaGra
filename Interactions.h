#pragma once
#include "character.h"
#include "monster.h"

class CharactersInteractions
{
private:
	Character * character1;
	Character * character2;

public:
	CharactersInteractions(Character * character1, Character * character2)
	{
		this->character1 = character1;
		this->character2 = character2;
	}

	//Skrypt walki, zwraca wskaźnik na zwycięzcę (lub nullptr w przypadku jego braku
	Character * Fight()
	{
		int hp1 = character1->GetStats().getByEnum(Wytrzymalosc) * 10;
		int hp2 = character2->GetStats().getByEnum(Wytrzymalosc) * 10;
		bool turn = true; //true - 1, false - 2
		std::cout << "Walka: " << character1->GetName() << " vs. " << character2->GetName() << std::endl;
		while (true) {
			std::cout << "Aktualny gracz: " << (turn ? character1->GetName() : character2->GetName()) << std::endl;
			std::cout << "Aktualne HP: " << (turn ? hp1 : hp2) << std::endl;
			int decyzja = 0;
			while (true) {
				std::cout << "Wybierz akcje: " << std::endl;
				std::cout << "1. Atak fizyczny." << std::endl;
				std::cout << "2. Atak magiczny." << std::endl;
				std::cout << "3. Ucieknij";
				if (turn) {
					if (character1->GetProffesion() == PROFF_ARCHER)
						std::cout << "4. Strzel z luku" << std::endl;
				}
				else {
					if (character2->GetProffesion() == PROFF_ARCHER)
						std::cout << "4. Strzel z luku";
				}
				std::cin >> decyzja;
				if (decyzja > 4 && decyzja < 1) {
					std::cout << "Niepoprawna decyzja";
				}
				else {
					break;
				}
			}
			switch (decyzja) {
			case 1:
				if (turn) {
					int dmg = character1->GetStats().getByEnum(Sila) * 0.5 +
						rand() % character1->GetStats().getByEnum(Szczescie);
					hp2 -= dmg;
					std::cout << character2->GetName() << " oberwal za " << dmg << " HP." << std::endl;
				}
				else {
					int dmg = character2->GetStats().getByEnum(Sila) * 0.5 +
						rand() % character2->GetStats().getByEnum(Szczescie);
					hp1 -= dmg;
					std::cout << character1->GetName() << " oberwal za " << dmg << " HP." << std::endl;
				}
				break;
			case 2:
				if (turn) {
					int dmg = character1->GetStats().getByEnum(Inteligencja) * 0.5 +
						rand() % character1->GetStats().getByEnum(Szczescie);
					hp2 -= dmg;
					std::cout << character2->GetName() << " zostal zaatakowany magicznie za " << dmg << " HP." << std::endl;
				}
				else {
					int dmg = character2->GetStats().getByEnum(Inteligencja) * 0.5 +
						(rand() % character2->GetStats().getByEnum(Szczescie));
					hp1 -= dmg;
					std::cout << character1->GetName() << " zostal zaatakowany magicznie za " << dmg << " HP." << std::endl;
				}
				break;
			case 3:
				if (turn) {
					std::cout << character1->GetName() << " uciekl!" << std::endl;
					return character2;
				}
				else {
					std::cout << character2->GetName() << " uciekl!" << std::endl;
					return character1;
				}
				break;
			case 4:
				if (turn) {
					int dmg = character1->GetStats().getByEnum(Zrecznosc) * 0.5 +
						(rand() % character1->GetStats().getByEnum(Szczescie));
					hp2 -= dmg;
					std::cout << character2->GetName() << " zostal postrzelony za " << dmg << " HP." << std::endl;
				}
				else {
					int dmg = character2->GetStats().getByEnum(Zrecznosc) * 0.5 +
						(rand() % character2->GetStats().getByEnum(Szczescie));
					hp1 -= dmg;
					std::cout << character1->GetName() << " zostal postrzelony za " << dmg << " HP." << std::endl;
				}
				break;
			}
				if (hp2 <= 0) {
					std::cout << character1->GetName() << " wygrywa!" << std::endl;
					return character1;
				}
			
				if (hp1 <= 0) {
					std::cout << character2->GetName() << " wygrywa!" << std::endl;
					return character2;
				}
				if (turn)
					turn = false;
				else
					turn = true;
			
		}
	}	
};

class MonsterFight {

};