#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../Main/Headers/InfoFromFile.h"
#include "../Main/Headers/MathFunctions.h"

void read_data(std::vector<studentaiInfo>& studentai) {
	std::ifstream input;

	try {
		input.open("Main/Resources/Kursiokai.txt");
		if(input.fail()) throw "Failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	int tempPazymys;
	std::string tempString;
	while (input >> tempString) {
		studentaiInfo studentas;

		studentas.vardas.append(tempString);
		input >> tempString;
		studentas.pavarde.append(tempString);
		for (size_t i = 0; i < 5; i++) {
			input >> tempPazymys;
			studentas.nDarbai.push_back(tempPazymys);
		}
		input >> tempPazymys;
		studentas.egzaminas = tempPazymys;
		studentas.average = darbuVidurkis(studentas.nDarbai);
		studentas.median = darbuMediana(studentas.nDarbai);
		studentai.push_back(studentas);
	}
	input.close();
}