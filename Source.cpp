#include <iostream>
#include "character.h"
#include "CharacterInteractions.h"

void main() {
	srand(time(NULL));
	Character* character = new Mage("Hazeliusz", false); //Witamy w dynamicznie alokowanych obiektach :P
	character->wylosuj_statystyki();
	character->wypisz_karte_postaci();

	Character* character2 = new Knight("Jan Pawel 2", false);
	character2->wylosuj_statystyki();
	character2->wypisz_karte_postaci();

	CharactersInteractions interact = CharactersInteractions(character, character2);
	std::cout << "Walke wygral: " << interact.Fight(Inteligencja)->GetName(); 

	system("pause");
	delete character;
}