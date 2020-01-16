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
		void advanceStatsByEnum(int enumStat) {
			switch (enumStat)
			{
			case Strength:
				this->strength++;
				break;
			case Perception:
				perception++;
				break;
			case Endurance:
				endurance++;
				break;
			case Charisma:
				charisma++;
				break;
			case Intelligence:
				intelligence++;
				break;
			case Agility:
				agility++;
				break;
			case Luck:
				luck++;
				break;
			}
		}
};