#include "NPC.h"
#include <iostream>
#include "ekwipunek.h"

void Non_Character::function()
{
	//potrzebna mapa
}

void Non_Character::talk() //zrobiæ dialog w zale¿noœci od p³ci bohatera
{
	if (name == "Chemik")
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
	else if (name == "Kowal")
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
	else if (name == "Handlarz")
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
	while (quit==0)
	{
		std::cout << std::endl << "'1' - sklep";
		std::cout << std::endl << "'2' - rozmowa";
		if(name == "Kowal")	std::cout << std::endl << "'3' - naprawa zbroi";
		else				std::cout << std::endl << "'3' - sprzedarz";
		std::cout << std::endl << "'4' - wyjscie" << std::endl;

		std::cin >> choice;
		switch (choice)
		{
		case 1: // sklep
			//potrzebny plecak
			break;
		case 2: //historia
			if (name == "Chemik")
			{

			}
			else if (name == "Kowal")
			{

			}
			else if (name == "Handlarz")
			{

			}
			break;
		case 3:
			if (name == "Chemik")
			{
				std::cout << std::endl << "Podziêkujê, nie jestem tutaj, by kupowaæ, a by sprzedawac";
				std::cout << std::endl << "A propos sprzedarzy, nie chcia³by pan czegos kupic?";
			}
			else if (name == "Kowal")
			{
				repair();
			}
			else if (name == "Handlarz")
			{
				std::cout << std::endl << "Kupic zawsze moge, zawsze sie to pozniej odsprzeda";
				sell(); //sprzedarz
			}
			break;
		case 4:
			quit = 1;
			break;
		default:
			std::cout << std::endl << "Nie ma takiej opcji";
		}
	}
	quit = 0;
}

void Non_Character::buy()
{
	//potrzebny plecak
}

void Non_Character::sell()
{
	//potrzebny  plecak
}

void Non_Character::repair()
{
	int przelicznik_ceny, choice_armor;
	float rep_cost;
	Armor thing1; 
	if (1 - thing1.defending() > 0)
		rep_cost = przelicznik_ceny * (1 - thing1.defending()) - przelicznik_ceny * log10(1 - thing1.defending);
	else
		rep_cost = przelicznik_ceny * (1 - thing1.defending()) + przelicznik_ceny;
		
	std::cout << std::endl << "1. Helm";
	std::cout << std::endl << "2. Napiersnik";
	std::cout << std::endl << "3. Buty";
	std::cin >> choice_armor;
	std::cout << "Koszt naprawy to: ";
	switch (choice_armor)
	{
	case 1:
		std::cout << rep_cost;
		pay(rep_cost);
		break;
	case 2:
		//
		break;
	case 3:
		//
		break;
	default:
		std::cout << "Cos nie pyklo, nie ma pan takiej zbroi";
		break;
	}

}

void Non_Character::pay(int cost)
{
	char paying_choice = 'o';
	bool number = 0;
	Armor thing2;
	std::cout << std::endl << "Placisz? (y/n)";
	while (paying_choice != 'y' || paying_choice != 'n')
	{
		if (number == 1) std::cout << std::endl << "To tak, czy nie? (y/n)";
		std::cin >> paying_choice;
		number = 1;
	}
	switch (paying_choice)
	{
	case 'y':
		if (gold < cost)
			std::cout << std::endl << "Chyba nie masz czym zaplacic. Wroc, gdy uzbierasz cos drobnych";
		else
		{
			gold -= cost;
			thing2.
		}
	}
}
