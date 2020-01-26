#pragma once

enum StatsEnum
{
	Strength, Perception, Endurance, Charisma, Intelligence, Agility, Luck
};

class Statistics
{ 
	public:
		int strength, perception, endurance, charisma, intelligence, agility, luck;
		
		Statistics(int s = 0, int p = 0, int e = 0, int c = 0, int i = 0, int a = 0, int l = 0)
		{
			strength = s;
			perception = p;
			endurance = e;
			charisma = c;
			intelligence = i;
			agility = a;
			luck = l;
		}

		int getByEnum(int enumStat)
		{
			switch (enumStat)
			{
			case Strength:
				return strength;
			case Perception:
				return perception;
			case Endurance:
				return endurance;
			case Charisma:
				return charisma;
			case Intelligence:
				return intelligence;
			case Agility:
				return agility;
			case Luck:
				return luck;
			default:
				return -1;
				break;
			}
		}
		void setStatistics(int s, int p, int e, int c, int i, int a, int l) {
			strength = s;
			perception = p;
			endurance = e;
			charisma = c;
			intelligence = i;
			agility = a;
			luck = l;
		}
		void advanceStatsByEnum(int enumStat, int number) {
			switch (enumStat)
			{
			case Strength:
				this->strength += number;
				break;
			case Perception:
				perception += number;
				break;
			case Endurance:
				endurance += number;
				break;
			case Charisma:
				charisma += number;
				break;
			case Intelligence:
				intelligence += number;
				break;
			case Agility:
				agility += number;
				break;
			case Luck:
				luck += number;
				break;
			}
		}
};