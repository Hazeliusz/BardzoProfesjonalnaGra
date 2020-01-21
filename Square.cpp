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
	tab[b][a][y][x] = 'U';
	bufor = '-';
}

void Square::draw()
{
	system("cls");
	tab[b][a][y][x] = 'U';
	for (int i=0;i<15;i++)
	{
		for (int j=0;j<15;j++)
		{
			std::cout << tab[b][a][i][j];
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
			if (tab[b][a][y - 1][x] == '-')
			{
				tab[b][a][y][x] = '-';
				y--;
			}
			else if (tab[b][a][y - 1][x] == 'G')
			{
				tab[b][a][y][x] = '-';
				y--;
				//dodawanie z�ota do ekwipunku
			}
			else if (tab[b][a][y - 1][x] == 'I')
			{
				tab[b][a][y][x] = '-';
				y--;
				//dodawanie przedmiotu do ekwipunku, ka�dy musi mie� wsp�rz�ne, bo s� r�ne, trzeba to zrobi� podobnie jak z NPC poni�ej
			}
			else if (tab[b][a][y - 1][x] == '1' || tab[b][a][y-1][x] == '2' || tab[b][a][y - 1][x] == '3' || tab[b][a][y - 1][x] == '4' || tab[b][a][y - 1][x] == '5' || tab[b][a][y - 1][x] == '6' || tab[b][a][y - 1][x] == '7' || tab[b][a][y - 1][x] == '8' || tab[b][a][y - 1][x] == '9')
			{
				//tab[b][a][y][x] = '-';
				//y--;
				//walka z potworem wylosowanym; ka�dy symbol od 1 do 9 losuje 1 z 2 potwor�w w puli; je�li wygrana, to zmiana wsp�rz�dnych, je�li ucieczka, to bez zmiany 
			}
			else if (tab[b][a][y - 1][x] == 'N' || tab[b][a][y - 1][x] == 'K' || tab[b][a][y - 1][x] == 'C' || tab[b][a][y - 1][x] == 'Z')
			{
				//bez zmiany wsp�rz�dnych U i trzeba zrobi� if dla ka�dego NPC, bo ka�dy m�wi inny tekst, ale ich wsp�rz�dne najlepiej da� albo w metodzie draw albo niech ka�dy NPC b�dzie obiektem klasy NPC, a w jego parametrach niech b�d� wsp�rz�dne
			}
			else if (tab[b][a][y - 1][x] == '^')
			{
				tab[b][a][y][x] = '-';
				b--;
				y = 13;
			}
			break;
		}
		case 'a':
		{
			if (tab[b][a][y][x - 1] == '-')
			{
				tab[b][a][y][x] = '-';
				x--;
			}
			else if (tab[b][a][y][x-1] == 'G')
			{
				tab[b][a][y][x] = '-';
				x--;
				//dodawanie z�ota do ekwipunku
			}
			else if (tab[b][a][y][x - 1] == '<')
			{
				tab[b][a][y][x] = '-';
				a--;
				x = 13;
			}
			break;
		}
		case 'd':
		{
			if (tab[b][a][y][x + 1] == '-')
			{
				tab[b][a][y][x] = '-';
				x++;
			}
			else if (tab[b][a][y][x+1] == 'G')
			{
				tab[b][a][y][x] = '-';
				x++;
				//dodawanie z�ota do ekwipunku
			}
			else if (tab[b][a][y][x + 1] == '>')
			{
				tab[b][a][y][x] = '-';
				a++;
				x = 1;
			}
			break;
		}
		case 's':
		{
			if (tab[b][a][y + 1][x] == '-')
			{
				tab[b][a][y][x] = '-';
				y++;
			}
			else if (tab[b][a][y + 1][x] == 'G')
			{
				tab[b][a][y][x] = '-';
				y++;
				//dodawanie z�ota do ekwipunku
			}
			else if (tab[b][a][y + 1][x] == 'v')
			{
				tab[b][a][y][x] = '-';
				b++;
				y = 1;
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