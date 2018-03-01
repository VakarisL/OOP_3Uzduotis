#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <fstream>

#include "../Main/Headers/RandomInput.h"

void generate_values(std::vector<int> *ivertinimai, int *egzaminas) {
	std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);

	int kiekis = 0;
	std::cout << "Kiek pazymiu noretumete sugeneruoti?" << std::endl;
	std::cin >> kiekis;

	for (int i = 0; i < kiekis; i++) {
		ivertinimai->push_back(dist(mt));
	}

	*egzaminas = dist(mt);
}