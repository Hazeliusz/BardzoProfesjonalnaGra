#pragma once
#include <iostream>
#include "Square.h"


void main() {
	setlocale(LC_ALL, "polish");
	srand(time(NULL));
	std::cout << "Wybierz p³eæ: 1 - kobieta, 2 - mê¿czyzna" << std::endl;
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
			std::cout << "Niepoprawny wybór, wybierz ponownie!" << std::endl;
	}
	std::cout << "Witaj, " << (*chosen_sex ? "podró¿niczko" : "podró¿niku") << "!" << std::endl;
	Proffesion* chosen_profession = new Proffesion;
	std::cout << "Do jakiej klasy chcesz przynale¿eæ?" << std::endl;
	std::cout << "1 - Rycerz" << std::endl;
	std::cout << "2 - £ucznik" << std::endl;
	std::cout << "3 - Bard" << std::endl;
	std::cout << "4 - Kleryk" << std::endl;
	std::cout << "5 - Upad³y Rycerz" << std::endl;
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
			std::cout << "Niepoprawny wybór! Wybierz jeszcze raz." << std::endl;
			break;

		}
	}
	std::cout << "Na koniec ostatnie ¿yczenie..." << std::endl;
	std::cout << "Podziel siê swoim imieniem: ";
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
		std::cout << "S³awna wszêdzie Szko³a Rycerstwa w Sahri, znajduj¹ca siê daleko na po³udnie od Borknagaru," << std::endl;
		std::cout << "wypuœci³a ostatnio jednego ze swoich najwybitniejszych absolwentów - ciebie." << std::endl;
		std::cout << "Twój œwiatopogl¹d jest wype³niony szczytnymi ideami, twój umys³ jest szeroki, twoje cia³o jest silne, a twoje umiejêtnoœci - niezrównane." << std::endl;
		std::cout << "Jednak po kilku latach w s³u¿bie Jego Królewskiej Moœci, zaczynasz siê zastanawiaæ : dlaczego na œwiecie jest tyle wojen i dlaczego tylu ludzi musi gin¹æ ? " << std::endl;
		std::cout << "A przecie¿ jesteœ czêœci¹ tego. Ostatnio pewien zakapturzony podró¿nik powiedzia³ ci o Lustrze Grizzalidu: " << std::endl;
		std::cout << "legendarnym artefakcie mog¹cym spe³niæ twoje ¿yczenie o pokoju na œwiecie." << std::endl;
		std::cout << "Wyruszasz wiêc w podró¿ do Borknagaru - krainy na pograniczu legend i prawdy - ¿eby uczyniæ œwiat lepszym miejscem..." << std::endl;
		break;
	case PROFF_ARCHER:
		std::cout << "Twoja rodzina od pokoleñ mieszka³a w Puszczy Ilathiel. Od zawsze byliœcie najlepszymi ³owczymi w okolicy." << std::endl;
		std::cout << "Twoja matka mówi³a, ¿e to dla ciebie za ma³o i zostaniesz kimœ wielkim, kimœ o kim bêdzie siê pisa³o dytyramby." << std::endl;
		std::cout << "Niestety, parê miesiêcy temu zarówno j¹, jak i twojego przyjaciela zabili bandyci.\nTwoja wiêŸ z oboma z nich by³a niezniszczalna, nikt nie mia³ takich przyjació³." << std::endl;
		std::cout << "Gdy zabrak³o w tobie ju¿ ca³kowicie chêci do ¿ycia, podszed³ do ciebie pewien zakapturzony podró¿nik," << std::endl;
		std::cout << "który powiedzia³ ci o Lustrze Grizzalidu - przedmiocie mog¹cym przywróciæ ich do ¿ycia." << std::endl;
		std::cout << "Nie maj¹c wiele do stracenia, wyruszasz na wschód, do Borknagaru," << std::endl;
		std::cout << "krainy, o której kr¹¿¹ niesamowite historie..." << std::endl;
		break;
	case PROFF_BARD:
		std::cout << "Kiedyœ, nie tak dawno temu, twój skarbiec by³ wype³niony po brzegi. Król i Niepodzielny W³adca Gerfhritu - to w³aœnie ty." << std::endl;
		std::cout << "Jednak rz¹dzenie nigdy nie by³o twoj¹ pasj¹ - zamiast tego wiêkszoœæ czasu zajmowa³a ci gra na twojej ukochanej lutni." << std::endl;
		std::cout << "Przez zaniedbywanie rz¹dów i doprowadzenie do biedy pañstwa, wybuch³ bunt. Str¹cono ciê z tronu i goniono po ulicach jak psa." << std::endl;
		std::cout << "Na szczêœcie uda³o ci siê uciec daleko st¹d. Twoj¹ now¹, znalezion¹ na szybko prac¹, zosta³o wypasanie œwiñ." << std::endl;
		std::cout << "Na szczêœcie zosta³a ci jeszcze twoja wspania³a i niezawodna lutnia. Któregoœ dnia podszed³\ndo ciebie pewien zakapturzony podró¿nik, który powiedzia³ ci o Lustrze Grizzalidu: " << std::endl;
		std::cout << "artefakcie mog¹cym przywróciæ ci bogactwo." << std::endl;
		std::cout << "Nie myœl¹c nic, od razu wyruszasz na zachód do krainy Borknagar - miejsca o którym wiele dziwnych rzeczy siê s³yszy..." << std::endl;
		break;
	case PROFF_CLERIC:
		std::cout << "Nie pamiêtasz kiedy rodzice wys³ali ciê na szkolenie kap³añskie, ale tam dzieci oddaje siê zazwyczaj w wieku 4 albo 5 lat." << std::endl;
		std::cout << "Od tamtej pory ju¿ siê nie pojawili. Kiedyœ w twojej g³owie kr¹¿y³y myœli ,,A mo¿e mnie nie kochali''?" << std::endl;
		std::cout << "Ale teraz nie jest to ju¿ wa¿ne." << std::endl;
		std::cout << "Jedyne o czym myœlisz, to Sprawa, a Sprawa polega na wypêdzaniu z tego œwiata demonów i nieumar³ych, a tak¿e leczeniu ludzi i byciu w tym coraz lepszym." << std::endl;
		std::cout << "Przez te wszystkie lata przylgn¹³ do ciebie tytu³ ,,Mistrza Egzorcyzmów''.Teraz interesuje ciê pewna rzecz - imiona demonów." << std::endl;
		std::cout << "Jeœli znasz imiê jakiegoœ demona, to mo¿esz nim w³adaæ, ale czy da siê jakoœ prosto poznaæ jego imiê ? " << std::endl;
		std::cout << "Twoje poszukiwania zakoñczy³a historia o Lustrze Grizzalidu - artefakcie mog¹cym spe³niaæ ¿yczenia." << std::endl;
		std::cout << "Czym prêdzej wiêc wyruszasz na po³udnie to niesamowitej i znanej z licznych opowieœci krainy Borknagar..." << std::endl;
		break;
	case PROFF_DARK_KNIGHT:
		std::cout << "Budzisz siê. Przez kilkadziesi¹t lat demony poddawa³y ciê nieustannym katuszom - \nprzez swoje liczne i ogromnej wagi grzechy na s¹dzie dusz mog³o dostaæ ci siê tylko  jedno - str¹cenie do Piek³a." << std::endl;
		std::cout << "Ale teraz nie jesteœ w Otch³ani. Jesteœ gdzieœ indziej. S³yszysz g³os ,,To ja przywróci³em ciê do ¿ycia!''." << std::endl;
		std::cout << "W³aœciciel g³osu stoi parê metrów przed tob¹, jest zakapturzony. Wstajesz, podnosisz swój miecz...i przecinasz tajemnicz¹ postaæ w pó³." << std::endl;
		std::cout << "Flaki zajmuj¹ ca³¹ pod³ogê. ,,G³upcze! ¯aden nekromanta ani czarodziej nie bêdzie mia³ w³adzy nade mn¹!'' krzyczysz." << std::endl;
		std::cout << "Po tym jak upewniasz siê, ¿e nikogo innego w pokoju nie ma, podchodzisz do tajemniczej\nsterty dokumentów i zaczynasz czytaæ. Na jednej z pierwszych kartek jest opisane Lustro Grizzalidu:" << std::endl;
		std::cout << "artefakt mog¹cy spe³niaæ ¿yczenia. Nie wiedz¹c co ze sob¹ pocz¹æ, wyruszasz do Borknagaru, gdzie ów przedmiot ponoæ siê znajduje..." << std::endl;
		break;
	case PROFF_MAGE:
		std::cout << "Mieszkasz w swojej wie¿y zaraz obok Borknagaru. Przez ca³e ¿ycie jedyn¹ rzecz¹, która by³a dla ciebie cokolwiek warta, by³a wiedza." << std::endl;
		std::cout << "Ju¿ od dziecka wiêcej twojego czasu zajmowa³y ksi¹¿ki ni¿ inni ludzie.Twoja wie¿a stoi daleko od ludzkich osiedli, " << std::endl;
		std::cout << "a jej samej pilnuj¹ stworzone przez ciebie golemy, ¿eby nikt nie przeszkadza³ ci w badaniach." << std::endl;
		std::cout << "Przez te wszystkie lata twoja m¹droœæ i wiedza ci¹gle wzrasta³y, ale ci¹gle by³o ci ma³o, a do tego okazywa³o siê, ¿e nie zd¹¿ysz wszystkiego odkryæ," << std::endl;
		std::cout << "dlatego twoim kolejnym wynalazkiem by³ eliksir m³odoœci - od tamtej pory nie liczysz ju¿ lat." << std::endl;
		std::cout << "Twoje oczy widzia³y jak w Borknagarze zmienia³y siê pory roku, a potem jak pojawi³y siê tam straszliwe bestie i ludzie uciekali czym prêdzej." << std::endl;
		std::cout << "Oczywiœcie historia o Lustrze Grizzalidu nie by³a ci obca. Pewnego dnia nudz¹c siê dopad³a ciê myœl o tym Lustrze." << std::endl;
		std::cout << "Z nudów wyruszasz wiêc do Borknagaru, po wielu latach siedzenia w swojej wie¿y..." << std::endl;
		break;
	default:
		std::cout << "Masz kryzys to¿samoœci." << std::endl;
	}
	system("pause");
	Square world(player);
	while (true) {
		world.draw();
		world.move();
	}

	system("pause");
}