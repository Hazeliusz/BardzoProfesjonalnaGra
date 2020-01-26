#pragma once
#include <iostream>
#include "Square.h"
#include <Windows.h>
#include "NPC.h"

void Non_Character::options(Character* player)
{

	while (quit == 0)
	{
		if (npc_name != "Wieœniak")
		{
			std::cout << "'1' - sklep" << std::endl;
			std::cout << "'2' - rozmowa" << std::endl;
			if (npc_name == "Kowal")		std::cout << "'3' - naprawa zbroi" << std::endl;
			else							std::cout << "'3' - sprzedarz" << std::endl;
			std::cout << std::endl << "'4' - wyjœcie" << std::endl;

			std::cin >> choice;
			switch (choice)
			{
			case 1: // sklep //-------------------------//
				//potrzebny plecak
				break;
			case 2: //historia //------------------------//
				talk(player);
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
				else if (npc_name == "Gerwalt" || npc_name == "Oktis" || npc_name == "Zbrojmistrz5" || npc_name == "Zbrojmistrz6")
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
	}
	quit = 0;
}

void Non_Character::buy(Character* player)
{
	bool agreement; // 0-nie, 1-tak;
	int nr_choice;
	int  seller; //seller - ma³y wspó³czynnik kosztów 

	seller = 8 - player->GetStats().getByEnum(Charisma) / 5;
	

	if (npc_type == 'C') //chemicy
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
			potions[i].eq_cost = 10 * (potions[i].eq_stats[0] + potions[i].eq_stats[1] + potions[i].eq_stats[2] + potions[i].eq_stats[3] + potions[i].eq_stats[4] + potions[i].eq_stats[5] + seller);
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
		else if (npc_name == "Zbrojmistrz3" || npc_name == "Zbrojmistrz6")
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
			else if (npc_name == "Zbrojmistrz6")
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

void Non_Character::opening_talk(char npc_world[3][3][15][15], Character* player) //zrobiæ dialog w zale¿noœci od p³ci bohatera
{

	if (first_time == true)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "Witam, witam! Pan tu chyba nowy? Nienowy? No nowy Pan tu, nie inaczej!" << std::endl;
			Sleep(600);
			std::cout << "A czego Pan potrzebuje? Zió³ek? Broni? Nie? No oczywiscie, ¿e nie!" << std::endl;
			Sleep(400);
			std::cout << "Nie po to pan przyszed³ akurat do mnie. Czy jednak nie? oczywiœcie!" << std::endl;
			Sleep(400);
			std::cout << "Oczywiœcie, ¿e Pan chcia³ przyjœæ tutaj, w moje progi. Oczywiœcie... " << std::endl;
			Sleep(400);
			std::cout << "To jak, o czym chcia³by Pan ze mn¹ porozmawiaæ?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false))
		{
			std::cout << ".";
			Sleep(1000);
			std::cout << ".";
			Sleep(1000);
			std::cout << "." << std::endl;
			Sleep(1000);
			std::cout << "Dzieñ dobry." << std::endl;
			Sleep(750);
			std::cout << "Przyjezdny widzê, niekt tendy nie przeje¿d¿a. Tego jestem pewna." << std::endl;
			Sleep(750);
			std::cout << "Wola³abym, by Pan szybko kupi³ pan szybko to, co chce i odszed³. Nie mam czasu, muszê siê pakowaæ..." << std::endl;
			Sleep(1000);
			std::cout << "Poza tym wygl¹da pan doœæ... nieprzyjaŸnie" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false))
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
			std::cout << "Oh, witam przybysza. Sk¹d Pan przyby³?" << std::endl;
			Sleep(400);
			std::cout << "Na pewno z daleka, taka cera nie bierze siê z nik¹d." << std::endl;
			Sleep(400);
			std::cout << "Có¿ takiego robi Pan w naszych skromnych, aktualnie doœæ nieprzyjemnych progach?" << std::endl;
			Sleep(400);
			std::cout << "Mo¿e chcia³by pan byæ naszym wybawc¹ i zniszczyæ te okropne stwory, szwêdaj¹ce siê wszêdzie po okolicy?" << std::endl;
			Sleep(400);
			std::cout << "Wiem, co takiej osobie jak Pan mo¿e siê przydaæ, proszê za mn¹ do sklepu!" << std::endl;
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
			std::cout << "No oczywiœcie, ¿e Dobrze! Wybornie! To jak, przyszedl Pan po wiecej, prawda?" << std::endl;
			Sleep(400);
			std::cout << "Jak¿e by inaczej! Nieinaczej? No oczywiœcie..." << std::endl;
			Sleep(500);
			std::cout << "Porozmawiajmy wiêc o interesach." << std::endl;
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->GetStats().getByEnum(Charisma) < 30))
		{
			std::cout << "To ponownie Pan..." << std::endl;
			Sleep(1250);
			std::cout << "Proszê wejœæ i wzi¹æ to, co jest Panu potrzebne." << std::endl;
			Sleep(500);
			std::cout << "Byle szybko, zajêta jestem, nie widaæ?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->GetStats().getByEnum(Charisma) >= 30))
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
			std::cout << "Dzieñ dobry, co tym razem chcia³by Pan kupiæ? Osobiœcie poleci³bym ciasto." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "Zapraszam!..." << std::endl;
			Sleep(1000);
			std::cout << "Kojarzê Pana i cieszê siê, ¿e jest Pan zainteresowany moimi ofertami!" << std::endl;
			Sleep(500);
			std::cout << "S³ucham, czego Pan szuka? W czym mogê pomóc?" << std::endl;
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
			std::cout << "o... witam ponownie, nie zauwa¿y³em Pana." << std::endl;
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

		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false))
		{

		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false))
		{

		}
		else if (npc_name == "Kowal Gregori")
		{

		}
		else if (npc_name == "Kowal Andrzej")
		{

		}
		else if (npc_name == "Handlarz")
		{

		}
		else if (npc_name == "Gerwalt")
		{

		}
		else if (npc_name == "Zbrojmistrz2")
		{
			std::cout << "..." << std::endl;
			Sleep(1000);
			std::cout << "Nie." << std::endl;
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz3")
		{

		}
		else if (npc_name == "Oktis")
		{

		}
		else if (npc_name == "Zbrojmistrz5")
		{

		}
		else if (npc_name == "Zbrojmistrz6")
		{

		}
	}
	else if(player->GetStats().getByEnum(Charisma) >= 25)
	{
		if (npc_name == "Chemik Renagan")
		{

		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false))
		{

		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false))
		{

		}
		else if (npc_name == "Kowal Gregori")
		{

		}
		else if (npc_name == "Kowal Andrzej")
		{

		}
		else if (npc_name == "Handlarz")
		{

		}
		else if (npc_name == "Gerwalt")
		{

		}
		else if (npc_name == "Zbrojmistrz2")
		{
			std::cout << "..." << std::endl;
			Sleep(1000);
			std::cout << "Nie." << std::endl;
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz3")
		{

		}
		else if (npc_name == "Oktis")
		{

		}
		else if (npc_name == "Zbrojmistrz5")
		{

		}
		else if (npc_name == "Zbrojmistrz6")
		{

		}
	}
}

