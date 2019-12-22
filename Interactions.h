#pragma once
#include "character.h"
#include "monster.h"
#include <vector>

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
		bufor bf;

		character1->hp = character1->GetStats().getByEnum(Wytrzymalosc) * 10;
		character2->hp = character2->GetStats().getByEnum(Wytrzymalosc) * 10;

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
				std::cout << attacking->GetName() << "Uciekl!" << std::endl;
				return defending;
			}

			attacking->GetSkills()[skills[decyzja - 1]](attacking, defending, bf);

			if (defending->hp <= 0)
			{
				std::cout << attacking->GetName() << "Wygrywa!" << std::endl;
				return attacking;
			}

			turn = !turn;
		}
	}
};

class MonsterFight {

};