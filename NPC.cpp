#include "NPC.h"
#include <iostream>
#include "ekwipunek.h"
#include "Square.h"
#include <Windows.h>

void Non_Character::options()
{
	while (quit == 0)
	{
		if (npc_name != "Wiesniak")
		{
			std::cout << std::endl << "'1' - sklep";
			std::cout << std::endl << "'2' - rozmowa";
			if (npc_name == "Kowal")		std::cout << std::endl << "'3' - naprawa zbroi";
			else							std::cout << std::endl << "'3' - sprzedarz";
			std::cout << std::endl << "'4' - wyjscie" << std::endl;

			std::cin >> choice;
			switch (choice)
			{
			case 1: // sklep //-------------------------
				//potrzebny plecak
				break;
			case 2: //historia //------------------------
				talk();
			case 3:
				if (npc_name == "Chemik")
				{
					std::cout << std::endl << "Podzi�kuj�, nie jestem tutaj, by kupowa�, a by sprzedawac";
					std::cout << std::endl << "A propos sprzedarzy, nie chcia�by pan czegos kupic?";
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
					std::cout << std::endl << "Nie kupuj� �mieci";
				}
				break;
			case 4:
				quit = 1;
				break;
			default:
				std::cout << std::endl << "Nie ma takiej opcji";
			}
		}
	}
	quit = 0;
}

void Non_Character::buy()
{
	Character* player;
	bool agreement; // 0-nie, 1-tak;
	short int nr_choice;
	if (npc_type == 'C')
	{
		Equipment potions[6];
		potions[0].eq_name == "eliksir Galow";
		potions[1].eq_name == "wywar z czerwonego byka";
		potions[2].eq_name == "retoryka w butelce";
		potions[3].eq_name == "roztwor wro�skianu potasu";
		potions[4].eq_name == "sok z gumijagod";
		potions[5].eq_name == "wywar z totolotka";

		for (int i = 0; i < 6; i++)
		{
			potions[i].give_statistics();
			potions[i].usage();
		}

		if (npc_name == "Chemik Renagan")
			std::cout << std::endl << "Aktualnie mam takie drobnostki na zbyciu. Jeste� zainteresowany? jeste�?";
		else if (npc_name == "Chemik Beatrycze" && (player->GetSex() == true || player->GetProffesion() == PROFF_BARD || player->charisma >= 15))// 15- jaka� lczba, kt�r� trzeba doustali�
			std::cout << std::endl << "Jak zwykle u mnie eliksiry najlepszej jako�ci. Patrz i wybieraj, czego tylko pragniesz.";
		else
			std::cout << std::endl << "Tylko niczego nie zbij.";

		for (int i = 0; i < 6; i += 2)
		{
		std::cout << std::endl << i + 1 << ". " << potions[i].eq_name;
		std::cout << "\t\t\t\t" << potions[i + 1].eq_name;
		std::cout << std::endl << potions[i].eq_stats[i];
		std::cout << "\t\t\t\t" << potions[i + 1].eq_stats[i + 1];
		}
		std::cout << std::endl << "Aktualnie wszystko kosztuje 50 dukat�w";
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
	case 1:  //dla helmu ------------------------------------------|| aktualnie ni ma r�nicy. Trzeba zrobi�, by wybiera�o jeden z przedmiot�w
		std::cout << rep_cost;
		if (pay(rep_cost) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		else break;
	case 2://dla Napier�nika
		std::cout << rep_cost;
		if (pay(rep_cost) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		else break;
	case 3: //dla But�w
		std::cout << rep_cost;
		if (pay(rep_cost) == 1)
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
			gold -= cost;  //orygina� golda potrzbny, by go zmienia�!
			return 1;
		}
	case 'n':
		std::cout << std::endl << "No c�...";
		return 0;
	}
}

void Non_Character::opening_talk(char npc_world[3][3][15][15]) //zrobi� dialog w zale�no�ci od p�ci bohatera
{
	Character* player;

	if (first_time == 1)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << std::endl << "Witam, witam! Pan tu chyba nowy? Nienowy? No nowy Pan tu, nie inaczej!";
			Sleep(600);
			std::cout << std::endl << "A czego Pan potrzebuje? Zi�ek? Broni? Nie? No oczywiscie, �e nie!";
			Sleep(400);
			std::cout << std::endl << "Nie po to pan przyszed� akurat do mnie. Czy jednak nie? oczywi�cie!";
			Sleep(400);
			std::cout << std::endl << "Oczywi�cie, �e Pan chcia� przyj�� tutaj, w moje progi. Oczywi�cie... ";
			Sleep(400);
			std::cout << std::endl << "To jak, o czym chcia�by Pan ze mn� porozmawia�?";
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false))
		{
			std::cout << std::endl << ".";
			Sleep(1000);
			std::cout << ".";
			Sleep(1000);
			std::cout << ".";
			Sleep(1000);
			std::cout << std::endl << "Dzie� dobry.";
			Sleep(750);
			std::cout << std::endl << "Pan tu nowy. Tego jestem pewna.";
			Sleep(750);
			std::cout << std::endl << "Wola�abym, by Pan szybko kupi� pan szybko to, co chce i odszed�. Straszy mi pan klient�w...";
			Sleep(1000);
			std::cout << std::endl << "Wygl�da pan do��... nieprzyja�nie";
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false))
		{
			std::cout << std::endl << "Ah... dzie� dobry. Nazywam si� Beatrycze, ale wi�kszo�� ludzi mo�e mi m�wi� Beti";
			Sleep(500);
			std::cout << std::endl << "Oczywi�cie r�wnie� i ty mo�esz mnie tak nazywa�, je�li tylko wejdziesz do mojego sklepiku.";
			Sleep(400);
			std::cout << std::endl << "Porozmawiamy sobie przy herbatce. Opowiesz, jak tam poza wiosk� �ycie wygl�da.";
			Sleep(400);
			std::cout << std::endl << "Na pewno masz wiele historii, kt�re s� warte opowiedzenia.";
			Sleep(400);
			std::cout << std::endl << "A przy okazji mo�e zobaczysz na m�j ma�y sk�adzik eliksir�w.";
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori")
		{
			std::cout << std::endl << "Czego?";
			Sleep(300);
			std::cout << std::endl << "...";
			Sleep(1250);
			std::cout << std::endl << "Je�li chcesz bro�, to trzeba by�o gada�!";
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << std::endl << "Czego?!";
			Sleep(800);
			std::cout << std::endl << "Nie przeszkadza�, zaj�ty jestem!";
			Sleep(700);
			std::cout << std::endl << "A, chcesz naprawi� zbroj�. To dawaj!" << std::endl << "...";
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << std::endl << "Oh, witam przybysza. Sk�d Pan przyby�?";
			Sleep(400);
			std::cout << std::endl << "Na pewno z daleka, taka cera nie bierze si� z nik�d.";
			Sleep(400);
			std::cout << std::endl << "C� takiego robi Pan w naszych skromnych progach?";
			Sleep(400);
			std::cout << std::endl << "Mo�e chcia�by pan by� naszym wybawc� i zniszczy� te okropne stwory, szw�daj�ce si� wsz�dzie po okolicy?";
			Sleep(400);
			std::cout << std::endl << "Wiem, co takiej osobie jak Pan mo�e si� przyda�, prosz� za mn� do sklepu!";
			Sleep(600);
		}
		else if (npc_name == "Zbrojmistrz1") //ma by� 6
		{
			std::cout << std::endl << "O, klient! Zapraszam. Niecz�sto zdarza mi si� mie� kogokolwiek, dlatego mam do�� du�o produk�w na zbyciu.";
			Sleep(400);
			std::cout << std::endl << "Do wyboru do koloru, wed�ug uznania i preferencji.";
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz2") //ma by� 6
		{
			std::cout << std::endl << "...";
			Sleep(700);
			std::cout << std::endl << "...";
			Sleep(500);
			std::cout << std::endl << "...";
			Sleep(300);
		}
		else if (npc_name == "Zbrojmistrz3") //ma by� 6
		{
			std::cout << std::endl << "Co?";
			Sleep(500);
			std::cout << std::endl << "A tak, tak... dzie� dobry.";
			Sleep(500);
			std::cout << std::endl << "W czym� pom�c?";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz4") //ma by� 6
		{
			std::cout << std::endl << "Czaaaapki, kapelusze, he�mym, bereeetyyy!";
			Sleep(600);
			std::cout << std::endl << "Ceny niskie i co� na g�ow�, same zleeetyyy!";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz5") //ma by� 6
		{
			std::cout << std::endl << "Bluuuzy, kurtki, zbrooooje!";
			Sleep(600);
			std::cout << std::endl << "Mam tu wszyyystkie modne stroje!";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz6") //ma by� 6
		{
			std::cout << std::endl << "Stopy go�e, c� pomo�e?";
			Sleep(600);
			std::cout << std::endl << "A me butki! A to mo�e!";
			Sleep(500);
		}

		first_time = 0;
	}
	else if (first_time == 0)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << std::endl << "Witam ponownie! Jak tam sie korzystalo z moich wyrobow?";
			Sleep(400);
			std::cout << std::endl << "Wiedzialem, ze wybornie! To jak, przyszedl Pan po wiecej?";
			Sleep(400);
			std::cout << std::endl << "To jak, porozmawiamy o interesach?";
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->charisma < 30))
		{
			std::cout << std::endl << "To ponownie Pan...";
			Sleep(1250);
			std::cout << std::endl << "Prosz� wej�� i wzi�� to, co jest Panu potrzebne.";
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->charisma >= 30))
		{
			std::cout << std::endl << "Witam ponownie, nie spodziewa�am si� teraz nag�ych klient�w, ale prosz� wej��.";
			Sleep(700);
			std::cout << std::endl << "Dzi� jest dok�adnie to, co zawsze, wi�c nie ma co zwleka�, prosz� m�wi�, czego potrzeba!";
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")
		{
			std::cout << std::endl << "A, to ty..." << std::endl << "Popatrz se i m�w, czego chcesz.";
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << std::endl << "Dzie� dobry, co tym razem chcia�by Pan kupi�?";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz1")
		{
			std::cout << std::endl << "Zapraszam!...";
			Sleep(1000);
			std::cout << " Kojarz� Pana, ciesz� si�, �e jesp Pan zainteresowany moimi ofertami!";
			Sleep(500);
			std::cout << std::endl << "S�ucham, czego Pan szuka? W czym mog� pom�c?";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz2") 
		{
			std::cout << std::endl << "...";
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz3") 
		{
			std::cout << std::endl << "...";
			Sleep(500);
			std::cout << std::endl << "o... witam ponownie, nie auwa�y�em Pana.";
			Sleep(900);
			std::cout << std::endl << "W czym pom�c?";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz4")
		{
			std::cout << std::endl << "Czaaaapki, kapelusze, he�mym, bereeetyyy!";
			Sleep(600);
			std::cout << std::endl << "Ceny niskie i co� na g�ow�, same zleeetyyy!";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz5") 
		{
			std::cout << std::endl << "Bluuuzy, kurtki, zbrooooje!";
			Sleep(600);
			std::cout << std::endl << "Mam tu wszyyystkie modne stroje!";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz6")
		{
			std::cout << std::endl << "Stopy go�e, c� pomo�e?";
			Sleep(600);
			std::cout << std::endl << "A me butki! A to mo�e!";
			Sleep(500);
		}
	}
	else
	{
		std::cout << std::endl << "Popsuted dzie� dobry.";
		Sleep(300);
	}


}

void Non_Character::talk()
{
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
}

