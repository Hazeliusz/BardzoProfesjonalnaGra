#pragma once
#include <iostream>

class Square
{
public:

	char tab[3][3][15][15];
	int b, a, y, x;
	char bufor;
	
	Square(); //wczytuje map� z pliku tekstowego
	void draw(); //rysuje t� 1/9 mapy, w kt�rej znajduje si� gracz
	void move(); //poruszanie si� postaci
};