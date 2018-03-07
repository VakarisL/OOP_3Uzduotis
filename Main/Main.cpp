#include <iostream>
#include <string>
#include <vector>

#include "../Main/Headers/FileInput.h"
#include "../Main/Headers/ConsoleInput.h"
#include "../Main/Headers/RandomInput.h"
#include "../Main/Headers/MathFunctions.h"
#include "../Main/Headers/ConsoleOutput.h"



void output(double galBalasVid, double galBalasMed, int *egzaminas, std::vector<int> *ivertinimai, std::string vardas, std::string pavarde);

int main() {


	std::vector<int> *ivertinimai = new std::vector<int>;
	int *egzaminas = new int;
	double galBalasVid, galBalasMed;

	int choice = 0;
	do {
		std::cout << "Ar norite:" << std::endl;
		std::cout << "1- Irasyti pazymius ranka" << std::endl;
		std::cout << "2- Generuoti atsitiktinius pazymius" << std::endl;
		std::cout << "3- Skaityti pazymius is failo" << std::endl;
		std::cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3);

	switch (choice) {
	case 1: {
		std::string vardas, pavarde;
		std::cout << "Iveskite studento varda: " << std::endl;
		std::cin >> vardas;
		std::cout << "Iveskite studento pavarde: " << std::endl;
		std::cin >> pavarde;
		input_by_hand(ivertinimai, egzaminas);

		output(galBalasVid,galBalasMed,egzaminas,ivertinimai, vardas, pavarde);
		break;
	}
	case 2: {
		std::string vardas, pavarde;
		std::cout << "Iveskite studento varda: " << std::endl;
		std::cin >> vardas;
		std::cout << "Iveskite studento pavarde: " << std::endl;
		std::cin >> pavarde;
		generate_values(ivertinimai, egzaminas);

		output(galBalasVid,galBalasMed,egzaminas,ivertinimai, vardas, pavarde);
		break;
	}
	case 3: {
		std::vector<studentaiInfo> studentai;
		read_data(studentai);
		for (size_t i = 0; i < studentai.size(); i++) {
			studentai[i].average = darbuVidurkis(&studentai[i].nDarbai);
			studentai[i].median = darbuMediana(studentai[i].nDarbai);
		}
		write_data(studentai);
		break;
	}
	}
}

