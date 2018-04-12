#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>

#include "../Main/Headers/TestFileRead.h"
#include "../Main/Headers/StudentaiInfo.h"
#include "../Main/Headers/MathFunctions.h"

void read_data_test(std::vector<studentaiInfo>& studentai) {
	std::ifstream input;

	try {
		input.open("Main/Resources/Test.txt");
		if (input.fail()) throw "Test failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	int tempPazymys;
	std::string tempString;
	while (input >> tempString) {
		studentaiInfo studentas;

		studentas.setVardas(tempString);
		input >> tempString;
		studentas.setPavarde(tempString);
		for (size_t i = 0; i < 5; i++) {
			input >> tempPazymys;
			studentas.setDarbai(tempPazymys);
		}
		input >> tempPazymys;
		studentas.setEgzaminas(tempPazymys);
		studentai.push_back(studentas);
	}
	input.close();
}

void read_data_test(std::list<studentaiInfo>& studentai) {
	std::ifstream input;

	try {
		input.open("Main/Resources/Test.txt");
		if (input.fail()) throw "Test failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	int tempPazymys;
	std::string tempString;
	while (input >> tempString) {
		studentaiInfo studentas;

		studentas.setVardas(tempString);
		input >> tempString;
		studentas.setPavarde(tempString);
		for (size_t i = 0; i < 5; i++) {
			input >> tempPazymys;
			studentas.setDarbai(tempPazymys);
		}
		input >> tempPazymys;
		studentas.setEgzaminas(tempPazymys);
		studentai.push_back(studentas);
	}
	input.close();
}

void read_data_test(std::deque<studentaiInfo>& studentai) {
	std::ifstream input;

	try {
		input.open("Main/Resources/Test.txt");
		if (input.fail()) throw "Test failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	int tempPazymys;
	std::string tempString;
	while (input >> tempString) {
		studentaiInfo studentas;

		studentas.setVardas(tempString);
		input >> tempString;
		studentas.setPavarde(tempString);
		for (size_t i = 0; i < 5; i++) {
			input >> tempPazymys;
			studentas.setDarbai(tempPazymys);
		}
		input >> tempPazymys;
		studentas.setEgzaminas(tempPazymys);
		studentai.push_back(studentas);
	}
	input.close();
}