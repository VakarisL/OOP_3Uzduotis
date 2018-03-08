#include <iostream>
#include <string>
#include <vector>

#include "../Main/Headers/FileInput.h"
#include "../Main/Headers/ConsoleInput.h"
#include "../Main/Headers/RandomInput.h"
#include "../Main/Headers/MathFunctions.h"
#include "../Main/Headers/ConsoleOutput.h"

int main() {


	std::vector<int> *ivertinimai = new std::vector<int>;
	int *egzaminas = new int;
	double galBalasVid, galBalasMed;

	int choice = 0;
	MainMenu(choice);

	switch (choice) {
	case 1: {
		std::string vardas, pavarde;
		InitialInfo(vardas, pavarde);
		input_by_hand(ivertinimai, egzaminas);
		output(galBalasVid, galBalasMed, egzaminas, ivertinimai, vardas, pavarde);
		break;
	}
	case 2: {
		std::string vardas, pavarde;
		InitialInfo(vardas, pavarde);
		generate_values(ivertinimai, egzaminas);
		output(galBalasVid, galBalasMed, egzaminas, ivertinimai, vardas, pavarde);
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
	default: {
		std::cout << "Ivyko switch klaida" << std::endl;
	}
	}
}

