#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../Main/Headers/InfoFromFile.h"
#include "../Main/Headers/StudentaiInfo.h"

void read_data(std::vector<studentaiInfo>& studentai) {
	std::ifstream input;

	try {
		input.open("Main/Resources/Kursiokai.txt");
		if (input.fail()) throw "Failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::terminate();
	}

	int tempPazymys;
	std::string tempString;
	while (input >> tempString) {
		studentaiInfo studentas;

		studentas.setVardas(tempString);
		input >> tempString;
		studentas.setPavarde(tempString);
		for (size_t i = 0; i < 5; i++) {
			if (!(input >> tempPazymys)) {
				std::cerr << "Pateiktas failas turi formatavimo klaida" << std::endl;
				std::exit(EXIT_SUCCESS);
			} else {studentas.setDarbai(tempPazymys);}

		}
		if (!(input >> tempPazymys)) {
			std::cerr << "Pateiktas failas turi formatavimo klaida" << std::endl;
			std::terminate();
		} else {studentas.setEgzaminas(tempPazymys);}
		studentai.push_back(studentas);
	}
	input.close();
}