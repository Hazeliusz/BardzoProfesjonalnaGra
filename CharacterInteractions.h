#pragma once
#include "character.h"

class CharactersInteractions
{
private:
	Character * character1;
	Character * character2;

public:
	CharactersInteractions(Character * character1, Character * character2)
	{
		this->character1 = character1;
		this->character2 = character2;
	}

	Character * Fight(StatsEnum stats = Sila)
	{
		if (character1->GetStats().getByEnum(stats) < character2->GetStats().getByEnum(stats))
			return character2;
		else if (character1->GetStats().getByEnum(stats) > character2->GetStats().getByEnum(stats))
			return character1;
		else
			return nullptr;
	}	
};