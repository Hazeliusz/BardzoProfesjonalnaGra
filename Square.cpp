#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include "Square.h"
#include <conio.h>



Square::Square(Character* player)
{
	this->player = player;
	std::fstream plik;
	plik.open("Whole.txt", std::ios::in);
	if (plik.good() == false)
	{
		std::cout << "Nie mozna otworzyc pliku!";
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 15; k++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int l = 0; l < 15; l++)
					{
						plik >> tab[i][j][k][l];
					}
				}
			}
		}
		plik.close();
	}


	b = 2; a = 0; y = 12; x = 1;
	b0 = b; a0 = a; y0 = y; x0 = x;
	tab[b][a][y][x] = 'U';
	bufor = '-';
}

void Square::check()
{
	if (b == 0 && a == 0) //lewy górny róg ,,du¿ej'' mapy
	{
		if (x == 2 && y == 1) //Chemik
		{

		}
		else if (x == 4 && y == 1) //Zbrojomistrz 1
		{

		}
		else if (x == 6 && y == 1) //Zbrojomistrz 2
		{

		}
		else if (x == 1 && y == 2) //Kowal
		{

		}
		else if (x == 1 && y == 4) //Zbrojomistrz 3
		{

		}
		else if (x == 1 && y == 6) //Handlarz
		{

		}
		else if (x == 1 && y == 11) //NPC 1 w domku 1
		{
			std::cout << "Jesteœ kolejnym ze znamieniem Utriona?! Tfu!\n.\nMasz szczêœcie, jednego ju¿ wyrzuciliœmy!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 1 && y == 10) //NPC 2 w domku 1
		{
			std::cout << "Szkoda, ¿e nasze targowisko zosta³o ostatnim w Borknagarze...\nKiedyœ przybywali tu handlarze z najdalszych zak¹tków,\nnawet z Sahri i Gerfhritu.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 2 && y == 9) //NPC 3 w domku 1
		{
			std::cout << "Lustro...\nspe³nia ¿yczenia...\nale nikt go nigdy nie widzia³...\nto ju¿ chyba 200 lat jak zaginê³o...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 10 && y == 1) //NPC 1 w domku 2
		{
			std::cout << "Dobrze, ¿e schowa³em swoje z³oto przy murze klasztoru.\nW dzisiejszych czasach nie mo¿na byæ pewnym niczego.\n.\nUgh, nie pods³uchuj brudasie!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 9 && y == 2) //NPC 2 w domku 2
		{
			std::cout << "To mniszka zmienia³a pory roku.\nPodobno u¿ywa³a do tego jakiegoœ artefaktu...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 11 && y == 8) //NPC przy znaku ,,+''
		{
			std::cout << "S³ysza³am, ¿e problemy w Borknagarze zaczê³y siê, gdy \nktoœ wymordowa³ wszystkich mnichów.\nNie wiem czy to prawda, ale to i tak okropne...\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 0 && a == 1) //zamek
	{
		if (x == 3 && y == 13) //przedmiot przy wejœciu
		{

		}
		else if (x == 1 && y == 11) //NPC za zgraj¹ potworów 6 (na dole)
		{
			std::cout << "Utrion! Utrion zabi³ ich wszystkich!\nMnie te¿ zabi³!\nMoja dusza jest przeklêta, bo zgrzeszy³em - teraz muszê siê \nb³¹kaæ po tym klasztorze...\nM¹dra mniszka trzyma³a tutaj Lustro Grizzalidu i spe³nia³a ¿yczenia\ninnych ludzi, którzy byli za g³upi, by w nie patrzeæ! Gdy popatrzy siê w Lustro, ono\npokazuje twoje najskrytsze pragnienie, a potem je spe³nia. \nNiektórzy ludzie byli o to zazdroœni,\na zw³aszcza ten jeden, który w nie spojrza³, choæ nie powinien...\n";
			Sleep(20000);
			system("cls");
		}
		else if (x == 13 && y == 6) //NPC na koñcu tunelu z potworami
		{
			std::cout << "Ma dusza jest przeklêta! Jestem alchemikiem, który stworzy³ Lustro Grizzalidu...\nOno spe³nia ¿yczenia, ale nawet te, których nie chcesz, ¿eby siê spe³ni³y...\nAle nie wiesz, co ono zrobi, dopóki w nie nie spojrzysz...!\nJa mia³em ukryte myœli samobójcze...\nZrobi³em wiele z³ego, teraz za karê muszê ogl¹daæ losy Lustra, a¿ ktoœ go nie zniszczy...\nOno tyle z³eg ju¿ zrobi³o...\nA do tego ostatni¹ rzecz¹, któr¹ zrobi³o, by³o zniszczenie Borknagaru...\n";
			Sleep(20000);
			system("cls");
		}
		/*else if (x == 5 && y == 1) //boss
		{

		}*/
		else if (x == 1 && y == 1) //Lustro Grizzalidu, KONIEC GRY!
		{

		}
	}
	else if (b == 0 && a == 2) //prawy górny róg ,,du¿ej'' mapy
	{
		if (x == 10 && y == 9) //przedmiot obok NPC
		{

		}
		else if (x == 11 && y == 9) //NPC jedyny tutaj
		{
			std::cout << "Dziêkujê za pozbycie siê tej bestii!\n.\nWidzisz przed sob¹ Klasztor Suuomo, to tam mieszka³a legendarna mniszka...\ngdy jeszcze ¿y³a.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 7 && y == 1) //przedmiot za dwoma potworami 8
		{

		}
	}
	else if (b == 1 && a == 0) //czêœæ na pó³noc od startu
	{
		if (x == 4 && y == 10) //NPC w dolnej czêœci
		{
			std::cout << "Na pó³noc st¹d jest targowisko, ale te potê¿ne bestie toruj¹ drogê... \nJu¿ ponad tydzieñ stojê tutaj i czekam a¿ ktoœ siê ich pozbêdzie \ni bêdê móg³ przewieŸæ swoje towary.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 5 && y == 6) //przedmiot za dwoma potworami 4
		{

		}
	 else if (x == 7 && y == 5) //przedmiot za dwoma potworami 5
		{

		}
	 else if (x == 5 && y == 3) //NPC w górnej czêœci
		{
			std::cout << "Wyrzucili mnie z miasta. Powiedzieli, ¿e noszê znamiê Utriona, \nale nie wiem co to znaczy... Ju¿ nie mogê tam wróciæ!\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 1 && a == 1) //œrodek mapy
	{
		if (x == 3 && y == 13) //przedmiot otoczony potworami 7
		{

		}
		else if (x == 1 && y == 7) //przedmiot za zgraj¹ potworów 6
		{

		}
		else if (x == 7 && y == 3) //przedmiot za potworem 7
		{

		}
		else if (x == 6 && y == 6) //NPC jedyny tutaj
		{
			std::cout << "To jest krypta zbudowana dla m¹drej mniszki, \nktóra niegdyœ bardzo pomaga³a mieszkañcom tych ziem. \nMieszkañcy Borknagaru znosili tutaj swoje kosztownoœci w podziêce za to, \nco dla nich zrobi³a.\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 1 && a == 2) //,,twarz demona''
	{
		if (x == 13 && y == 11) //przedmiot za zgraj¹ potworów 7
		{

		}
		else if (x == 7 && y == 2) //NPC jedyny tutaj
		{
			std::cout << "Podobno gdzieœ tutaj mo¿na zobaczyæ twarz Utriona u³o¿on¹ z kamieni.\nSzukam jej ju¿ 3 dni!\nTo tylko legenda, ale i tak nie mam nic do roboty...\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 2 && a == 0) //lewy dolny róg ,,du¿ej'' mapy
	{
		if (x == 1 && y == 13) //NPC przy starcie
		{
			std::cout << "Witaj nieznajomy! Lustro Grizzalidu? Nie wiem czy istnieje naprawdê, \nale wed³ug starych legend znajduje siê w klasztorze Suuomo, \nna pó³nocny wschód st¹d...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 1 && y == 10) //pierwsza broñ
		{

		}
		else if (x == 1 && y == 4) //przedmiot przy lewej granicy
		{

		}
		else if (x == 3 && y == 9) //przedmiot we wnêce za ,,1''
		{

		}
		else if (x == 11 && y == 10) //przedmiot w prawym dolnym rogu
		{

		}
		else if (x == 10 && y == 1) //NPC w prawym górnym rogu
		{
			std::cout << "Pamiêtam, ¿e jak by³em ma³y, w Borknagarze w ogóle nie by³o potworów... \nNie wiem co siê sta³o, ale pewnego dnia, to by³o z 200 lat temu, \nmnisi z klasztoru przestali siê pokazywaæ... \nPewnie potwory dopad³y i ich...\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 2 && a == 1) //wioska
	{
		if (x == 1 && y == 13) //Zbrojomistrz 4
		{

		}
		else if (x == 2 && y == 13) //Zbrojomistrz 5
		{

		}
		else if (x == 3 && y == 13) //Zbrojomistrz 6
		{

		}
		else if (x == 3 && y == 2) //Chemik
		{

		}
		else if (x == 5 && y == 1) //Kowal
		{

		}
		else if (x == 10 && y == 13) //NPC przy dolnej granicy
		{
			std::cout << "Hej, cz³owieku! Wiesz, ¿e w krypcie tak naprawdê nie ma cia³a mniszki? \nOna zmar³a w klasztorze razem z innymi, ale ma³o kto chce o tym pamiêtaæ, \nto jednak dodaje jej chwa³y i powinniœmy o tym mówiæ g³oœno.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 7 && y == 11) //NPC 4 linie od do³u
		{
			std::cout << "Proszê o 5.0!\n";
			Sleep(5000);
			system("cls");
		}
		else if (x == 7 && y == 9) //NPC 1 w domku 1
		{
			std::cout << "Cholera! Przgra³em w grê!\n";
			Sleep(5000);
			system("cls");
		}
		else if (x == 7 && y == 7) //NPC 2 w domku 1
		{
			std::cout << "Szkoda, ¿e prawie wszyscy st¹d pouciekali... \nBorknagar by³ pe³en ludzi przed tamtymi wydarzeniami...\n";
			Sleep(7000);
			system("cls");
		}
		else if (x == 8 && y == 7) //NPC 3 w domku 1
		{
			std::cout << "Kiedyœ wystarczy³o pójœæ do klasztoru i poprosiæ o zimê...\nTo wystarczy³o, ¿eby zacz¹³ padaæ œnieg...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 11 && y == 8) //NPC 1 w domku 2
		{
			std::cout << "Pamiêtam jak w Borknagarze pory roku zmienia³y siê na ¿yczenie... \nale bez tego nie dam rady ju¿ uprawiaæ roli!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 10 && y == 7) //NPC 2 w domku 2
		{
			std::cout << "Czemu bierzesz moje z³oto?! Z£ODZIEJ!!!\n";
			Sleep(4000);
			system("cls");
		}
	}
	else if (b == 2 && a == 2) //prawy dolny róg ,,du¿ej'' mapy
	{
	if (x == 13 && y == 13) //prawy dolny róg
		{

		}
	else if (x == 8 && y == 11) //przedmiot otoczony potworami 3 na dole
	{

	}
	else if (x == 5 && y == 9) //przedmiot za zgraj¹ potworów 2
	{

	}
	else if (x == 4 && y == 5) //NPC za potworem 4 (jedyny tutaj)
	{
		std::cout << "Dziêkujê za ocalenie mi ¿ycia!\nChowa³em siê przed tym potworem kilka godzin!\nJak wchodzi³em do tej jaskini, to go tutaj nie by³o!\n";
		Sleep(10000);
		system("cls");
	}
	else if (x == 7 && y == 9) //przedmiot za dwoma potworami 4
	{

	}
	else if (x == 11 && y == 5) //przedmiot za potworem 6
	{

	}
	}
}

void Square::draw()
{
	system("cls");
	
	switch (bufor)
	{
	case '-':
		{
			break;
		}
	case 'X':
		{
			b = b0;
			a = a0;
			y = y0;
			x = x0;
			break;
		}
		case 'G':
		{
			player->addGold(200);
			break;
		}
		case 'I':
		{
			check();
			break;
		}
		case 'K': case 'Z': case 'C': case 'N': case 'H':
		{
			check();
			b = b0;
			a = a0;
			y = y0;
			x = x0;
			break;
		}
		case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
			Monster *monster = new Monster(bufor);
			CharactersInteractions *interact = new CharactersInteractions(player, monster);
			int result = interact->MonsterFight();
			delete interact;
			delete monster;
		//case '!': specjalna instrukcja do walki z bossem
	}

	tab[b][a][y][x] = 'U';
	std::cout << std::endl;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			std::cout << tab[b][a][i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Square::menu()
{
	int choice;
	std::cout << "1.Poka¿ ekwipunek \n2.Wyœwietl kartê \n3.Za³ó¿ broñ \n4.Za³ó¿ he³m \n5.Za³ó¿ zbrojê \n6.Za³ó¿ buty \n7.U¿yj przedmiot jednorazowy\n";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		player->displayInventory();
		system("pause");
		break;
	}
	case 2:
	{
		player->drawCharacterCard();
		system("pause");
		break;
	}
	case 3:
	{
		player->EquipWeapon();
		system("pause");
		break;
	}
	case 4:
	{
		player->EquipHelmet();
		system("pause");
		break;
	}
	case 5:
	{
		player->EquipArmor();
		system("pause");
		break;
	}
	case 6:
	{
		player->EquipBoots();
		system("pause");
		break;
	}
	case 7:
	{
		player->useEquipment();
		system("pause");
		break;
	}
	}

}

void Square::move()
{
	char arrow;
	arrow = _getch();

	switch (arrow)
	{
	case 'w': case 'W':
	{
		if (tab[b][a][y - 1][x] == '^')
		{
			bufor = tab[b-1][a][13][x];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			b--;
			y = 13;
		}
		else
		{
			bufor = tab[b][a][y - 1][x];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			y--;
		}
		break;
	}
	case 'a': case 'A':
	{
		if (tab[b][a][y][x-1] == '<')
		{
			bufor = tab[b][a-1][y][13];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			a--;
			x = 13;
		}
		else
		{
			bufor = tab[b][a][y][x - 1];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			x--;
		}
		break;
	}
	case 'd': case 'D':
	{
		if (tab[b][a][y][x + 1] == '>')
		{
			bufor = tab[b][a+1][y][1];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			a++;
			x = 1;
		}
		else
		{
			bufor = tab[b][a][y][x + 1];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			x++;
		}
		break;
	}
	case 's': case 'S':
	{
		if (tab[b][a][y + 1][x] == 'v')
		{
			bufor = tab[b+1][a][1][x];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			b++;
			y = 1;
		}
		else
		{
			bufor = tab[b][a][y + 1][x];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			y++;
		}
		break;
	}
	case 'm': case 'M':
	{
		menu();
	}
	default:
	{
		std::cout << "Zla komenda!";
		Sleep(1000);
		break;
	}
	}
}