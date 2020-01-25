#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include "Square.h"
#include <conio.h>

Square::Square()
{
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

		}
		else if (x == 1 && y == 10) //NPC 2 w domku 1
		{

		}
		else if (x == 2 && y == 9) //NPC 3 w domku 1
		{

		}
		else if (x == 10 && y == 1) //NPC 1 w domku 2
		{

		}
		else if (x == 9 && y == 2) //NPC 2 w domku 2
		{

		}
		else if (x == 11 && y == 8) //NPC przy znaku ,,+''
		{

		}
	}
	else if (b == 0 && a == 1) //zamek
	{
		if (x == 3 && y == 13) //przedmiot przy wejœciu
		{

		}
		else if (x == 1 && y == 11) //NPC za zgraj¹ potworów 6 (na dole)
		{

		}
		else if (x == 13 && y == 6) //NPC na koñcu tunelu z potworami
		{

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

		}
		else if (x == 7 && y == 1) //przedmiot za dwoma potworami 8
		{

		}
	}
	else if (b == 1 && a == 0) //czêœæ na pó³noc od startu
	{
		if (x == 4 && y == 10) //NPC w dolnej czêœci
		{

		}
		else if (x == 5 && y == 6) //przedmiot za dwoma potworami 4
		{

		}
	 else if (x == 7 && y == 5) //przedmiot za dwoma potworami 5
		{

		}
	 else if (x == 5 && y == 3) //NPC w górnej czêœci
		{

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
	}
	else if (b == 1 && a == 2) //,,twarz demona''
	{
		if (x == 13 && y == 11) //przedmiot za zgraj¹ potworów 7
		{

		}
		else if (x == 7 && y == 2) //NPC jedyny tutaj
		{

		}
	}
	else if (b == 2 && a == 0) //lewy dolny róg ,,du¿ej'' mapy
	{
		if (x == 1 && y == 13) //NPC przy starcie
		{

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

		}
		else if (x == 7 && y == 11) //NPC 4 linie od do³u
		{

		}
		else if (x == 7 && y == 9) //NPC 1 w domku 1
		{

		}
		else if (x == 7 && y == 7) //NPC 2 w domku 1
		{

		}
		else if (x == 8 && y == 7) //NPC 3 w domku 1
		{

		}
		else if (x == 11 && y == 8) //NPC 1 w domku 2
		{

		}
		else if (x == 10 && y == 7) //NPC 2 w domku 2
		{

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
			//dodanie z³ota
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
		//case PRZECIWNIK, nie wiem czy daæ to w 1 case czy w 9; gdy wygrana to exp+ i break, jeœli ucieczka to wsp=wsp0
		//case '!': specjalna instrukcja do walki z bossem
	}

	tab[b][a][y][x] = 'U';
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			std::cout << tab[b][a][i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Square::move()
{
	char arrow;
	arrow = _getch();

	switch (arrow)
	{
	case 'w':
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
	case 'a':
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
	case 'd':
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
	case 's':
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
	default:
	{
		std::cout << "Zla komenda!";
		Sleep(1000);
		break;
	}
	}
}