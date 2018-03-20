#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <list>
#include <deque>

#include "../Main/Headers/FileInput.h"

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
	size_t counter = 0;
	while (input >> tempString) {
		studentai.push_back(studentaiInfo());
		studentai[counter].pavarde.append(tempString);
		input >> tempString;
		studentai[counter].vardas.append(tempString);
		for (size_t i = 0; i < 5; i++) {
			input >> tempPazymys;
			studentai[counter].nDarbai.push_back(tempPazymys);
		}
		input >> tempPazymys;
		studentai[counter].egzaminas = tempPazymys;
		counter++;
	}
	input.close();
}

void read_data_test(std::vector<studentaiInfo>& studentai) {
	std::ifstream input;

	try {
		input.open("Main/Resources/Test.txt");
		if(input.fail()) throw "Test failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	int tempPazymys;
	std::string tempString;
	size_t counter = 0;
	double tempAvg;
	while (input >> tempString) {
		tempAvg=0;
		studentai.push_back(studentaiInfo());
		studentai[counter].vardas.append(tempString);
		input >> tempString;
		studentai[counter].pavarde.append(tempString);
		for (size_t i = 0; i < 5; i++) {
			input >> tempPazymys;
			studentai[counter].nDarbai.push_back(tempPazymys);
			tempAvg+=tempPazymys;
		}
		input >> tempPazymys;
		studentai[counter].egzaminas = tempPazymys;
		studentai[counter].average = tempAvg/5;
		counter++;
	}
	input.close();
}

void read_data_test(std::list<studentaiInfo>& studentas) {
	std::ifstream input;

	try {
		input.open("Main/Resources/Test.txt");
		if(input.fail()) throw "Test failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	int tempPazymys;
	std::string tempString;
	size_t counter = 0;
	double tempAvg;
	while (input >> tempString) {
		tempAvg=0;
		studentaiInfo studentai;
		
		studentai.vardas.append(tempString);
		input >> tempString;
		studentai.pavarde.append(tempString);
		for (size_t i = 0; i < 5; i++) {
			input >> tempPazymys;
			studentai.nDarbai.push_back(tempPazymys);
			tempAvg+=tempPazymys;
		}
		input >> tempPazymys;
		studentai.egzaminas = tempPazymys;
		studentai.average = tempAvg/5;
		studentas.push_back(studentai);
	}
	input.close();
}

void read_data_test(std::deque<studentaiInfo>& studentas) {
	std::ifstream input;

	try {
		input.open("Main/Resources/Test.txt");
		if(input.fail()) throw "Test failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	int tempPazymys;
	std::string tempString;
	size_t counter = 0;
	double tempAvg;
	while (input >> tempString) {
		tempAvg=0;
		studentaiInfo studentai;
		
		studentai.vardas.append(tempString);
		input >> tempString;
		studentai.pavarde.append(tempString);
		for (size_t i = 0; i < 5; i++) {
			input >> tempPazymys;
			studentai.nDarbai.push_back(tempPazymys);
			tempAvg+=tempPazymys;
		}
		input >> tempPazymys;
		studentai.egzaminas = tempPazymys;
		studentai.average = tempAvg/5;
		studentas.push_back(studentai);
	}
	input.close();
}

void write_data(std::vector<studentaiInfo> studentai) {
	std::sort(studentai.begin(), studentai.end(), compareNames);
	std::cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) <<
	          "Galutinis-Vidurkis" << std::setw(20) << "Galutinis-Mediana" << std::endl;
	for (size_t i = 0; i < studentai.size(); i++) {
		std::cout << std::left << std::setw(20) << studentai[i].pavarde << std::setw(20) << studentai[i].vardas <<
		          std::setprecision(2) << std::fixed << std::setw(20) << 0.4 * studentai[i].average + studentai[i].egzaminas * 0.6 <<
		          std::setw(20) << 0.4 * studentai[i].median + studentai[i].egzaminas * 0.6 << std::endl;
	}
}

bool compareNames(const studentaiInfo& a, const studentaiInfo& b) {return a.vardas < b.vardas;}