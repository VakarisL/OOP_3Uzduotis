#include <iostream>
#include <vector>

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