#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../Main/Headers/InfoFromFile.h"
#include "../Main/Headers/StudentaiInfo.h"

/**
 * @brief	reads data from Kursiokai.txt
 * @details the data in file has to be of form [name] [surname] [grade] [grade] [grade] [grade] [grade] [exam grade]
 * 
 * @param studentai [vector of class objects to read data into]
 */

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
	while (!input.eof()) {
		studentaiInfo tempStudentas(input);
		studentai.push_back(tempStudentas);
	}
	input.close();
}