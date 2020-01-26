#pragma once
#include <iostream>
#include "monster.h"

class Character;

class Square
{
public:
	
	Character* player;
	char tab[3][3][15][15];
	int b, a, y, x, b0, a0, y0, x0;
	char bufor;

	Square(Character* player); //wczytuje map� z pliku tekstowego
	void draw(); //rysuje t� 1/9 mapy, w kt�rej znajduje si� gracz
	void move(); //poruszanie si� postaci
	void check(); //baza danych z unikalnymi przedmiotami na mapie; TA FUNKCJA WAS INTERESUJE
	void menu(); //menu
};