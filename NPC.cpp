#include "NPC.h"
#include <iostream>
#include "ekwipunek.h"
#include "Square.h"
#include <Windows.h>

void Non_Character::options()
{
	Character* player;

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
			case 1: // sklep //-------------------------//
				//potrzebny plecak
				break;
			case 2: //historia //------------------------//
				talk();
			case 3: //nic lub sprzedarz, lub naprawa
				if (npc_name == "Chemik Renagan")
				{
					std::cout << std::endl << "Podzi�kuj�, nie jestem tutaj, by kupowa�, a by sprzedawac";
					std::cout << std::endl << "A propos sprzedarzy, nie chcia�by pan czegos kupic?";
				}
				else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->charisma < 30))
				{
					std::cout << std::endl << "Nie potrzbuj� teraz wi�kszej ilo�ci baga�u.";
				}
				else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->charisma >= 30))
				{
					std::cout << std::endl << "Nie dam rady odkupi� tego od ciebie, przykro mi";
				}
				else if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")
				{
					repair(); //naprawa
				}
				else if (npc_name == "Handlarz")
				{
					std::cout << std::endl << "Kupic zawsze moge, zawsze sie to pozniej odsprzeda";
					sell(); //sprzedarz
				}
				else if (npc_name == "Zbrojmistrz1" || npc_name == "Zbrojmistrz4" || npc_name == "Zbrojmistrz5" || npc_name == "Zbrojmistrz6")
				{
					std::cout << std::endl << "Nie kupuj� �mieci";
				}
				else if (npc_name == "Zbrojmistrz2" || npc_name == "Zbrojmistrz3")
				{
					std::cout << std::endl << "Nie.";
				}
				else std::cout << std::endl << "nie...";
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
	int nr_choice;
	int  seller; //seller - ma�y wsp�czynnik koszt�w 

	seller = 8 - player->charisma / 5;
	

	if (npc_type == 'C') //chemicy
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
		{
			std::cout << std::endl << "Aktualnie mam takie drobnostki na zbyciu. Jeste� zainteresowany? Jeste�, prawda? Prawda...";
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->charisma >= 15))// 15- jaka� lczba, kt�r� trzeba doustali�
		{
			std::cout << std::endl << "Mie ma tego wiele, ale we�, co chcesz";
			seller = 1;
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->charisma < 15))
		{
			std::cout << std::endl << "Jak zwykle u mnie eliksiry najlepszej jako�ci. Patrz i wybieraj, czego tylko pragniesz.";
			seller = 6;
		}
		else
		{
			std::cout << std::endl << "Tylko niczego nie zbij.";
		}


		for (int i = 0; i < 6; i++) //koszt
		{
			potions[i].eq_cost = 10 * (potions[i].eq_stats[0] + potions[i].eq_stats[1] + potions[i].eq_stats[2] + potions[i].eq_stats[3] + potions[i].eq_stats[4] + potions[i].eq_stats[5] + seller);
		}

		for (int i = 0; i < 6; i += 2) //wypisywanie
		{
			std::cout << std::endl << "nazwa:      " << i + 1 << ". " << potions[i].eq_name << "\t\t\t\t" << i+2 << potions[i + 1].eq_name;
			std::cout << std::endl << "statystyka?:" << potions[i].eq_stats[i] << "\t\t\t\t" << potions[i + 1].eq_stats[i + 1];
			std::cout << std::endl << "koszt:      " << potions[i].eq_cost     << "\t\t\t\t" << potions[i + 1].eq_cost;
			std::cout << std::endl;
		}
		std::cout << std::endl << "To kt�ry z eliksir�w chcia�by� kupi�? ('6' - nie kupuj�)" << std::endl;
		std::cin >> nr_choice;
		
		if (nr_choice > 0 && nr_choice <= 6)
		{
			agreement = pay(potions[nr_choice - 1].eq_cost);
			if (agreement == 1)
			{
				// danie do plecaka przedmiotu przedmiotu o tym numerze ------------------------------------------------------------------//

			}
		}
		else
		{
			std::cout << std::endl << "eh...";
		}
	}
	else if (npc_type == 'Z') //zbrojmistrzowie
	{
		Armor armory[6];
		if (npc_name == "Zbrojmistrz1" || npc_name == "Zbrojmistrz4")
		{
			
			for (int i = 0; i < 6; i++)
			{
				armory[i].armor_name = "He�m";
				armory[i].type_def();
				armory[i].type_stats();
			}

			if (npc_name == "Zbrojmistrz1")
			{
				std::cout << std::endl << "W mojej ofercie aktualnie znajduj� si� tylko takie przedmioty";
			}
			else if (npc_name == "Zbrojmistrz4")
			{
				std::cout << std::endl << "Takie skarbe�ki tu mamy. Na pewno kt�ry� ci si� spodoba!";
			}
			else
			{
				std::cout << std::endl << "Tylko nie zniszcz.";
			}
		}
		else if (npc_name == "Zbrojmistrz2" || npc_name == "Zbrojmistrz5")
		{
			for (int i = 0; i < 6; i++)
			{
				armory[i].armor_name = "Napier�nik";
				armory[i].type_def();
				armory[i].type_stats();
			}

			if (npc_name == "Zbrojmistrz2")
			{
				std::cout << std::endl << "...";
			}
			else if (npc_name == "Zbrojmistrz5")
			{
				std::cout << std::endl << "Takie skarbe�ki tu mamy. Na pewno kt�ry� ci si� spodoba!";
			}
			else
			{
				std::cout << std::endl << "Tylko nie zniszcz.";
			}
		}
		else if (npc_name == "Zbrojmistrz3" || npc_name == "Zbrojmistrz6")
		{
			for (int i = 0; i < 6; i++)
			{
				armory[i].armor_name = "Buty";
				armory[i].type_def();
				armory[i].type_stats();
			}

			if (npc_name == "Zbrojmistrz3")
			{
				std::cout << std::endl << "...To, to prosz� chwilk� zaczeka�, za chwilk� przynios� wszystko, co mam.";
				Sleep(3000);
				std::cout << std::endl << "Prosz�...";
			}
			else if (npc_name == "Zbrojmistrz6")
			{
				std::cout << std::endl << "Takie skarbe�ki tu mamy. Na pewno kt�ry� ci si� spodoba!";
			}
			else
			{
				std::cout << std::endl << "Tylko nie zniszcz.";
			}
		}

		for (int i = 0; i < 6; i++) //koszt
		{
			armory[i].ar_cost = 10 * (armory[i].armor_stats[0] + armory[i].armor_stats[1] + armory[i].armor_stats[2] + armory[i].armor_stats[3] + armory[i].armor_stats[4] + armory[i].armor_stats[5] + seller);
		}

		for (int i = 0; i < 6; i += 2) //wypisywanie nazwy
		{
			std::cout << std::endl << "nazwa:        " << i + 1 << ". " << armory[i].armor_name << "\t\t\t\t" << armory[i + 1].armor_name;
			std::cout << std::endl << "si�a:         " << armory[i].armor_stats[0] << "\t\t\t\t" << armory[i + 1].armor_stats[0];
			std::cout << std::endl << "wytrzyma�o��: " << armory[i].armor_stats[1] << "\t\t\t\t" << armory[i + 1].armor_stats[1];
			std::cout << std::endl << "charyzma:     " << armory[i].armor_stats[2] << "\t\t\t\t" << armory[i + 1].armor_stats[2];
			std::cout << std::endl << "inteligencja: " << armory[i].armor_stats[3] << "\t\t\t\t" << armory[i + 1].armor_stats[3];
			std::cout << std::endl << "zwinno��:     " << armory[i].armor_stats[4] << "\t\t\t\t" << armory[i + 1].armor_stats[4];
			std::cout << std::endl << "szcz�cie:    " << armory[i].armor_stats[5] << "\t\t\t\t" << armory[i + 1].armor_stats[5];
			std::cout << std::endl << "koszt:        " << armory[i].ar_cost        << "\t\t\t\t" << armory[i + 1].ar_cost;
			std::cout << std::endl;
		}
		std::cout << std::endl << "Co kupujesz? ('6' - nie kupuj�)" << std::endl;
		std::cin >> nr_choice;
		if (nr_choice > 0 && nr_choice <= 6)
		{
			agreement = pay(armory[nr_choice - 1].ar_cost);
			if (agreement == 1)
			{
				// danie do plecaka przedmiotu ------------------------------------------------------------------------//

			}
		}
		else
		{
			std::cout << std::endl << "...";
		}
	}
	else if (npc_type == 'H') //handlarz
	{
		bool not_cake=1;
		Equipment special_thing;

		if (not_cake = 1)
		{
			special_thing.eq_name = "special";
		}
		else
		{
			special_thing.eq_name = "ciasto";
		}
		special_thing.usage();

		std::cout << std::endl << "Jest to jedyna taka okazja, lepszej nie b�dzie!";
		special_thing.eq_cost = 1001;
		std::cout << std::endl << "nazwa: " << special_thing.eq_name;
		std::cout << std::endl << "koszt: " << special_thing.eq_cost;
		std::cout << std::endl << "Kupujesz? ('1'-tak, reszta - nie)";
		std::cin >> nr_choice;
		if (nr_choice == 1)
		{
			agreement = pay(special_thing.eq_cost);
			if (agreement == 1)
			{
				// danie do plecaka przedmiotu ------------------------------------------------------------------------//

				not_cake = 0;
			}
		}
		else
		{
			std::cout << std::endl << "Nie martw si�, b�dzie to na ciebie czeka� a� kiedy� kupisz.";
		}
	}
	else if (npc_type == 'K') //kowal
	{
		Weapon weaps[6];
		for (int i = 0; i < 6; i++)
		{
			weaps[0].weapon_statistics_name();
		}

		if (npc_name == "Kowal Gregori")
		{
			std::cout << std::endl << "Wygl�dasz jak " << player->GetProffesion() << ". Masz, takie rzeczy s� dla takich jak ty.";
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << std::endl << "Ty� jest ten, no... " << player->GetProffesion() << "! To dla ciebie.";
		}
	
		for (int i = 0; i < 6; i++) //koszt
		{
			weaps[i].we_cost = 10 * (weaps[i].weapon_stats[0] + weaps[i].weapon_stats[1] + weaps[i].weapon_stats[2] + weaps[i].weapon_stats[3] + weaps[i].weapon_stats[4] + weaps[i].weapon_stats[5] + seller);
		}

		for (int i = 0; i < 6; i+=2) //wypisanie
		{
			std::cout << std::endl << "nazwa:        " << i + 1 << ". " << weaps[i].we_name << "\t\t\t\t" << weaps[i + 1].we_name;
			std::cout << std::endl << "si�a:         " << weaps[i].weapon_stats[0] << "\t\t\t\t" << weaps[i + 1].weapon_stats[0];
			std::cout << std::endl << "wytrzyma�o��: " << weaps[i].weapon_stats[1] << "\t\t\t\t" << weaps[i + 1].weapon_stats[1];
			std::cout << std::endl << "charyzma:     " << weaps[i].weapon_stats[2] << "\t\t\t\t" << weaps[i + 1].weapon_stats[2];
			std::cout << std::endl << "inteligencja: " << weaps[i].weapon_stats[3] << "\t\t\t\t" << weaps[i + 1].weapon_stats[3];
			std::cout << std::endl << "zwinno��:     " << weaps[i].weapon_stats[4] << "\t\t\t\t" << weaps[i + 1].weapon_stats[4];
			std::cout << std::endl << "szcz�cie:    " << weaps[i].weapon_stats[5] << "\t\t\t\t" << weaps[i + 1].weapon_stats[05];
			std::cout << std::endl << "koszt:        " << weaps[i].we_cost		   << "\t\t\t\t" << weaps[i + 1].we_cost;
			std::cout << std::endl;


		}

		std::cout << std::endl << "Kupujesz co�? ('6' - nie kupuj�)" << std::endl;
		std::cin >> nr_choice;
		if (nr_choice > 0 && nr_choice <= 6)
		{
			agreement = pay(weaps[nr_choice - 1].we_cost);
			if (agreement == 1)
			{
				// danie do plecaka przedmiotu ------------------------------------------------------------------------//

			}
		}
		else
		{
			std::cout << std::endl << "I po co to wyci�ga�em?!";
		}
	}
	//potrzebny plecak
}

void Non_Character::sell()
{
	Character* player;
	bool sell_more = 1;
	int nr_choice;
	int  seller;
	seller = 8 - player->charisma / 7;

	std::cout << std::endl << "C� takiego chcia�y� mi ooda�?";
	while(sell_more == 1)
	{
		//pokazanie przedmiot�w z plecaka -------------------------------------------------------------------//

		std::cin >> nr_choice;
		if (nr_choice > 0 && nr_choice < ile�tam) //maksymalna obj�to�� plecaka +1 ----------------------------------------------//
		{
			// zabranie z plecaka przedmiotu ------------------------------------------------------------------------//
			gold += 6 * (statystyki_przedmiotu - seller);
		}
		else
		{
			std::cout << "czyli jednak rozmy�li� si� Pan?";
		}

		std::cout << "Chcia�by� odda� co� jeszcze? (1 - tak, 0 - nie)";
		std::cin >> sell_more;
	}
	//potrzebny  plecak
}

void Non_Character::repair()
{
	int przelicznik_ceny = 1, choice_armor;
	float rep_cost;
	Armor thing1; //-------------------------------------------------|| odwo�ywa� si� powinno do za�o�onej cz�ci zbroi, nie wiem, jak zrobi�
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
			std::cout << std::endl << "Chyba nie masz czym zap�aci�. Wr��, gdy uzbierasz nieco drobnych";
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
			std::cout << std::endl << "Przyjezdny widz�, niekt tendy nie przeje�d�a. Tego jestem pewna.";
			Sleep(750);
			std::cout << std::endl << "Wola�abym, by Pan szybko kupi� pan szybko to, co chce i odszed�. Nie mam czasu, musz� si� pakowa�...";
			Sleep(1000);
			std::cout << std::endl << "Poza tym wygl�da pan do��... nieprzyja�nie";
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false))
		{
			std::cout << std::endl << "Ah... dzie� dobry. Nazywam si� Beatrycze, ale wi�kszo�� ludzi mo�e mi m�wi� Beti";
			Sleep(500);
			std::cout << std::endl << "Oczywi�cie r�wnie� i ty mo�esz mnie tak nazywa�, je�li tylko wejdziesz do mojego sklepiku.";
			Sleep(400);
			std::cout << std::endl << "Usi�dziemy w spokojnym zau�ku, z dala od poj�kiwa� potwor�w.";
			Sleep(600);
			std::cout << std::endl << "Porozmawiamy sobie przy herbatce.";
			Sleep(600);
			std::cout << std::endl << "Prosz�, nie zwracaj wi�kszej uwagi na ba�agan, w�a�nie si� pakuj�.";
			Sleep(600);
			std::cout << std::endl << "To miejsce staje si� gorsze z dnia na dzie�, czuj�, �e musz� wyjecha�.";
			Sleep(600);
			std::cout << std::endl << "A tak poza tym...";
			Sleep(500);
			std::cout << std::endl << "zosta�o mi jeszcze kilkana�cie eliksir�w. Mog� ci je odsprzeda� za ni�sz� cen�.";
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori")
		{
			std::cout << std::endl << "Czego?";
			Sleep(300);
			std::cout << std::endl << "...";
			Sleep(1250);
			std::cout << std::endl << "Je�li chcesz bro�, to trzeba by�o gada�!";
			Sleep(400);
			std::cout << std::endl << "*pod nosem* Ah, ci aroganccy poszukiwacze guz�w i nieszcz�cia";
			Sleep(500);
		}
		else if (npc_name == "Kowal Andrzej")
		{
			std::cout << std::endl << "Czego?!";
			Sleep(800);
			std::cout << std::endl << "Nie przeszkadza�, zaj�ty jestem!";
			Sleep(700);
			std::cout << std::endl << "A, chcesz naprawi� zbroj�. To dawaj!";
			Sleep(500);
			std::cout << std::endl << "...";
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << std::endl << "Oh, witam przybysza. Sk�d Pan przyby�?";
			Sleep(400);
			std::cout << std::endl << "Na pewno z daleka, taka cera nie bierze si� z nik�d.";
			Sleep(400);
			std::cout << std::endl << "C� takiego robi Pan w naszych skromnych, aktualnie do�� nieprzyjemnych progach?";
			Sleep(400);
			std::cout << std::endl << "Mo�e chcia�by pan by� naszym wybawc� i zniszczy� te okropne stwory, szw�daj�ce si� wsz�dzie po okolicy?";
			Sleep(400);
			std::cout << std::endl << "Wiem, co takiej osobie jak Pan mo�e si� przyda�, prosz� za mn� do sklepu!";
			Sleep(600);
		}
		else if (npc_name == "Zbrojmistrz1")
		{
			std::cout << std::endl << "O, klient! Zapraszam! Niecz�sto zdarza mi si� ostatnio mie� kogokolwiek,";
			std::cout << std::endl << "dlatego mam do�� du�o produk�w na zbyciu.";
			Sleep(600);
			std::cout << std::endl << "Do wyboru do koloru, wed�ug uznania i preferencji.";
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz2")
		{
			std::cout << std::endl << "...";
			Sleep(700);
			std::cout << std::endl << "...";
			Sleep(500);
			std::cout << std::endl << "...";
			Sleep(300);
		}
		else if (npc_name == "Zbrojmistrz3")
		{
			std::cout << std::endl << "Co?";
			Sleep(500);
			std::cout << std::endl << "A tak, tak... dzie� dobry.";
			Sleep(500);
			std::cout << std::endl << "W czym mog� pom�c?";
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

		first_time = 0;
	}
	else if (first_time == 0)
	{
		if (npc_name == "Chemik Renagan")
		{
			std::cout << std::endl << "Witam ponownie! Jak tam sie korzysta�o z moich wyrob�w? Dobrze?";
			Sleep(400);
			std::cout << std::endl << "No oczywi�cie, �e Dobrze! Wybornie! To jak, przyszedl Pan po wiecej, prawda?";
			Sleep(400);
			std::cout << std::endl << "Jak�e by inaczej! Nieinaczej? No oczywi�cie...";
			Sleep(500);
			std::cout << std::endl << "Porozmawiajmy wi�c o interesach.";
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() != PROFF_BARD || player->GetSex() == false || player->charisma < 30))
		{
			std::cout << std::endl << "To ponownie Pan...";
			Sleep(1250);
			std::cout << std::endl << "Prosz� wej�� i wzi�� to, co jest Panu potrzebne.";
			Sleep(500);
			std::cout << std::endl << "Byle szybko, zaj�ta jestem, nie wida�?";
			Sleep(500);
		}
		else if (npc_name == "Chemik Beatrycze" && (player->GetProffesion() == PROFF_BARD || player->GetSex() != false || player->charisma >= 30))
		{
			std::cout << std::endl << "Witam ponownie! Osobi�cie - spodziewa�am si�, �e jeszcze ci� zobacz�,";
			Sleep(400);
			std::cout << std::endl << "ale, dzi�ki Bogu, uda�o ci si� prze�y� w tym okropnym miejscu.";
			Sleep(700);
			std::cout << std::endl << "Prosz�, wejd�, jeszze niesko�czy�am si� pakowa�, wi�c mo�esz si� rozgo�ci�.";
			Sleep(500);
		}
		else if (npc_name == "Kowal Gregori" || npc_name == "Kowal Andrzej")
		{
			std::cout << std::endl << "A, to ty..." << std::endl << "Popatrz se i m�w, czego chcesz.";
			Sleep(500);
		}
		else if (npc_name == "Handlarz")
		{
			std::cout << std::endl << "Dzie� dobry, co tym razem chcia�by Pan kupi�? Osobi�cie poleci�bym ciasto.";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz1")
		{
			std::cout << std::endl << "Zapraszam!...";
			Sleep(1000);
			std::cout << std::endl << "Kojarz� Pana i ciesz� si�, �e jest Pan zainteresowany moimi ofertami!";
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
			std::cout << std::endl << "o... witam ponownie, nie zauwa�y�em Pana.";
			Sleep(900);
			std::cout << std::endl << "W czym pom�c?";
			Sleep(500);
		}
		else if (npc_name == "Zbrojmistrz4")
		{
			std::cout << std::endl << "Czaaaapki, kapelusze, he�mym, bereeetyyy!";
			Sleep(600);
			std::cout << std::endl << "Ceny niskie, co� na g�ow� - same zleeetyyy!";
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
			std::cout << std::endl << "Stopy go�e - c� pomo�e?";
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
	Character* player;
	if (player->charisma < 25)
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
		else if (npc_name == "Zbrojmistrz1")
		{

		}
		else if (npc_name == "Zbrojmistrz2")
		{
			std::cout << std::endl << "...";
			Sleep(1000);
			std::cout << std::endl << "Nie.";
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz3")
		{

		}
		else if (npc_name == "Zbrojmistrz4")
		{

		}
		else if (npc_name == "Zbrojmistrz5")
		{

		}
		else if (npc_name == "Zbrojmistrz6")
		{

		}
	}
	else if(player->charisma >= 25)
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
		else if (npc_name == "Zbrojmistrz1")
		{

		}
		else if (npc_name == "Zbrojmistrz2")
		{
			std::cout << std::endl << "...";
			Sleep(1000);
			std::cout << std::endl << "Nie.";
			Sleep(1000);
		}
		else if (npc_name == "Zbrojmistrz3")
		{

		}
		else if (npc_name == "Zbrojmistrz4")
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

