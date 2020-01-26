#pragma once
#include <iostream>
#include "Square.h"
#include <Windows.h>
#include "NPC.h"

void Non_Character::options(Character* player)
{

	while (quit == 0)
	{
		if (npc_name != "Wie�niak")
		{
			std::cout << "'1' - sklep" << std::endl;
			std::cout << "'2' - rozmowa" << std::endl;
			if (npc_name == "Kowal")		std::cout << "'3' - naprawa zbroi" << std::endl;
			else							std::cout << "'3' - sprzedarz" << std::endl;
			std::cout << std::endl << "'4' - wyj�cie" << std::endl;

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
				else if (npc_name == "Gerwalt" || npc_name == "Oktis" || npc_name == "Zbrojmistrz5" || npc_name == "Zbrojmistrz6")
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
	}
	quit = 0;
}

void Non_Character::buy(Character* player)
{
	bool agreement; // 0-nie, 1-tak;
	int nr_choice;
	int  seller; //seller - ma�y wsp�czynnik koszt�w 

	seller = 8 - player->GetStats().getByEnum(Charisma) / 5;
	

	if (npc_type == 'C') //chemicy
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
			potions[i].eq_cost = 10 * (potions[i].eq_stats[0] + potions[i].eq_stats[1] + potions[i].eq_stats[2] + potions[i].eq_stats[3] + potions[i].eq_stats[4] + potions[i].eq_stats[5] + seller);
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
				std::cout << "...To, to prosz� chwilk� zaczeka�, za chwilk� przynios� wszystko, co mam." << std::endl;
				Sleep(3000);
				std::cout << "Prosz�..." << std::endl;
			}
			else if (npc_name == "Zbrojmistrz6")
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

void Non_Character::opening_talk(char npc_world[3][3][15][15], Character* player) //zrobi� dialog w zale�no�ci od p�ci bohatera
{

	if (first_time == true)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << "Witam, witam! Pan tu chyba nowy? Nienowy? No nowy Pan tu, nie inaczej!" << std::endl;
			Sleep(600);
			std::cout << "A czego Pan potrzebuje? Zi�ek? Broni? Nie? No oczywiscie, �e nie!" << std::endl;
			Sleep(400);
			std::cout << "Nie po to pan przyszed� akurat do mnie. Czy jednak nie? oczywi�cie!" << std::endl;
			Sleep(400);
			std::cout << "Oczywi�cie, �e Pan chcia� przyj�� tutaj, w moje progi. Oczywi�cie... " << std::endl;
			Sleep(400);
			std::cout << "To jak, o czym chcia�by Pan ze mn� porozmawia�?" << std::endl;
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
			std::cout << "Dzie� dobry." << std::endl;
			Sleep(750);
			std::cout << "Przyjezdny widz�, niekt tendy nie przeje�d�a. Tego jestem pewna." << std::endl;
			Sleep(750);
			std::cout << "Wola�abym, by Pan szybko kupi� pan szybko to, co chce i odszed�. Nie mam czasu, musz� si� pakowa�..." << std::endl;
			Sleep(1000);
			std::cout << "Poza tym wygl�da pan do��... nieprzyja�nie" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false))
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
			std::cout << "Oh, witam przybysza. Sk�d Pan przyby�?" << std::endl;
			Sleep(400);
			std::cout << "Na pewno z daleka, taka cera nie bierze si� z nik�d." << std::endl;
			Sleep(400);
			std::cout << "C� takiego robi Pan w naszych skromnych, aktualnie do�� nieprzyjemnych progach?" << std::endl;
			Sleep(400);
			std::cout << "Mo�e chcia�by pan by� naszym wybawc� i zniszczy� te okropne stwory, szw�daj�ce si� wsz�dzie po okolicy?" << std::endl;
			Sleep(400);
			std::cout << "Wiem, co takiej osobie jak Pan mo�e si� przyda�, prosz� za mn� do sklepu!" << std::endl;
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
			std::cout << "No oczywi�cie, �e Dobrze! Wybornie! To jak, przyszedl Pan po wiecej, prawda?" << std::endl;
			Sleep(400);
			std::cout << "Jak�e by inaczej! Nieinaczej? No oczywi�cie..." << std::endl;
			Sleep(500);
			std::cout << "Porozmawiajmy wi�c o interesach." << std::endl;
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->GetStats().getByEnum(Charisma) < 30))
		{
			std::cout << "To ponownie Pan..." << std::endl;
			Sleep(1250);
			std::cout << "Prosz� wej�� i wzi�� to, co jest Panu potrzebne." << std::endl;
			Sleep(500);
			std::cout << "Byle szybko, zaj�ta jestem, nie wida�?" << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->GetStats().getByEnum(Charisma) >= 30))
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
			std::cout << "Dzie� dobry, co tym razem chcia�by Pan kupi�? Osobi�cie poleci�bym ciasto." << std::endl;
			Sleep(500);
		}
		else if (npc_name == "Gerwalt")
		{
			std::cout << "Zapraszam!..." << std::endl;
			Sleep(1000);
			std::cout << "Kojarz� Pana i ciesz� si�, �e jest Pan zainteresowany moimi ofertami!" << std::endl;
			Sleep(500);
			std::cout << "S�ucham, czego Pan szuka? W czym mog� pom�c?" << std::endl;
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
			std::cout << "o... witam ponownie, nie zauwa�y�em Pana." << std::endl;
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

