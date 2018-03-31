#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include "../Main/Headers/InfoFromRNG.h"

void generate_values(std::vector<int>& ivertinimai, int& egzaminas) {
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
		ivertinimai.push_back(dist(mt));
	}

	egzaminas = dist(mt);
}