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
	if (b == 0 && a == 0) //lewy górny róg ,,du¿ej'' mapy
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
			std::cout << "Jesteœ kolejnym ze znamieniem Utriona?! Tfu!\nMasz szczêœcie, jednego ju¿ wyrzuciliœmy!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 1 && y == 10) //NPC 2 w domku 1
		{
			std::cout << "Szkoda, ¿e nasze targowisko zosta³o ostatnim w Borknagarze...\nKiedyœ przybywali tu handlarze z najdalszych zak¹tków,\nnawet z Sahri i Gerfhritu.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 2 && y == 9) //NPC 3 w domku 1
		{
			std::cout << "Lustro...\nspe³nia ¿yczenia...\nale nikt go nigdy nie widzia³...\nto ju¿ chyba 200 lat jak zaginê³o...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 10 && y == 1) //NPC 1 w domku 2
		{
			std::cout << "Dobrze, ¿e schowa³em swoje z³oto przy murze klasztoru.\nW dzisiejszych czasach nie mo¿na byæ pewnym niczego.\n.\nUgh, nie pods³uchuj brudasie!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 9 && y == 2) //NPC 2 w domku 2
		{
			std::cout << "To mniszka zmienia³a pory roku.\nPodobno u¿ywa³a do tego jakiegoœ artefaktu...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 11 && y == 8) //NPC przy znaku ,,+''
		{
			std::cout << "S³ysza³am, ¿e problemy w Borknagarze zaczê³y siê, gdy \nktoœ wymordowa³ wszystkich mnichów.\nNie wiem czy to prawda, ale to i tak okropne...\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 0 && a == 1) //zamek
	{
		if (x == 3 && y == 13) //przedmiot przy wejœciu
		{
			Armor deffender7_3;
			deffender7_3.type_def(player);
			deffender7_3.type_stats(player);
			player->addArmor(deffender7_3);
		}
		else if (x == 1 && y == 11) //NPC za zgraj¹ potworów 6 (na dole)
		{
			std::cout << "Utrion! Utrion zabi³ ich wszystkich!\nMnie te¿ zabi³!\nMoja dusza jest przeklêta, bo zgrzeszy³em - teraz muszê siê \nb³¹kaæ po tym klasztorze...\nM¹dra mniszka trzyma³a tutaj Lustro Grizzalidu i spe³nia³a ¿yczenia\ninnych ludzi, którzy byli za g³upi, by w nie patrzeæ! Gdy popatrzy siê w Lustro, ono\npokazuje twoje najskrytsze pragnienie, a potem je spe³nia. \nNiektórzy ludzie byli o to zazdroœni,\na zw³aszcza ten jeden, który w nie spojrza³, choæ nie powinien...\n";
			Sleep(20000);
			system("cls");
		}
		else if (x == 13 && y == 6) //NPC na koñcu tunelu z potworami
		{
			std::cout << "Ma dusza jest przeklêta! Jestem alchemikiem, który stworzy³ Lustro Grizzalidu...\nOno spe³nia ¿yczenia, ale nawet te, których nie chcesz, ¿eby siê spe³ni³y...\nAle nie wiesz, co ono zrobi, dopóki w nie nie spojrzysz...!\nJa mia³em ukryte myœli samobójcze...\nZrobi³em wiele z³ego, teraz za karê muszê ogl¹daæ losy Lustra, a¿ ktoœ go nie zniszczy...\nOno tyle z³eg ju¿ zrobi³o...\nA do tego ostatni¹ rzecz¹, któr¹ zrobi³o, by³o zniszczenie Borknagaru...\n";
			Sleep(20000);
			system("cls");
		}
		else if (x == 5 && y == 1) //boss
		{
			std::cout << "Widzisz cz³owieka w starej podziurawionej zbroi, który szuka czegoœ i krzyczy ,,Muszê naprawiæ! Naprawiæ...!''." << std::endl;
			std::cout << "Za nim widzisz stertê z³ota, a tak¿e wielkie lustro odwrócone ty³em do ciebie." << std::endl;
			std::cout << "Pytasz go ,,Co tu robisz?'', ale on zamiast odpowiedzi rzuca siê na ciebie unosz¹c ogromny topór..." << std::endl;
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
				std::cout << "Przegrywasz walkê. Twoja podró¿ koñczy siê tutaj..." << std::endl;
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
				std::cout << "ludzi, którzy rzucaj¹ na ziemiê broñ, zaczynaj¹ bawiæ siê razem i œpiewaæ." << std::endl;
				std::cout << "Cieszysz siê niesamowicie i kierujesz swoje kroki w stronê wyjœcia z klasztoru.Gdy wychodzisz, wydaje ci siê, ¿e obok ciebie przemyka siê zakapturzona postaæ." << std::endl;
				std::cout << "Nie przejmujesz siê tym i wychodzisz.Wracasz do swojej ojczyzny widz¹c po drodze jak obszary," << std::endl;
				std::cout << "które jeszcze nie tak dawno by³y ogarniête wojn¹, teraz op³ywaj¹ w szczêœcie i dostatek." << std::endl;
				std::cout << "Jednak gdy docierasz do swojego domu, widzisz ogromn¹ bataliê. Klêkasz przed tym widokiem i zaczynasz p³akaæ..." << std::endl;
				break;
			case PROFF_ARCHER:
				std::cout << "Znajdujesz Lustro Grizzalidu, patrzysz w nie i widzisz..." << std::endl;
				std::cout << "bandytów, tych samych którzy zabili twojego przyjaciela i matkê. Nastêpnie w odbiciu bandyci trafiaj¹ do ciemnego pokoju i s¹ poddawani torturom." << std::endl;
				std::cout << "Dociera do ciebie, ¿e bardziej od powrotu twoich bliskich, ci¹gnê³a ciê tutaj ¿¹dza krwawej zemsty." << std::endl;
				std::cout << "Odwracasz siê i patrzysz w Lustro jeszcze raz... ale widzisz dok³adnie to samo.Jeszcze raz.I jeszcze raz.I jeszcze raz." << std::endl;
				std::cout << "Wyci¹gasz swój ³owiecki sztylet i wbijasz go sobie w brzuch. Gdy padasz na ziemiê, wydaje ci siê, ¿e widzisz zakapturzon¹ postaæ, ale pewnie ci siê przywidzia³o." << std::endl;
				std::cout << "Tracisz przytomnoœæ. Gdy siê budzisz, jesteœ u jakiegoœ szamana.Ktoœ ciê uratowa³.Stoi obok.Mówi, ¿e widzia³ jak wchodzisz do Klasztoru i siê zmartwi³, potem s³ysza³ jak krzyczysz." << std::endl;
				std::cout << "Gdy zobaczy³ twoje krwawi¹ce cia³o na pod³odze i wyniós³ ciê tutaj.Pytasz go o Lustro, ale on twierdzi, ¿e nie by³o tam ¿adnego lustra." << std::endl;
				std::cout << "Gdy koñczysz leczenie, wracasz do normalnoœci, nie wiedz¹c do koñca co siê sta³o.Nie panuje jednak w tobie smutek tak jak wczeœniej" << std::endl;
				std::cout << "dotar³o do ciebie, ¿e musisz ¿yæ dalej.Ruszasz w ¿ycie z nowym nastawieniem..." << std::endl;
				break;
			case PROFF_BARD:
				std::cout << "Znajdujesz Lustro Grizzalidu, patrzysz w nie i widzisz..." << std::endl;
				std::cout << "górê z³ota. Wiêcej z³ota ni¿ twoje oczy kiedykolwiek ujrza³y. Ca³e to bogactwo natychmiast pojawia siê przed tob¹." << std::endl;
				std::cout << "Pakujesz kosztownoœci do worków i wynosisz - bêdzie trzeba jeszcze wróciæ po resztê, bo nawet 1/100 z tego wszystkiego ci siê nie zmieœci³a." << std::endl;
				std::cout << "Wydaje ci siê, ¿e widzia³eœ zakapturzon¹ postaæ, ale nie przejmujesz siê tym." << std::endl;
				std::cout << "Za³atwiasz sobie wózek i pacho³ków do przeniesienia pieniêdzy, ale gdy wchodzisz z powrotem do klasztoru, Lustra ju¿ nie ma. " << std::endl;
				std::cout << "Przez chwilê jest ci smutno, ale przecie¿ taka iloœæ z³ota wystarczy ci do koñca ¿ycia. Ca³a reszta jest ju¿ niewa¿na..." << std::endl;
				std::cout << "Cieszysz siê bogactwem przez kilka tygodni, ale pewnego dnia, gdy chcesz zap³aciæ za nocleg, zamiast pieniêdzy wyci¹gasz z mieszka b³oto." << std::endl;
				std::cout << "Wszystkie kosztownoœci, jakie mia³eœ przy sobie, zamieni³y siê w b³oto." << std::endl;
				std::cout << "Nie myœl¹c wiele, zaczynasz biec do reszty swojego skarbu, ale w³aœciciel luksusowego zajazdu, widz¹c to, wysy³a za tob¹ pacho³ków." << std::endl;
				std::cout << "Przez przejedzenie wykwintnymi potrawami, nie jesteœ w stanie im uciec. £api¹ ciê i wyci¹gaj¹ miecze. W ostatnim przyp³ywie desperacji zas³aniasz siê swoj¹ ukochan¹ lutni¹, po czym dostajesz miêdzy ¿ebra..." << std::endl;
				break;
			case PROFF_CLERIC:
				std::cout << "Znajdujesz Lustro Grizzalidu, patrzysz w nie i widzisz..." << std::endl;
				std::cout << "siebie ze œwiec¹cymi oczyma, a dooko³a pojawiaj¹ siê imiona demonów. Kiedy tak patrzysz, wyczuwasz w pobli¿u obecnoœæ si³ nieczystych." << std::endl;
				std::cout << "Biegasz po Klasztorze, a¿ w koñcu znajdujesz zakapturzon¹ postaæ - czujesz, ¿e to diabe³." << std::endl;
				std::cout << "Dziêki urzeczywistnieniu twojego marzenia w Lustrze - widzisz jego imiê - to Bethrezen, jeden z wy¿szych ksi¹¿¹t piekielnych." << std::endl;
				std::cout << "Przez chwilê siê przestraszasz i stajesz jak s³up soli, ale ta chwila wystarcza twojemu przeciwnikowi do szybkiego przeteleportowania siê do ciebie i przebicia ci klatki piersiowej." << std::endl;
				std::cout << " W ostatniej chwili ¿ycia u¿ywasz potê¿nego zaklêcia (które równie¿ da³o ci Lustro), dziêki któremu wysy³asz imiê Bethrezena do innej linii czasowej, " << std::endl;
				std::cout << "w której ktoœ inny znajduje Lustro, a sam starasz siê wys³aæ sobie wiadomoœæ do przesz³oœci, ¿eby nie jechaæ do Borknagaru.Tracisz przytomnoœæ..." << std::endl;
				std::cout << "Budzisz siê w swoim domu.Chyba ca³y ten Borknagar ci siê przyœni³. Idziesz wykonywaæ swoje codzienne obowi¹zki..." << std::endl;
				break;
			case PROFF_DARK_KNIGHT:
				std::cout << "Znajdujesz Lustro Grizzalidu, patrzysz w nie i widzisz..." << std::endl;
				std::cout << "zklan¹ taflê. Nie rozumiesz, co siê dzieje, ale po chwili dociera do ciebie - duchy nie odbijaj¹ siê w lustrach!" << std::endl;
				std::cout << "Gdy pogr¹¿asz siê w rozpaczy, ktoœ staje za tob¹. Odwracasz siê i widzisz zakapturzon¹ postaæ - t¹ sam¹, która przywróci³a ciê do ¿ycia." << std::endl;
				std::cout << ",,Myœla³eœ, ¿e nikt nie da rady tob¹ sterowaæ? Twoim marzeniem by³o Lustro tylko dlatego, ¿e ja je w tobie zaszczepi³em!'' mówi." << std::endl;
				std::cout << "W pierwszym odruchu chcesz go zabiæ, ale przypominasz sobie, ¿e ju¿ raz zgin¹³ i pewnie nic to nie da, wiêc pytasz tylko ,,Kim jesteœ?''" << std::endl;
				std::cout << "On odpowiada ,,Moje imiê nie jest wa¿ne, ale to ja pokierowa³em wiele osób do Lustra, poniewa¿ sam nie mog³em zabiæ Utriona - ci¹¿y³a na nim wyj¹tkowa kl¹twa, która rozdar³aby mnie." << std::endl;
				std::cout << "Akurat ty go zabi³eœ, a nie nikt inny, chyba powinienem ci podziêkowaæ...''., , Po co ci Lustro ? '' pytasz." << std::endl;
				std::cout << ",,U¿yjê go, ¿eby zdobyæ w³adzê w Piekle, z którego mnie wyrzucono na po¿arcie przez ludzi! I to za pomoc¹ jednego z mieszkañców Otch³ani!O ironio!''" << std::endl;
				std::cout << "Rzucasz siê na tego cz³owieka(?), ale on jednym ruchem rêki rozrywa ciê na strzêpy. Czujesz gor¹ce d³onie demonów, które wci¹gaj¹ ciê w Ciemnoœæ..." << std::endl;
				break;
			case PROFF_MAGE:
				std::cout << "Znajdujesz Lustro Grizzalidu, ale myœlisz sobie" << std::endl;
				std::cout << ",,Czy ja w ogóle chcê w nie patrzeæ? Co zobaczê? Siebie wiedz¹cego wszystko? Ale zdobywanie wiedzy to moja pasja, nie bêdê mieæ co ze sob¹ pocz¹æ i popadnê w depresjê!''" << std::endl;
				std::cout << "Odchodzisz, ale po chwili wracasz w¹tpi¹c w swoj¹ decyzjê. Stwierdzasz, ¿e to bêdzie ciê mêczyæ, po czym przygotowujesz potê¿ne zaklêcie i... rozbijasz Lustro Grizzalidu w drobne kawa³eczki." << std::endl;
				std::cout << "Nagle s³yszysz za sob¹ okrzyk rozpaczy. Odwracasz siê i widzisz pêdz¹cego w twoj¹ stronê zakapturzonego cz³owieka." << std::endl;
				std::cout << "Jednoczeœnie pojawia ci siê przed oczyma napis B E T H R E Z E N. Krzyczysz ,,Bethrezenie!'', a postaæ siê zatrzymuje." << std::endl;
				std::cout << "Rozumiej¹c, ¿e jest on demonem (tak dzia³a na demona powiedzenie jego imienia), zaczynasz myœleæ. On ci wygra¿a, ale ty siê tym nie przejmujesz, bo teraz nie mo¿e ci nic zrobiæ." << std::endl;
				std::cout << "Zabierasz go do swojej wie¿y, ¿eby poddaæ go badaniom, dziêki czemu masz dostêp do nieznanej jeszcze przez siebie dziedziny wiedzy - demonologii." << std::endl;
				std::cout << "Odczuwasz coœ, co dawno nie znalaz³o siê w twoim sercu - dzieciêc¹ radoœæ, dzieciêc¹ fascynacjê nieznanym i dzieciêce szczêœcie." << std::endl;
				break;
			default:
				std::cout << "Masz kryzys to¿samoœci." << std::endl;
			}
			system("cls");
			std::cout << "Koniec gry.";
			system("pause");
			exit(0);
		}
	}
	else if (b == 0 && a == 2) //prawy górny róg ,,du¿ej'' mapy
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
			std::cout << "Dziêkujê za pozbycie siê tej bestii!\n.\nWidzisz przed sob¹ Klasztor Suuomo, to tam mieszka³a legendarna mniszka...\ngdy jeszcze ¿y³a.\n";
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
	else if (b == 1 && a == 0) //czêœæ na pó³noc od startu
	{
		if (x == 4 && y == 10) //NPC w dolnej czêœci
		{
			std::cout << "Na pó³noc st¹d jest targowisko, ale te potê¿ne bestie toruj¹ drogê... \nJu¿ ponad tydzieñ stojê tutaj i czekam a¿ ktoœ siê ich pozbêdzie \ni bêdê móg³ przewieŸæ swoje towary.\n";
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
	 else if (x == 5 && y == 3) //NPC w górnej czêœci
		{
			std::cout << "Wyrzucili mnie z miasta. Powiedzieli, ¿e noszê znamiê Utriona, \nale nie wiem co to znaczy... Ju¿ nie mogê tam wróciæ!\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 1 && a == 1) //œrodek mapy
	{
		if (x == 3 && y == 13) //przedmiot otoczony potworami 7
		{
			Armor deffender7_1;
			deffender7_1.type_def(player);
			deffender7_1.type_stats(player);
			player->addArmor(deffender7_1);
		}
		else if (x == 1 && y == 7) //przedmiot za zgraj¹ potworów 6
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
			std::cout << "To jest krypta zbudowana dla m¹drej mniszki, \nktóra niegdyœ bardzo pomaga³a mieszkañcom tych ziem. \nMieszkañcy Borknagaru znosili tutaj swoje kosztownoœci w podziêce za to, \nco dla nich zrobi³a.\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 1 && a == 2) //,,twarz demona''
	{
		if (x == 13 && y == 11) //przedmiot za zgraj¹ potworów 7
		{
			Armor deffender7_2;
			deffender7_2.type_def(player);
			deffender7_2.type_stats(player);
			player->addArmor(deffender7_2);
		}
		else if (x == 7 && y == 2) //NPC jedyny tutaj
		{
			std::cout << "Podobno gdzieœ tutaj mo¿na zobaczyæ twarz Utriona u³o¿on¹ z kamieni.\nSzukam jej ju¿ 3 dni!\nTo tylko legenda, ale i tak nie mam nic do roboty...\n";
			Sleep(10000);
			system("cls");
		}
	}
	else if (b == 2 && a == 0) //lewy dolny róg ,,du¿ej'' mapy
	{
		if (x == 1 && y == 13) //NPC przy starcie
		{
			std::cout << "Witaj nieznajomy! Lustro Grizzalidu? Nie wiem czy istnieje naprawdê, \nale wed³ug starych legend znajduje siê w klasztorze Suuomo, \nna pó³nocny wschód st¹d...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 1 && y == 10) //pierwsza broñ
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
		else if (x == 3 && y == 9) //przedmiot we wnêce za ,,1''
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
		else if (x == 10 && y == 1) //NPC w prawym górnym rogu
		{
			std::cout << "Pamiêtam, ¿e jak by³em ma³y, w Borknagarze w ogóle nie by³o potworów... \nNie wiem co siê sta³o, ale pewnego dnia, to by³o z 200 lat temu, \nmnisi z klasztoru przestali siê pokazywaæ... \nPewnie potwory dopad³y i ich...\n";
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
			std::cout << "Hej, cz³owieku! Wiesz, ¿e w krypcie tak naprawdê nie ma cia³a mniszki? \nOna zmar³a w klasztorze razem z innymi, ale ma³o kto chce o tym pamiêtaæ, \nto jednak dodaje jej chwa³y i powinniœmy o tym mówiæ g³oœno.\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 7 && y == 11) //NPC 4 linie od do³u
		{
			std::cout << "Proszê o 5.0!\n";
			Sleep(5000);
			system("cls");
		}
		else if (x == 7 && y == 9) //NPC 1 w domku 1
		{
			std::cout << "Cholera! Przgra³em w grê!\n";
			Sleep(5000);
			system("cls");
		}
		else if (x == 7 && y == 7) //NPC 2 w domku 1
		{
			std::cout << "Szkoda, ¿e prawie wszyscy st¹d pouciekali... \nBorknagar by³ pe³en ludzi przed tamtymi wydarzeniami...\n";
			Sleep(7000);
			system("cls");
		}
		else if (x == 8 && y == 7) //NPC 3 w domku 1
		{
			std::cout << "Kiedyœ wystarczy³o pójœæ do klasztoru i poprosiæ o zimê...\nTo wystarczy³o, ¿eby zacz¹³ padaæ œnieg...\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 11 && y == 8) //NPC 1 w domku 2
		{
			std::cout << "Pamiêtam jak w Borknagarze pory roku zmienia³y siê na ¿yczenie... \nale bez tego nie dam rady ju¿ uprawiaæ roli!\n";
			Sleep(10000);
			system("cls");
		}
		else if (x == 10 && y == 7) //NPC 2 w domku 2
		{
			std::cout << "Czemu bierzesz moje z³oto?! Z£ODZIEJ!!!\n";
			Sleep(4000);
			system("cls");
		}
	}
	else if (b == 2 && a == 2) //prawy dolny róg ,,du¿ej'' mapy
	{
	if (x == 13 && y == 13) //prawy dolny róg
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
	else if (x == 5 && y == 9) //przedmiot za zgraj¹ potworów 2
	{
		Equipment potion2(player, 0, "eliksir");
		player->addEquipment(potion2);
	}
	else if (x == 4 && y == 5) //NPC za potworem 4 (jedyny tutaj)
	{
		std::cout << "Dziêkujê za ocalenie mi ¿ycia!\nChowa³em siê przed tym potworem kilka godzin!\nJak wchodzi³em do tej jaskini, to go tutaj nie by³o!\n";
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
				std::cout << "Przegrywasz walkê. Twoja podró¿ koñczy siê tutaj..." << std::endl;
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
	std::cout << "1.Poka¿ ekwipunek \n2.Wyœwietl kartê \n3.Za³ó¿ broñ \n4.Za³ó¿ he³m \n5.Za³ó¿ zbrojê \n6.Za³ó¿ buty \n7.U¿yj przedmiot jednorazowy\n";
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