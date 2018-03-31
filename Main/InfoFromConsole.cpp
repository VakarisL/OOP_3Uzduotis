#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "../Main/Headers/InfoFromConsole.h"

void input_by_hand(std::vector<int>& ivertinimai, int& egzaminas) {
	std::cout << "Iveskite namu darbu pazymius (-1 norint uzbaigti)" << std::endl;

	int pazymys = 0, counter = 1;
	do {
		std::cout << "iveskite " << counter << " pazymi: ";
		if (!(std::cin >> pazymys)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (pazymys <= 10 &&  pazymys >= 0) {
			ivertinimai.push_back(pazymys);
			counter++;
		} else {
			if (pazymys != (-1)) {
				std::cout << "Ivestas ivertinimas nepriklauso desimtbalei sistemai" << std::endl;
				pazymys = 0;
			}
		}
	} while (pazymys != (-1));


	do {
		std::cout << "iveskite egzamino pazymi: ";
		if (!(std::cin >> pazymys)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		} else {egzaminas = pazymys;}
		if (pazymys > 10 || pazymys <= 0) {
			std::cout << "Ivestas ivertinimas nepriklauso desimtbalei sistemai" << std::endl;
			pazymys = 0;
		}
	} while (pazymys > 10 || pazymys < 1);
}