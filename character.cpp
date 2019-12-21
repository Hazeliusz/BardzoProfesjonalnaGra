#include "character.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

Character::Character(std::string imie, bool plec, Statistics statystyki) {
	this->imie = imie;
	this->plec = plec;
	this->special = statystyki;
}

void Character::wypisz_statystyki() {
	std::cout << "Sila: " << special.sila << std::endl;
	std::cout << "Percepcja: " << special.percepcja << std::endl;
	std::cout << "Wytrzymalosc: " << special.wytrzymalosc << std::endl;
	std::cout << "Charyzma: " << special.charyzma << std::endl;
	std::cout << "Inteligencja: " << special.inteligencja << std::endl;
	std::cout << "Zrecznosc: " << special.zrecznosc << std::endl;
	std::cout << "Szczescie: " << special.szczescie << std::endl;
}

//Constructors

Knight::Knight(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	klasa = PROFF_KNIGHT;
}
Archer::Archer(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	klasa = PROFF_ARCHER;
}

Bard::Bard(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	klasa = PROFF_BARD;
}
Dark_Knight::Dark_Knight(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	klasa = PROFF_DARK_KNIGHT;
}

Cleric::Cleric(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	klasa = PROFF_CLERIC;
}
Mage::Mage(std::string n, bool g, Statistics statystyki) : Character(n, g, statystyki)
{
	klasa = PROFF_MAGE;
}

//Randomizing statistics

void Knight::wylosuj_statystyki() {
	special.sila = rand() % 10 + 20;
	special.percepcja = rand() % 10 + 5;
	special.wytrzymalosc = rand() % 10 + 25;
	special.charyzma = rand() % 5 + 5;
	special.inteligencja = rand() % 5 + 7;
	special.zrecznosc = rand() % 4 + 5;
	special.szczescie = rand() % 20 + 1;
}

void Archer::wylosuj_statystyki() {
	special.sila = rand() % 5 + 5;
	special.percepcja = rand() % 10 + 15;
	special.wytrzymalosc = rand() % 10 + 5;
	special.charyzma = rand() % 5 + 7;
	special.inteligencja = rand() % 5 + 7;
	special.zrecznosc = rand() % 10 + 25;
	special.szczescie = rand() % 20 + 1;
}

void Bard::wylosuj_statystyki() {
	special.sila = rand() % 5 + 5;
	special.percepcja = rand() % 10 + 5;
	special.wytrzymalosc = rand() % 10 + 5;
	special.charyzma = rand() % 10 + 25;
	special.inteligencja = rand() % 5 + 15;
	special.zrecznosc = rand() % 5 + 3;
	special.szczescie = rand() % 20 + 1;
}

void Dark_Knight::wylosuj_statystyki() {
	special.sila = rand() % 10 + 30;
	special.percepcja = rand() % 10 + 5;
	special.wytrzymalosc = rand() % 5 + 20;
	special.charyzma = 1;
	special.inteligencja = rand() % 5 + 10;
	special.zrecznosc = rand() % 5 + 10;
	special.szczescie = 1;
}

void Cleric::wylosuj_statystyki() {
	special.sila = rand() % 5 + 5;
	special.percepcja = rand() % 10 + 5;
	special.wytrzymalosc = rand() % 5 + 5;
	special.charyzma = rand() % 10 + 15;
	special.inteligencja = rand() % 5 + 25;
	special.zrecznosc = rand() % 5 + 3;
	special.szczescie = rand() % 10 + 15;
}

void Mage::wylosuj_statystyki() {
	special.sila = rand() % 5 + 5;
	special.percepcja = rand() % 10 + 5;
	special.wytrzymalosc = rand() % 10 + 5;
	special.charyzma = rand() % 10 + 10;
	special.inteligencja = rand() % 5 + 25;
	special.zrecznosc = rand() % 5 + 3;
	special.szczescie = rand() % 20 + 1;
}

//Draw character cards

void Character::wypisz_karte_postaci()
{
	std::cout << "Imie: " << this->imie << std::endl;
	std::cout << "Klasa: " << this->GetProffesionName() << std::endl;
	std::cout << "Plec: ";
	std::cout << (plec ? "kobieta":"mezczyzna") << std::endl;
	wypisz_statystyki();
}

/*void Character::zapisz_do_pliku() {

}

void Character::odczytaj_z_pliku() {
	std::fstream plik;
	plik.open("postac.txt", std::ios::in);
	if (plik.is_open()) {
		for (int i = 1; i <= 10; i++) {
			int cos = getline(plik, i);
		}
	}
}*/

Magic_Item::Magic_Item(std::string n, std::string o, int m, int rz) {
	nazwa = n;
	opis = o;
	moc = m;
	rzadkosc = rz;
}