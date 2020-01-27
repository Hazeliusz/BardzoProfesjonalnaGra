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
		if (npc_name != "Wie�niak")
		{
			std::cout << "'1' - sklep" << std::endl;
			std::cout << "'2' - rozmowa" << std::endl;
			if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")		
				std::cout << "'3' - naprawa zbroi" << std::endl;
			else
				std::cout << "'3' - sprzedarz" << std::endl;
			std::cout << std::endl << "'4' - wyj�cie" << std::endl;

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
					std::cout << "Podzi�kuj�, nie jestem tutaj, by kupowa�, a by sprzedawac" << std::endl;
					std::cout << "A propos sprzedarzy, nie chcia�by pan czegos kupic?" << std::endl;
				}
				else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->GetStats().getByEnum(Charisma) < 30))
				{
					std::cout << "Nie potrzebuj� teraz wi�kszej ilo�ci baga�u." << std::endl;
				}
				else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->GetStats().getByEnum(Charisma) >= 30))
				{
					std::cout << "Nie dam rady odkupi� tego od ciebie, przykro mi" << std::endl;
				}
				else if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")
				{
					repair(player); //naprawa
				}
				else if (npc_name == "Gerwalt" || npc_name == "Oktis" || npc_name == "Zbrojmistrz5" || npc_name == "Zet")
				{
					std::cout << "Nie kupuj� �mieci" << std::endl;
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
	int  seller; //seller - ma�y wsp�czynnik koszt�w 

	seller = 8 - player->GetStats().getByEnum(Charisma) / 5;
	

	if (this->npc_type == 'C') //chemicy
	{
		Equipment potions[6];
		potions[0].eq_name == "Eliksir Galow";
		potions[1].eq_name == "Wywar z czerwonego byka";
		potions[2].eq_name == "Retoryka w butelce";
		potions[3].eq_name == "Roztwor wro�skianu potasu";
		potions[4].eq_name == "Sok z gumijagod";
		potions[5].eq_name == "Wywar z totolotka";


		for (int i = 0; i < 6; i++)
		{
			potions[i].give_statistics();
			potions[i].usage(player);
		}

		if (npc_name == "Chemik Renagan")
		{
			std::cout << "Aktualnie mam takie drobnostki na zbyciu. Jeste� " << (player->GetSex() ? "zainteresowana" : "zainteresowany") <<"? Jeste�, prawda? Prawda..." << std::endl;
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->GetStats().getByEnum(Charisma) >= 15))// 15- jaka� lczba, kt�r� trzeba doustali�
		{
			std::cout << "Nie ma tego wiele, ale we�, co chcesz" << std::endl;
			seller = 1;
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->GetStats().getByEnum(Charisma) < 15))
		{
			std::cout << "Jak zwykle u mnie eliksiry najlepszej jako�ci. Patrz i wybieraj, czego tylko pragniesz." << std::endl;
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
		std::cout << "To kt�ry z eliksir�w " << (player->GetSex() ? "chcia�aby�" : "chcia�by�") << " kupi�? ('6' - nie kupuj�)" << std::endl;
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
				armory[i].armor_name = "He�m";
				armory[i].type_def(player);
				armory[i].type_stats(player);
			}

			if (npc_name == "Gerwalt")
			{
				std::cout << "W mojej ofercie aktualnie znajduj� si� tylko takie przedmioty" << std::endl;
			}
			else if (npc_name == "Oktis")
			{
				std::cout << "Takie skarbe�ki tu mamy. Na pewno kt�ry� ci si� spodoba!" << std::endl;
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
				armory[i].armor_name = "Napier�nik";
				armory[i].type_def(player);
				armory[i].type_stats(player);
			}

			if (npc_name == "Zbrojmistrz2")
			{
				std::cout << "..." << std::endl;
			}
			else if (npc_name == "Zbrojmistrz5")
			{
				std::cout << "Takie skarbe�ki tu mamy. Na pewno kt�ry� ci si� spodoba!" << std::endl;
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
				std::cout << "...To, to prosz� chwilk� zaczeka�, za chwilk� przynios� wszystko, co mam." << std::endl;
				Sleep(3000);
				std::cout << "Prosz�..." << std::endl;
			}
			else if (npc_name == "Zet")
			{
				std::cout << "Takie skarbe�ki tu mamy. Na pewno kt�ry� ci si� spodoba!" << std::endl;
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
			std::cout << "Si�a:         " << armory[i].armor_stats[0] << "\t\t\t\t" << armory[i + 1].armor_stats[0] << std::endl;
			std::cout << "Wytrzyma�o��: " << armory[i].armor_stats[1] << "\t\t\t\t" << armory[i + 1].armor_stats[1] << std::endl;
			std::cout << "Charyzma:     " << armory[i].armor_stats[2] << "\t\t\t\t" << armory[i + 1].armor_stats[2] << std::endl;
			std::cout << "Inteligencja: " << armory[i].armor_stats[3] << "\t\t\t\t" << armory[i + 1].armor_stats[3] << std::endl;
			std::cout << "Zwinno��:     " << armory[i].armor_stats[4] << "\t\t\t\t" << armory[i + 1].armor_stats[4] << std::endl;
			std::cout << "Szcz�cie:    " << armory[i].armor_stats[5] << "\t\t\t\t" << armory[i + 1].armor_stats[5] << std::endl;
			std::cout << "Koszt:        " << armory[i].ar_cost        << "\t\t\t\t" << armory[i + 1].ar_cost << std::endl;
		}
		std::cout << "Co kupujesz? ('6' - nie kupuj�)" << std::endl;
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

		std::cout << "Jest to jedyna taka okazja, lepszej nie b�dzie!" << std::endl;
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
			std::cout << "Nie martw si�, b�dzie to na ciebie czeka�, a� kiedy� kupisz." << std::endl;
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
			std::cout << "Wygl�dasz jak " << player->GetProffesionName() << ". Masz, takie rzeczy s� dla takich jak ty." << std::endl;
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << "Ty� jest ten, no... " << player->GetProffesionName() << "! To dla ciebie." << std::endl;
		}
	
		for (int i = 0; i < 6; i++) //koszt
		{
			weaps[i].we_cost = 10 * (weaps[i].weapon_stats[0] + weaps[i].weapon_stats[1] + weaps[i].weapon_stats[2] + weaps[i].weapon_stats[3] + weaps[i].weapon_stats[4] + weaps[i].weapon_stats[5] + seller);
		}

		for (int i = 0; i < 6; i+=2) //wypisanie
		{
			std::cout << "Nazwa:        " << i + 1 << ". " << weaps[i].we_name << "\t\t\t\t" << weaps[i + 1].we_name << std::endl;
			std::cout << "Si�a:         " << weaps[i].weapon_stats[0] << "\t\t\t\t" << weaps[i + 1].weapon_stats[0] << std::endl;
			std::cout << "Wytrzyma�o��: " << weaps[i].weapon_stats[1] << "\t\t\t\t" << weaps[i + 1].weapon_stats[1] << std::endl;
			std::cout << "Charyzma:     " << weaps[i].weapon_stats[2] << "\t\t\t\t" << weaps[i + 1].weapon_stats[2] << std::endl;
			std::cout << "Inteligencja: " << weaps[i].weapon_stats[3] << "\t\t\t\t" << weaps[i + 1].weapon_stats[3] << std::endl;
			std::cout << "Zwinno��:     " << weaps[i].weapon_stats[4] << "\t\t\t\t" << weaps[i + 1].weapon_stats[4] << std::endl;
			std::cout << "Szcz�cie:    " << weaps[i].weapon_stats[5] << "\t\t\t\t" << weaps[i + 1].weapon_stats[5] << std::endl;
			std::cout << "Koszt:        " << weaps[i].we_cost		   << "\t\t\t\t" << weaps[i + 1].we_cost << std::endl;


		}

		std::cout << "Kupujesz co�? ('6' - nie kupuj�)" << std::endl;
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
			std::cout << "I po co to wyci�ga�em?!" << std::endl;
		}
	}
	//potrzebny plecak
}


void Non_Character::repair(Character* player)
{
	int przelicznik_ceny = 1, choice_armor;
	float rep_cost;
	Armor thing1; //-------------------------------------------------|| odwo�ywa� si� powinno do za�o�onej cz�ci zbroi, nie wiem, jak zrobi�
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
	case 1:  //dla helmu ------------------------------------------|| aktualnie ni ma r�nicy. Trzeba zrobi�, by wybiera�o jeden z przedmiot�w
		std::cout << rep_cost;
		if (pay(rep_cost, player) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		else break;
	case 2://dla Napier�nika
		std::cout << rep_cost;
		if (pay(rep_cost, player) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		else break;
	case 3: //dla But�w
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
			std::cout << "Chyba nie masz czym zap�aci�. Wr��, gdy uzbierasz nieco drobnych" << std::endl;
			return false;
		}
		else
		{
			player->lostGold(cost);  //orygina� golda potrzbny, by go zmienia�!
			return true;
		}
	case 'n':
		std::cout << "No c�..." << std::endl;
		return false;
	}
}

void Non_Character::opening_talk(Character* player) //zrobi� dialog w zale�no�ci od p�ci bohatera
{

	if (first_time == true)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "Witam, witam!" << (player->GetSex() ? "Pani tu chyba nowa? Nienowa? No nowa Pani tu, nie inaczej!" :
				"Pan tu chyba nowy? Nienowy? No nowy Pan tu, nie inaczej!") << std::endl;
			Sleep(600);
			std::cout << "A czego " << (player->GetSex() ? "Pani" : "Pan") << " potrzebuje? Zi�ek? Broni? Nie? No oczywiscie, �e nie!" << std::endl;
			Sleep(400);
			std::cout << "Nie po to " << (player->GetSex() ? "pan przyszed�" : "pani przysz�a") << " akurat do mnie. Czy jednak nie? oczywi�cie!" << std::endl;
			Sleep(400);
			std::cout << "Oczywi�cie, �e " << (player->GetSex() ? "Pan chcia�" : "Pani chcia�a") << " przyj�� tutaj, w moje progi. Oczywi�cie... " << std::endl;
			Sleep(400);
			std::cout << "To jak, o czym " << (player->GetSex() ? "chcia�aby Pani" : "chcia�bym Pan") << " ze mn� porozmawia�?" << std::endl;
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
			std::cout << "Dzie� dobry." << std::endl;
			Sleep(750);
			std::cout << (player->GetSex() ? "Przyjezdna" : "Przyjezdny") << " widz�, nikt t�dy nie przeje�d�a. Tego jestem pewna." << std::endl;
			Sleep(750);
			std::cout << "Wola�abym, by Pan szybko kupi� pan szybko to, co chce i odszed�. Nie mam czasu, musz� si� pakowa�..." << std::endl;
			Sleep(1000);
			std::cout << "Poza tym wygl�da pan do��... nieprzyja�nie" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex()))
		{
			std::cout << "Ah... dzie� dobry. Nazywam si� Beatrycze, ale wi�kszo�� ludzi mo�e mi m�wi� Betty" << std::endl;
			Sleep(500);
			std::cout << "Oczywi�cie, r�wnie� i ty mo�esz mnie tak nazywa�, je�li tylko wejdziesz do mojego sklepiku." << std::endl;
			Sleep(400);
			std::cout  << "Usi�dziemy w spokojnym zau�ku, z dala od poj�kiwa� potwor�w." << std::endl;
			Sleep(600);
			std::cout << "Porozmawiamy sobie przy herbatce." << std::endl;
			Sleep(600);
			std::cout << "Prosz�, nie zwracaj wi�kszej uwagi na ba�agan, w�a�nie si� pakuj�." << std::endl;
			Sleep(600);
			std::cout << "To miejsce staje si� gorsze z dnia na dzie�, czuj�, �e musz� wyjecha�." << std::endl;
			Sleep(600);
			std::cout << "A tak poza tym..." << std::endl;
			Sleep(500);
			std::cout << "zosta�o mi jeszcze kilkana�cie eliksir�w. Mog� ci je odsprzeda� za ni�sz� cen�." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori")
		{
			std::cout << "Czego?" << std::endl;
			Sleep(300);
			std::cout << "..." << std::endl;
			Sleep(1250);
			std::cout << "Je�li chcesz bro�, to trzeba by�o gada�!" << std::endl;
			Sleep(400);
			std::cout << "*pod nosem* Ah, ci aroganccy poszukiwacze guz�w i nieszcz�cia" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << "Czego?!" << std::endl;
			Sleep(800);
			std::cout << "Nie przeszkadza�, zaj�ty jestem!" << std::endl;
			Sleep(700);
			std::cout << "A, chcesz naprawi� zbroj�. To dawaj!" << std::endl;
			Sleep(500);
			std::cout << "..." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << "Oh, witam przybysza. Sk�d " << (player->GetSex() ? "Pani przyby�a" : "Pan przyby�") << "?" << std::endl;
			Sleep(400);
			std::cout << "Na pewno z daleka, taka cera nie bierze si� z nik�d." << std::endl;
			Sleep(400);
			std::cout << "C� takiego robi " << (player->GetSex() ? "Pani" : "Pan") << " w naszych skromnych, aktualnie do�� nieprzyjemnych progach?" << std::endl;
			Sleep(400);
			std::cout << "Mo�e " << (player->GetSex() ? "chcia�aby pani" : "chcia�by pan") <<" by� naszym wybawc� i zniszczy� te okropne stwory, szw�daj�ce si� wsz�dzie po okolicy?" << std::endl;
			Sleep(400);
			std::cout << "Wiem, co takiej osobie jak " << (player->GetSex() ? "Pani" : "Pan") << " mo�e si� przyda�, prosz� za mn� do sklepu!" << std::endl;
			Sleep(600);
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "O, klient! Zapraszam! Niecz�sto zdarza mi si� ostatnio mie� kogokolwiek," << std::endl;
			std::cout << "dlatego mam do�� du�o produk�w na zbyciu." << std::endl;
			Sleep(600);
			std::cout << "Do wyboru do koloru, wed�ug uznania i preferencji." << std::endl;
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
			std::cout << "A tak, tak... dzie� dobry." << std::endl;
			Sleep(500);
			std::cout << "W czym mog� pom�c?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Oktis") 
		{
			std::cout << "Czaaaapki, kapelusze, he�mym, bereeetyyy!" << std::endl;
			Sleep(600);
			std::cout << "Ceny niskie i co� na g�ow�, same zleeetyyy!" << std::endl;
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
			std::cout << "Stopy go�e, c� pomo�e?" << std::endl;
			Sleep(600);
			std::cout << "A me butki! A to mo�e!" << std::endl;
			Sleep(500);
		}

		first_time = false;
	}
	else if (first_time == false)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "Witam ponownie! Jak tam sie korzysta�o z moich wyrob�w? Dobrze?" << std::endl;
			Sleep(400);
			std::cout << "No oczywi�cie, �e Dobrze! Wybornie! To jak, " << (player->GetSex() ? "przysz�a Pani" : "przyszed� Pan") << " po wi�cej, prawda?" << std::endl;
			Sleep(400);
			std::cout << "Jak�e by inaczej! Nieinaczej? No oczywi�cie..." << std::endl;
			Sleep(500);
			std::cout << "Porozmawiajmy wi�c o interesach." << std::endl;
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || !player->GetSex() || player->GetStats().getByEnum(Charisma) < 30))
		{
			std::cout << "To ponownie " << (player->GetSex() ? "Pani" : "Pan") << "..." << std::endl;
			Sleep(1250);
			std::cout << "Prosz� wej�� i wzi�� to, co jest " << (player->GetSex() ? "Pani" : "Panu") << " potrzebne." << std::endl;
			Sleep(500);
			std::cout << "Byle szybko, zaj�ta jestem, nie wida�?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || !player->GetSex() || player->GetStats().getByEnum(Charisma) >= 30))
		{
			std::cout << "Witam ponownie! Osobi�cie - spodziewa�am si�, �e jeszcze ci� zobacz�," << std::endl;
			Sleep(400);
			std::cout << "ale, dzi�ki Bogu, uda�o ci si� prze�y� w tym okropnym miejscu." << std::endl;
			Sleep(700);
			std::cout << "Prosz�, wejd�, jeszze nie sko�czy�am si� pakowa�, wi�c mo�esz si� rozgo�ci�." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")
		{
			std::cout << "A, to ty..." << std::endl << "Popatrz se i m�w, czego chcesz." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << "Dzie� dobry, co tym razem " << (player->GetSex() ? "chcia�aby pani" : "chcia�by Pan") << " kupi�? Osobi�cie poleci�bym ciasto." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "Zapraszam!..." << std::endl;
			Sleep(1000);
			std::cout << "Kojarz� " << (player->GetSex() ? "Pani�" : "Pana") << " i ciesz� si�, �e jest " <<
				(player->GetSex() ? "Pani zainsteresowana" : "Pan zainteresowany") << "moimi ofertami!" << std::endl;
			Sleep(500);
			std::cout << "S�ucham, czego " << (player->GetSex() ? "Pani" : "Pan") << " szuka? W czym mog� pom�c?" << std::endl;
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
			std::cout << "o... witam ponownie, nie zauwa�y�em " << (player->GetSex() ? "Pani." : "Pana.") << std::endl;
			Sleep(900);
			std::cout << "W czym pom�c?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Oktis")
		{
			std::cout << "Czaaaapki, kapelusze, he�mym, bereeetyyy!" << std::endl;
			Sleep(600);
			std::cout << "Ceny niskie, co� na g�ow� - same zleeetyyy!" << std::endl;
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
			std::cout << "Stopy go�e - c� pomo�e?" << std::endl;
			Sleep(600);
			std::cout << "A me butki! A to mo�e!" << std::endl;
			Sleep(500);
		}
	}
	else
	{
		std::cout << "Popsuted dzie� dobry." << std::endl;
		Sleep(300);
	}

}

void Non_Character::talk(Character* player)
{
	if (player->GetStats().getByEnum(Charisma) < 25)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "No wiesz, kiedy� to tu by�o �adne miasteczko, du�o zieleni tu by�o," << std::endl;
			std::cout << "ale potwory si� zjawi�y i wszystko zniszczy�y..." << std::endl;
			Sleep(700);
			std::cout << "Oczywi�cie nie ma ju� ani miasteczka, ani tym bardziej spokojnej okolicy..." << std::endl;
			std::cout << "Chyba �e kto� by si� pozby�, wyr�ba� w pie� wszystkie te monstra." << std::endl;
			Sleep(800);
			std::cout << "O tak, nie inaczej. Dok�adnie tak, no bo jak? Hm..." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex()))
		{
			std::cout << "Oj nie wiem, nie wiem, czy ci opowiem." << std::endl;
			Sleep(400);
			std::cout << "Przekonaj mnie jako� do tego, mo�e dowiesz si� du�o wi�cej o tym i o owym." << std::endl;
			Sleep(400);
			std::cout << "Bo tak, to mog� tylko powiedzie�, �e wszystko zacz�o si� o tam," << std::endl;
			std::cout << "w tamtym klasztorze. Podobno w�a�nie z tamt�d wype�z�y te wszystkie monstra." << std::endl;
			Sleep(500);
			std::cout << "Co jednak by�o tego przyczyn�, tego nie wiem." << std::endl;
			Sleep(500);
			std::cout << "Wiem za to, �e w tym miejscu nie czeka mnie nic dobrego," << std::endl;
			std::cout << "wi�c aktualnie si� pakuj�, by wyjecha� i nigdy tu nie wraca�." << std::endl;
			Sleep(600);
			std::cout << "Widz� jednak, �e ty przyby�e� tu z jakiego� powodu." << std::endl;
			Sleep(500);
			std::cout << "Mo�e teraz twoja kolej opowiadania historyjek. Opowiesz mi co� o sobie, co nie?" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || !player->GetSex()))
		{
			std::cout << "Chyba �nisz, je�li my�lisz, �e ci co� opowiem." << std::endl;
			Sleep(400);
			std::cout << "To, �e tu przyby�e� i nagle wybijasz jakie� potworki s�absze, mocniejsze, nic nie zmienia." << std::endl;
			Sleep(600);
			std::cout << "Aktualnie ci�ko mi jest na ciebie patrze�, a co dopiero co ciebie gada�." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Kowal Gregori")
		{
			std::cout << "Nie wiem, co si� sta�o, ani kiedy," << std::endl;
			std::cout << "ale za to doskonale zdaj� sobie spraw� z tego," << std::endl;
			std::cout << "�e ludzie tacy jak ty przyje�d�aj� tu, kupuj� ode mnie bro� i umieraj�." << std::endl;
			Sleep(1000);
			std::cout << "Zarabiam nie ma�o, wi�cej mnie nie obchodzi" << std::endl;
			Sleep(500);
			std::cout << "...No mo�e poza t�, no... jak jej by�o..." << std::endl;
			Sleep(700);
			std::cout << "No taka mniszka z tego klasztoru niedaleko." << std::endl;
			Sleep(500);
			std::cout << "Ona to podobno, gdy wraca�a do klasztoru, to cuda si� dzia�y." << std::endl;
			Sleep(700);
			std::cout << "Jednak nikt jej nie widzia� od wielu lat." << std::endl;
			Sleep(600);
			std::cout << "Mo�e zmar�a lub jaki� barbarzy�ca zabi� j�." << std::endl;
			Sleep(400);
			std::cout << "Tego nie wiem, ale je�li bym j� spotka�, to mo�e w ko�cu..." << std::endl;
			Sleep(700);
			std::cout << "Cholibka, wygada�em si�... Wi�cej nie powiem!" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << "..." << std::endl;
			Sleep(600);
			std::cout << "A id� se w pieruny!" << std::endl;
			Sleep(500);
			std::cout << "Nie nie wiem, nic nie powiem." << std::endl;
			Sleep(500);
			std::cout << "A nawet gdybym wiedzia�, to i tak bym nie powiedzia�." << std::endl;
			Sleep(600);
			std::cout << "Je�li chcesz czego� innego ode mnie, to m�w, je�li nie - odejd�." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << "Tak� bym ci histori� opowiedzia�. Tak� hisori�, ja ci m�wi�," << std::endl;
			std::cout << "jednak nie wydajesz mi si� godnym s�uchaczem." << std::endl;
			Sleep(600);
			std::cout << "W zamian powiem ci jedn� rzecz..." << std::endl;
			Sleep(700);
			std::cout << "..." << std::endl;
			Sleep(700);
			std::cout << "Kup co� ode mnie." << std::endl;
			Sleep(700);
			std::cout << "Aktualnie jeste� moim jedynym potencjalnym klientem," << std::endl;
			std::cout << "bo reszta albo uciek�a, albo zgin�a." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "Oh, za informacj� r�wnie� trzeba zap�aci� i raczej w�tpi�," << std::endl;
			std::cout << "by by�o ci� na to sta�. Ceni� si�." << std::endl;
			Sleep(400);
			std::cout << "Jednak w tajemnicy powiem ci, �e od momentu przybycia do tego miejsca pewnej osoby," << std::endl;
			std::cout << "od wtedy w�a�nie w tej krainie zacz�y si� dzia� z�e rzeczy." << std::endl;
			Sleep(900);
			std::cout << "Wiem, �e to ci nic nie m�wi, ale na wi�cej informacji to musisz mocniej zapracowa�." << std::endl;
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
			std::cout << "Mia�em gdzie� o tym ksi��k�... prosz�zaczeka�..." << std::endl;
			Sleep(1000);
			std::cout << "Gdzie ona jest, gdzie ja j� trzepn��em?" << std::endl;
			Sleep(1000);
			std::cout << "..." << std::endl;
			Sleep(600);
			std::cout << "Przykro mi, nie mog� znale��, prosz� przyj�� p�niej." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Oktis")
		{
			std::cout << "Hej, Zet, wiemy co� o tym miejsc?" << std::endl;
			Sleep(600);
			std::cout << "Dla tego pana nic nie wemy." << std::endl;
			Sleep(300);
			std::cout << "Okey." << std::endl;
			Sleep(500);
			std::cout << "Przykro mi, jeste�my tu tylko przyjezdnymi kupcami" << std::endl;
			Sleep(600);
			std::cout << "Nie mamy praktycznie �adnych informacji na temat" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz5")
		{
			std::cout << "Hej, Zet, wiemy co� o tym miejsc?" << std::endl;
			Sleep(600);
			std::cout << "Dla tego pana nic nie wemy." << std::endl;
			Sleep(300);
			std::cout << "Okey." << std::endl;
			Sleep(500);
			std::cout << "Przykro mi, jeste�my tu tylko przyjezdnymi kupcami" << std::endl;
			Sleep(600);
			std::cout << "Nie mamy praktycznie �adnych informacji na temat" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz6")
		{
			std::cout << "Hm..." << std::endl;
			Sleep(1000);
			std::cout << "Hej, co o tym s�dzicie? Powiedzie� mu co�?" << std::endl;
			Sleep(700);
			std::cout << "Nie... przykro mi, jeste�my tu tylko przyjezdnymi kupcami" << std::endl;
			Sleep(600);
			std::cout << "Nie mamy praktycznie �adnych informacji na temat" << std::endl;
			Sleep(500);
			system("PAUSE");
		}
	}
	else if(player->GetStats().getByEnum(Charisma) >= 25)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "No, no c� mog� powiedzie�. Nie wiem zbyt wiele." << std::endl;
			Sleep(600);
			std::cout << "Kiedy� to tu by�o tu �adne miasteczko, du�o zieleni tu by�o, kwietki ros�y," << std::endl;
			std::cout << "ptaki �piewa�y, ale potwory si� zjawi�y i wszystko zniszczy�y..." << std::endl;
			Sleep(700);
			std::cout << "Oczywi�cie nie ma ju� ani miasteczka, ani tym bardziej spokojnej okolicy..." << std::endl;
			Sleep(600);
			std::cout << "A pomy�le�, �e kiedy� kiedy�, to nawet pogoda si� do ludzi tutaj dostosowywa�a." << std::endl;
			Sleep(600);
			std::cout << "Plony by�y obfite, kraina prosperowa�a... ja ju� nie znam tych czas�w," << std::endl;
			std::cout << "ale powiem ci skrycie, �e podobno nawet pory roku zmienia�y si� tak," << std::endl;
			std::cout << "by ludziom �y�o si� jak najlepiej i najbardziej dosttnie." << std::endl;
			Sleep(1200);
			std::cout << "Teraz wszystko jest zniszczone, a ziemi� t� skazi�y potwory." << std::endl;
			Sleep(700);
			std::cout << "dybym ne by� ju� stary, to pewnie bym my�la� o przeprowadzce, ale aktualnie nie mam si�y tego robi�." << std::endl;
			Sleep(800);
			std::cout << "Ale mo�e kiedy� komu� uda�oby si�  zniszczy� te potwory i ocali� t� krain�..." << std::endl;
			Sleep(600);
			std::cout << "W ko�cu tylu dzielnych podr�nik�w zewsz�d tu przyje�d�a..." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false))
		{
			std::cout << "Dobrze! Ju�, dobrze! Powiem ci co�..." << std::endl;
			Sleep(600);
			std::cout << "Widzisz ten klasztor? To w�asnie tam podobno si� to wszystko zacz�o." << std::endl;
			Sleep(400);
			std::cout << "W�a�nie z tamt�d na pocz�tku wyp�z�y te wszystkie maszkary, kt�re teraz nawiedzaj� te ziemie." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false))
		{
			std::cout << "My�l�, �e mog� ci zaufa� i opowiedzie� ci co� wi�cej ni� wi�kszo�ci ludzi..." << std::endl;
			Sleep(500);
			std::cout << "Wi�kszo�� osi��w czy t�pak�w, kt�rzy tu przybyli nie byli godni s�ysze� ode mnie czegokolwiek." << std::endl;
			Sleep(700);
			std::cout << "Tu si� dziej� z�e rzeczy. Wszyscy ludzie, kt�rzy tu przybywali ostatnio (r�wnie� ty troch� tak wygl�dasz)," << std::endl;
			std::cout << "Mieli jakiego� chopla na punkcie wej�cia do klasztoru. Poza tym widz� na nich objawy jakiej� magii, czy czego� takiego..." << std::endl;
			Sleep(1200);
			std::cout << "Tak jakby im si� troszk� oczy zmienia�y nienaturalnie, r�ce im dr�� nawet, gdy w spokoju rozmawiaj�." << std::endl;
			Sleep(700);
			std::cout << "Obawiam si�, �e to, co mo�e znajdowa� si� w �rodku klasztoru nie jest warte tego wszystkiego." << std::endl;
			Sleep(900);
			std::cout << "Patrz, czy kto� ci� nie obserwuje, czy kto� ci� nie �ledzi." << std::endl;
			Sleep(1000);
			std::cout << "Mam przeczuci�, �e to wszystko mo�e �le si� dla ciebie sko�czy�, wi�c uwa�aj na siebie..." << std::endl;
			Sleep(900);
			std::cout << "Poza tym ten klasztor by� miejscem, z kt�rego ca�e to z�o zacz�o, wi�c spodziewaj si� niespodziewanego w �rodku." << std::endl;
			Sleep(1000);
			std::cout << "..." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Kowal Gregori")
		{
			std::cout << "Nie wiem, co si� sta�o, ani kiedy," << std::endl;
			std::cout << "ale za to doskonale zdaj� sobie spraw� z tego," << std::endl;
			std::cout << "�e ludzie tacy jak ty przyje�d�aj� tu, kupuj� ode mnie bro� i umieraj�." << std::endl;
			Sleep(1000);
			std::cout << "Zarabiam nie ma�o, wi�cej mnie nie obchodzi" << std::endl;
			Sleep(500);
			std::cout << "...No mo�e poza t�, no... jak jej by�o..." << std::endl;
			Sleep(700);
			std::cout << "No taka mniszka z tego klasztoru niedaleko." << std::endl;
			Sleep(500);
			std::cout << "Ona to podobno, gdy wraca�a do klasztoru, to cuda si� dzia�y." << std::endl;
			Sleep(700);
			std::cout << "Jednak nikt jej nie widzia� od wielu lat." << std::endl;
			Sleep(600);
			std::cout << "Mo�e zmar�a lub jaki� barbarzy�ca zabi� j�." << std::endl;
			Sleep(400);
			std::cout << "Tego nie wiem, ale je�li bym j� spotka�, to mo�e w ko�cu uda�oby mi si� spotka� kogo� dla mnie." << std::endl;
			Sleep(700);
			std::cout << "W ko�cu cuda si� zdarzaj�..." << std::endl;
			Sleep(600);
			std::cout << "Sam jednak do klsztoru nie wejd�, jaki� szaleniec go strze�e." << std::endl;
			Sleep(500);
			std::cout << "Przej�� ko�o niego si� nie da, a je�li chcia�by� si� zakra��, to nic to nie da." << std::endl;
			Sleep(600);
			std::cout << "Ten cz�owiek jest op�tany, wyczuje ci�, je�li tylko zbli�ysz si� do klasztoru." << std::endl;
			Sleep(400);
			std::cout << "Gadanie z nim te� nic nie daje, wi�c nie polecam tej strategii." << std::endl;
			Sleep(500);
			system("PAUSE");
		}
		else if (npc_name == "Kowal Andrzej")
		{

			std::cout << "A id� se w pieruny! " << std::endl;
			Sleep(600);
			std::cout << "Jedyne co wiem, to to, �e ten pobliski klasztor nazywa si� Suuomo i to," << std::endl;
			std::cout << " �e mieszka�a w nim niedy� bardzo m�dra kobieta, dzi�ki kt�rej ludziom �y�o si� �atwiej." << std::endl;
			Sleep(600);
			std::cout << "Jednak teraz jej ju� nie ma, pewnie umar�a ze staro�ci, w ko�cu tyle lat min�o." << std::endl;
			Sleep(600);
			std::cout << "Ostatni� rzecz� jak� jednak wiem i to doskonale to to, �e mnie denerwujesz." << std::endl;
			Sleep(800);
			std::cout << "Przesta� mnie wypytywa� o dziwne rzeczy!" << std::endl;
			Sleep(600);
			system("PAUSE");
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << "Ale� oczywi�cie, �e ci opowiem, bo jakbym m�g� nie opowiedzie�!" << std::endl;
			Sleep(1000);
			std::cout << "Wi�c... to zacz�o sto pi��dziesi�t lat temu, za mojego pra pra dziadka." << std::endl;
			std::cout << "Nazywa� si� on Jackob i by� z�odziejaszkiem." << std::endl;
			Sleep(1000);
			std::cout << "Nie by� on zwyk�ym z�odziejaszkiem, on nie." << std::endl;
			std::cout << "On by� koniokradem. Najznakomitszym koniokradem w okolicy Gralaronu." << std::endl;
			Sleep(1000);
			std::cout << "Cho� mo�liwe jest i to, �e m�j dziadek przekr�ci� nazw� miejscowo�ci," << std::endl;
			std::cout << "bo on to nigdy nie mia� g�owy do imion i nazw." << std::endl;
			Sleep(1000);
			std::cout << "On to jednak by� podr�nikiem, cho� do Galaronu nigdy nie dojecha�." << std::endl;
			std::cout << "Nie wiesz gdzie to? ja te� nie, ale podobno bardzo daleko." << std::endl;
			Sleep(1000);
			std::cout << "�y� on w zwyk�ej wiosce... a ta wioska by�a ma�a, malusie�ka." << std::endl;
			std::cout << "I �y�o mu si� tam bardzo wygodnie i wi�d� zwyk�e �ycie koniokrada." << std::endl;
			Sleep(1000);
			std::cout << "A ludzie go nie znosili. W ko�cu by� koniokradem," << std::endl;
			std::cout << "a tak to ju� z koniokradami bywa, �e ludzi ich nie znosz�." << std::endl;
			Sleep(1000);
			std::cout << "Dlatego te� m�j pra pra dziadek Jackob zamieszka� na odludziu," << std::endl;
			std::cout << "bo tam nikomu si� nie chcia�o go wyzywa� od z�odziei." << std::endl;
			Sleep(1000);
			std::cout << "A pewnego poranka, to ja ci powiem szczerze..." << std::endl;
			std::cout << "No oczywi�cie, �e szczerze ci powiem, �e jednak jedna dziewczyna" << std::endl;
			Sleep(1000);
			std::cout << "na takie odludzie si� zapu�ci�a, wi�c odludziem si� ju� to nazywa� nie mog�o." << std::endl;
			std::cout << "I, ja ci powiem, okaza�o si�, �e ona te� jest koniokradem" << std::endl;
			Sleep(1000);
			std::cout << "i ukrad�� mojemu pra pra dziadkowi jego konie," << std::endl;
			std::cout << "ale on to widzia� i ukradkiem, jak taki ninja, bo jak�e by inaczej," << std::endl;
			Sleep(1000);
			std::cout << "szed� za ni�, a ona go nie widzia�a. Tak to by�o? ...Oczywi�cie!" << std::endl;
			std::cout << "Noc� odbi� swe ukradzione przez niego kiedy� konie" << std::endl;
			Sleep(1000);
			std::cout << "i wr�ci� na swe nieodludziowe odludzie." << std::endl;
			std::cout << "Ta kobieta jednak nie dawa�a za wygran� i krad�a co chwil� te konie," << std::endl;
			Sleep(1000);
			std::cout << "a m�j pra pra dziadek je krad� spowrotem." << std::endl;
			std::cout << "Zwierzaki tak si� do tego przyzwyczai�y," << std::endl;
			Sleep(1000);
			std::cout << "�e zacz�y to traktowa� jako swoisty spacerek i prycha�y z rado�ci�," << std::endl;
			std::cout << "gdy to widzia�y raz j�, raz jego." << std::endl;
			Sleep(1000);
			std::cout << "W ko�... cu tak si� i oni ze sob� z�yli, �e a� si� pobrali," << std::endl;
			std::cout << "a ludzi w �wi�tyni by�o z pi��dziesi�ciu" << std::endl;
			Sleep(1000);
			std::cout << "i po�owa z nich, to byli ci," << std::endl;
			std::cout << "kt�rym te konie na samym pocz�tku ukradziono." << std::endl;
			Sleep(1000);
			std::cout << "Drug� po�ow� byli ich prawnicy i kap�an." << std::endl;
			std::cout << "Tak wi�c m�j pra pra dziadek - Jackob konikrad -" << std::endl;
			Sleep(1000);
			std::cout << "- o�eni� si� z moj� pra pra babk� - Ameli�..." << std::endl;
			std::cout << "r�wnie� o ps�donimie konikrad... Mieli tr�jk� dzieci, w tym mojego dziadka..." << std::endl;
			Sleep(1000);
			std::cout << "A propos mojego pra dziadka, to zgadnij jak mia� on na imi�..." << std::endl;
			Sleep(600);
			system("PAUSE");
			std::cout << "Jackob, a sta�o si� tak dlatego, �e m�j pra pra dziadek zapomnia�," << std::endl;
			std::cout << "jakie imi� mu wcze�niej wybra� wraz z �on�" << std::endl;
			Sleep(1000);
			std::cout << "i spanikowawszy opwiedzia� podczas chrztu <<Jackob>>." << std::endl;
			std::cout << "Jednak wszyscy m�wili do niego po prostu junior," << std::endl;
			Sleep(1000);
			std::cout << "by rozr�ni�, kiedy mowa o synu, a kiedy o ojcu," << std::endl;
			std::cout << "bo m�j pra pra dziadek, tak jak ju� m�wi�em," << std::endl;
			Sleep(1000);
			std::cout << "te� nazywa� si� Jackob. Co ciekawe lub niekoniecznie," << std::endl;
			std::cout << "ale wydaje mi si�, �e i owszem - m�j dziadek te� nazywa� si� Jackob," << std::endl;
			Sleep(1000);
			std::cout << "ale to historia nie na ten wiecz�r, oj nie..." << std::endl;
			std::cout << "A mo�e? Niee... Tak czy inaczej, st�d w�a�nie powsta�o moje nazwisko..." << std::endl;
			Sleep(1000);
			std::cout << "Jackobson, bo Ka�dy Jackob w rodzinie by� synem innego Jackoba," << std::endl;
			std::cout << "a ka�dy Jackob by� ojecem kolejnego Jackoba. I tak ma rodzina ustanowi�a," << std::endl;
			Sleep(1000);
			std::cout << "�e pierwszy syn z rodu b�dzie mia� na imi� Jackob," << std::endl;
			std::cout << "by podtrzyma� rodzinn� tradycj�. Oczywi�cie nie chciano," << std::endl;
			Sleep(1000);
			std::cout << "by do ka�dego pokolenia rodziny przypad� przydomek koniokrada," << std::endl;
			std::cout << "dlatego te� m�j pra pra dziadek Jackob wraz z moj� pra pra babk� Ameli�" << std::endl;
			Sleep(1000);
			std::cout << "porzucili sw�j z�y zaw�d, gdy urodzi�o im si� drugie dziecko" << std::endl;
			std::cout << "i sprzedali wi�kszo�� z koni za bezcen, g�r� z�ota, ja ci powiem." << std::endl;
			Sleep(1000);
			std::cout << "Co ciekawe wi�kszo�� z nich zosta�o odkupionych przez ludzi," << std::endl;
			std::cout << "kt�rym wiele lat wcze�niej zabrano te konie." << std::endl;
			Sleep(1000);
			std::cout << "Podobno byli tak w�ciekli, ale nic zrobi� nie mogli," << std::endl;
			std::cout << "s�dy zgadza�y si�, �e powinno si� odda� tym ludziom ich konie," << std::endl;
			Sleep(1000);
			std::cout << "ale �e nikt koni w okolicy nie mia� (oczywi�cie poza moimi pra pra dziadkami)," << std::endl;
			std::cout << "to gdy uciekali z tymi ko�mi, to nie mogli ich dogoni�," << std::endl;
			Sleep(1000);
			std::cout << "a i konie jakie� takie weselsze by�y przy moich przodkach" << std::endl;
			std::cout << "ni� wyzyskiwane na polach i przy wozach." << std::endl;
			Sleep(1000);
			std::cout << "No wi�c wyjechali z g�r� pieni�dzy i, no ja ci powiem, bo kto inny," << std::endl;
			std::cout << "stwierdzili, �e zostan� kupcami, wi�c osiedlili si� w ma�ym miasteczku," << std::endl;
			Sleep(1000);
			std::cout << "no nie uwierzysz, bardzo prosperuj�cym i uroczym." << std::endl;
			std::cout << "Mo�e wydawa� si� to dziwne dla ciebie, ale w�a�nie si� w nim znajdujesz..." << std::endl;
			Sleep(1000);
			std::cout << "a raczej znajdowa�by� si�, gdyby nie to, �e niewiele z niego zosta�o." << std::endl;
			Sleep(600);
			system("PAUSE");
			std::cout << "Ale wracaj�c do historii, bo w ko�cu by�e� jej ciekaw." << std::endl;
			std::cout << "Za�o�yli tam sklepik i dobrze im si� wiod�o. lata mija�y, a z�ota przybywa�o." << std::endl;
			Sleep(1000);
			std::cout << "W pewnym momencie m�j pra pra dziadek Jackob nie da� ju� jednak rady" << std::endl;
			std::cout << "prowadzi� biznesu, wi�c pa�eczk� po nim przej�� Jackob, m�j pra dziadek." << std::endl;
			Sleep(1000);
			std::cout << "No i pewnego ranka przechodzi�a iedaleko mieszkania pewna kobieta." << std::endl;
			std::cout << "Z ojca opowiada� o opowie�ciach dziadka, kt�ry opowiada� o czasach pradziadkowych," << std::endl;
			Sleep(1000);
			std::cout << "dowiedzia�em si�, �e ona by�a jak� taka, no w�a�nie ci�ko do okre�lenia," << std::endl;
			std::cout << "bo podobno ona wygl�da�a na tak, m�wi�c szczerze, potwornie o�wiecon�," << std::endl;
			Sleep(1000);
			std::cout << "a w swej m�dro�ci zachwycaj�c�, �e nie wiadomo by�o," << std::endl;
			std::cout << "czy ona jest stara,czy m�oda," << std::endl;
			Sleep(1000);
			std::cout << "czy ubrana na bia�o, czy nie," << std::endl;
			std::cout << "czy to mo�e duch by� jaki�, taka, nie mog� tego krywa�, potwornie m�dra by�a," << std::endl;
			Sleep(1000);
			std::cout << "a w tej m�dro�ci ni to tajemnicza, ni to nie," << std::endl;
			std::cout << "czy to przyjazna, czy mo�e jednak nie." << std::endl;
			Sleep(1000);
			std::cout << "To co jednak mog� powiedzie�, to to," << std::endl;
			std::cout << "�e ta kobieta sk�oni�a si� przed moim pradziadkiem na powitanie." << std::endl;
			Sleep(1000);
			std::cout << "On patrz�c na ni� by� jak g�az - skamienia� podobno na amen i nie odk�oni� si�," << std::endl;
			std::cout << "ale to chyba nic, kobieta to nie zwa�aj�c na to, jak m�wi� m�j ojciec:" << std::endl;
			Sleep(1000);
			std::cout << "<<U�miechn�a si� niczym t�cza pojawiaj�ca si� po bu�y," << std::endl;
			std::cout << "jak p�ki kwiat�w otwieraj�ce si� o poranku>>," << std::endl;
			Sleep(1000);
			std::cout << "a podobno tak m�j pra dziadek m�wi�, a on w poezj� si� nie bawi�." << std::endl;
			std::cout << "Tak czy inaczej po tym spotkaniu min�o tak kilka dni," << std::endl;
			Sleep(1000);
			std::cout << "a jego �ycie zacz�o si� powodzi� jak nigdy dot�d." << std::endl;
			std::cout << "Znalaz� sobie �on�, a moj� pra babk� Jadwig�," << std::endl;
			Sleep(1000);
			std::cout << "z kt�r� mia� pi�cioro dzieci, a pierwszy syn, m�j dziadek," << std::endl;
			std::cout << "tak jak wcze�niej m�wi�em, nazywa� si� Jackob," << std::endl;
			Sleep(1000);
			std::cout << "ale �e m�j pra dziadek mia� przydomek junior," << std::endl;
			std::cout << "to Jackob, m�j dziadek takiego przydomka ju� nie dosta�," << std::endl;
			Sleep(1000);
			std::cout << "by si� ludziom nie myli�o i nie robili g�upich pomy�ek." << std::endl;
			std::cout << "Dlatego te� to strego Jackoba nadal nazywali junior," << std::endl;
			Sleep(1000);
			std::cout << "a m�odego po prostu Jackob, co czasami �mieszy�o przejezdnych," << std::endl;
			std::cout << "lecz na to ju� nie by�o rady, trzeba by�o si� z tym pogodzi�." << std::endl;
			Sleep(500);
			system("PAUSE");
			std::cout << "Lata mija�y, a miasteczko prosperowa�o," << std::endl;
			std::cout << "nawet pogod� mia�o zawsze tak�, jak� trzeba by�o." << std::endl;
			Sleep(1000);
			std::cout << "Jednak moojemu dziadkowi, Jackobowi by�o nie w smak to, �e tu ci�gle by�o dobrze," << std::endl;
			std::cout << "bo on to by�, ja ci powiem szczerze, bo jak�e by inaczej, jak nie szczerze," << std::endl;
			Sleep(1000);
			std::cout << "bo na nieszczero�� to g�upio j�zyk sobie strz�pi�, tak wi�c, ja ci powiem," << std::endl;
			std::cout << "ten m�j dziadunio to on usiedzie� w jednym miejscu nie m�g�." << std::endl;
			Sleep(1000);
			std::cout << "Dlatego te�, gdy nieco podr�s�, to kt�rej� nocy poczu� zew przygody," << std::endl;
			std::cout << "zabra� nieco w�asnych oszcz�dno�ci i, czego potem si� wstydzi�," << std::endl;
			Sleep(1000);
			std::cout << "nieco oszcz�dno�ci ojca, troch� ciuch�w i jedzenia, oraz" << std::endl;
			std::cout << "niczym jego dziadek, a m�j pra pra dziadek, ukrad� konia," << std::endl;
			Sleep(1000);
			std::cout << "by wyruszy� w nieznany mu dot�d, pe�ny niebezpiecze�stw �wiat." << std::endl;
			std::cout << "Nazwa� prawie od razu swojego konia Sapa, jak taka ryba" << std::endl;
			Sleep(1000);
			std::cout << "i p�dzi� na jej grzbiecie jak najszybciej i jak najdalej" << std::endl;
			std::cout << "od krainy, kt�ra mlekiem i miodem p�yn�a przez d�ugie lata." << std::endl;
			Sleep(1000);
			std::cout << "No i jecha� przed siebie, a zapasu rzywno�ci i got�rka ubywa�y," << std::endl;
			std::cout << "co zmusi�o mojego dziadka jackoba do d�u�szego postoju, by zarobi� na siebie" << std::endl;
			Sleep(1000);
			std::cout << "i by m�c sfinansowa� sobie dalsz� podr�." << std::endl;
			std::cout << "Oczywi�cie po pewnym czasie nauczy� si� y� bez pieni�dzy," << std::endl;
			Sleep(1000);
			std::cout << "ale takie rzeczy to nie od razu si� potrafi." << std::endl;
			std::cout << "No wiesz, sztuka przetrwania w dzikiej puszczy" << std::endl;
			Sleep(1000);
			std::cout << "lub na takich stepach to jest wielki wyczyn," << std::endl;
			std::cout << "a i jeszcze mog� ci� napa��... A w�a�nie, napa��! Oczywi�cie!" << std::endl;
			Sleep(1000);
			std::cout << "Prawie zapomnia�em, dziadek zosta� przecie� na stepach z�apany!" << std::endl;
			std::cout << "Chcieli go zabi�, ale jedna z tamtejszych kobiet ujrza�� w nim m�a" << std::endl;
			Sleep(1000);
			std::cout << "i niczym Bulimia w Rondeo, czy jak tam si� nazywali g��wni bohaterowie" << std::endl;
			std::cout << "do�� nanego na zachodzie dramatu teatralnego, zakocha�a si�." << std::endl;
			Sleep(1000);
			std::cout << "Teraz pewnie pomy�la�e� sobie, �e m�j dziadek si� z ni� o�eni�." << std::endl;
			std::cout << "Musz� ci� jednak zdziwi�. Jedyne co zrobi�, to noc�," << std::endl;
			Sleep(1000);
			std::cout << "gdy si� wyswobodzi� i nie grozi�a mu ju� wi�ksza krzywda," << std::endl;
			std::cout << "wymkn�� si� z namiotu.Jeszcze wyra�niej wdaj�c si� w swego dziadka," << std::endl;
			Sleep(1000);
			std::cout << "a mojego pra pra dziadka Jackoba i ukrad� im wszystkie konie," << std::endl;
			std::cout << "przez co nie mieli go jak �ciga�, by by� za szybki," << std::endl;
			Sleep(1000);
			std::cout << "jak to w ko�cu cz�owiek na koniu niejad�cy ty�em," << std::endl;
			std::cout << "bo ty�em to je�d�a tylko ci pachn�cy, a m�j dziadek �adnie nie pachnia�." << std::endl;
			Sleep(1000);
			std::cout << "Wr�cz przeciwnie, on to jednak �mierdzia� spoconym koniem." << std::endl;
			std::cout << "Konie te sprzeda� i z zarobionych pieni�dzy op�aci� sobie d�ug� podr�." << std::endl;
			Sleep(1000);
			std::cout << "Oj, d�uga to podr� by�a i gdybym mia� wszystko opowiedzie�," << std::endl;
			std::cout << "to by� mi pewnie tu usn��, wi�c streszcz� si�." << std::endl;
			Sleep(1000);
			std::cout << "By�o wiele przyg�d, wiele historii, podczas kt�rych spotka�," << std::endl;
			std::cout << "a jak�e by inaczej, niekogo innego, jak w�asn� �on�," << std::endl;
			Sleep(1000);
			std::cout << "a moj� babk� - Morgwind�. Mia� z ni� nie lada problemy," << std::endl;
			std::cout << "a k�ucili si� na okr�g�o, ale dzieci to mieli troje.\" " << std::endl;
			Sleep(1000);
			system("PAUSE");
			std::cout << "..." << std::endl;
			std::cout << "Tak ko�czy si� historia, kt�r� opowiedzia� mi m�j dziadek, dok�adnie, co do s�owa." << std::endl;
			Sleep(1000);
			std::cout << "M�j dziadek Jackob by��wietnym opowidaczem." << std::endl;
			std::cout << "A jego historie zapiera�y dech w piersiach." << std::endl;
			Sleep(1000);
			std::cout << "A co do dalszej historii mego rodu..." << std::endl;
			std::cout << "Dziadek mia� tylko jedno dziecko -" << std::endl;
			Sleep(1000);
			std::cout << "- mojego ojca - Jackoba juniora Jackobspna..." << std::endl;
			std::cout << "M�j ojciec by� nudnym i g�upim go�ciem," << std::endl;
			Sleep(1000);
			std::cout << "wi�c nie chc� o nim gada� za du�o." << std::endl;
			std::cout << "Uda�o mu si� jakim� cudem znale�� �on�," << std::endl;
			Sleep(1000);
			std::cout << "a m� matk� - najcudowniejsz� kobiet�," << std::endl;
			std::cout << "kt�ra urodzi�a mnie i dwoje rodze�stwa." << std::endl;
			Sleep(1000);
			std::cout << "I, jak mog�e� si� spodziewa� po historii," << std::endl;
			std::cout << "mnie nazwano Jan, bo m�j brat by� starszy" << std::endl;
			Sleep(1000);
			std::cout << "i to on dosta� zaszczytne imi� Jackoba w rodzinie Jackobson�w." << std::endl;
			std::cout << "I oto po ca�ej historii mego rodu ja," << std::endl;
			Sleep(1000);
			std::cout << "ca�y na bia�o przyby�em do miasteczka mego pra dziadka Jackoba," << std::endl;
			std::cout << "by pokaza� swe umiej�tno�ci w handlu" << std::endl;
			Sleep(1000);
			std::cout << "i by wykupi� dom niegdy� nale��cy do mej rodziny," << std::endl;
			std::cout << "gdy tu nagle przybywam, a tu z�o i spustoszenie si� panoszy." << std::endl;
			Sleep(1000);
			std::cout << "Potwory zabi�y, ba - zamordowa�y z zimn� krwi� mi mojego konia," << std::endl;
			std::cout << "kt�rego, chcia�bym to podkre�li� z pe�n� moc�, nie ukrad�em." << std::endl;
			Sleep(1000);
			std::cout << "Nie spoczn� jednak, puki nie ziszcz� swego marzenia!" << std::endl;
			std::cout << "Ja tu kiedy� zamieszkam! W miejscu, gdzie mleko i mi�d p�yn�y!" << std::endl;
			Sleep(1000);
			std::cout << "..." << std::endl;
			std::cout << "W ko�cu kto� kiedy� wymorduje wszystkie te demony," << std::endl;
			Sleep(1000);
			std::cout << "a wtedy do krainy wr�ci dostatek, prawda?" << std::endl;
			std::cout << "Prawda?" << std::endl;
			Sleep(1000);
			system("PAUSE");
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "Oj wszystko, co wiem, to albo s� pog�oski, albo jakie� inne nie do ko�ca zaufane �r�d�a" << std::endl;
			Sleep(600);
			std::cout << "No bo wie pan, ja s�ysza�em, �e kiedy� na przyk�ad przyby� w to miejsce jaki� rycerz" << std::endl;
			std::cout << "Podobno nie by� z�y, ale strasznie zazdro�� z niego bi�a." << std::endl;
			Sleep(600);
			std::cout << "I poszed� on do klasztoru i po tym znikn��." << std::endl;
			Sleep(600);
			std::cout << "Nikt nie wie co si� z nim sta�o, ani co si� sta�o z kobiet�," << std::endl;
			std::cout << "Kt�ra r�wnie� od tamtego czasu nie wysz�a ju� z klasztoru." << std::endl;
			Sleep(1000);
			std::cout << "Wtedy w�a�nie zacz�y si� dzia� z�e rzeczy w krainie... a teraz zosta�o ju� tylko to, co zosta�o," << std::endl;
			std::cout << "a tego ju� nie pozosta�o zbyt wiele." << std::endl;
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
			std::cout << "Dobrze, �e Pan o tym wspomina. Prawie o tym ju� zapomnia�em." << std::endl;
			Sleep(700);
			std::cout << "W�a�nie kilka minut temu znalaz�em ksi��k�, w kt�rej jest co� na ten temat napisane." << std::endl;
			Sleep(700);
			std::cout << "Legenda g�osi, �e w tym klasztorze znajduje si� magiczne zwierciad�o spe�niaj�ce marzenia." << std::endl;
			Sleep(600);
			std::cout << "By�o ono wyorzystywane, by czyni� dobro, lecz pewnego dnia przyby� tu jaki� obcy go��," << std::endl;
			std::cout << "kt�ry w swej niepochamowanej chciwo�ci i rz�dzy pozabija� wszystkich, kt�rzy go nie dopuszczali do lustra." << std::endl;
			Sleep(1000);
			std::cout << "Sprowadzi� on wielkie ieszcz�cia na te ziemie i znikn��, a potem wyp�z�y spod ziemi potwory." << std::endl;
			Sleep(700);
			std::cout << "Oczywi�cie to tylko streszczenie legendy, kt�ra nijak mo�e mie� si� do prawdziwej historii." << std::endl;
			Sleep(600);
			std::cout << "Cho� trzeba przyzna�, �e gdyby tak rzeczywi�cie by�o, to to lustro mog�oby pos�u�y�, by oczy�ci� krain�." << std::endl;
			Sleep(900);
			system("PAUSE");
		}
		else if (npc_name == "Oktis")
		{
			std::cout << "Zet, m�wimy mu?" << std::endl;
			Sleep(1000);
			std::cout << "A powiedz." << std::endl;
			Sleep(1000);
			std::cout << "No to tak... Nie mog� powiedzie� za du�o, bo te� zbyt du�o nie wiemy," << std::endl;
			Sleep(700);
			std::cout << "ale to co wiem z pog�osek, to to, �e podobno ten go��, co jak taki pijak wygl�da" << std::endl;
			Sleep(400);
			std::cout << "i ci�gle ko�o tego du�ego budynku si� krz�ta. Ten typior podobno ma na imi�..." << std::endl;
			Sleep(700);
			std::cout << "...Neutron? Utron...? O, wiem, Utrion!" << std::endl;
			Sleep(600);
			std::cout << "Podobno wredny typ i kompletnie nikogo nie s�ucha. Nie polecam zbli�a� si� do niego." << std::endl;
			Sleep(1000);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz5")
		{
			std::cout << "Zet, m�wimy mu?" << std::endl;
			Sleep(1000);
			std::cout << "...Czemu nie." << std::endl;
			Sleep(1000);
			std::cout << "No to tak... Nie mog� powiedzie� za du�o, bo te� zbyt du�o nie wiemy," << std::endl;
			Sleep(700);
			std::cout << "ale to co wiem z pog�osek, to to, �e podobno ten go��, co jak taki pijak wygl�da" << std::endl;
			Sleep(400);
			std::cout << "i ci�gle ko�o tego du�ego budynku si� krz�ta. Ten typior podobno ma na imi� Urtion" << std::endl;
			Sleep(700);
			std::cout << "Go�� ewidentnie strze�e wj�cia do klasztoru. Pewnie jest tam co� cennego." << std::endl;
			Sleep(600);
			system("PAUSE");
		}
		else if (npc_name == "Zbrojmistrz6")
		{
			std::cout << "Ej, m�wimy mu?" << std::endl;
			Sleep(1000);
			std::cout << "Jak chcesz." << std::endl;
			Sleep(1000);
			std::cout << "No to tak... Nie mog� powiedzie� za du�o, bo te� zbyt du�o nie wiemy." << std::endl;
			Sleep(700);
			std::cout << "Pewnie ju� si� dowiedzia�e�, jak nazywa si� ten go�� od klasztoru." << std::endl;
			Sleep(600);
			std::cout << "S�ysza�em, �e go�� pojawi� si� podobno na kr�tko przed pojawieniem si� potwor�w" << std::endl;
			Sleep(700);
			std::cout << "Ale po co tu przyszed�, czy co tu teraz robi - tego nie wiema" << std::endl;
			Sleep(600);
			std::cout << "ale podobno to wredny typ i kompletnie nikogo nie s�ucha." << std::endl;
			Sleep(1000);
			system("PAUSE");
		}
	}
}

