#pragma once
#include <iostream>
#include "Square.h"
#include <Windows.h>
#include <stdlib.h>
#include "NPC.h"

void Non_Character::options(Character* player)
{
	short int choice = -1;
	short int quit = 0;
	while (quit == 0)
	{
		if (npc_name != "Wieœniak")
		{
			std::cout << "'1' - sklep" << std::endl;
			std::cout << "'2' - rozmowa" << std::endl;
			if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")		
				std::cout << "'3' - naprawa zbroi" << std::endl;
			else
				std::cout << "'3' - sprzedarz" << std::endl;
			std::cout << std::endl << "'4' - wyjœcie" << std::endl;

			std::cin >> choice;
			switch (choice)
			{
			case 1: // sklep //-------------------------//
				this->buy(player);
				break;
			case 2: //historia //------------------------//
				this->talk(player);
				break;
			case 3: //nic lub sprzedarz, lub naprawa
				if (npc_name == "Chemik Renagan")
				{
					std::cout << "Podziêkujê, nie jestem tutaj, by kupowaæ, a by sprzedawac" << std::endl;
					std::cout << "A propos sprzedarzy, nie chcia³by pan czegos kupic?" << std::endl;
				}
				else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->GetStats().getByEnum(Charisma) < 30))
				{
					std::cout << "Nie potrzebujê teraz wiêkszej iloœci baga¿u." << std::endl;
				}
				else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->GetStats().getByEnum(Charisma) >= 30))
				{
					std::cout << "Nie dam rady odkupiæ tego od ciebie, przykro mi" << std::endl;
				}
				else if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")
				{
					repair(player); //naprawa
				}
				else if (npc_name == "Gerwalt" || npc_name == "Oktis" || npc_name == "Zbrojmistrz5" || npc_name == "Zet")
				{
					std::cout << "Nie kupujê œmieci" << std::endl;
				}
				else if (npc_name == "Zbrojmistrz2" || npc_name == "Zbrojmistrz3")
				{
					std::cout << "Nie." << std::endl;
				}
				else std::cout << "nie..." << std::endl;
				break;
			case 4:
				quit = 1;
				break;
			default:
				std::cout << "Nie ma takiej opcji." << std::endl;
			}
		}
		else {
			quit = 1;
		}
	}
	quit = 0;
}

void Non_Character::buy(Character* player)
{
	bool agreement; // 0-nie, 1-tak;
	int nr_choice;
	int  seller; //seller - ma³y wspó³czynnik kosztów 

	seller = 8 - player->GetStats().getByEnum(Charisma) / 5;
	

	if (this->npc_type == 'C') //chemicy
	{
		Equipment potions[6];
		potions[0].eq_name == "Eliksir Galow";
		potions[1].eq_name == "Wywar z czerwonego byka";
		potions[2].eq_name == "Retoryka w butelce";
		potions[3].eq_name == "Roztwor wroñskianu potasu";
		potions[4].eq_name == "Sok z gumijagod";
		potions[5].eq_name == "Wywar z totolotka";


		for (int i = 0; i < 6; i++)
		{
			potions[i].give_statistics();
			potions[i].usage(player);
		}

		if (npc_name == "Chemik Renagan")
		{
			std::cout << "Aktualnie mam takie drobnostki na zbyciu. Jesteœ " << (player->GetSex() ? "zainteresowana" : "zainteresowany") <<"? Jesteœ, prawda? Prawda..." << std::endl;
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->GetStats().getByEnum(Charisma) >= 15))// 15- jakaœ lczba, któr¹ trzeba doustaliæ
		{
			std::cout << "Nie ma tego wiele, ale weŸ, co chcesz" << std::endl;
			seller = 1;
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->GetStats().getByEnum(Charisma) < 15))
		{
			std::cout << "Jak zwykle u mnie eliksiry najlepszej jakoœci. Patrz i wybieraj, czego tylko pragniesz." << std::endl;
			seller = 6;
		}
		else
		{
			std::cout << "Tylko niczego nie zbij." << std::endl;
		}


		for (int i = 0; i < 6; i++) //koszt
		{
			potions[i].eq_cost = 100 * (potions[i].eq_stats[0] + potions[i].eq_stats[1] + potions[i].eq_stats[2] + potions[i].eq_stats[3]
				+ potions[i].eq_stats[4] + potions[i].eq_stats[5] + seller);
		}

		for (int i = 0; i < 6; i += 2) //wypisywanie
		{
			std::cout << "nazwa:      " << i + 1 << ". " << potions[i].eq_name << "\t\t\t\t" << i+2 << potions[i + 1].eq_name << std::endl;
			std::cout << "statystyka?:" << potions[i].eq_stats[i] << "\t\t\t\t" << potions[i + 1].eq_stats[i + 1] << std::endl;
			std::cout << "koszt:      " << potions[i].eq_cost     << "\t\t\t\t" << potions[i + 1].eq_cost << std::endl;
		}
		std::cout << "To który z eliksirów " << (player->GetSex() ? "chcia³abyœ" : "chcia³byœ") << " kupiæ? ('6' - nie kupujê)" << std::endl;
		std::cin >> nr_choice;
		
		if (nr_choice > 0 && nr_choice <= 6)
		{
			agreement = pay(potions[nr_choice - 1].eq_cost, player);
			if (agreement == true)
			{
				player->addEquipment(potions[nr_choice - 1]);
			}
		}
		else
		{
			std::cout << "Eh..." << std::endl;
		}
	}
	else if (npc_type == 'Z') //zbrojmistrzowie
	{
		Armor armory[6];
		if (npc_name == "Gerwalt" || npc_name == "Oktis")
		{
			
			for (int i = 0; i < 6; i++)
			{
				armory[i].armor_name = "He³m";
				armory[i].type_def(player);
				armory[i].type_stats(player);
			}

			if (npc_name == "Gerwalt")
			{
				std::cout << "W mojej ofercie aktualnie znajduj¹ siê tylko takie przedmioty" << std::endl;
			}
			else if (npc_name == "Oktis")
			{
				std::cout << "Takie skarbeñki tu mamy. Na pewno któryœ ci siê spodoba!" << std::endl;
			}
			else
			{
				std::cout << "Tylko nie zniszcz." << std::endl;
			}
		}
		else if (npc_name == "Zbrojmistrz2" || npc_name == "Zbrojmistrz5")
		{
			for (int i = 0; i < 6; i++)
			{
				armory[i].armor_name = "Napierœnik";
				armory[i].type_def(player);
				armory[i].type_stats(player);
			}

			if (npc_name == "Zbrojmistrz2")
			{
				std::cout << "..." << std::endl;
			}
			else if (npc_name == "Zbrojmistrz5")
			{
				std::cout << "Takie skarbeñki tu mamy. Na pewno któryœ ci siê spodoba!" << std::endl;
			}
			else
			{
				std::cout << "Tylko nie zniszcz." << std::endl;
			}
		}
		else if (npc_name == "Zbrojmistrz3" || npc_name == "Zet")
		{
			for (int i = 0; i < 6; i++)
			{
				armory[i].armor_name = "Buty";
				armory[i].type_def(player);
				armory[i].type_stats(player);
			}

			if (npc_name == "Zbrojmistrz3")
			{
				std::cout << "...To, to proszê chwilkê zaczekaæ, za chwilkê przyniosê wszystko, co mam." << std::endl;
				Sleep(3000);
				std::cout << "Proszê..." << std::endl;
			}
			else if (npc_name == "Zet")
			{
				std::cout << "Takie skarbeñki tu mamy. Na pewno któryœ ci siê spodoba!" << std::endl;
			}
			else
			{
				std::cout << "Tylko nie zniszcz." << std::endl;
			}
		}

		for (int i = 0; i < 6; i++) //koszt
		{
			armory[i].ar_cost = 10 * (armory[i].armor_stats[0] + armory[i].armor_stats[1] + armory[i].armor_stats[2] + armory[i].armor_stats[3] + armory[i].armor_stats[4] + armory[i].armor_stats[5] + seller);
		}

		for (int i = 0; i < 6; i += 2) //wypisywanie nazwy
		{
			std::cout << "Nazwa:        " << i + 1 << ". " << armory[i].armor_name << "\t\t\t\t" << armory[i + 1].armor_name << std::endl;
			std::cout << "Si³a:         " << armory[i].armor_stats[0] << "\t\t\t\t" << armory[i + 1].armor_stats[0] << std::endl;
			std::cout << "Wytrzyma³oœæ: " << armory[i].armor_stats[1] << "\t\t\t\t" << armory[i + 1].armor_stats[1] << std::endl;
			std::cout << "Charyzma:     " << armory[i].armor_stats[2] << "\t\t\t\t" << armory[i + 1].armor_stats[2] << std::endl;
			std::cout << "Inteligencja: " << armory[i].armor_stats[3] << "\t\t\t\t" << armory[i + 1].armor_stats[3] << std::endl;
			std::cout << "Zwinnoœæ:     " << armory[i].armor_stats[4] << "\t\t\t\t" << armory[i + 1].armor_stats[4] << std::endl;
			std::cout << "Szczêœcie:    " << armory[i].armor_stats[5] << "\t\t\t\t" << armory[i + 1].armor_stats[5] << std::endl;
			std::cout << "Koszt:        " << armory[i].ar_cost        << "\t\t\t\t" << armory[i + 1].ar_cost << std::endl;
		}
		std::cout << "Co kupujesz? ('6' - nie kupujê)" << std::endl;
		std::cin >> nr_choice;
		if (nr_choice > 0 && nr_choice <= 6)
		{
			agreement = pay(armory[nr_choice - 1].ar_cost, player);
			if (agreement == 1)
			{
				// danie do plecaka przedmiotu ------------------------------------------------------------------------//

			}
		}
		else
		{
			std::cout << "..." << std::endl;
		}
	}
	else if (npc_type == 'H') //handlarz
	{
		bool not_cake= true;
		Equipment special_thing;

		if (not_cake = true)
		{
			special_thing.eq_name = "special";
		}
		else
		{
			special_thing.eq_name = "ciasto";
		}
		special_thing.usage(player);

		std::cout << "Jest to jedyna taka okazja, lepszej nie bêdzie!" << std::endl;
		special_thing.eq_cost = 1001;
		std::cout << "Nazwa: " << special_thing.eq_name << std::endl;
		std::cout << "Koszt: " << special_thing.eq_cost << std::endl;
		std::cout << "Kupujesz? ('1'-tak, reszta - nie)" << std::endl;
		std::cin >> nr_choice;
		if (nr_choice == 1)
		{
			agreement = pay(special_thing.eq_cost, player);
			if (agreement == true)
			{
				// danie do plecaka przedmiotu ------------------------------------------------------------------------//

				not_cake = false;
			}
		}
		else
		{
			std::cout << "Nie martw siê, bêdzie to na ciebie czekaæ, a¿ kiedyœ kupisz." << std::endl;
		}
	}
	else if (npc_type == 'K') //kowal
	{
		Weapon weaps[6];
		for (int i = 0; i < 6; i++)
		{
			weaps[0].weapon_statistics_name(player);
		}

		if (npc_name == "Kowal Gregori")
		{
			std::cout << "Wygl¹dasz jak " << player->GetProffesionName() << ". Masz, takie rzeczy s¹ dla takich jak ty." << std::endl;
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << "Tyœ jest ten, no... " << player->GetProffesionName() << "! To dla ciebie." << std::endl;
		}
	
		for (int i = 0; i < 6; i++) //koszt
		{
			weaps[i].we_cost = 10 * (weaps[i].weapon_stats[0] + weaps[i].weapon_stats[1] + weaps[i].weapon_stats[2] + weaps[i].weapon_stats[3] + weaps[i].weapon_stats[4] + weaps[i].weapon_stats[5] + seller);
		}

		for (int i = 0; i < 6; i+=2) //wypisanie
		{
			std::cout << "Nazwa:        " << i + 1 << ". " << weaps[i].we_name << "\t\t\t\t" << weaps[i + 1].we_name << std::endl;
			std::cout << "Si³a:         " << weaps[i].weapon_stats[0] << "\t\t\t\t" << weaps[i + 1].weapon_stats[0] << std::endl;
			std::cout << "Wytrzyma³oœæ: " << weaps[i].weapon_stats[1] << "\t\t\t\t" << weaps[i + 1].weapon_stats[1] << std::endl;
			std::cout << "Charyzma:     " << weaps[i].weapon_stats[2] << "\t\t\t\t" << weaps[i + 1].weapon_stats[2] << std::endl;
			std::cout << "Inteligencja: " << weaps[i].weapon_stats[3] << "\t\t\t\t" << weaps[i + 1].weapon_stats[3] << std::endl;
			std::cout << "Zwinnoœæ:     " << weaps[i].weapon_stats[4] << "\t\t\t\t" << weaps[i + 1].weapon_stats[4] << std::endl;
			std::cout << "Szczêœcie:    " << weaps[i].weapon_stats[5] << "\t\t\t\t" << weaps[i + 1].weapon_stats[5] << std::endl;
			std::cout << "Koszt:        " << weaps[i].we_cost		   << "\t\t\t\t" << weaps[i + 1].we_cost << std::endl;


		}

		std::cout << "Kupujesz coœ? ('6' - nie kupujê)" << std::endl;
		std::cin >> nr_choice;
		if (nr_choice > 0 && nr_choice <= 6)
		{
			agreement = pay(weaps[nr_choice - 1].we_cost, player);
			if (agreement == true)
			{
				// danie do plecaka przedmiotu ------------------------------------------------------------------------//

			}
		}
		else
		{
			std::cout << "I po co to wyci¹ga³em?!" << std::endl;
		}
	}
	//potrzebny plecak
}


void Non_Character::repair(Character* player)
{
	int przelicznik_ceny = 1, choice_armor;
	float rep_cost;
	Armor thing1; //-------------------------------------------------|| odwo³ywaæ siê powinno do za³o¿onej czêœci zbroi, nie wiem, jak zrobiæ
	if (1 - thing1.defending() > 0)
		rep_cost = przelicznik_ceny* 100 * (1 - thing1.defending()) - przelicznik_ceny * log10(1 - thing1.defending());
	else
		rep_cost = przelicznik_ceny * (1 - thing1.defending()) + przelicznik_ceny;
		
	std::cout << "1. Helm" << std::endl;
	std::cout << "2. Napiersnik" << std::endl;
	std::cout << "3. Buty" << std::endl;
	std::cin >> choice_armor;
	std::cout << "Koszt naprawy to: ";
	switch (choice_armor)
	{
	case 1:  //dla helmu ------------------------------------------|| aktualnie ni ma ró¿nicy. Trzeba zrobiæ, by wybiera³o jeden z przedmiotów
		std::cout << rep_cost;
		if (pay(rep_cost, player) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		else break;
	case 2://dla Napierœnika
		std::cout << rep_cost;
		if (pay(rep_cost, player) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		else break;
	case 3: //dla Butów
		std::cout << rep_cost;
		if (pay(rep_cost, player) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		break;
	default:
		std::cout << "Cos nie pyklo, nie ma pan takiej zbroi";
		break;
	}

}

bool Non_Character::pay(int cost, Character* player)
{
	char paying_choice = 'o';
	bool number = false;

	std::cout << "Placisz? (y/n)" << std::endl;
	while (paying_choice != 'y' && paying_choice != 'n')
	{
		if (number == 1) std::cout << "To znaczy tak, czy nie? Nie rozumiem... (y/n)" << std::endl;
		std::cin >> paying_choice;
		number = true;
	}

	switch (paying_choice)
	{
	case 'y':
		if (player->getGold() < cost)
		{
			std::cout << "Chyba nie masz czym zap³aciæ. Wróæ, gdy uzbierasz nieco drobnych" << std::endl;
			return false;
		}
		else
		{
			player->lostGold(cost);  //orygina³ golda potrzbny, by go zmieniaæ!
			return true;
		}
	case 'n':
		std::cout << "No có¿..." << std::endl;
		return false;
	}
}

void Non_Character::opening_talk(Character* player) //zrobiæ dialog w zale¿noœci od p³ci bohatera
{

	if (first_time == true)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "Witam, witam!" << (player->GetSex() ? "Pani tu chyba nowa? Nienowa? No nowa Pani tu, nie inaczej!" :
				"Pan tu chyba nowy? Nienowy? No nowy Pan tu, nie inaczej!") << std::endl;
			Sleep(600);
			std::cout << "A czego " << (player->GetSex() ? "Pani" : "Pan") << " potrzebuje? Zió³ek? Broni? Nie? No oczywiscie, ¿e nie!" << std::endl;
			Sleep(400);
			std::cout << "Nie po to " << (player->GetSex() ? "pan przyszed³" : "pani przysz³a") << " akurat do mnie. Czy jednak nie? oczywiœcie!" << std::endl;
			Sleep(400);
			std::cout << "Oczywiœcie, ¿e " << (player->GetSex() ? "Pan chcia³" : "Pani chcia³a") << " przyjœæ tutaj, w moje progi. Oczywiœcie... " << std::endl;
			Sleep(400);
			std::cout << "To jak, o czym " << (player->GetSex() ? "chcia³aby Pani" : "chcia³bym Pan") << " ze mn¹ porozmawiaæ?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || !player->GetSex()))
		{
			std::cout << ".";
			Sleep(1000);
			std::cout << ".";
			Sleep(1000);
			std::cout << "." << std::endl;
			Sleep(1000);
			std::cout << "Dzieñ dobry." << std::endl;
			Sleep(750);
			std::cout << (player->GetSex() ? "Przyjezdna" : "Przyjezdny") << " widzê, nikt têdy nie przeje¿d¿a. Tego jestem pewna." << std::endl;
			Sleep(750);
			std::cout << "Wola³abym, by Pan szybko kupi³ pan szybko to, co chce i odszed³. Nie mam czasu, muszê siê pakowaæ..." << std::endl;
			Sleep(1000);
			std::cout << "Poza tym wygl¹da pan doœæ... nieprzyjaŸnie" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex()))
		{
			std::cout << "Ah... dzieñ dobry. Nazywam siê Beatrycze, ale wiêkszoœæ ludzi mo¿e mi mówiæ Betty" << std::endl;
			Sleep(500);
			std::cout << "Oczywiœcie, równie¿ i ty mo¿esz mnie tak nazywaæ, jeœli tylko wejdziesz do mojego sklepiku." << std::endl;
			Sleep(400);
			std::cout  << "Usi¹dziemy w spokojnym zau³ku, z dala od pojêkiwañ potworów." << std::endl;
			Sleep(600);
			std::cout << "Porozmawiamy sobie przy herbatce." << std::endl;
			Sleep(600);
			std::cout << "Proszê, nie zwracaj wiêkszej uwagi na ba³agan, w³aœnie siê pakujê." << std::endl;
			Sleep(600);
			std::cout << "To miejsce staje siê gorsze z dnia na dzieñ, czujê, ¿e muszê wyjechaæ." << std::endl;
			Sleep(600);
			std::cout << "A tak poza tym..." << std::endl;
			Sleep(500);
			std::cout << "zosta³o mi jeszcze kilkanaœcie eliksirów. Mogê ci je odsprzedaæ za ni¿sz¹ cenê." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori")
		{
			std::cout << "Czego?" << std::endl;
			Sleep(300);
			std::cout << "..." << std::endl;
			Sleep(1250);
			std::cout << "Jeœli chcesz broñ, to trzeba by³o gadaæ!" << std::endl;
			Sleep(400);
			std::cout << "*pod nosem* Ah, ci aroganccy poszukiwacze guzów i nieszczêœcia" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << "Czego?!" << std::endl;
			Sleep(800);
			std::cout << "Nie przeszkadzaæ, zajêty jestem!" << std::endl;
			Sleep(700);
			std::cout << "A, chcesz naprawiæ zbrojê. To dawaj!" << std::endl;
			Sleep(500);
			std::cout << "..." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << "Oh, witam przybysza. Sk¹d " << (player->GetSex() ? "Pani przyby³a" : "Pan przyby³") << "?" << std::endl;
			Sleep(400);
			std::cout << "Na pewno z daleka, taka cera nie bierze siê z nik¹d." << std::endl;
			Sleep(400);
			std::cout << "Có¿ takiego robi " << (player->GetSex() ? "Pani" : "Pan") << " w naszych skromnych, aktualnie doœæ nieprzyjemnych progach?" << std::endl;
			Sleep(400);
			std::cout << "Mo¿e " << (player->GetSex() ? "chcia³aby pani" : "chcia³by pan") <<" byæ naszym wybawc¹ i zniszczyæ te okropne stwory, szwêdaj¹ce siê wszêdzie po okolicy?" << std::endl;
			Sleep(400);
			std::cout << "Wiem, co takiej osobie jak " << (player->GetSex() ? "Pani" : "Pan") << " mo¿e siê przydaæ, proszê za mn¹ do sklepu!" << std::endl;
			Sleep(600);
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "O, klient! Zapraszam! Nieczêsto zdarza mi siê ostatnio mieæ kogokolwiek," << std::endl;
			std::cout << "dlatego mam doœæ du¿o produków na zbyciu." << std::endl;
			Sleep(600);
			std::cout << "Do wyboru do koloru, wed³ug uznania i preferencji." << std::endl;
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz2")
		{
			std::cout << "..." << std::endl;
			Sleep(700);
			std::cout << "..." << std::endl;
			Sleep(500);
			std::cout << "..." << std::endl;
			Sleep(300);
		}
		else if (npc_name == "Zbrojmistrz3")
		{
			std::cout << "Co?" << std::endl;
			Sleep(500);
			std::cout << "A tak, tak... dzieñ dobry." << std::endl;
			Sleep(500);
			std::cout << "W czym mogê pomóc?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Oktis") 
		{
			std::cout << "Czaaaapki, kapelusze, he³mym, bereeetyyy!" << std::endl;
			Sleep(600);
			std::cout << "Ceny niskie i coœ na g³owê, same zleeetyyy!" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz5") 
		{
			std::cout << "Bluuuzy, kurtki, zbrooooje!" << std::endl;
			Sleep(600);
			std::cout << "Mam tu wszyyystkie modne stroje!" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz6") 
		{
			std::cout << "Stopy go³e, có¿ pomo¿e?" << std::endl;
			Sleep(600);
			std::cout << "A me butki! A to mo¿e!" << std::endl;
			Sleep(500);
		}

		first_time = false;
	}
	else if (first_time == false)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "Witam ponownie! Jak tam sie korzysta³o z moich wyrobów? Dobrze?" << std::endl;
			Sleep(400);
			std::cout << "No oczywiœcie, ¿e Dobrze! Wybornie! To jak, " << (player->GetSex() ? "przysz³a Pani" : "przyszed³ Pan") << " po wiêcej, prawda?" << std::endl;
			Sleep(400);
			std::cout << "Jak¿e by inaczej! Nieinaczej? No oczywiœcie..." << std::endl;
			Sleep(500);
			std::cout << "Porozmawiajmy wiêc o interesach." << std::endl;
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || !player->GetSex() || player->GetStats().getByEnum(Charisma) < 30))
		{
			std::cout << "To ponownie " << (player->GetSex() ? "Pani" : "Pan") << "..." << std::endl;
			Sleep(1250);
			std::cout << "Proszê wejœæ i wzi¹æ to, co jest " << (player->GetSex() ? "Pani" : "Panu") << " potrzebne." << std::endl;
			Sleep(500);
			std::cout << "Byle szybko, zajêta jestem, nie widaæ?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || !player->GetSex() || player->GetStats().getByEnum(Charisma) >= 30))
		{
			std::cout << "Witam ponownie! Osobiœcie - spodziewa³am siê, ¿e jeszcze ciê zobaczê," << std::endl;
			Sleep(400);
			std::cout << "ale, dziêki Bogu, uda³o ci siê prze¿yæ w tym okropnym miejscu." << std::endl;
			Sleep(700);
			std::cout << "Proszê, wejdŸ, jeszze nie skoñczy³am siê pakowaæ, wiêc mo¿esz siê rozgoœciæ." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")
		{
			std::cout << "A, to ty..." << std::endl << "Popatrz se i mów, czego chcesz." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << "Dzieñ dobry, co tym razem " << (player->GetSex() ? "chcia³aby pani" : "chcia³by Pan") << " kupiæ? Osobiœcie poleci³bym ciasto." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "Zapraszam!..." << std::endl;
			Sleep(1000);
			std::cout << "Kojarzê " << (player->GetSex() ? "Pani¹" : "Pana") << " i cieszê siê, ¿e jest " <<
				(player->GetSex() ? "Pani zainsteresowana" : "Pan zainteresowany") << "moimi ofertami!" << std::endl;
			Sleep(500);
			std::cout << "S³ucham, czego " << (player->GetSex() ? "Pani" : "Pan") << " szuka? W czym mogê pomóc?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz2") 
		{
			std::cout << "..." << std::endl;
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz3") 
		{
			std::cout << "..." << std::endl;
			Sleep(500);
			std::cout << "o... witam ponownie, nie zauwa¿y³em " << (player->GetSex() ? "Pani." : "Pana.") << std::endl;
			Sleep(900);
			std::cout << "W czym pomóc?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Oktis")
		{
			std::cout << "Czaaaapki, kapelusze, he³mym, bereeetyyy!" << std::endl;
			Sleep(600);
			std::cout << "Ceny niskie, coœ na g³owê - same zleeetyyy!" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz5") 
		{
			std::cout << "Bluuuzy, kurtki, zbrooooje!" << std::endl;
			Sleep(600);
			std::cout << "Mam tu wszyyystkie modne stroje!" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz6")
		{
			std::cout << "Stopy go³e - có¿ pomo¿e?" << std::endl;
			Sleep(600);
			std::cout << "A me butki! A to mo¿e!" << std::endl;
			Sleep(500);
		}
	}
	else
	{
		std::cout << "Popsuted dzieñ dobry." << std::endl;
		Sleep(300);
	}

}

void Non_Character::talk(Character* player)
{
	if (player->GetStats().getByEnum(Charisma) < 25)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "No wiesz, kiedyœ to tu by³o ³adne miasteczko, du¿o zieleni tu by³o," << std::endl;
			std::cout << "ale potwory siê zjawi³y i wszystko zniszczy³y..." << std::endl;
			Sleep(700);
			std::cout << "Oczywiœcie nie ma ju¿ ani miasteczka, ani tym bardziej spokojnej okolicy..." << std::endl;
			std::cout << "Chyba ¿e ktoœ by siê pozby³, wyr¹ba³ w pieñ wszystkie te monstra." << std::endl;
			Sleep(800);
			std::cout << "O tak, nie inaczej. Dok³adnie tak, no bo jak? Hm..." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex()))
		{
			std::cout << "Oj nie wiem, nie wiem, czy ci opowiem." << std::endl;
			Sleep(400);
			std::cout << "Przekonaj mnie jakoœ do tego, mo¿e dowiesz siê du¿o wiêcej o tym i o owym." << std::endl;
			Sleep(400);
			std::cout << "Bo tak, to mogê tylko powiedzieæ, ¿e wszystko zaczê³o siê o tam," << std::endl;
			std::cout << "w tamtym klasztorze. Podobno w³aœnie z tamt¹d wype³z³y te wszystkie monstra." << std::endl;
			Sleep(500);
			std::cout << "Co jednak by³o tego przyczyn¹, tego nie wiem." << std::endl;
			Sleep(500);
			std::cout << "Wiem za to, ¿e w tym miejscu nie czeka mnie nic dobrego," << std::endl;
			std::cout << "wiêc aktualnie siê pakujê, by wyjechaæ i nigdy tu nie wracaæ." << std::endl;
			Sleep(600);
			std::cout << "Widzê jednak, ¿e ty przyby³eœ tu z jakiegoœ powodu." << std::endl;
			Sleep(500);
			std::cout << "Mo¿e teraz twoja kolej opowiadania historyjek. Opowiesz mi coœ o sobie, co nie?" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || !player->GetSex()))
		{
			std::cout << "Chyba œnisz, jeœli myœlisz, ¿e ci coœ opowiem." << std::endl;
			Sleep(400);
			std::cout << "To, ¿e tu przyby³eœ i nagle wybijasz jakieœ potworki s³absze, mocniejsze, nic nie zmienia." << std::endl;
			Sleep(600);
			std::cout << "Aktualnie ciê¿ko mi jest na ciebie patrzeæ, a co dopiero co ciebie gadaæ." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Kowal Gregori")
		{
			std::cout << "Nie wiem, co siê sta³o, ani kiedy," << std::endl;
			std::cout << "ale za to doskonale zdajê sobie sprawê z tego," << std::endl;
			std::cout << "¿e ludzie tacy jak ty przyje¿d¿aj¹ tu, kupuj¹ ode mnie broñ i umieraj¹." << std::endl;
			Sleep(1000);
			std::cout << "Zarabiam nie ma³o, wiêcej mnie nie obchodzi" << std::endl;
			Sleep(500);
			std::cout << "...No mo¿e poza t¹, no... jak jej by³o..." << std::endl;
			Sleep(700);
			std::cout << "No taka mniszka z tego klasztoru niedaleko." << std::endl;
			Sleep(500);
			std::cout << "Ona to podobno, gdy wraca³a do klasztoru, to cuda siê dzia³y." << std::endl;
			Sleep(700);
			std::cout << "Jednak nikt jej nie widzia³ od wielu lat." << std::endl;
			Sleep(600);
			std::cout << "Mo¿e zmar³a lub jakiœ barbarzyñca zabi³ j¹." << std::endl;
			Sleep(400);
			std::cout << "Tego nie wiem, ale jeœli bym j¹ spotka³, to mo¿e w koñcu..." << std::endl;
			Sleep(700);
			std::cout << "Cholibka, wygada³em siê... Wiêcej nie powiem!" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << "..." << std::endl;
			Sleep(600);
			std::cout << "A idŸ se w pieruny!" << std::endl;
			Sleep(500);
			std::cout << "Nie nie wiem, nic nie powiem." << std::endl;
			Sleep(500);
			std::cout << "A nawet gdybym wiedzia³, to i tak bym nie powiedzia³." << std::endl;
			Sleep(600);
			std::cout << "Jeœli chcesz czegoœ innego ode mnie, to mów, jeœli nie - odejdŸ." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << "Tak¹ bym ci historiê opowiedzia³. Tak¹ hisoriê, ja ci mówiê," << std::endl;
			std::cout << "jednak nie wydajesz mi siê godnym s³uchaczem." << std::endl;
			Sleep(600);
			std::cout << "W zamian powiem ci jedn¹ rzecz..." << std::endl;
			Sleep(700);
			std::cout << "..." << std::endl;
			Sleep(700);
			std::cout << "Kup coœ ode mnie." << std::endl;
			Sleep(700);
			std::cout << "Aktualnie jesteœ moim jedynym potencjalnym klientem," << std::endl;
			std::cout << "bo reszta albo uciek³a, albo zginê³a." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "Oh, za informacjê równie¿ trzeba zap³aciæ i raczej w¹tpiê," << std::endl;
			std::cout << "by by³o ciê na to staæ. Ceniê siê." << std::endl;
			Sleep(400);
			std::cout << "Jednak w tajemnicy powiem ci, ¿e od momentu przybycia do tego miejsca pewnej osoby," << std::endl;
			std::cout << "od wtedy w³aœnie w tej krainie zaczê³y siê dziaæ z³e rzeczy." << std::endl;
			Sleep(900);
			std::cout << "Wiem, ¿e to ci nic nie mówi, ale na wiêcej informacji to musisz mocniej zapracowaæ." << std::endl;
			Sleep(600);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz2")
		{
		std::cout << "..." << std::endl;
		std::cout << "..." << std::endl;
		Sleep(1000);
		Sleep(1000);
		std::cout << "Nie." << std::endl;
		std::cout << "Nie." << std::endl;
		Sleep(1000);
		Sleep(1000);
		system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz3")
		{
			std::cout << "A tak, historia... historia tego miejsca..." << std::endl;
			Sleep(1000);
			std::cout << "Mia³em gdzieœ o tym ksi¹¿kê... proszêzaczekaæ..." << std::endl;
			Sleep(1000);
			std::cout << "Gdzie ona jest, gdzie ja j¹ trzepn¹³em?" << std::endl;
			Sleep(1000);
			std::cout << "..." << std::endl;
			Sleep(600);
			std::cout << "Przykro mi, nie mogê znaleŸæ, proszê przyjœæ póŸniej." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Oktis")
		{
			std::cout << "Hej, Zet, wiemy coœ o tym miejsc?" << std::endl;
			Sleep(600);
			std::cout << "Dla tego pana nic nie wemy." << std::endl;
			Sleep(300);
			std::cout << "Okey." << std::endl;
			Sleep(500);
			std::cout << "Przykro mi, jesteœmy tu tylko przyjezdnymi kupcami" << std::endl;
			Sleep(600);
			std::cout << "Nie mamy praktycznie ¿adnych informacji na temat" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz5")
		{
			std::cout << "Hej, Zet, wiemy coœ o tym miejsc?" << std::endl;
			Sleep(600);
			std::cout << "Dla tego pana nic nie wemy." << std::endl;
			Sleep(300);
			std::cout << "Okey." << std::endl;
			Sleep(500);
			std::cout << "Przykro mi, jesteœmy tu tylko przyjezdnymi kupcami" << std::endl;
			Sleep(600);
			std::cout << "Nie mamy praktycznie ¿adnych informacji na temat" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz6")
		{
			std::cout << "Hm..." << std::endl;
			Sleep(1000);
			std::cout << "Hej, co o tym s¹dzicie? Powiedzieæ mu coœ?" << std::endl;
			Sleep(700);
			std::cout << "Nie... przykro mi, jesteœmy tu tylko przyjezdnymi kupcami" << std::endl;
			Sleep(600);
			std::cout << "Nie mamy praktycznie ¿adnych informacji na temat" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
	}
	else if(player->GetStats().getByEnum(Charisma) >= 25)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "No, no có¿ mogê powiedzieæ. Nie wiem zbyt wiele." << std::endl;
			Sleep(600);
			std::cout << "Kiedyœ to tu by³o tu ³adne miasteczko, du¿o zieleni tu by³o, kwietki ros³y," << std::endl;
			std::cout << "ptaki œpiewa³y, ale potwory siê zjawi³y i wszystko zniszczy³y..." << std::endl;
			Sleep(700);
			std::cout << "Oczywiœcie nie ma ju¿ ani miasteczka, ani tym bardziej spokojnej okolicy..." << std::endl;
			Sleep(600);
			std::cout << "A pomyœleæ, ¿e kiedyœ kiedyœ, to nawet pogoda siê do ludzi tutaj dostosowywa³a." << std::endl;
			Sleep(600);
			std::cout << "Plony by³y obfite, kraina prosperowa³a... ja ju¿ nie znam tych czasów," << std::endl;
			std::cout << "ale powiem ci skrycie, ¿e podobno nawet pory roku zmienia³y siê tak," << std::endl;
			std::cout << "by ludziom ¿y³o siê jak najlepiej i najbardziej dosttnie." << std::endl;
			Sleep(1200);
			std::cout << "Teraz wszystko jest zniszczone, a ziemiê tê skazi³y potwory." << std::endl;
			Sleep(700);
			std::cout << "dybym ne by³ ju¿ stary, to pewnie bym myœla³ o przeprowadzce, ale aktualnie nie mam si³y tego robiæ." << std::endl;
			Sleep(800);
			std::cout << "Ale mo¿e kiedyœ komuœ uda³oby siê  zniszczyæ te potwory i ocaliæ tê krainê..." << std::endl;
			Sleep(600);
			std::cout << "W koñcu tylu dzielnych podró¿ników zewsz¹d tu przyje¿d¿a..." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false))
		{
			std::cout << "Dobrze! Ju¿, dobrze! Powiem ci coœ..." << std::endl;
			Sleep(600);
			std::cout << "Widzisz ten klasztor? To w³asnie tam podobno siê to wszystko zaczê³o." << std::endl;
			Sleep(400);
			std::cout << "W³aœnie z tamt¹d na pocz¹tku wypêz³y te wszystkie maszkary, które teraz nawiedzaj¹ te ziemie." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false))
		{
			std::cout << "Myœlê, ¿e mogê ci zaufaæ i opowiedzieæ ci coœ wiêcej ni¿ wiêkszoœci ludzi..." << std::endl;
			Sleep(500);
			std::cout << "Wiêkszoœæ osi³ów czy têpaków, którzy tu przybyli nie byli godni s³yszeæ ode mnie czegokolwiek." << std::endl;
			Sleep(700);
			std::cout << "Tu siê dziej¹ z³e rzeczy. Wszyscy ludzie, którzy tu przybywali ostatnio (równie¿ ty trochê tak wygl¹dasz)," << std::endl;
			std::cout << "Mieli jakiegoœ chopla na punkcie wejœcia do klasztoru. Poza tym widzê na nich objawy jakiejœ magii, czy czegoœ takiego..." << std::endl;
			Sleep(1200);
			std::cout << "Tak jakby im siê troszkê oczy zmienia³y nienaturalnie, rêce im dr¿¹ nawet, gdy w spokoju rozmawiaj¹." << std::endl;
			Sleep(700);
			std::cout << "Obawiam siê, ¿e to, co mo¿e znajdowaæ siê w œrodku klasztoru nie jest warte tego wszystkiego." << std::endl;
			Sleep(900);
			std::cout << "Patrz, czy ktoœ ciê nie obserwuje, czy ktoœ ciê nie œledzi." << std::endl;
			Sleep(1000);
			std::cout << "Mam przeczuciê, ¿e to wszystko mo¿e Ÿle siê dla ciebie skoñczyæ, wiêc uwa¿aj na siebie..." << std::endl;
			Sleep(900);
			std::cout << "Poza tym ten klasztor by³ miejscem, z którego ca³e to z³o zaczê³o, wiêc spodziewaj siê niespodziewanego w œrodku." << std::endl;
			Sleep(1000);
			std::cout << "..." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Kowal Gregori")
		{
			std::cout << "Nie wiem, co siê sta³o, ani kiedy," << std::endl;
			std::cout << "ale za to doskonale zdajê sobie sprawê z tego," << std::endl;
			std::cout << "¿e ludzie tacy jak ty przyje¿d¿aj¹ tu, kupuj¹ ode mnie broñ i umieraj¹." << std::endl;
			Sleep(1000);
			std::cout << "Zarabiam nie ma³o, wiêcej mnie nie obchodzi" << std::endl;
			Sleep(500);
			std::cout << "...No mo¿e poza t¹, no... jak jej by³o..." << std::endl;
			Sleep(700);
			std::cout << "No taka mniszka z tego klasztoru niedaleko." << std::endl;
			Sleep(500);
			std::cout << "Ona to podobno, gdy wraca³a do klasztoru, to cuda siê dzia³y." << std::endl;
			Sleep(700);
			std::cout << "Jednak nikt jej nie widzia³ od wielu lat." << std::endl;
			Sleep(600);
			std::cout << "Mo¿e zmar³a lub jakiœ barbarzyñca zabi³ j¹." << std::endl;
			Sleep(400);
			std::cout << "Tego nie wiem, ale jeœli bym j¹ spotka³, to mo¿e w koñcu uda³oby mi siê spotkaæ kogoœ dla mnie." << std::endl;
			Sleep(700);
			std::cout << "W koñcu cuda siê zdarzaj¹..." << std::endl;
			Sleep(600);
			std::cout << "Sam jednak do klsztoru nie wejdê, jakiœ szaleniec go strze¿e." << std::endl;
			Sleep(500);
			std::cout << "Przejœæ ko³o niego siê nie da, a jeœli chcia³byœ siê zakraœæ, to nic to nie da." << std::endl;
			Sleep(600);
			std::cout << "Ten cz³owiek jest opêtany, wyczuje ciê, jeœli tylko zbli¿ysz siê do klasztoru." << std::endl;
			Sleep(400);
			std::cout << "Gadanie z nim te¿ nic nie daje, wiêc nie polecam tej strategii." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Kowal Andrzej")
		{

			std::cout << "A idŸ se w pieruny! " << std::endl;
			Sleep(600);
			std::cout << "Jedyne co wiem, to to, ¿e ten pobliski klasztor nazywa siê Suuomo i to," << std::endl;
			std::cout << " ¿e mieszka³a w nim niedyœ bardzo m¹dra kobieta, dziêki której ludziom ¿y³o siê ³atwiej." << std::endl;
			Sleep(600);
			std::cout << "Jednak teraz jej ju¿ nie ma, pewnie umar³a ze staroœci, w koñcu tyle lat minê³o." << std::endl;
			Sleep(600);
			std::cout << "Ostatni¹ rzecz¹ jak¹ jednak wiem i to doskonale to to, ¿e mnie denerwujesz." << std::endl;
			Sleep(800);
			std::cout << "Przestañ mnie wypytywaæ o dziwne rzeczy!" << std::endl;
			Sleep(600);
			system("PAUSE");
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << "Ale¿ oczywiœcie, ¿e ci opowiem, bo jakbym móg³ nie opowiedzieæ!" << std::endl;
			Sleep(1000);
			std::cout << "Wiêc... to zaczê³o sto piêædziesi¹t lat temu, za mojego pra pra dziadka." << std::endl;
			std::cout << "Nazywa³ siê on Jackob i by³ z³odziejaszkiem." << std::endl;
			Sleep(1000);
			std::cout << "Nie by³ on zwyk³ym z³odziejaszkiem, on nie." << std::endl;
			std::cout << "On by³ koniokradem. Najznakomitszym koniokradem w okolicy Gralaronu." << std::endl;
			Sleep(1000);
			std::cout << "Choæ mo¿liwe jest i to, ¿e mój dziadek przekrêci³ nazwê miejscowoœci," << std::endl;
			std::cout << "bo on to nigdy nie mia³ g³owy do imion i nazw." << std::endl;
			Sleep(1000);
			std::cout << "On to jednak by³ podró¿nikiem, choæ do Galaronu nigdy nie dojecha³." << std::endl;
			std::cout << "Nie wiesz gdzie to? ja te¿ nie, ale podobno bardzo daleko." << std::endl;
			Sleep(1000);
			std::cout << "¯y³ on w zwyk³ej wiosce... a ta wioska by³a ma³a, malusieñka." << std::endl;
			std::cout << "I ¿y³o mu siê tam bardzo wygodnie i wiód³ zwyk³e ¿ycie koniokrada." << std::endl;
			Sleep(1000);
			std::cout << "A ludzie go nie znosili. W koñcu by³ koniokradem," << std::endl;
			std::cout << "a tak to ju¿ z koniokradami bywa, ¿e ludzi ich nie znosz¹." << std::endl;
			Sleep(1000);
			std::cout << "Dlatego te¿ mój pra pra dziadek Jackob zamieszka³ na odludziu," << std::endl;
			std::cout << "bo tam nikomu siê nie chcia³o go wyzywaæ od z³odziei." << std::endl;
			Sleep(1000);
			std::cout << "A pewnego poranka, to ja ci powiem szczerze..." << std::endl;
			std::cout << "No oczywiœcie, ¿e szczerze ci powiem, ¿e jednak jedna dziewczyna" << std::endl;
			Sleep(1000);
			std::cout << "na takie odludzie siê zapuœci³a, wiêc odludziem siê ju¿ to nazywaæ nie mog³o." << std::endl;
			std::cout << "I, ja ci powiem, okaza³o siê, ¿e ona te¿ jest koniokradem" << std::endl;
			Sleep(1000);
			std::cout << "i ukrad³¹ mojemu pra pra dziadkowi jego konie," << std::endl;
			std::cout << "ale on to widzia³ i ukradkiem, jak taki ninja, bo jak¿e by inaczej," << std::endl;
			Sleep(1000);
			std::cout << "szed³ za ni¹, a ona go nie widzia³a. Tak to by³o? ...Oczywiœcie!" << std::endl;
			std::cout << "Noc¹ odbi³ swe ukradzione przez niego kiedyœ konie" << std::endl;
			Sleep(1000);
			std::cout << "i wróci³ na swe nieodludziowe odludzie." << std::endl;
			std::cout << "Ta kobieta jednak nie dawa³a za wygran¹ i krad³a co chwilê te konie," << std::endl;
			Sleep(1000);
			std::cout << "a mój pra pra dziadek je krad³ spowrotem." << std::endl;
			std::cout << "Zwierzaki tak siê do tego przyzwyczai³y," << std::endl;
			Sleep(1000);
			std::cout << "¿e zaczê³y to traktowaæ jako swoisty spacerek i prycha³y z radoœci¹," << std::endl;
			std::cout << "gdy to widzia³y raz j¹, raz jego." << std::endl;
			Sleep(1000);
			std::cout << "W koñ... cu tak siê i oni ze sob¹ z¿yli, ¿e a¿ siê pobrali," << std::endl;
			std::cout << "a ludzi w œwi¹tyni by³o z piêædziesiêciu" << std::endl;
			Sleep(1000);
			std::cout << "i po³owa z nich, to byli ci," << std::endl;
			std::cout << "którym te konie na samym pocz¹tku ukradziono." << std::endl;
			Sleep(1000);
			std::cout << "Drug¹ po³ow¹ byli ich prawnicy i kap³an." << std::endl;
			std::cout << "Tak wiêc mój pra pra dziadek - Jackob konikrad -" << std::endl;
			Sleep(1000);
			std::cout << "- o¿eni³ siê z moj¹ pra pra babk¹ - Ameli¹..." << std::endl;
			std::cout << "równie¿ o psêdonimie konikrad... Mieli trójkê dzieci, w tym mojego dziadka..." << std::endl;
			Sleep(1000);
			std::cout << "A propos mojego pra dziadka, to zgadnij jak mia³ on na imiê..." << std::endl;
			Sleep(600);
			system("PAUSE");
			std::cout << "Jackob, a sta³o siê tak dlatego, ¿e mój pra pra dziadek zapomnia³," << std::endl;
			std::cout << "jakie imiê mu wczeœniej wybra³ wraz z ¿on¹" << std::endl;
			Sleep(1000);
			std::cout << "i spanikowawszy opwiedzia³ podczas chrztu <<Jackob>>." << std::endl;
			std::cout << "Jednak wszyscy mówili do niego po prostu junior," << std::endl;
			Sleep(1000);
			std::cout << "by rozró¿niæ, kiedy mowa o synu, a kiedy o ojcu," << std::endl;
			std::cout << "bo mój pra pra dziadek, tak jak ju¿ mówi³em," << std::endl;
			Sleep(1000);
			std::cout << "te¿ nazywa³ siê Jackob. Co ciekawe lub niekoniecznie," << std::endl;
			std::cout << "ale wydaje mi siê, ¿e i owszem - mój dziadek te¿ nazywa³ siê Jackob," << std::endl;
			Sleep(1000);
			std::cout << "ale to historia nie na ten wieczór, oj nie..." << std::endl;
			std::cout << "A mo¿e? Niee... Tak czy inaczej, st¹d w³aœnie powsta³o moje nazwisko..." << std::endl;
			Sleep(1000);
			std::cout << "Jackobson, bo Ka¿dy Jackob w rodzinie by³ synem innego Jackoba," << std::endl;
			std::cout << "a ka¿dy Jackob by³ ojecem kolejnego Jackoba. I tak ma rodzina ustanowi³a," << std::endl;
			Sleep(1000);
			std::cout << "¿e pierwszy syn z rodu bêdzie mia³ na imiê Jackob," << std::endl;
			std::cout << "by podtrzymaæ rodzinn¹ tradycjê. Oczywiœcie nie chciano," << std::endl;
			Sleep(1000);
			std::cout << "by do ka¿dego pokolenia rodziny przypad³ przydomek koniokrada," << std::endl;
			std::cout << "dlatego te¿ mój pra pra dziadek Jackob wraz z moj¹ pra pra babk¹ Ameli¹" << std::endl;
			Sleep(1000);
			std::cout << "porzucili swój z³y zawód, gdy urodzi³o im siê drugie dziecko" << std::endl;
			std::cout << "i sprzedali wiêkszoœæ z koni za bezcen, górê z³ota, ja ci powiem." << std::endl;
			Sleep(1000);
			std::cout << "Co ciekawe wiêkszoœæ z nich zosta³o odkupionych przez ludzi," << std::endl;
			std::cout << "którym wiele lat wczeœniej zabrano te konie." << std::endl;
			Sleep(1000);
			std::cout << "Podobno byli tak wœciekli, ale nic zrobiæ nie mogli," << std::endl;
			std::cout << "s¹dy zgadza³y siê, ¿e powinno siê oddaæ tym ludziom ich konie," << std::endl;
			Sleep(1000);
			std::cout << "ale ¿e nikt koni w okolicy nie mia³ (oczywiœcie poza moimi pra pra dziadkami)," << std::endl;
			std::cout << "to gdy uciekali z tymi koñmi, to nie mogli ich dogoniæ," << std::endl;
			Sleep(1000);
			std::cout << "a i konie jakieœ takie weselsze by³y przy moich przodkach" << std::endl;
			std::cout << "ni¿ wyzyskiwane na polach i przy wozach." << std::endl;
			Sleep(1000);
			std::cout << "No wiêc wyjechali z gór¹ pieniêdzy i, no ja ci powiem, bo kto inny," << std::endl;
			std::cout << "stwierdzili, ¿e zostan¹ kupcami, wiêc osiedlili siê w ma³ym miasteczku," << std::endl;
			Sleep(1000);
			std::cout << "no nie uwierzysz, bardzo prosperuj¹cym i uroczym." << std::endl;
			std::cout << "Mo¿e wydawaæ siê to dziwne dla ciebie, ale w³aœnie siê w nim znajdujesz..." << std::endl;
			Sleep(1000);
			std::cout << "a raczej znajdowa³byœ siê, gdyby nie to, ¿e niewiele z niego zosta³o." << std::endl;
			Sleep(600);
			system("PAUSE");
			std::cout << "Ale wracaj¹c do historii, bo w koñcu by³eœ jej ciekaw." << std::endl;
			std::cout << "Za³o¿yli tam sklepik i dobrze im siê wiod³o. lata mija³y, a z³ota przybywa³o." << std::endl;
			Sleep(1000);
			std::cout << "W pewnym momencie mój pra pra dziadek Jackob nie da³ ju¿ jednak rady" << std::endl;
			std::cout << "prowadziæ biznesu, wiêc pa³eczkê po nim przej¹³ Jackob, mój pra dziadek." << std::endl;
			Sleep(1000);
			std::cout << "No i pewnego ranka przechodzi³a iedaleko mieszkania pewna kobieta." << std::endl;
			std::cout << "Z ojca opowiadañ o opowieœciach dziadka, który opowiada³ o czasach pradziadkowych," << std::endl;
			Sleep(1000);
			std::cout << "dowiedzia³em siê, ¿e ona by³a jakœ taka, no w³aœnie ciê¿ko do okreœlenia," << std::endl;
			std::cout << "bo podobno ona wygl¹da³a na tak, mówi¹c szczerze, potwornie oœwiecon¹," << std::endl;
			Sleep(1000);
			std::cout << "a w swej m¹droœci zachwycaj¹c¹, ¿e nie wiadomo by³o," << std::endl;
			std::cout << "czy ona jest stara,czy m³oda," << std::endl;
			Sleep(1000);
			std::cout << "czy ubrana na bia³o, czy nie," << std::endl;
			std::cout << "czy to mo¿e duch by³ jakiœ, taka, nie mogê tego krywaæ, potwornie m¹dra by³a," << std::endl;
			Sleep(1000);
			std::cout << "a w tej m¹droœci ni to tajemnicza, ni to nie," << std::endl;
			std::cout << "czy to przyjazna, czy mo¿e jednak nie." << std::endl;
			Sleep(1000);
			std::cout << "To co jednak mogê powiedzieæ, to to," << std::endl;
			std::cout << "¿e ta kobieta sk³oni³a siê przed moim pradziadkiem na powitanie." << std::endl;
			Sleep(1000);
			std::cout << "On patrz¹c na ni¹ by³ jak g³az - skamienia³ podobno na amen i nie odk³oni³ siê," << std::endl;
			std::cout << "ale to chyba nic, kobieta to nie zwa¿aj¹c na to, jak mówi³ mój ojciec:" << std::endl;
			Sleep(1000);
			std::cout << "<<Uœmiechnê³a siê niczym têcza pojawiaj¹ca siê po bu¿y," << std::endl;
			std::cout << "jak p¹ki kwiatów otwieraj¹ce siê o poranku>>," << std::endl;
			Sleep(1000);
			std::cout << "a podobno tak mój pra dziadek mówi³, a on w poezjê siê nie bawi³." << std::endl;
			std::cout << "Tak czy inaczej po tym spotkaniu minê³o tak kilka dni," << std::endl;
			Sleep(1000);
			std::cout << "a jego ¿ycie zaczê³o siê powodziæ jak nigdy dot¹d." << std::endl;
			std::cout << "Znalaz³ sobie ¿onê, a moj¹ pra babkê Jadwigê," << std::endl;
			Sleep(1000);
			std::cout << "z któr¹ mia³ piêcioro dzieci, a pierwszy syn, mój dziadek," << std::endl;
			std::cout << "tak jak wczeœniej mówi³em, nazywa³ siê Jackob," << std::endl;
			Sleep(1000);
			std::cout << "ale ¿e mój pra dziadek mia³ przydomek junior," << std::endl;
			std::cout << "to Jackob, mój dziadek takiego przydomka ju¿ nie dosta³," << std::endl;
			Sleep(1000);
			std::cout << "by siê ludziom nie myli³o i nie robili g³upich pomy³ek." << std::endl;
			std::cout << "Dlatego te¿ to strego Jackoba nadal nazywali junior," << std::endl;
			Sleep(1000);
			std::cout << "a m³odego po prostu Jackob, co czasami œmieszy³o przejezdnych," << std::endl;
			std::cout << "lecz na to ju¿ nie by³o rady, trzeba by³o siê z tym pogodziæ." << std::endl;
			Sleep(500);
			system("PAUSE");
			std::cout << "Lata mija³y, a miasteczko prosperowa³o," << std::endl;
			std::cout << "nawet pogodê mia³o zawsze tak¹, jak¹ trzeba by³o." << std::endl;
			Sleep(1000);
			std::cout << "Jednak moojemu dziadkowi, Jackobowi by³o nie w smak to, ¿e tu ci¹gle by³o dobrze," << std::endl;
			std::cout << "bo on to by³, ja ci powiem szczerze, bo jak¿e by inaczej, jak nie szczerze," << std::endl;
			Sleep(1000);
			std::cout << "bo na nieszczeroœæ to g³upio jêzyk sobie strzêpiæ, tak wiêc, ja ci powiem," << std::endl;
			std::cout << "ten mój dziadunio to on usiedzieæ w jednym miejscu nie móg³." << std::endl;
			Sleep(1000);
			std::cout << "Dlatego te¿, gdy nieco podrós³, to którejœ nocy poczu³ zew przygody," << std::endl;
			std::cout << "zabra³ nieco w³asnych oszczêdnoœci i, czego potem siê wstydzi³," << std::endl;
			Sleep(1000);
			std::cout << "nieco oszczêdnoœci ojca, trochê ciuchów i jedzenia, oraz" << std::endl;
			std::cout << "niczym jego dziadek, a mój pra pra dziadek, ukrad³ konia," << std::endl;
			Sleep(1000);
			std::cout << "by wyruszyæ w nieznany mu dot¹d, pe³ny niebezpieczeñstw œwiat." << std::endl;
			std::cout << "Nazwa³ prawie od razu swojego konia Sapa, jak taka ryba" << std::endl;
			Sleep(1000);
			std::cout << "i pêdzi³ na jej grzbiecie jak najszybciej i jak najdalej" << std::endl;
			std::cout << "od krainy, która mlekiem i miodem p³ynê³a przez d³ugie lata." << std::endl;
			Sleep(1000);
			std::cout << "No i jecha³ przed siebie, a zapasu rzywnoœci i gotórka ubywa³y," << std::endl;
			std::cout << "co zmusi³o mojego dziadka jackoba do d³u¿szego postoju, by zarobiæ na siebie" << std::endl;
			Sleep(1000);
			std::cout << "i by móc sfinansowaæ sobie dalsz¹ podró¿." << std::endl;
			std::cout << "Oczywiœcie po pewnym czasie nauczy³ siê yæ bez pieniêdzy," << std::endl;
			Sleep(1000);
			std::cout << "ale takie rzeczy to nie od razu siê potrafi." << std::endl;
			std::cout << "No wiesz, sztuka przetrwania w dzikiej puszczy" << std::endl;
			Sleep(1000);
			std::cout << "lub na takich stepach to jest wielki wyczyn," << std::endl;
			std::cout << "a i jeszcze mog¹ ciê napaœæ... A w³aœnie, napaœæ! Oczywiœcie!" << std::endl;
			Sleep(1000);
			std::cout << "Prawie zapomnia³em, dziadek zosta³ przecie¿ na stepach z³apany!" << std::endl;
			std::cout << "Chcieli go zabiæ, ale jedna z tamtejszych kobiet ujrza³¹ w nim mê¿a" << std::endl;
			Sleep(1000);
			std::cout << "i niczym Bulimia w Rondeo, czy jak tam siê nazywali g³ówni bohaterowie" << std::endl;
			std::cout << "doœæ nanego na zachodzie dramatu teatralnego, zakocha³a siê." << std::endl;
			Sleep(1000);
			std::cout << "Teraz pewnie pomyœla³eœ sobie, ¿e mój dziadek siê z ni¹ o¿eni³." << std::endl;
			std::cout << "Muszê ciê jednak zdziwiæ. Jedyne co zrobi³, to noc¹," << std::endl;
			Sleep(1000);
			std::cout << "gdy siê wyswobodzi³ i nie grozi³a mu ju¿ wiêksza krzywda," << std::endl;
			std::cout << "wymkn¹³ siê z namiotu.Jeszcze wyraŸniej wdaj¹c siê w swego dziadka," << std::endl;
			Sleep(1000);
			std::cout << "a mojego pra pra dziadka Jackoba i ukrad³ im wszystkie konie," << std::endl;
			std::cout << "przez co nie mieli go jak œcigaæ, by by³ za szybki," << std::endl;
			Sleep(1000);
			std::cout << "jak to w koñcu cz³owiek na koniu niejad¹cy ty³em," << std::endl;
			std::cout << "bo ty³em to je¿d¿a tylko ci pachn¹cy, a mój dziadek ³adnie nie pachnia³." << std::endl;
			Sleep(1000);
			std::cout << "Wrêcz przeciwnie, on to jednak œmierdzia³ spoconym koniem." << std::endl;
			std::cout << "Konie te sprzeda³ i z zarobionych pieniêdzy op³aci³ sobie d³ug¹ podró¿." << std::endl;
			Sleep(1000);
			std::cout << "Oj, d³uga to podró¿ by³a i gdybym mia³ wszystko opowiedzieæ," << std::endl;
			std::cout << "to byœ mi pewnie tu usn¹³, wiêc streszczê siê." << std::endl;
			Sleep(1000);
			std::cout << "By³o wiele przygód, wiele historii, podczas których spotka³," << std::endl;
			std::cout << "a jak¿e by inaczej, niekogo innego, jak w³asn¹ ¿onê," << std::endl;
			Sleep(1000);
			std::cout << "a moj¹ babkê - Morgwindê. Mia³ z ni¹ nie lada problemy," << std::endl;
			std::cout << "a k³ucili siê na okr¹g³o, ale dzieci to mieli troje.\" " << std::endl;
			Sleep(1000);
			system("PAUSE");
			std::cout << "..." << std::endl;
			std::cout << "Tak koñczy siê historia, któr¹ opowiedzia³ mi mój dziadek, dok³adnie, co do s³owa." << std::endl;
			Sleep(1000);
			std::cout << "Mój dziadek Jackob by³œwietnym opowidaczem." << std::endl;
			std::cout << "A jego historie zapiera³y dech w piersiach." << std::endl;
			Sleep(1000);
			std::cout << "A co do dalszej historii mego rodu..." << std::endl;
			std::cout << "Dziadek mia³ tylko jedno dziecko -" << std::endl;
			Sleep(1000);
			std::cout << "- mojego ojca - Jackoba juniora Jackobspna..." << std::endl;
			std::cout << "Mój ojciec by³ nudnym i g³upim goœciem," << std::endl;
			Sleep(1000);
			std::cout << "wiêc nie chcê o nim gadaæ za du¿o." << std::endl;
			std::cout << "Uda³o mu siê jakimœ cudem znaleŸæ ¿onê," << std::endl;
			Sleep(1000);
			std::cout << "a m¹ matkê - najcudowniejsz¹ kobietê," << std::endl;
			std::cout << "która urodzi³a mnie i dwoje rodzeñstwa." << std::endl;
			Sleep(1000);
			std::cout << "I, jak mog³eœ siê spodziewaæ po historii," << std::endl;
			std::cout << "mnie nazwano Jan, bo mój brat by³ starszy" << std::endl;
			Sleep(1000);
			std::cout << "i to on dosta³ zaszczytne imiê Jackoba w rodzinie Jackobsonów." << std::endl;
			std::cout << "I oto po ca³ej historii mego rodu ja," << std::endl;
			Sleep(1000);
			std::cout << "ca³y na bia³o przyby³em do miasteczka mego pra dziadka Jackoba," << std::endl;
			std::cout << "by pokazaæ swe umiejêtnoœci w handlu" << std::endl;
			Sleep(1000);
			std::cout << "i by wykupiæ dom niegdyœ nale¿¹cy do mej rodziny," << std::endl;
			std::cout << "gdy tu nagle przybywam, a tu z³o i spustoszenie siê panoszy." << std::endl;
			Sleep(1000);
			std::cout << "Potwory zabi³y, ba - zamordowa³y z zimn¹ krwi¹ mi mojego konia," << std::endl;
			std::cout << "którego, chcia³bym to podkreœliæ z pe³n¹ moc¹, nie ukrad³em." << std::endl;
			Sleep(1000);
			std::cout << "Nie spocznê jednak, puki nie ziszczê swego marzenia!" << std::endl;
			std::cout << "Ja tu kiedyœ zamieszkam! W miejscu, gdzie mleko i miód p³ynê³y!" << std::endl;
			Sleep(1000);
			std::cout << "..." << std::endl;
			std::cout << "W koñcu ktoœ kiedyœ wymorduje wszystkie te demony," << std::endl;
			Sleep(1000);
			std::cout << "a wtedy do krainy wróci dostatek, prawda?" << std::endl;
			std::cout << "Prawda?" << std::endl;
			Sleep(1000);
			system("PAUSE");
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "Oj wszystko, co wiem, to albo s¹ pog³oski, albo jakieœ inne nie do koñca zaufane Ÿród³a" << std::endl;
			Sleep(600);
			std::cout << "No bo wie pan, ja s³ysza³em, ¿e kiedyœ na przyk³ad przyby³ w to miejsce jakiœ rycerz" << std::endl;
			std::cout << "Podobno nie by³ z³y, ale strasznie zazdroœæ z niego bi³a." << std::endl;
			Sleep(600);
			std::cout << "I poszed³ on do klasztoru i po tym znikn¹³." << std::endl;
			Sleep(600);
			std::cout << "Nikt nie wie co siê z nim sta³o, ani co siê sta³o z kobiet¹," << std::endl;
			std::cout << "Która równie¿ od tamtego czasu nie wysz³a ju¿ z klasztoru." << std::endl;
			Sleep(1000);
			std::cout << "Wtedy w³aœnie zaczê³y siê dziaæ z³e rzeczy w krainie... a teraz zosta³o ju¿ tylko to, co zosta³o," << std::endl;
			std::cout << "a tego ju¿ nie pozosta³o zbyt wiele." << std::endl;
			Sleep(1000);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz2")
		{
			std::cout << "..." << std::endl;
			std::cout << "..." << std::endl;
			Sleep(1000);
			Sleep(1000);
			std::cout << "Nie." << std::endl;
			std::cout << "Nie." << std::endl;
			Sleep(1000);
			Sleep(1000);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz3")
		{
			std::cout << "Dobrze, ¿e Pan o tym wspomina. Prawie o tym ju¿ zapomnia³em." << std::endl;
			Sleep(700);
			std::cout << "W³aœnie kilka minut temu znalaz³em ksi¹¿kê, w której jest coœ na ten temat napisane." << std::endl;
			Sleep(700);
			std::cout << "Legenda g³osi, ¿e w tym klasztorze znajduje siê magiczne zwierciad³o spe³niaj¹ce marzenia." << std::endl;
			Sleep(600);
			std::cout << "By³o ono wyorzystywane, by czyniæ dobro, lecz pewnego dnia przyby³ tu jakiœ obcy goœæ," << std::endl;
			std::cout << "który w swej niepochamowanej chciwoœci i rz¹dzy pozabija³ wszystkich, którzy go nie dopuszczali do lustra." << std::endl;
			Sleep(1000);
			std::cout << "Sprowadzi³ on wielkie ieszczêœcia na te ziemie i znikn¹³, a potem wypêz³y spod ziemi potwory." << std::endl;
			Sleep(700);
			std::cout << "Oczywiœcie to tylko streszczenie legendy, która nijak mo¿e mieæ siê do prawdziwej historii." << std::endl;
			Sleep(600);
			std::cout << "Choæ trzeba przyznaæ, ¿e gdyby tak rzeczywiœcie by³o, to to lustro mog³oby pos³u¿yæ, by oczyœciæ krainê." << std::endl;
			Sleep(900);
			system("PAUSE");
		}
		else if (npc_name == "Oktis")
		{
			std::cout << "Zet, mówimy mu?" << std::endl;
			Sleep(1000);
			std::cout << "A powiedz." << std::endl;
			Sleep(1000);
			std::cout << "No to tak... Nie mogê powiedzieæ za du¿o, bo te¿ zbyt du¿o nie wiemy," << std::endl;
			Sleep(700);
			std::cout << "ale to co wiem z pog³osek, to to, ¿e podobno ten goœæ, co jak taki pijak wygl¹da" << std::endl;
			Sleep(400);
			std::cout << "i ci¹gle ko³o tego du¿ego budynku siê krz¹ta. Ten typior podobno ma na imiê..." << std::endl;
			Sleep(700);
			std::cout << "...Neutron? Utron...? O, wiem, Utrion!" << std::endl;
			Sleep(600);
			std::cout << "Podobno wredny typ i kompletnie nikogo nie s³ucha. Nie polecam zbli¿aæ siê do niego." << std::endl;
			Sleep(1000);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz5")
		{
			std::cout << "Zet, mówimy mu?" << std::endl;
			Sleep(1000);
			std::cout << "...Czemu nie." << std::endl;
			Sleep(1000);
			std::cout << "No to tak... Nie mogê powiedzieæ za du¿o, bo te¿ zbyt du¿o nie wiemy," << std::endl;
			Sleep(700);
			std::cout << "ale to co wiem z pog³osek, to to, ¿e podobno ten goœæ, co jak taki pijak wygl¹da" << std::endl;
			Sleep(400);
			std::cout << "i ci¹gle ko³o tego du¿ego budynku siê krz¹ta. Ten typior podobno ma na imiê Urtion" << std::endl;
			Sleep(700);
			std::cout << "Goœæ ewidentnie strze¿e wjœcia do klasztoru. Pewnie jest tam coœ cennego." << std::endl;
			Sleep(600);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz6")
		{
			std::cout << "Ej, mówimy mu?" << std::endl;
			Sleep(1000);
			std::cout << "Jak chcesz." << std::endl;
			Sleep(1000);
			std::cout << "No to tak... Nie mogê powiedzieæ za du¿o, bo te¿ zbyt du¿o nie wiemy." << std::endl;
			Sleep(700);
			std::cout << "Pewnie ju¿ siê dowiedzia³eœ, jak nazywa siê ten goœæ od klasztoru." << std::endl;
			Sleep(600);
			std::cout << "S³ysza³em, ¿e goœæ pojawi³ siê podobno na krótko przed pojawieniem siê potworów" << std::endl;
			Sleep(700);
			std::cout << "Ale po co tu przyszed³, czy co tu teraz robi - tego nie wiema" << std::endl;
			Sleep(600);
			std::cout << "ale podobno to wredny typ i kompletnie nikogo nie s³ucha." << std::endl;
			Sleep(1000);
			system("PAUSE");
		}
	}
}

