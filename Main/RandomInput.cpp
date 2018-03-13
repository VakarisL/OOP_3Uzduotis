#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include "../Main/Headers/RandomInput.h"

void generate_values(std::vector<int> *ivertinimai, int *egzaminas) {
	std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);

	int kiekis = -1;

	do {
		std::cout << "Kiek pazymiu noretumete sugeneruoti?" << std::endl;
		if (!(std::cin >> kiekis)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			kiekis = -1;
		};
	} while (kiekis == -1);


	for (int i = 0; i < kiekis; i++) {
		ivertinimai->push_back(dist(mt));
	}

	*egzaminas = dist(mt);
}

void generate_speed_test(std::vector <studentaiInfoTest>& speedTest, int amount) {
	std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);

	int tempAvg;
	for (size_t i = 0; i < amount; i++) {
		speedTest.push_back(studentaiInfoTest());
		speedTest[i].vardas.append("Vardas"	+ std::to_string(i + 1));
		speedTest[i].pavarde.append("Pavarde" + std::to_string(i + 1));

		tempAvg =0;
		for (size_t j = 0; j < 5; j++) {
			speedTest[i].nDarbai.push_back(dist(mt));
			tempAvg+=speedTest[i].nDarbai[j];
		}
		double(tempAvg/5) >= 6 ? speedTest[i].pass = true : speedTest[i].pass = false;
		speedTest[i].egzaminas = dist(mt);
	}
}


bool comparePass(const studentaiInfoTest& a, const studentaiInfoTest& b) {return a.pass > b.pass;}