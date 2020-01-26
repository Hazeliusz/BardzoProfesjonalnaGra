#pragma once
#include "character.h"
#include "monster.h"
#include <vector>

class CharactersInteractions //zelentjuniorikij
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
		bufor bf;

		character1->hp = character1->GetStats().getByEnum(Endurance) * 10;
		character2->hp = character2->GetStats().getByEnum(Endurance) * 10;

		bool turn = true; //true - 1, false - 2
		std::cout << "Walka: " << character1->GetName() << " vs. " << character2->GetName() << std::endl;

		while (true) {
			Character* attacking = (turn ? character1 : character2);
			Character* defending = (turn ? character2 : character1);
			//minela tura, odejmujemy 1 od kazdego cooldowna
			for (auto const& x : bf)
				if (x.first.find("cooldown") != std::string::npos)
					bf[x.first]--;

			std::vector<std::string> skills;

			for (auto const& x : attacking->GetSkills())
			{
				if (bf[attacking->GetName() + "_" + x.first + "_cooldown"] < 1)
				{
					skills.push_back(x.first);
				}
			}

			std::cout << "Aktualny gracz: " << attacking->GetName() << std::endl;
			std::cout << "Aktualne HP: " << attacking->hp << std::endl;
			int decyzja = 0;
			while (true) {
				std::cout << "Wybierz akcje: " << std::endl;
				for (int i = 0; i < skills.size(); i++)
				{
					std::cout << (i + 1) << ". " << skills[i] << std::endl;
				}
				std::cout << 0 << ". Ucieczka" << std::endl;
				std::cin >> decyzja;
				if (decyzja < 0 || decyzja > skills.size()) {
					std::cout << "Niepoprawna decyzja";
				}
				else {
					break;
				}
			}

			if (decyzja == 0)
			{
				std::cout << attacking->GetName() << " uciekl!" << std::endl;
				return defending;
			}

			attacking->GetSkills()[skills[decyzja - 1]](attacking, defending, bf);

			if (defending->hp <= 0)
			{
				std::cout << attacking->GetName() << " wygrywa!" << std::endl;
				return attacking;
			}

			turn = !turn;
		}
	}

	int MonsterFight() { //1 - ucieczka, 2 - wygrana gracza, 0 - przegrana gracza
		bufor bf;
		Character* player = character1;
		Character* monster = character2;
		player->hp = character1->GetStats().getByEnum(Endurance) * 10;
		monster->hp = monster->GetStats().getByEnum(Endurance) * 10;

		bool turn = true;
		std::cout << "Walka: " << character1->GetName() << " vs. " << character2->GetName() << std::endl;

		while (true) {
			//minela tura, odejmujemy 1 od kazdego cooldowna
			for (auto const& x : bf)
				if (x.first.find("cooldown") != std::string::npos)
					bf[x.first]--;

			std::vector<std::string> skills;

			for (auto const& x : player->GetSkills())
			{
				if (bf[player->GetName() + "_" + x.first + "_cooldown"] < 1)
				{
					skills.push_back(x.first);
				}
			}
			if (turn) {
				std::cout << "Twój ruch!" << std::endl;
				std::cout << "Aktualne HP: " << player->hp << std::endl;
				std::cout << "HP przeciwnika: " << monster->hp << std::endl;
				int decyzja = 0;
				while (true) {
					std::cout << "Wybierz akcje: " << std::endl;
					for (int i = 0; i < skills.size(); i++)
					{
						std::cout << (i + 1) << ". " << skills[i] << std::endl;
					}
					std::cout << 0 << ". Ucieczka" << std::endl;
					std::cin >> decyzja;
					if (decyzja < 0 || decyzja > skills.size()) {
						std::cout << "Niepoprawna decyzja";
					}
					else {
						break;
					}
				}

				if (decyzja == 0)
				{
					std::cout << player->GetName() << " uciekl!" << std::endl;
					return 1; //ucieczka
				}

				player->GetSkills()[skills[decyzja - 1]](player, monster, bf);


				if (monster->hp <= 0) {
					std::cout << "Wygrywasz walkę!" << std::endl;
					player->addEXP(monster->GetStats().getByEnum(Strength) * 2.5 + monster->GetStats().getByEnum(Endurance) * 2.5);
					system("pause");
					system("cls");
					return 2;
				}
			}
			else {
				int dmg = 0;
				if (monster->GetStats().getByEnum(Strength) > monster->GetStats().getByEnum(Intelligence)) {
					dmg = monster->GetStats().getByEnum(Strength) * 1.5 - (rand() % player->GetStats().getByEnum(Luck))
						- player->getArmorDef();
					if(dmg <= 0)
						std::cout << monster->GetName() << " nie trafia!" << std::endl;
					else {
						std::cout << monster->GetName() << " atakuje Cię za " << dmg << " HP!" << std::endl;
						player->hp -= dmg;
					}
				}
				else {
					dmg = monster->GetStats().getByEnum(Intelligence) * 1.5 - (rand() % player->GetStats().getByEnum(Luck))
						- player->getArmorDef();
					if (dmg <= 0)
						std::cout << monster->GetName() << " nie trafia!" << std::endl;
					else {
						std::cout << monster->GetName() << " rzuca zaklęcie, zadając Ci " << dmg << " HP!" << std::endl;
						player->hp -= dmg;
					}
				}
				if (player->hp <= 0) {
					std::cout << "Przegrywasz walkę..." << std::endl;
					return 0;
				}
				system("pause");
				system("cls");
			}
			turn = !turn;
			
		}
	}

};