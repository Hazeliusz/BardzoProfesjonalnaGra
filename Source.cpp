#pragma once
#include <iostream>
#include "Square.h"


void main() {
	setlocale(LC_ALL, "polish");
	srand(time(NULL));
	std::cout << "Wybierz p�e�: 1 - kobieta, 2 - m�czyzna" << std::endl;
	bool* chosen_sex = new bool;
	while (true) {
		int choice;
		std::cin >> choice;
		if (choice == 1) {
			*chosen_sex = true;
			break;
		}
		else if (choice == 2) {
			*chosen_sex = false;
			break;
		}
		else
			std::cout << "Niepoprawny wyb�r, wybierz ponownie!" << std::endl;
	}
	std::cout << "Witaj, " << (*chosen_sex ? "podr�niczko" : "podr�niku") << "!" << std::endl;
	Proffesion* chosen_profession = new Proffesion;
	std::cout << "Do jakiej klasy chcesz przynale�e�?" << std::endl;
	std::cout << "1 - Rycerz" << std::endl;
	std::cout << "2 - �ucznik" << std::endl;
	std::cout << "3 - Bard" << std::endl;
	std::cout << "4 - Kleryk" << std::endl;
	std::cout << "5 - Upad�y Rycerz" << std::endl;
	std::cout << "6 - Mag" << std::endl;
	for (bool stop = true; stop;) {
		int wybor;
		std::cin >> wybor;
		switch (wybor) {
		case 1:
			*chosen_profession = PROFF_KNIGHT;
			stop = false;
			break;
		case 2:
			*chosen_profession = PROFF_ARCHER;
			stop = false;
			break;
		case 3:
			*chosen_profession = PROFF_BARD;
			stop = false;
			break;
		case 4:
			*chosen_profession = PROFF_CLERIC;
			stop = false;
			break;
		case 5:
			*chosen_profession = PROFF_DARK_KNIGHT;
			stop = false;
			break;
		case 6:
			*chosen_profession = PROFF_MAGE;
			stop = false;
			break;
		default:
			std::cout << "Niepoprawny wyb�r! Wybierz jeszcze raz." << std::endl;
			break;

		}
	}
	std::cout << "Na koniec ostatnie �yczenie..." << std::endl;
	std::cout << "Podziel si� swoim imieniem: ";
	std::string chosen_name;
	std::cin >> chosen_name;
	Character* player = nullptr;
	switch (*chosen_profession) {
	case PROFF_KNIGHT:
		player = new Knight(chosen_name, *chosen_sex);
		break;
	case PROFF_ARCHER:
		player = new Archer(chosen_name, *chosen_sex);
		break;
	case PROFF_BARD:
		player = new Bard(chosen_name, *chosen_sex);
		break;
	case PROFF_CLERIC:
		player = new Cleric(chosen_name, *chosen_sex);
		break;
	case PROFF_DARK_KNIGHT:
		player = new Dark_Knight(chosen_name, *chosen_sex);
		break;
	case PROFF_MAGE:
		player = new Mage(chosen_name, *chosen_sex);
		break;
	}
	delete chosen_sex;
	delete chosen_profession;
	player->randomizeStatistics();
	player->drawCharacterCard();
	switch (player->GetProffesion()) {
	case PROFF_KNIGHT:
		std::cout << "S�awna wsz�dzie Szko�a Rycerstwa w Sahri, znajduj�ca si� daleko na po�udnie od Borknagaru," << std::endl;
		std::cout << "wypu�ci�a ostatnio jednego ze swoich najwybitniejszych absolwent�w - ciebie." << std::endl;
		std::cout << "Tw�j �wiatopogl�d jest wype�niony szczytnymi ideami, tw�j umys� jest szeroki, twoje cia�o jest silne, a twoje umiej�tno�ci - niezr�wnane." << std::endl;
		std::cout << "Jednak po kilku latach w s�u�bie Jego Kr�lewskiej Mo�ci, zaczynasz si� zastanawia� : dlaczego na �wiecie jest tyle wojen i dlaczego tylu ludzi musi gin�� ? " << std::endl;
		std::cout << "A przecie� jeste� cz�ci� tego. Ostatnio pewien zakapturzony podr�nik powiedzia� ci o Lustrze Grizzalidu: " << std::endl;
		std::cout << "legendarnym artefakcie mog�cym spe�ni� twoje �yczenie o pokoju na �wiecie." << std::endl;
		std::cout << "Wyruszasz wi�c w podr� do Borknagaru - krainy na pograniczu legend i prawdy - �eby uczyni� �wiat lepszym miejscem..." << std::endl;
		break;
	case PROFF_ARCHER:
		std::cout << "Twoja rodzina od pokole� mieszka�a w Puszczy Ilathiel. Od zawsze byli�cie najlepszymi �owczymi w okolicy." << std::endl;
		std::cout << "Twoja matka m�wi�a, �e to dla ciebie za ma�o i zostaniesz kim� wielkim, kim� o kim b�dzie si� pisa�o dytyramby." << std::endl;
		std::cout << "Niestety, par� miesi�cy temu zar�wno j�, jak i twojego przyjaciela zabili bandyci.\nTwoja wi� z oboma z nich by�a niezniszczalna, nikt nie mia� takich przyjaci�." << std::endl;
		std::cout << "Gdy zabrak�o w tobie ju� ca�kowicie ch�ci do �ycia, podszed� do ciebie pewien zakapturzony podr�nik," << std::endl;
		std::cout << "kt�ry powiedzia� ci o Lustrze Grizzalidu - przedmiocie mog�cym przywr�ci� ich do �ycia." << std::endl;
		std::cout << "Nie maj�c wiele do stracenia, wyruszasz na wsch�d, do Borknagaru," << std::endl;
		std::cout << "krainy, o kt�rej kr��� niesamowite historie..." << std::endl;
		break;
	case PROFF_BARD:
		std::cout << "Kiedy�, nie tak dawno temu, tw�j skarbiec by� wype�niony po brzegi. Kr�l i Niepodzielny W�adca Gerfhritu - to w�a�nie ty." << std::endl;
		std::cout << "Jednak rz�dzenie nigdy nie by�o twoj� pasj� - zamiast tego wi�kszo�� czasu zajmowa�a ci gra na twojej ukochanej lutni." << std::endl;
		std::cout << "Przez zaniedbywanie rz�d�w i doprowadzenie do biedy pa�stwa, wybuch� bunt. Str�cono ci� z tronu i goniono po ulicach jak psa." << std::endl;
		std::cout << "Na szcz�cie uda�o ci si� uciec daleko st�d. Twoj� now�, znalezion� na szybko prac�, zosta�o wypasanie �wi�." << std::endl;
		std::cout << "Na szcz�cie zosta�a ci jeszcze twoja wspania�a i niezawodna lutnia. Kt�rego� dnia podszed�\ndo ciebie pewien zakapturzony podr�nik, kt�ry powiedzia� ci o Lustrze Grizzalidu: " << std::endl;
		std::cout << "artefakcie mog�cym przywr�ci� ci bogactwo." << std::endl;
		std::cout << "Nie my�l�c nic, od razu wyruszasz na zach�d do krainy Borknagar - miejsca o kt�rym wiele dziwnych rzeczy si� s�yszy..." << std::endl;
		break;
	case PROFF_CLERIC:
		std::cout << "Nie pami�tasz kiedy rodzice wys�ali ci� na szkolenie kap�a�skie, ale tam dzieci oddaje si� zazwyczaj w wieku 4 albo 5 lat." << std::endl;
		std::cout << "Od tamtej pory ju� si� nie pojawili. Kiedy� w twojej g�owie kr��y�y my�li ,,A mo�e mnie nie kochali''?" << std::endl;
		std::cout << "Ale teraz nie jest to ju� wa�ne." << std::endl;
		std::cout << "Jedyne o czym my�lisz, to Sprawa, a Sprawa polega na wyp�dzaniu z tego �wiata demon�w i nieumar�ych, a tak�e leczeniu ludzi i byciu w tym coraz lepszym." << std::endl;
		std::cout << "Przez te wszystkie lata przylgn�� do ciebie tytu� ,,Mistrza Egzorcyzm�w''.Teraz interesuje ci� pewna rzecz - imiona demon�w." << std::endl;
		std::cout << "Je�li znasz imi� jakiego� demona, to mo�esz nim w�ada�, ale czy da si� jako� prosto pozna� jego imi� ? " << std::endl;
		std::cout << "Twoje poszukiwania zako�czy�a historia o Lustrze Grizzalidu - artefakcie mog�cym spe�nia� �yczenia." << std::endl;
		std::cout << "Czym pr�dzej wi�c wyruszasz na po�udnie to niesamowitej i znanej z licznych opowie�ci krainy Borknagar..." << std::endl;
		break;
	case PROFF_DARK_KNIGHT:
		std::cout << "Budzisz si�. Przez kilkadziesi�t lat demony poddawa�y ci� nieustannym katuszom - \nprzez swoje liczne i ogromnej wagi grzechy na s�dzie dusz mog�o dosta� ci si� tylko  jedno - str�cenie do Piek�a." << std::endl;
		std::cout << "Ale teraz nie jeste� w Otch�ani. Jeste� gdzie� indziej. S�yszysz g�os ,,To ja przywr�ci�em ci� do �ycia!''." << std::endl;
		std::cout << "W�a�ciciel g�osu stoi par� metr�w przed tob�, jest zakapturzony. Wstajesz, podnosisz sw�j miecz...i przecinasz tajemnicz� posta� w p�." << std::endl;
		std::cout << "Flaki zajmuj� ca�� pod�og�. ,,G�upcze! �aden nekromanta ani czarodziej nie b�dzie mia� w�adzy nade mn�!'' krzyczysz." << std::endl;
		std::cout << "Po tym jak upewniasz si�, �e nikogo innego w pokoju nie ma, podchodzisz do tajemniczej\nsterty dokument�w i zaczynasz czyta�. Na jednej z pierwszych kartek jest opisane Lustro Grizzalidu:" << std::endl;
		std::cout << "artefakt mog�cy spe�nia� �yczenia. Nie wiedz�c co ze sob� pocz��, wyruszasz do Borknagaru, gdzie �w przedmiot pono� si� znajduje..." << std::endl;
		break;
	case PROFF_MAGE:
		std::cout << "Mieszkasz w swojej wie�y zaraz obok Borknagaru. Przez ca�e �ycie jedyn� rzecz�, kt�ra by�a dla ciebie cokolwiek warta, by�a wiedza." << std::endl;
		std::cout << "Ju� od dziecka wi�cej twojego czasu zajmowa�y ksi��ki ni� inni ludzie.Twoja wie�a stoi daleko od ludzkich osiedli, " << std::endl;
		std::cout << "a jej samej pilnuj� stworzone przez ciebie golemy, �eby nikt nie przeszkadza� ci w badaniach." << std::endl;
		std::cout << "Przez te wszystkie lata twoja m�dro�� i wiedza ci�gle wzrasta�y, ale ci�gle by�o ci ma�o, a do tego okazywa�o si�, �e nie zd��ysz wszystkiego odkry�," << std::endl;
		std::cout << "dlatego twoim kolejnym wynalazkiem by� eliksir m�odo�ci - od tamtej pory nie liczysz ju� lat." << std::endl;
		std::cout << "Twoje oczy widzia�y jak w Borknagarze zmienia�y si� pory roku, a potem jak pojawi�y si� tam straszliwe bestie i ludzie uciekali czym pr�dzej." << std::endl;
		std::cout << "Oczywi�cie historia o Lustrze Grizzalidu nie by�a ci obca. Pewnego dnia nudz�c si� dopad�a ci� my�l o tym Lustrze." << std::endl;
		std::cout << "Z nud�w wyruszasz wi�c do Borknagaru, po wielu latach siedzenia w swojej wie�y..." << std::endl;
		break;
	default:
		std::cout << "Masz kryzys to�samo�ci." << std::endl;
	}
	system("pause");
	Square world(player);
	while (true) {
		world.draw();
		world.move();
	}

	system("pause");
}