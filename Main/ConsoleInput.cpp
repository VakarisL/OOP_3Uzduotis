#include <iostream>
#include <vector>
#include <string>

#include "../Main/Headers/ConsoleInput.h"

void input_by_hand(std::vector<int> *ivertinimai, int *egzaminas) {
	std::cout << "Iveskite namu darbu pazymius (-1 norint uzbaigti)" << std::endl;

	int pazymys = 0, counter = 1;
	do {
		std::cout << "iveskite " << counter << " pazymi: ";
		std::cin >> pazymys;
		if (pazymys <= 10 &&  pazymys >= 0) {
			ivertinimai->push_back(pazymys);
			counter++;
		} else {
			if (pazymys != (-1)) {
				std::cout << "Ivestas ivertinimas nepriklauso desimtbalei sistemai" << std::endl;
				pazymys = 0;
			}
		}
	} while (pazymys != (-1));

	std::cout << "iveskite egzamino pazymi: ";
	std::cin >> *egzaminas;
}

void InitialInfo(std::string& vardas, std::string& pavarde) {
	std::cout << "Iveskite studento varda: " << std::endl;
	std::cin >> vardas;
	std::cout << "Iveskite studento pavarde: " << std::endl;
	std::cin >> pavarde;
}

void MainMenu(int& choice) {
	do {
		std::cout << "Ar norite:" << std::endl;
		std::cout << "1- Irasyti pazymius ranka" << std::endl;
		std::cout << "2- Generuoti atsitiktinius pazymius" << std::endl;
		std::cout << "3- Skaityti pazymius is failo" << std::endl;
		std::cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3);
}