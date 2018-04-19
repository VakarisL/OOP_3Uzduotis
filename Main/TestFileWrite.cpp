#include <iostream>
#include <vector>
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
		FileOut << i.vardas() << " " << i.pavarde() << " ";
		for (auto j : i.pazymiai()) {
			FileOut << j << " ";
		}
		FileOut << i.egzaminas() << " " << "Pazymys: " << i.galBalas();
		i.galBalas() >= 6 ? FileOut << " Pass" << std::endl : FileOut << " Fail" << std::endl;
	}

	FileOut.close();

}

void FileWriteUC(std::vector <studentaiInfo>& kieti, std::vector <studentaiInfo>& vargsai) {
	std::ofstream FileOut;
	try {
		FileOut.open("TestOutputV.txt", std::ofstream::out | std::ofstream::trunc);
		if (FileOut.fail()) throw "Nepavyko sukurti failo irasymui";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	for (auto i : kieti) {
		FileOut << i.vardas() << " " << i.pavarde() << " ";
		for (auto j : i.pazymiai()) {
			FileOut << j << " ";
		}
		FileOut << i.egzaminas() << " " << "Pazymys: " << i.galBalas();
		FileOut << " Pass" << std::endl;
	}

	for (auto i : vargsai) {
		FileOut << i.vardas() << " " << i.pavarde() << " ";
		for (auto j : i.pazymiai()) {
			FileOut << j << " ";
		}
		FileOut << i.egzaminas() << " " << "Pazymys: " << i.galBalas();
		FileOut << " Fail" << std::endl;
	}

	FileOut.close();
}