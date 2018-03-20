#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

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

void generate_speed_test_file(int amount) {
	std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution<int> dist(1, 10);

	std::ofstream TestFile;
	try{
		TestFile.open("Main/Resources/Test.txt", std::ofstream::out | std::ofstream::trunc);
		if(TestFile.fail()) throw "Nepavyko sukurti failo testavimui ";
	} catch (const char* e) {
		std::cerr << e << amount << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	for (size_t i = 0; i < amount; i++) {
		TestFile << "Vardas" << i + 1 << " Pavarde" << i+1 << " ";
		for (size_t j = 0; j < 5; j++) {
			TestFile << dist(mt) << " ";
		}
		TestFile << dist(mt) << std::endl;
	}

	TestFile.close();
}