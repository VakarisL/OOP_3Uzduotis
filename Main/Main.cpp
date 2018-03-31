#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

#include "../Main/Headers/Menu.h"
#include "../Main/Headers/InfoFromConsole.h"
#include "../Main/Headers/studentaiInfo.h"
#include "../Main/Headers/InfoFromRNG.h"

#include "../Main/Headers/FileInput.h"
#include "../Main/Headers/RandomInput.h"
#include "../Main/Headers/MathFunctions.h"
#include "../Main/Headers/ConsoleOutput.h"

int main() {
	int choice = 0;
	MainMenu(choice);

	switch (choice) {
	case 1: {
    	studentaiInfo studentai;
		InitialInfo(studentai.vardas, studentai.pavarde);
		input_by_hand(studentai.nDarbai, studentai.egzaminas);
		output(studentai);
		break;
	}
	case 2: {
		studentaiInfo studentai;
		InitialInfo(studentai.vardas, studentai.pavarde);
		generate_values(studentai.nDarbai, studentai.egzaminas);
		output(studentai);
		break;
	}
	case 3: {
		// std::vector<studentaiInfo> studentai;
		// read_data(studentai);
		// for (size_t i = 0; i < studentai.size(); i++) {
		// 	studentai[i].average = darbuVidurkis(&studentai[i].nDarbai);
		// 	studentai[i].median = darbuMediana(studentai[i].nDarbai);
		// }
		// write_data(studentai);
		break;
	}
  case 4: {
    SpeedTest(10);
    SpeedTest(100);
    SpeedTest(1000);
    SpeedTest(10000);
    SpeedTest(100000);
    break;
  }
  case 5: {
    std::cout << "Bye bye!" << std::endl;
    break;
  }
	default: {
		std::cerr << "Ivyko switch klaida" << std::endl;
	}
	}
}

