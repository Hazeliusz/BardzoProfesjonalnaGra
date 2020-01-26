#pragma once
#include <iostream>
#include "character.h"

class Character;

class Square
{
public:

	char tab[3][3][15][15];
	int b, a, y, x, b0, a0, y0, x0;
	char bufor;

	Square(); //wczytuje mapê z pliku tekstowego
	void draw(Character* player); //rysuje tê 1/9 mapy, w której znajduje siê gracz
	void move(); //poruszanie siê postaci
	void check(Character* player); //baza danych z unikalnymi przedmiotami na mapie; TA FUNKCJA WAS INTERESUJE
	void menu(); //menu
};