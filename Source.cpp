#include <iostream>
#include "character.h"
#include "Interactions.h"

void main() {
	srand(time(NULL));
	Character* character = new Mage("Hazeliusz", false); //Witamy w dynamicznie alokowanych obiektach :P
	character->randomizeStatistics();
	character->drawCharacterCard();

	Character* character2 = new Knight("Anon", false);
	character2->randomizeStatistics();
	character2->drawCharacterCard();

	CharactersInteractions interact = CharactersInteractions(character, character2);
	interact.Fight();
	

	system("pause");
	delete character;
}