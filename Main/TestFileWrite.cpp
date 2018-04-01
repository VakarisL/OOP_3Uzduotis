#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <fstream>

#include "../Main/Headers/TestFileWrite.h"
#include "../Main/Headers/StudentaiInfo.h"

void FileWrite(std::vector <studentaiInfo>& speedTestPass) {
	std::ofstream FileOut;
	try {
		FileOut.open("TestOutputV.txt", std::ofstream::out | std::ofstream::trunc);
		if (FileOut.fail()) throw "Nepavyko sukurti failo irasymui";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	for (auto i : speedTestPass) {
		FileOut << i.vardas << " " << i.pavarde << " ";
		for (auto j : i.nDarbai) {
			FileOut << j << " ";
		}
		FileOut << i.egzaminas << " " << "Vidurkis: " << i.average;
		i.average >= 6 ? FileOut << " Pass" << std::endl : FileOut << " Fail" << std::endl;
	}

	FileOut.close();

}

void FileWrite(std::list <studentaiInfo>& speedTestPass) {
	std::ofstream FileOut;
	try {
		FileOut.open("TestOutputL.txt", std::ofstream::out | std::ofstream::trunc);
		if (FileOut.fail()) throw "Nepavyko sukurti failo irasymui";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	for (auto i : speedTestPass) {
		FileOut << i.vardas << " " << i.pavarde << " ";
		for (auto j : i.nDarbai) {
			FileOut << j << " ";
		}
		FileOut << i.egzaminas << " " << "Vidurkis: " << i.average;
		i.average >= 6 ? FileOut << " Pass" << std::endl : FileOut << " Fail" << std::endl;
	}

	FileOut.close();

}

void FileWrite(std::deque <studentaiInfo>& speedTestPass) {
	std::ofstream FileOut;
	try {
		FileOut.open("TestOutputD.txt", std::ofstream::out | std::ofstream::trunc);
		if (FileOut.fail()) throw "Nepavyko sukurti failo irasymui";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	for (auto i : speedTestPass) {
		FileOut << i.vardas << " " << i.pavarde << " ";
		for (auto j : i.nDarbai) {
			FileOut << j << " ";
		}
		FileOut << i.egzaminas << " " << "Vidurkis: " << i.average;
		i.average >= 6 ? FileOut << " Pass" << std::endl : FileOut << " Fail" << std::endl;
	}

	FileOut.close();

}