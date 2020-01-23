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
		potions[3].eq_name == "roztwor wroñskianu potasu";
		potions[4].eq_name == "sok z gumijagod";
		potions[5].eq_name == "wywar z totolotka";

		for (int i = 0; i < 6; i++)
		{
			potions[i].give_statistics();
			potions[i].usage();
		}

		if (npc_name == "Chemik Renagan")
			std::cout << std::endl << "Aktualnie mam takie drobnostki na zbyciu. Jesteœ zainteresowany? jesteœ?";
		else if (npc_name == "Chemik Beatrycze" && (player->GetSex() == true || player->GetProffesion() == PROFF_BARD || player->charisma >= 15))// 15- jakaœ lczba, któr¹ trzeba doustaliæ
			std::cout << std::endl << "Jak zwykle u mnie eliksiry najlepszej jakoœci. Patrz i wybieraj, czego tylko pragniesz.";
		else
			std::cout << std::endl << "Tylko niczego nie zbij.";

		for (int i = 0; i < 6; i += 2)
		{
		std::cout << std::endl << i + 1 << ". " << potions[i].eq_name;
		std::cout << "\t\t\t\t" << potions[i + 1].eq_name;
		std::cout << std::endl << potions[i].eq_stats[i];
		std::cout << "\t\t\t\t" << potions[i + 1].eq_stats[i + 1];
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
	case 1:  //dla helmu ------------------------------------------|| aktualnie ni ma ró¿nicy. Trzeba zrobiæ, by wybiera³o jeden z przedmiotów
		std::cout << rep_cost;
		if (pay(rep_cost) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		else break;
	case 2://dla Napierœnika
		std::cout << rep_cost;
		if (pay(rep_cost) == 1)
		{
			thing1.durability_cur = thing1.durability_max;
			break;
		}
		else break;
	case 3: //dla Butów
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
			gold -= cost;  //orygina³ golda potrzbny, by go zmieniaæ!
			return 1;
		}
	case 'n':
		std::cout << std::endl << "No có¿...";
		return 0;
	}
}

void Non_Character::opening_talk(char npc_world[3][3][15][15]) //zrobiæ dialog w zale¿noœci od p³ci bohatera
{
	Character* player;

	if (first_time == 1)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << std::endl << "Witam, witam! Pan tu chyba nowy? Nienowy? No nowy Pan tu, nie inaczej!";
			Sleep(600);
			std::cout << std::endl << "A czego Pan potrzebuje? Zió³ek? Broni? Nie? No oczywiscie, ¿e nie!";
			Sleep(400);
			std::cout << std::endl << "Nie po to pan przyszed³ akurat do mnie. Czy jednak nie? oczywiœcie!";
			Sleep(400);
			std::cout << std::endl << "Oczywiœcie, ¿e Pan chcia³ przyjœæ tutaj, w moje progi. Oczywiœcie... ";
			Sleep(400);
			std::cout << std::endl << "To jak, o czym chcia³by Pan ze mn¹ porozmawiaæ?";
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
			std::cout << std::endl << "Dzieñ dobry.";
			Sleep(750);
			std::cout << std::endl << "Pan tu nowy. Tego jestem pewna.";
			Sleep(750);
			std::cout << std::endl << "Wola³abym, by Pan szybko kupi³ pan szybko to, co chce i odszed³. Straszy mi pan klientów...";
			Sleep(1000);
			std::cout << std::endl << "Wygl¹da pan doœæ... nieprzyjaŸnie";
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false))
		{
			std::cout << std::endl << "Ah... dzieñ dobry. Nazywam siê Beatrycze, ale wiêkszoœæ ludzi mo¿e mi mówiæ Beti";
			Sleep(500);
			std::cout << std::endl << "Oczywiœcie równie¿ i ty mo¿esz mnie tak nazywaæ, jeœli tylko wejdziesz do mojego sklepiku.";
			Sleep(400);
			std::cout << std::endl << "Porozmawiamy sobie przy herbatce. Opowiesz, jak tam poza wiosk¹ ¿ycie wygl¹da.";
			Sleep(400);
			std::cout << std::endl << "Na pewno masz wiele historii, które s¹ warte opowiedzenia.";
			Sleep(400);
			std::cout << std::endl << "A przy okazji mo¿e zobaczysz na mój ma³y sk³adzik eliksirów.";
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori")
		{
			std::cout << std::endl << "Czego?";
			Sleep(300);
			std::cout << std::endl << "...";
			Sleep(1250);
			std::cout << std::endl << "Jeœli chcesz broñ, to trzeba by³o gadaæ!";
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << std::endl << "Czego?!";
			Sleep(800);
			std::cout << std::endl << "Nie przeszkadzaæ, zajêty jestem!";
			Sleep(700);
			std::cout << std::endl << "A, chcesz naprawiæ zbrojê. To dawaj!" << std::endl << "...";
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << std::endl << "Oh, witam przybysza. Sk¹d Pan przyby³?";
			Sleep(400);
			std::cout << std::endl << "Na pewno z daleka, taka cera nie bierze siê z nik¹d.";
			Sleep(400);
			std::cout << std::endl << "Có¿ takiego robi Pan w naszych skromnych progach?";
			Sleep(400);
			std::cout << std::endl << "Mo¿e chcia³by pan byæ naszym wybawc¹ i zniszczyæ te okropne stwory, szwêdaj¹ce siê wszêdzie po okolicy?";
			Sleep(400);
			std::cout << std::endl << "Wiem, co takiej osobie jak Pan mo¿e siê przydaæ, proszê za mn¹ do sklepu!";
			Sleep(600);
		}
		else if (npc_name == "Zbrojmistrz1") //ma byæ 6
		{
			std::cout << std::endl << "O, klient! Zapraszam. Nieczêsto zdarza mi siê mieæ kogokolwiek, dlatego mam doœæ du¿o produków na zbyciu.";
			Sleep(400);
			std::cout << std::endl << "Do wyboru do koloru, wed³ug uznania i preferencji.";
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz2") //ma byæ 6
		{
			std::cout << std::endl << "...";
			Sleep(700);
			std::cout << std::endl << "...";
			Sleep(500);
			std::cout << std::endl << "...";
			Sleep(300);
		}
		else if (npc_name == "Zbrojmistrz3") //ma byæ 6
		{
			std::cout << std::endl << "Co?";
			Sleep(500);
			std::cout << std::endl << "A tak, tak... dzieñ dobry.";
			Sleep(500);
			std::cout << std::endl << "W czymœ pomóc?";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz4") //ma byæ 6
		{
			std::cout << std::endl << "Czaaaapki, kapelusze, he³mym, bereeetyyy!";
			Sleep(600);
			std::cout << std::endl << "Ceny niskie i coœ na g³owê, same zleeetyyy!";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz5") //ma byæ 6
		{
			std::cout << std::endl << "Bluuuzy, kurtki, zbrooooje!";
			Sleep(600);
			std::cout << std::endl << "Mam tu wszyyystkie modne stroje!";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz6") //ma byæ 6
		{
			std::cout << std::endl << "Stopy go³e, có¿ pomo¿e?";
			Sleep(600);
			std::cout << std::endl << "A me butki! A to mo¿e!";
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
			std::cout << std::endl << "Proszê wejœæ i wzi¹æ to, co jest Panu potrzebne.";
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->charisma >= 30))
		{
			std::cout << std::endl << "Witam ponownie, nie spodziewa³am siê teraz nag³ych klientów, ale proszê wejœæ.";
			Sleep(700);
			std::cout << std::endl << "Dziœ jest dok³adnie to, co zawsze, wiêc nie ma co zwlekaæ, proszê mówiæ, czego potrzeba!";
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")
		{
			std::cout << std::endl << "A, to ty..." << std::endl << "Popatrz se i mów, czego chcesz.";
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << std::endl << "Dzieñ dobry, co tym razem chcia³by Pan kupiæ?";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz1")
		{
			std::cout << std::endl << "Zapraszam!...";
			Sleep(1000);
			std::cout << " Kojarzê Pana, cieszê siê, ¿e jesp Pan zainteresowany moimi ofertami!";
			Sleep(500);
			std::cout << std::endl << "S³ucham, czego Pan szuka? W czym mogê pomóc?";
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
			std::cout << std::endl << "o... witam ponownie, nie auwa¿y³em Pana.";
			Sleep(900);
			std::cout << std::endl << "W czym pomóc?";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz4")
		{
			std::cout << std::endl << "Czaaaapki, kapelusze, he³mym, bereeetyyy!";
			Sleep(600);
			std::cout << std::endl << "Ceny niskie i coœ na g³owê, same zleeetyyy!";
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
			std::cout << std::endl << "Stopy go³e, có¿ pomo¿e?";
			Sleep(600);
			std::cout << std::endl << "A me butki! A to mo¿e!";
			Sleep(500);
		}
	}
	else
	{
		std::cout << std::endl << "Popsuted dzieñ dobry.";
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

