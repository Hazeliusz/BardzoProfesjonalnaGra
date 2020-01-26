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
	if (b == 0 && a == 0) //lewy g�rny r�g ,,du�ej'' mapy
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
			std::cout << "Jeste� kolejnym ze znamieniem Utriona?! Tfu!\n.\nMasz szcz�cie, jednego ju� wyrzucili�my!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 1 && y == 10) //NPC 2 w domku 1
		{
			std::cout << "Szkoda, �e nasze targowisko zosta�o ostatnim w Borknagarze...\nKiedy� przybywali tu handlarze z najdalszych zak�tk�w,\nnawet z Sahri i Gerfhritu.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 2 && y == 9) //NPC 3 w domku 1
		{
			std::cout << "Lustro...\nspe�nia �yczenia...\nale nikt go nigdy nie widzia�...\nto ju� chyba 200 lat jak zagin�o...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 10 && y == 1) //NPC 1 w domku 2
		{
			std::cout << "Dobrze, �e schowa�em swoje z�oto przy murze klasztoru.\nW dzisiejszych czasach nie mo�na by� pewnym niczego.\n.\nUgh, nie pods�uchuj brudasie!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 9 && y == 2) //NPC 2 w domku 2
		{
			std::cout << "To mniszka zmienia�a pory roku.\nPodobno u�ywa�a do tego jakiego� artefaktu...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 11 && y == 8) //NPC przy znaku ,,+''
		{
			std::cout << "S�ysza�am, �e problemy w Borknagarze zacz�y si�, gdy \nkto� wymordowa� wszystkich mnich�w.\nNie wiem czy to prawda, ale to i tak okropne...\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 0 && a == 1) //zamek
	{
		if (x == 3 && y == 13) //przedmiot przy wej�ciu
		{

		}
		else if (x == 1 && y == 11) //NPC za zgraj� potwor�w 6 (na dole)
		{
			std::cout << "Utrion! Utrion zabi� ich wszystkich!\nMnie te� zabi�!\nMoja dusza jest przekl�ta, bo zgrzeszy�em - teraz musz� si� \nb��ka� po tym klasztorze...\nM�dra mniszka trzyma�a tutaj Lustro Grizzalidu i spe�nia�a �yczenia\ninnych ludzi, kt�rzy byli za g�upi, by w nie patrze�! Gdy popatrzy si� w Lustro, ono\npokazuje twoje najskrytsze pragnienie, a potem je spe�nia. \nNiekt�rzy ludzie byli o to zazdro�ni,\na zw�aszcza ten jeden, kt�ry w nie spojrza�, cho� nie powinien...\n";
			Sleep(20000);
			system("cls");
		}
		else if (x == 13 && y == 6) //NPC na ko�cu tunelu z potworami
		{
			std::cout << "Ma dusza jest przekl�ta! Jestem alchemikiem, kt�ry stworzy� Lustro Grizzalidu...\nOno spe�nia �yczenia, ale nawet te, kt�rych nie chcesz, �eby si� spe�ni�y...\nAle nie wiesz, co ono zrobi, dop�ki w nie nie spojrzysz...!\nJa mia�em ukryte my�li samob�jcze...\nZrobi�em wiele z�ego, teraz za kar� musz� ogl�da� losy Lustra, a� kto� go nie zniszczy...\nOno tyle z�eg ju� zrobi�o...\nA do tego ostatni� rzecz�, kt�r� zrobi�o, by�o zniszczenie Borknagaru...\n";
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
	else if (b == 0 && a == 2) //prawy g�rny r�g ,,du�ej'' mapy
	{
		if (x == 10 && y == 9) //przedmiot obok NPC
		{

		}
		else if (x == 11 && y == 9) //NPC jedyny tutaj
		{
			std::cout << "Dzi�kuj� za pozbycie si� tej bestii!\n.\nWidzisz przed sob� Klasztor Suuomo, to tam mieszka�a legendarna mniszka...\ngdy jeszcze �y�a.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 7 && y == 1) //przedmiot za dwoma potworami 8
		{

		}
	}
	else if (b == 1 && a == 0) //cz�� na p�noc od startu
	{
		if (x == 4 && y == 10) //NPC w dolnej cz�ci
		{
			std::cout << "Na p�noc st�d jest targowisko, ale te pot�ne bestie toruj� drog�... \nJu� ponad tydzie� stoj� tutaj i czekam a� kto� si� ich pozb�dzie \ni b�d� m�g� przewie�� swoje towary.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 5 && y == 6) //przedmiot za dwoma potworami 4
		{

		}
	 else if (x == 7 && y == 5) //przedmiot za dwoma potworami 5
		{

		}
	 else if (x == 5 && y == 3) //NPC w g�rnej cz�ci
		{
			std::cout << "Wyrzucili mnie z miasta. Powiedzieli, �e nosz� znami� Utriona, \nale nie wiem co to znaczy... Ju� nie mog� tam wr�ci�!\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 1 && a == 1) //�rodek mapy
	{
		if (x == 3 && y == 13) //przedmiot otoczony potworami 7
		{

		}
		else if (x == 1 && y == 7) //przedmiot za zgraj� potwor�w 6
		{

		}
		else if (x == 7 && y == 3) //przedmiot za potworem 7
		{

		}
		else if (x == 6 && y == 6) //NPC jedyny tutaj
		{
			std::cout << "To jest krypta zbudowana dla m�drej mniszki, \nkt�ra niegdy� bardzo pomaga�a mieszka�com tych ziem. \nMieszka�cy Borknagaru znosili tutaj swoje kosztowno�ci w podzi�ce za to, \nco dla nich zrobi�a.\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 1 && a == 2) //,,twarz demona''
	{
		if (x == 13 && y == 11) //przedmiot za zgraj� potwor�w 7
		{

		}
		else if (x == 7 && y == 2) //NPC jedyny tutaj
		{
			std::cout << "Podobno gdzie� tutaj mo�na zobaczy� twarz Utriona u�o�on� z kamieni.\nSzukam jej ju� 3 dni!\nTo tylko legenda, ale i tak nie mam nic do roboty...\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 2 && a == 0) //lewy dolny r�g ,,du�ej'' mapy
	{
		if (x == 1 && y == 13) //NPC przy starcie
		{
			std::cout << "Witaj nieznajomy! Lustro Grizzalidu? Nie wiem czy istnieje naprawd�, \nale wed�ug starych legend znajduje si� w klasztorze Suuomo, \nna p�nocny wsch�d st�d...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 1 && y == 10) //pierwsza bro�
		{

		}
		else if (x == 1 && y == 4) //przedmiot przy lewej granicy
		{

		}
		else if (x == 3 && y == 9) //przedmiot we wn�ce za ,,1''
		{

		}
		else if (x == 11 && y == 10) //przedmiot w prawym dolnym rogu
		{

		}
		else if (x == 10 && y == 1) //NPC w prawym g�rnym rogu
		{
			std::cout << "Pami�tam, �e jak by�em ma�y, w Borknagarze w og�le nie by�o potwor�w... \nNie wiem co si� sta�o, ale pewnego dnia, to by�o z 200 lat temu, \nmnisi z klasztoru przestali si� pokazywa�... \nPewnie potwory dopad�y i ich...\n";
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
			std::cout << "Hej, cz�owieku! Wiesz, �e w krypcie tak naprawd� nie ma cia�a mniszki? \nOna zmar�a w klasztorze razem z innymi, ale ma�o kto chce o tym pami�ta�, \nto jednak dodaje jej chwa�y i powinni�my o tym m�wi� g�o�no.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 7 && y == 11) //NPC 4 linie od do�u
		{
			std::cout << "Prosz� o 5.0!\n";
			Sleep(5000);
			system("cls");
		}
		else if (x == 7 && y == 9) //NPC 1 w domku 1
		{
			std::cout << "Cholera! Przgra�em w gr�!\n";
			Sleep(5000);
			system("cls");
		}
		else if (x == 7 && y == 7) //NPC 2 w domku 1
		{
			std::cout << "Szkoda, �e prawie wszyscy st�d pouciekali... \nBorknagar by� pe�en ludzi przed tamtymi wydarzeniami...\n";
			Sleep(7000);
			system("cls");
		}
		else if (x == 8 && y == 7) //NPC 3 w domku 1
		{
			std::cout << "Kiedy� wystarczy�o p�j�� do klasztoru i poprosi� o zim�...\nTo wystarczy�o, �eby zacz�� pada� �nieg...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 11 && y == 8) //NPC 1 w domku 2
		{
			std::cout << "Pami�tam jak w Borknagarze pory roku zmienia�y si� na �yczenie... \nale bez tego nie dam rady ju� uprawia� roli!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 10 && y == 7) //NPC 2 w domku 2
		{
			std::cout << "Czemu bierzesz moje z�oto?! Z�ODZIEJ!!!\n";
			Sleep(4000);
			system("cls");
		}
	}
	else if (b == 2 && a == 2) //prawy dolny r�g ,,du�ej'' mapy
	{
	if (x == 13 && y == 13) //prawy dolny r�g
		{

		}
	else if (x == 8 && y == 11) //przedmiot otoczony potworami 3 na dole
	{

	}
	else if (x == 5 && y == 9) //przedmiot za zgraj� potwor�w 2
	{

	}
	else if (x == 4 && y == 5) //NPC za potworem 4 (jedyny tutaj)
	{
		std::cout << "Dzi�kuj� za ocalenie mi �ycia!\nChowa�em si� przed tym potworem kilka godzin!\nJak wchodzi�em do tej jaskini, to go tutaj nie by�o!\n";
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
	std::cout << "1.Poka� ekwipunek \n2.Wy�wietl kart� \n3.Za�� bro� \n4.Za�� he�m \n5.Za�� zbroj� \n6.Za�� buty \n7.U�yj przedmiot jednorazowy\n";
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