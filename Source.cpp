#include <iostream>
#include "character.h"
#include "Interactions.h"

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
	
	

	system("pause");
}