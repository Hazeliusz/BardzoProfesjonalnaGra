#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include "Level.h"

Level::Level()
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

void Level::draw()
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

void Level::move()
{
	char arrow;
	std::cin >> arrow;

	switch (arrow)
	{
	case 'w':
		{
		if (tab[b][a][y - 1][x] == '-')
		{
			tab[b][a][y][x] = '-';
			y--;
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
		if (tab[b][a][y][x-1] == '-')
		{
			tab[b][a][y][x] = '-';
			x--;
		}
		else if (tab[b][a][y][x-1] == '<')
		{
			tab[b][a][y][x] = '-';
			a--;
			x = 13;
		}
		break;
		}
	case 'd':
		{
		if (tab[b][a][y][x+1] == '-')
		{
			tab[b][a][y][x] = '-';
			x++;
		}
		else if (tab[b][a][y][x+1] == '>')
		{
			tab[b][a][y][x] = '-';
			a++;
			x = 1;
		}
		break;
		}
	case 's':
		{
		if (tab[b][a][y+1][x] == '-')
		{
			tab[b][a][y][x] = '-';
			y++;
		}
		else if (tab[b][a][y+1][x] == 'v')
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