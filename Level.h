#pragma once
#include <iostream>

class Level
{
public:

	char tab[3][3][15][15];
	int b, a, y, x;
	char bufor;
	
	Level(); //wczytuje mapê z pliku tekstowego
	void draw(); //rysuje tê 1/9 mapy, w której znajduje siê gracz
	void move(); //poruszanie siê postaci
};