#include "NPC.h"
#include <iostream>
#include "ekwipunek.h"
#include "Square.h"

void Non_Character::function(char npc_word[3][3][15][15])
{
	Square mapa;
	switch (npc_word[mapa.b][mapa.a][mapa.y][mapa.x])
	{
	case 'K':
		npc_name = "Kowal";
	case 'Z':
		npc_name = "Zbrojmistrz";
	case 'C':
		npc_name = "Chemik";
	case 'N':
		npc_name = "Wiesniak";
	}
}

void Non_Character::talk() //zrobiæ dialog w zale¿noœci od p³ci bohatera
{
	if (npc_name == "Chemik")
	{
		if (first_time == 1)
		{
			std::cout << std::endl << "Witam, witam! Pan tu chyba nowy? Nienowy? No nowy Pan tu, nie inaczej!";
			std::cout << std::endl << "A czego Pan potrzebuje? Ziulek? Broni? Nie? No oczywiscie, ze nie!";
			std::cout << std::endl << "Nie po to pan przyszedl akurat do mnie. Czy jednak nie? oczywiscie!";
			std::cout << std::endl << "Oczywiœcie, ¿e pan chcial przyjsc tutaj, w moje progi. Oczywiœcie... ";
			std::cout << std::endl << "To jak, o czym chcialby pan ze mna porozmawiac?";
		}
		else
		{
			std::cout << std::endl << "Witam ponownie! Jak tam sie korzystalo z moich wyrobow?";
			std::cout << std::endl << "Wiedzialem, ze wybornie! To jak, przyszedl Pan po wiecej?";
			std::cout << std::endl << "To jak, porozmawiamy o interesach?";
		}
	}
	else if (npc_name == "Kowal")
	{
		if (first_time == 1)
		{
			std::cout << std::endl << "Czego?" << std::endl << "...";
			std::cout << std::endl << "Jesli chcesz bron lub zbroje, to trzeba bylo gadac!";
		}
		else
		{
			std::cout << std::endl << "A, to ty..." << std::endl << "Popatrz se i mow, co chcesz.";
		}
	}
	else if (npc_name == "Handlarz")
	{
		if (first_time == 1)
		{
			std::cout << std::endl << "Dzien dobry, co chcialby Pan tu u nas kupic?";
		}
		else
		{
			std::cout << std::endl << "Dzien dory, co tym razem chcialby Pan kupic?";
		}
	}
}


void Non_Character::options()
{
	while (quit == 0)
	{
		if (npc_name != "Wiesniak")
		{
			std::cout << std::endl << "'1' - sklep";
			std::cout << std::endl << "'2' - rozmowa";
			if (npc_name == "Zbrojmistrz")	std::cout << std::endl << "'3' - naprawa zbroi";
			else				std::cout << std::endl << "'3' - sprzedarz";
			std::cout << std::endl << "'4' - wyjscie" << std::endl;

			std::cin >> choice;
			switch (choice)
			{
			case 1: // sklep //-------------------------
				//potrzebny plecak
				break;
			case 2: //historia //------------------------
				if (npc_name == "Chemik")
				{
					std::cout << std::endl << "histroia";
				}
				else if (npc_name == "Kowal")
				{
					std::cout << std::endl << "histroia";
				}
				else if (npc_name == "Handlarz")
				{
					std::cout << std::endl << "histroia";
				}
				else if (npc_name == "Zbrojmistrz")
				{
					std::cout << std::endl << "histroia";
				}
				break;
			case 3:
				if (npc_name == "Chemik")
				{
					std::cout << std::endl << "Podziêkujê, nie jestem tutaj, by kupowaæ, a by sprzedawac";
					std::cout << std::endl << "A propos sprzedarzy, nie chcia³by pan czegos kupic?";
				}
				else if (npc_name == "Kowal")
				{
					repair();
				}
				else if (npc_name == "Handlarz")
				{
					std::cout << std::endl << "Kupic zawsze moge, zawsze sie to pozniej odsprzeda";
					sell(); //sprzedarz
				}
				else if (npc_name == "Zbrojmistrz")
				{
					std::cout << std::endl << "Nie kupujê œmieci";
				}
				break;
			case 4:
				quit = 1;
				break;
			default:
				std::cout << std::endl << "Nie ma takiej opcji";
			}
		}
		else
		{
			std::cout << std::endl << "Trzeba rozpisaæ rzeczy dla ka¿dego nps wiesniaka na mapie"; //----------------!
		}
	}
	quit = 0;
}

void Non_Character::buy()
{
	bool agreement; // 0-nie, 1-tak;
	short int nr_choice;
	if (npc_name == "Chemik")
	{
		Equipment potions[6];
		for (int i = 0; i < 6; i++)
		{
			potions[i].eq_name = "eliksir";
			potions[i].give_statistics();
			potions[i].usage();
		}
		std::cout << std::endl << "Aktualnie mam takie drobnostki na zbyciu. Jesteœ zainteresowany? jesteœ?";
		for (int i = 0; i < 6; i++)
		{
			std::cout << std::endl << i + 1 << ". " << potions[i].eq_name;
			if (potions[i].eq_name == "eliksir Galow")						std::cout << std::endl << potions[i].strength << std::endl;
			else if(potions[i].eq_name ==	"wywar z czerwonego byka")		std::cout << std::endl << potions[i].endurance << std::endl;
			else if (potions[i].eq_name == "retoryka w butelce")			std::cout << std::endl << potions[i].charisma << std::endl;
			else if (potions[i].eq_name == "roztwor wronskianinu potasu")	std::cout << std::endl << potions[i].intelligence << std::endl;
			else if (potions[i].eq_name == "sok z gumijagod")				std::cout << std::endl << potions[i].agility << std::endl;
			else if (potions[i].eq_name == "wywar z totolotka")				std::cout << std::endl << potions[i].luck << std::endl;
		}
		std::cout << std::endl << "Aktualnie wszystko kosztuje 50 dukatów";
		agreement = pay(50);
		if (agreement == 1)
		{
			std::cout << std::endl << "To ktory eliksirow chcialbys kupic?" << std::endl;
			std::cin >> nr_choice;
			// danie do plecaka przedmiotu tego numeru

		}
	}
	//potrzebny plecak1
}

void Non_Character::sell()
{
	//potrzebny  plecak
}

void Non_Character::repair()
{
	int przelicznik_ceny, choice_armor;
	float rep_cost;
	Armor thing1; //=================
	if (1 - thing1.defending() > 0)
		rep_cost = przelicznik_ceny* 100 * (1 - thing1.defending()) - przelicznik_ceny * log10(1 - thing1.defending);
	else
		rep_cost = przelicznik_ceny * (1 - thing1.defending()) + przelicznik_ceny;
		
	std::cout << std::endl << "1. Helm";
	std::cout << std::endl << "2. Napiersnik";
	std::cout << std::endl << "3. Buty";
	std::cin >> choice_armor;
	std::cout << "Koszt naprawy to: ";
	switch (choice_armor)
	{
	case 1:  //dla helmu
		std::cout << rep_cost;
		if (pay(rep_cost) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		break;
	case 2:
		//dla Napierœnika
		break;
	case 3:
		//dla Butów
		break;
	default:
		std::cout << "Cos nie pyklo, nie ma pan takiej zbroi";
		break;
	}

}

bool Non_Character::pay(int cost)
{
	char paying_choice = 'o';
	bool number = 0;
	Armor thing2; //========================

	std::cout << std::endl << "Placisz? (y/n)";
	while (paying_choice != 'y' && paying_choice != 'n')
	{
		if (number == 1) std::cout << std::endl << "To znaczy tak, czy nie? Nie rozumiem... (y/n)";
		std::cin >> paying_choice;
		number = 1;
	}

	switch (paying_choice)
	{
	case 'y':
		if (gold < cost) //potrzebny gold
		{
			std::cout << std::endl << "Chyba nie masz czym zaplacic. Wroc, gdy uzbierasz nieco drobnych";
			return 0;
		}
		else
		{
			gold -= cost;  //orygina³ golda potrzbny, by go zmieniaæ!
			return 1;
		}
	case 'n':
		std::cout << std::endl << "No có¿...";
		return 0;
	}
}
