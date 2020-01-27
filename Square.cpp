#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include "Square.h"
#include <conio.h>
#include "Interactions.h"



Square::Square(Character* player)
{
	this->player = player;
	std::fstream plik;
	plik.open("Whole.txt", std::ios::in);
	if (plik.good() == false)
	{
		std::cout << "Nie mozna otworzyc pliku!";
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 15; k++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int l = 0; l < 15; l++)
					{
						plik >> tab[i][j][k][l];
					}
				}
			}
		}
		plik.close();
	}


	b = 2; a = 0; y = 12; x = 1;
	b0 = b; a0 = a; y0 = y; x0 = x;
	tab[b][a][y][x] = 'U';
	bufor = '-';
}

void Square::check()
{
	if (b == 0 && a == 0) //lewy g�rny r�g ,,du�ej'' mapy
	{
		if (x == 2 && y == 1) //Chemik
		{
			Non_Character beatrycze("Chemik Beatrycze", 'C');
			beatrycze.opening_talk(player);
			beatrycze.options(player);
		}
		else if (x == 4 && y == 1) //Zbrojomistrz 1
		{
			Non_Character gerwalt("Gerwalt", 'Z');
			gerwalt.opening_talk(player);
			gerwalt.options(player);
		}
		else if (x == 6 && y == 1) //Zbrojomistrz 2
		{
			Non_Character zbrojmistrz2("Zbrojmistrz2", 'Z');
			zbrojmistrz2.opening_talk(player);
			zbrojmistrz2.options(player);
		}
		else if (x == 1 && y == 2) //Kowal
		{
			Non_Character grigori("Kowal Gregori", 'K');
			grigori.opening_talk(player);
			grigori.options(player);
		}
		else if (x == 1 && y == 4) //Zbrojomistrz 3
		{
			Non_Character zbrojmistrz3("Zbrojmistrz3", 'Z');
			zbrojmistrz3.opening_talk(player);
			zbrojmistrz3.options(player);
		}
		else if (x == 1 && y == 6) //Handlarz
		{
			Non_Character handlarz("Handlarz", 'H');
			handlarz.opening_talk(player);
			handlarz.options(player);
		}
		else if (x == 1 && y == 11) //NPC 1 w domku 1
		{
			std::cout << "Jeste� kolejnym ze znamieniem Utriona?! Tfu!\nMasz szcz�cie, jednego ju� wyrzucili�my!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 1 && y == 10) //NPC 2 w domku 1
		{
			std::cout << "Szkoda, �e nasze targowisko zosta�o ostatnim w Borknagarze...\nKiedy� przybywali tu handlarze z najdalszych zak�tk�w,\nnawet z Sahri i Gerfhritu.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 2 && y == 9) //NPC 3 w domku 1
		{
			std::cout << "Lustro...\nspe�nia �yczenia...\nale nikt go nigdy nie widzia�...\nto ju� chyba 200 lat jak zagin�o...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 10 && y == 1) //NPC 1 w domku 2
		{
			std::cout << "Dobrze, �e schowa�em swoje z�oto przy murze klasztoru.\nW dzisiejszych czasach nie mo�na by� pewnym niczego.\n.\nUgh, nie pods�uchuj brudasie!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 9 && y == 2) //NPC 2 w domku 2
		{
			std::cout << "To mniszka zmienia�a pory roku.\nPodobno u�ywa�a do tego jakiego� artefaktu...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 11 && y == 8) //NPC przy znaku ,,+''
		{
			std::cout << "S�ysza�am, �e problemy w Borknagarze zacz�y si�, gdy \nkto� wymordowa� wszystkich mnich�w.\nNie wiem czy to prawda, ale to i tak okropne...\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 0 && a == 1) //zamek
	{
		if (x == 3 && y == 13) //przedmiot przy wej�ciu
		{
			Armor deffender7_3;
			deffender7_3.type_def(player);
			deffender7_3.type_stats(player);
			player->addArmor(deffender7_3);
		}
		else if (x == 1 && y == 11) //NPC za zgraj� potwor�w 6 (na dole)
		{
			std::cout << "Utrion! Utrion zabi� ich wszystkich!\nMnie te� zabi�!\nMoja dusza jest przekl�ta, bo zgrzeszy�em - teraz musz� si� \nb��ka� po tym klasztorze...\nM�dra mniszka trzyma�a tutaj Lustro Grizzalidu i spe�nia�a �yczenia\ninnych ludzi, kt�rzy byli za g�upi, by w nie patrze�! Gdy popatrzy si� w Lustro, ono\npokazuje twoje najskrytsze pragnienie, a potem je spe�nia. \nNiekt�rzy ludzie byli o to zazdro�ni,\na zw�aszcza ten jeden, kt�ry w nie spojrza�, cho� nie powinien...\n";
			Sleep(20000);
			system("cls");
		}
		else if (x == 13 && y == 6) //NPC na ko�cu tunelu z potworami
		{
			std::cout << "Ma dusza jest przekl�ta! Jestem alchemikiem, kt�ry stworzy� Lustro Grizzalidu...\nOno spe�nia �yczenia, ale nawet te, kt�rych nie chcesz, �eby si� spe�ni�y...\nAle nie wiesz, co ono zrobi, dop�ki w nie nie spojrzysz...!\nJa mia�em ukryte my�li samob�jcze...\nZrobi�em wiele z�ego, teraz za kar� musz� ogl�da� losy Lustra, a� kto� go nie zniszczy...\nOno tyle z�eg ju� zrobi�o...\nA do tego ostatni� rzecz�, kt�r� zrobi�o, by�o zniszczenie Borknagaru...\n";
			Sleep(20000);
			system("cls");
		}
		else if (x == 5 && y == 1) //boss
		{
			std::cout << "Widzisz cz�owieka w starej podziurawionej zbroi, kt�ry szuka czego� i krzyczy ,,Musz� naprawi�! Naprawi�...!''." << std::endl;
			std::cout << "Za nim widzisz stert� z�ota, a tak�e wielkie lustro odwr�cone ty�em do ciebie." << std::endl;
			std::cout << "Pytasz go ,,Co tu robisz?'', ale on zamiast odpowiedzi rzuca si� na ciebie unosz�c ogromny top�r..." << std::endl;
			system("pause");
			Monster* boss = new Monster(10);
			CharactersInteractions* interact = new CharactersInteractions(player, boss);
			int result = interact->MonsterFight();
			delete interact;
			delete boss;

			switch (result)
			{
			case 1: //ucieczka
			{
				b = b0;
				a = a0;
				y = y0;
				x = x0;
				break;
			}
			case 0: //przegrana
			{
				//przegranie gry
				std::cout << "Przegrywasz walk�. Twoja podr� ko�czy si� tutaj..." << std::endl;
				system("pause");
				exit(0);
				break;
			}
			}
			bufor = '-';

		}
		else if (x == 1 && y == 1) //Lustro Grizzalidu, KONIEC GRY!
		{
			switch (player->GetProffesion()) {
			case PROFF_KNIGHT:
				std::cout << "Znajdujesz Lustro Grizzalidu, patrzysz w nie i widzisz..." << std::endl;
				std::cout << "ludzi, kt�rzy rzucaj� na ziemi� bro�, zaczynaj� bawi� si� razem i �piewa�." << std::endl;
				std::cout << "Cieszysz si� niesamowicie i kierujesz swoje kroki w stron� wyj�cia z klasztoru.Gdy wychodzisz, wydaje ci si�, �e obok ciebie przemyka si� zakapturzona posta�." << std::endl;
				std::cout << "Nie przejmujesz si� tym i wychodzisz.Wracasz do swojej ojczyzny widz�c po drodze jak obszary," << std::endl;
				std::cout << "kt�re jeszcze nie tak dawno by�y ogarni�te wojn�, teraz op�ywaj� w szcz�cie i dostatek." << std::endl;
				std::cout << "Jednak gdy docierasz do swojego domu, widzisz ogromn� batali�. Kl�kasz przed tym widokiem i zaczynasz p�aka�..." << std::endl;
				break;
			case PROFF_ARCHER:
				std::cout << "Znajdujesz Lustro Grizzalidu, patrzysz w nie i widzisz..." << std::endl;
				std::cout << "bandyt�w, tych samych kt�rzy zabili twojego przyjaciela i matk�. Nast�pnie w odbiciu bandyci trafiaj� do ciemnego pokoju i s� poddawani torturom." << std::endl;
				std::cout << "Dociera do ciebie, �e bardziej od powrotu twoich bliskich, ci�gn�a ci� tutaj ��dza krwawej zemsty." << std::endl;
				std::cout << "Odwracasz si� i patrzysz w Lustro jeszcze raz... ale widzisz dok�adnie to samo.Jeszcze raz.I jeszcze raz.I jeszcze raz." << std::endl;
				std::cout << "Wyci�gasz sw�j �owiecki sztylet i wbijasz go sobie w brzuch. Gdy padasz na ziemi�, wydaje ci si�, �e widzisz zakapturzon� posta�, ale pewnie ci si� przywidzia�o." << std::endl;
				std::cout << "Tracisz przytomno��. Gdy si� budzisz, jeste� u jakiego� szamana.Kto� ci� uratowa�.Stoi obok.M�wi, �e widzia� jak wchodzisz do Klasztoru i si� zmartwi�, potem s�ysza� jak krzyczysz." << std::endl;
				std::cout << "Gdy zobaczy� twoje krwawi�ce cia�o na pod�odze i wyni�s� ci� tutaj.Pytasz go o Lustro, ale on twierdzi, �e nie by�o tam �adnego lustra." << std::endl;
				std::cout << "Gdy ko�czysz leczenie, wracasz do normalno�ci, nie wiedz�c do ko�ca co si� sta�o.Nie panuje jednak w tobie smutek tak jak wcze�niej" << std::endl;
				std::cout << "dotar�o do ciebie, �e musisz �y� dalej.Ruszasz w �ycie z nowym nastawieniem..." << std::endl;
				break;
			case PROFF_BARD:
				std::cout << "Znajdujesz Lustro Grizzalidu, patrzysz w nie i widzisz..." << std::endl;
				std::cout << "g�r� z�ota. Wi�cej z�ota ni� twoje oczy kiedykolwiek ujrza�y. Ca�e to bogactwo natychmiast pojawia si� przed tob�." << std::endl;
				std::cout << "Pakujesz kosztowno�ci do work�w i wynosisz - b�dzie trzeba jeszcze wr�ci� po reszt�, bo nawet 1/100 z tego wszystkiego ci si� nie zmie�ci�a." << std::endl;
				std::cout << "Wydaje ci si�, �e widzia�e� zakapturzon� posta�, ale nie przejmujesz si� tym." << std::endl;
				std::cout << "Za�atwiasz sobie w�zek i pacho�k�w do przeniesienia pieni�dzy, ale gdy wchodzisz z powrotem do klasztoru, Lustra ju� nie ma. " << std::endl;
				std::cout << "Przez chwil� jest ci smutno, ale przecie� taka ilo�� z�ota wystarczy ci do ko�ca �ycia. Ca�a reszta jest ju� niewa�na..." << std::endl;
				std::cout << "Cieszysz si� bogactwem przez kilka tygodni, ale pewnego dnia, gdy chcesz zap�aci� za nocleg, zamiast pieni�dzy wyci�gasz z mieszka b�oto." << std::endl;
				std::cout << "Wszystkie kosztowno�ci, jakie mia�e� przy sobie, zamieni�y si� w b�oto." << std::endl;
				std::cout << "Nie my�l�c wiele, zaczynasz biec do reszty swojego skarbu, ale w�a�ciciel luksusowego zajazdu, widz�c to, wysy�a za tob� pacho�k�w." << std::endl;
				std::cout << "Przez przejedzenie wykwintnymi potrawami, nie jeste� w stanie im uciec. �api� ci� i wyci�gaj� miecze. W ostatnim przyp�ywie desperacji zas�aniasz si� swoj� ukochan� lutni�, po czym dostajesz mi�dzy �ebra..." << std::endl;
				break;
			case PROFF_CLERIC:
				std::cout << "Znajdujesz Lustro Grizzalidu, patrzysz w nie i widzisz..." << std::endl;
				std::cout << "siebie ze �wiec�cymi oczyma, a dooko�a pojawiaj� si� imiona demon�w. Kiedy tak patrzysz, wyczuwasz w pobli�u obecno�� si� nieczystych." << std::endl;
				std::cout << "Biegasz po Klasztorze, a� w ko�cu znajdujesz zakapturzon� posta� - czujesz, �e to diabe�." << std::endl;
				std::cout << "Dzi�ki urzeczywistnieniu twojego marzenia w Lustrze - widzisz jego imi� - to Bethrezen, jeden z wy�szych ksi���t piekielnych." << std::endl;
				std::cout << "Przez chwil� si� przestraszasz i stajesz jak s�up soli, ale ta chwila wystarcza twojemu przeciwnikowi do szybkiego przeteleportowania si� do ciebie i przebicia ci klatki piersiowej." << std::endl;
				std::cout << " W ostatniej chwili �ycia u�ywasz pot�nego zakl�cia (kt�re r�wnie� da�o ci Lustro), dzi�ki kt�remu wysy�asz imi� Bethrezena do innej linii czasowej, " << std::endl;
				std::cout << "w kt�rej kto� inny znajduje Lustro, a sam starasz si� wys�a� sobie wiadomo�� do przesz�o�ci, �eby nie jecha� do Borknagaru.Tracisz przytomno��..." << std::endl;
				std::cout << "Budzisz si� w swoim domu.Chyba ca�y ten Borknagar ci si� przy�ni�. Idziesz wykonywa� swoje codzienne obowi�zki..." << std::endl;
				break;
			case PROFF_DARK_KNIGHT:
				std::cout << "Znajdujesz Lustro Grizzalidu, patrzysz w nie i widzisz..." << std::endl;
				std::cout << "zklan� tafl�. Nie rozumiesz, co si� dzieje, ale po chwili dociera do ciebie - duchy nie odbijaj� si� w lustrach!" << std::endl;
				std::cout << "Gdy pogr��asz si� w rozpaczy, kto� staje za tob�. Odwracasz si� i widzisz zakapturzon� posta� - t� sam�, kt�ra przywr�ci�a ci� do �ycia." << std::endl;
				std::cout << ",,My�la�e�, �e nikt nie da rady tob� sterowa�? Twoim marzeniem by�o Lustro tylko dlatego, �e ja je w tobie zaszczepi�em!'' m�wi." << std::endl;
				std::cout << "W pierwszym odruchu chcesz go zabi�, ale przypominasz sobie, �e ju� raz zgin�� i pewnie nic to nie da, wi�c pytasz tylko ,,Kim jeste�?''" << std::endl;
				std::cout << "On odpowiada ,,Moje imi� nie jest wa�ne, ale to ja pokierowa�em wiele os�b do Lustra, poniewa� sam nie mog�em zabi� Utriona - ci��y�a na nim wyj�tkowa kl�twa, kt�ra rozdar�aby mnie." << std::endl;
				std::cout << "Akurat ty go zabi�e�, a nie nikt inny, chyba powinienem ci podzi�kowa�...''., , Po co ci Lustro ? '' pytasz." << std::endl;
				std::cout << ",,U�yj� go, �eby zdoby� w�adz� w Piekle, z kt�rego mnie wyrzucono na po�arcie przez ludzi! I to za pomoc� jednego z mieszka�c�w Otch�ani!O ironio!''" << std::endl;
				std::cout << "Rzucasz si� na tego cz�owieka(?), ale on jednym ruchem r�ki rozrywa ci� na strz�py. Czujesz gor�ce d�onie demon�w, kt�re wci�gaj� ci� w Ciemno��..." << std::endl;
				break;
			case PROFF_MAGE:
				std::cout << "Znajdujesz Lustro Grizzalidu, ale my�lisz sobie" << std::endl;
				std::cout << ",,Czy ja w og�le chc� w nie patrze�? Co zobacz�? Siebie wiedz�cego wszystko? Ale zdobywanie wiedzy to moja pasja, nie b�d� mie� co ze sob� pocz�� i popadn� w depresj�!''" << std::endl;
				std::cout << "Odchodzisz, ale po chwili wracasz w�tpi�c w swoj� decyzj�. Stwierdzasz, �e to b�dzie ci� m�czy�, po czym przygotowujesz pot�ne zakl�cie i... rozbijasz Lustro Grizzalidu w drobne kawa�eczki." << std::endl;
				std::cout << "Nagle s�yszysz za sob� okrzyk rozpaczy. Odwracasz si� i widzisz p�dz�cego w twoj� stron� zakapturzonego cz�owieka." << std::endl;
				std::cout << "Jednocze�nie pojawia ci si� przed oczyma napis B E T H R E Z E N. Krzyczysz ,,Bethrezenie!'', a posta� si� zatrzymuje." << std::endl;
				std::cout << "Rozumiej�c, �e jest on demonem (tak dzia�a na demona powiedzenie jego imienia), zaczynasz my�le�. On ci wygra�a, ale ty si� tym nie przejmujesz, bo teraz nie mo�e ci nic zrobi�." << std::endl;
				std::cout << "Zabierasz go do swojej wie�y, �eby podda� go badaniom, dzi�ki czemu masz dost�p do nieznanej jeszcze przez siebie dziedziny wiedzy - demonologii." << std::endl;
				std::cout << "Odczuwasz co�, co dawno nie znalaz�o si� w twoim sercu - dzieci�c� rado��, dzieci�c� fascynacj� nieznanym i dzieci�ce szcz�cie." << std::endl;
				break;
			default:
				std::cout << "Masz kryzys to�samo�ci." << std::endl;
			}
			system("cls");
			std::cout << "Koniec gry.";
			system("pause");
			exit(0);
		}
	}
	else if (b == 0 && a == 2) //prawy g�rny r�g ,,du�ej'' mapy
	{
		if (x == 10 && y == 9) //przedmiot obok NPC
		{
			Armor deffender8_1;
			deffender8_1.type_def(player);
			deffender8_1.type_stats(player);
			player->addArmor(deffender8_1);
		}
		else if (x == 11 && y == 9) //NPC jedyny tutaj
		{
			std::cout << "Dzi�kuj� za pozbycie si� tej bestii!\n.\nWidzisz przed sob� Klasztor Suuomo, to tam mieszka�a legendarna mniszka...\ngdy jeszcze �y�a.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 7 && y == 1) //przedmiot za dwoma potworami 8
		{
			Weapon attacker8;
			attacker8.weapon_statistics_name(player);
			player->addWeapon(attacker8);
		}
	}
	else if (b == 1 && a == 0) //cz�� na p�noc od startu
	{
		if (x == 4 && y == 10) //NPC w dolnej cz�ci
		{
			std::cout << "Na p�noc st�d jest targowisko, ale te pot�ne bestie toruj� drog�... \nJu� ponad tydzie� stoj� tutaj i czekam a� kto� si� ich pozb�dzie \ni b�d� m�g� przewie�� swoje towary.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 5 && y == 6) //przedmiot za dwoma potworami 4
		{
			Armor deffender4_2;
			deffender4_2.type_def(player);
			deffender4_2.type_stats(player);
			player->addArmor(deffender4_2);
		}
	 else if (x == 7 && y == 5) //przedmiot za dwoma potworami 5
		{
			Armor deffender5;
			deffender5.type_def(player);
			deffender5.type_stats(player);
			player->addArmor(deffender5);
		}
	 else if (x == 5 && y == 3) //NPC w g�rnej cz�ci
		{
			std::cout << "Wyrzucili mnie z miasta. Powiedzieli, �e nosz� znami� Utriona, \nale nie wiem co to znaczy... Ju� nie mog� tam wr�ci�!\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 1 && a == 1) //�rodek mapy
	{
		if (x == 3 && y == 13) //przedmiot otoczony potworami 7
		{
			Armor deffender7_1;
			deffender7_1.type_def(player);
			deffender7_1.type_stats(player);
			player->addArmor(deffender7_1);
		}
		else if (x == 1 && y == 7) //przedmiot za zgraj� potwor�w 6
		{
			Armor deffender6;
			deffender6.type_def(player);
			deffender6.type_stats(player);
			player->addArmor(deffender6);
		}
		else if (x == 7 && y == 3) //przedmiot za potworem 7
		{
			Equipment potion7(player, 0, "eliksir");
			player->addEquipment(potion7);
		}
		else if (x == 6 && y == 6) //NPC jedyny tutaj
		{
			std::cout << "To jest krypta zbudowana dla m�drej mniszki, \nkt�ra niegdy� bardzo pomaga�a mieszka�com tych ziem. \nMieszka�cy Borknagaru znosili tutaj swoje kosztowno�ci w podzi�ce za to, \nco dla nich zrobi�a.\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 1 && a == 2) //,,twarz demona''
	{
		if (x == 13 && y == 11) //przedmiot za zgraj� potwor�w 7
		{
			Armor deffender7_2;
			deffender7_2.type_def(player);
			deffender7_2.type_stats(player);
			player->addArmor(deffender7_2);
		}
		else if (x == 7 && y == 2) //NPC jedyny tutaj
		{
			std::cout << "Podobno gdzie� tutaj mo�na zobaczy� twarz Utriona u�o�on� z kamieni.\nSzukam jej ju� 3 dni!\nTo tylko legenda, ale i tak nie mam nic do roboty...\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 2 && a == 0) //lewy dolny r�g ,,du�ej'' mapy
	{
		if (x == 1 && y == 13) //NPC przy starcie
		{
			std::cout << "Witaj nieznajomy! Lustro Grizzalidu? Nie wiem czy istnieje naprawd�, \nale wed�ug starych legend znajduje si� w klasztorze Suuomo, \nna p�nocny wsch�d st�d...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 1 && y == 10) //pierwsza bro�
		{
			Weapon attacker_w;
			attacker_w.weapon_statistics_name(player);
			player->addWeapon(attacker_w);
		}
		else if (x == 1 && y == 4) //przedmiot przy lewej granicy
		{
			Armor deffender1_1;
			deffender1_1.type_def(player);
			deffender1_1.type_stats(player);
			player->addArmor(deffender1_1);
		}
		else if (x == 3 && y == 9) //przedmiot we wn�ce za ,,1''
		{
			Armor deffender1_2;
			deffender1_2.type_def(player);
			deffender1_2.type_stats(player);
			player->addArmor(deffender1_2);
		}
		else if (x == 11 && y == 10) //przedmiot w prawym dolnym rogu
		{
			Armor deffender2;
			deffender2.type_def(player);
			deffender2.type_stats(player);
			player->addArmor(deffender2);
		}
		else if (x == 10 && y == 1) //NPC w prawym g�rnym rogu
		{
			std::cout << "Pami�tam, �e jak by�em ma�y, w Borknagarze w og�le nie by�o potwor�w... \nNie wiem co si� sta�o, ale pewnego dnia, to by�o z 200 lat temu, \nmnisi z klasztoru przestali si� pokazywa�... \nPewnie potwory dopad�y i ich...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 10 && y == 7) // za 3
		{
			Equipment potion3(player, 0,  "eliksir");
			player->addEquipment(potion3);
		}
	}
	else if (b == 2 && a == 1) //wioska
	{
		if (x == 1 && y == 13) //Zbrojomistrz 4
		{
			Non_Character oktis("Oktis", 'Z');
			oktis.opening_talk(player);
			oktis.options(player);
		}
		else if (x == 2 && y == 13) //Zbrojomistrz 5
		{
			Non_Character zbrojmistrz5("Zbrojmistrz5", 'Z');
			zbrojmistrz5.opening_talk(player);
			zbrojmistrz5.options(player);
		}
		else if (x == 3 && y == 13) //Zbrojomistrz 6
		{
			Non_Character zbrojmistrz6("Zbrojmistrz6", 'Z');
			zbrojmistrz6.opening_talk(player);
			zbrojmistrz6.options(player);
		}
		else if (x == 3 && y == 2) //Chemik
		{
			Non_Character renagan("Chemik Renagan", 'C');
			renagan.opening_talk(player);
			renagan.options(player);
		}
		else if (x == 5 && y == 1) //Kowal
		{
			Non_Character andrzej("Kowal Andrzej", 'K');
			andrzej.opening_talk(player);
			andrzej.options(player);
		}
		else if (x == 10 && y == 13) //NPC przy dolnej granicy
		{
			std::cout << "Hej, cz�owieku! Wiesz, �e w krypcie tak naprawd� nie ma cia�a mniszki? \nOna zmar�a w klasztorze razem z innymi, ale ma�o kto chce o tym pami�ta�, \nto jednak dodaje jej chwa�y i powinni�my o tym m�wi� g�o�no.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 7 && y == 11) //NPC 4 linie od do�u
		{
			std::cout << "Prosz� o 5.0!\n";
			Sleep(5000);
			system("cls");
		}
		else if (x == 7 && y == 9) //NPC 1 w domku 1
		{
			std::cout << "Cholera! Przgra�em w gr�!\n";
			Sleep(5000);
			system("cls");
		}
		else if (x == 7 && y == 7) //NPC 2 w domku 1
		{
			std::cout << "Szkoda, �e prawie wszyscy st�d pouciekali... \nBorknagar by� pe�en ludzi przed tamtymi wydarzeniami...\n";
			Sleep(7000);
			system("cls");
		}
		else if (x == 8 && y == 7) //NPC 3 w domku 1
		{
			std::cout << "Kiedy� wystarczy�o p�j�� do klasztoru i poprosi� o zim�...\nTo wystarczy�o, �eby zacz�� pada� �nieg...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 11 && y == 8) //NPC 1 w domku 2
		{
			std::cout << "Pami�tam jak w Borknagarze pory roku zmienia�y si� na �yczenie... \nale bez tego nie dam rady ju� uprawia� roli!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 10 && y == 7) //NPC 2 w domku 2
		{
			std::cout << "Czemu bierzesz moje z�oto?! Z�ODZIEJ!!!\n";
			Sleep(4000);
			system("cls");
		}
	}
	else if (b == 2 && a == 2) //prawy dolny r�g ,,du�ej'' mapy
	{
	if (x == 13 && y == 13) //prawy dolny r�g
	{
		Equipment potion5(player, 0, "eliksir");
		player->addEquipment(potion5);
	}
	else if (x == 8 && y == 11) //przedmiot otoczony potworami 3 na dole
	{
		Weapon attacker1;
		attacker1.weapon_statistics_name(player);
		player->addWeapon(attacker1);
	}
	else if (x == 5 && y == 9) //przedmiot za zgraj� potwor�w 2
	{
		Equipment potion2(player, 0, "eliksir");
		player->addEquipment(potion2);
	}
	else if (x == 4 && y == 5) //NPC za potworem 4 (jedyny tutaj)
	{
		std::cout << "Dzi�kuj� za ocalenie mi �ycia!\nChowa�em si� przed tym potworem kilka godzin!\nJak wchodzi�em do tej jaskini, to go tutaj nie by�o!\n";
		Sleep(10000);
		system("cls");
	}
	else if (x == 7 && y == 9) //przedmiot za dwoma potworami 4
	{
		Armor deffender4_1;
		deffender4_1.type_def(player);
		deffender4_1.type_stats(player);
		player->addArmor(deffender4_1);
	}
	else if (x == 11 && y == 5) //przedmiot za potworem 6
	{
		Weapon attacker6;
		attacker6.weapon_statistics_name(player);
		player->addWeapon(attacker6);
	}
	}
}

void Square::draw()
{
	system("cls");
	
	switch (bufor)
	{
	case '-':
		{
			break;
		}
	case 'X':
		{
			b = b0;
			a = a0;
			y = y0;
			x = x0;
			break;
		}
		case 'G':
		{
			player->addGold(200);
			bufor = '-';
			break;
		}
		case 'I':
		{
			check();
			bufor = '-';
			break;
		}
		case 'K': case 'Z': case 'C': case 'N': case 'H':
		{
			check();
			b = b0;
			a = a0;
			y = y0;
			x = x0;
			break;
		}
		case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		{
			int monster_type = bufor - '0';
			Monster* monster = new Monster(monster_type);
			CharactersInteractions* interact = new CharactersInteractions(player, monster);
			int result = interact->MonsterFight();
			delete interact;
			delete monster;

			switch (result)
			{
			case 1: //ucieczka
			{
				b = b0;
				a = a0;
				y = y0;
				x = x0;
				break;
			}
			case 0: //przegrana
			{
				//przegranie gry
				std::cout << "Przegrywasz walk�. Twoja podr� ko�czy si� tutaj..." << std::endl;
				system("pause");
				exit(0);
				break;
			}
			}

			bufor = '-';
			break;
		}
		case '!':
		{
			check();
			break;
		}
	}

	tab[b][a][y][x] = 'U';
	std::cout << std::endl;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			std::cout << tab[b][a][i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Square::menu()
{
	int choice;
	std::cout << "1.Poka� ekwipunek \n2.Wy�wietl kart� \n3.Za�� bro� \n4.Za�� he�m \n5.Za�� zbroj� \n6.Za�� buty \n7.U�yj przedmiot jednorazowy\n";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		player->displayInventory();
		system("pause");
		break;
	}
	case 2:
	{
		player->drawCharacterCard();
		system("pause");
		break;
	}
	case 3:
	{
		player->EquipWeapon();
		system("pause");
		break;
	}
	case 4:
	{
		player->EquipHelmet();
		system("pause");
		break;
	}
	case 5:
	{
		player->EquipArmor();
		system("pause");
		break;
	}
	case 6:
	{
		player->EquipBoots();
		system("pause");
		break;
	}
	case 7:
	{
		player->useEquipment();
		system("pause");
		break;
	}
	}

}

void Square::move()
{
	char arrow;
	arrow = _getch();

	switch (arrow)
	{
	case 'w': case 'W':
	{
		if (tab[b][a][y - 1][x] == '^')
		{
			bufor = tab[b-1][a][13][x];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			b--;
			y = 13;
		}
		else
		{
			bufor = tab[b][a][y - 1][x];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			y--;
		}
		break;
	}
	case 'a': case 'A':
	{
		if (tab[b][a][y][x-1] == '<')
		{
			bufor = tab[b][a-1][y][13];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			a--;
			x = 13;
		}
		else
		{
			bufor = tab[b][a][y][x - 1];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			x--;
		}
		break;
	}
	case 'd': case 'D':
	{
		if (tab[b][a][y][x + 1] == '>')
		{
			bufor = tab[b][a+1][y][1];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			a++;
			x = 1;
		}
		else
		{
			bufor = tab[b][a][y][x + 1];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			x++;
		}
		break;
	}
	case 's': case 'S':
	{
		if (tab[b][a][y + 1][x] == 'v')
		{
			bufor = tab[b+1][a][1][x];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			b++;
			y = 1;
		}
		else
		{
			bufor = tab[b][a][y + 1][x];
			b0 = b;
			a0 = a;
			y0 = y;
			x0 = x;
			tab[b][a][y][x] = '-';
			y++;
		}
		break;
	}
	case 'm': case 'M':
	{
		menu();
	}
	default:
	{
		std::cout << "Zla komenda!";
		Sleep(1000);
		break;
	}
	}
}