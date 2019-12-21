#include <iostream>
#include "character.h"
#include "Interactions.h"

void main() {
	srand(time(NULL));
	Character* character = new Mage("Hazeliusz", false); //Witamy w dynamicznie alokowanych obiektach :P
	character->wylosuj_statystyki();
	character->wypisz_karte_postaci();

	Character* character2 = new Knight("Anon", false);
	character2->wylosuj_statystyki();
	character2->wypisz_karte_postaci();

	CharactersInteractions interact = CharactersInteractions(character, character2);
	interact.Fight();
	

	system("pause");
	delete character;
}