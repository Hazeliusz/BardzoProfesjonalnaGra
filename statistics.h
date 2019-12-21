#pragma once

enum StatsEnum
{
	Sila, Percepcja, Wytrzymalosc, Charyzma, Inteligencja, Zrecznosc, Szczescie
};

class Statistics
{ //w teorii tu mialybybyc gettery i settery, ale nie chce mi sie
	public:
		int sila, percepcja, wytrzymalosc, charyzma, inteligencja, zrecznosc, szczescie;
		
		Statistics(int s = 0, int p = 0, int e = 0, int c = 0, int i = 0, int a = 0, int l = 0)
		{
			sila = s;
			percepcja = p;
			wytrzymalosc = e;
			charyzma = c;
			inteligencja = i;
			zrecznosc = a;
			szczescie = l;
		}

		int getByEnum(int enumStat)
		{
			switch (enumStat)
			{
			case Sila:
				return sila;
			case Percepcja:
				return percepcja;
			case Wytrzymalosc:
				return wytrzymalosc;
			case Charyzma:
				return charyzma;
			case Inteligencja:
				return inteligencja;
			case Zrecznosc:
				return zrecznosc;
			case Szczescie:
				return szczescie;
			default:
				return -1;
				break;
			}
		}
		void setStatistics(int s, int p, int e, int c, int i, int a, int l) {
			sila = s;
			percepcja = p;
			wytrzymalosc = e;
			charyzma = c;
			inteligencja = i;
			zrecznosc = a;
			szczescie = l;
		}
};