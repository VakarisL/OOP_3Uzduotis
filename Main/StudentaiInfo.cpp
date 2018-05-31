#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#include "../Main/Headers/StudentaiInfo.h"

/**
 * @brief constructor for the class obj
 * @details takes the istream and tries to read values for the class object, if the file doesn't match the expected format
 * 			([name] [surname] [grade] [grade] [grade] [grade] [grade] [exam grade])
 * 			the program notifies the user and terminates.
 *
 * @param input [input stream of file form which the data will be collected]
 */

void studentaiInfo::readStudent(std:: istream& input) {
	input >> Vardas;
	input >> Pavarde;
	int tempPazymys;
	for (size_t i = 0; i < 5; i++) {
		if (!(input >> tempPazymys)) {
			std::cerr << "Pateiktas failas turi formatavimo klaida" << std::endl;
			std::terminate();

		}
		nDarbai.push_back(tempPazymys);
	}
	if (!(input >> Egzaminas)) {
		std::cerr << "Pateiktas failas turi formatavimo klaida" << std::endl;
		std::terminate();
	}
}

void studentaiInfo::setVidurkis() {
	if (nDarbai.size() == 0) Vidurkis = 0;
	else Vidurkis = ((double) std::accumulate(nDarbai.begin(), nDarbai.end(), 0.0) / nDarbai.size());
}

void studentaiInfo::setMediana() {
	std::vector<int> *tempVector = new std::vector<int>;
	*tempVector = nDarbai;
	if (tempVector->size() == 0) Mediana = 0;
	std::sort(tempVector->begin(), tempVector->end());
	if (tempVector->size() % 2 == 1) {
		Mediana = tempVector->operator[]((tempVector->size() - 1) / 2);
	} else {
		Mediana =  ((double)tempVector->operator[]((tempVector->size() - 1) / 2) / 2 +
		            (double)tempVector->operator[]((tempVector->size() - 1) / 2 + 1) / 2);
	}
}

void studentaiInfo::setGalutinisBalas() {
	Galutinis_Balas = (0.4 * Vidurkis + Egzaminas * 0.6);
}

std::ostream& operator<<(std::ostream& out, const studentaiInfo& a) {
	out << a.vardas() << " " << a.pavarde() << " -> Pazymiai: ";
	for (auto i : a.pazymiai()) {out << i << " ";}
	out << "Egzaminas: " << a.egzaminas() << " Galutinis Balas: " << a.galBalas() << "\n";
	return out;
}

