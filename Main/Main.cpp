#include <iostream>
#include <string>
#include <vector>

#include "../Main/Headers/Menu.h"
#include "../Main/Headers/studentaiInfo.h"
#include "../Main/Headers/InfoFromFile.h"
#include "../Main/Headers/Tests.h"

int main() {
	int choice = 0;
	MainMenu(choice);

	switch (choice) {
	case 1: {
		std::vector<studentaiInfo> studentai;
		read_data(studentai);
		output(studentai);
		break;
	}
	case 2: {
		SpeedTest(10, 1);
		SpeedTest(100, 1);
		SpeedTest(1000, 1);
		SpeedTest(10000, 1);
		SpeedTest(100000, 1);
		break;
	}
	case 3: {
		SpeedTest(10, 2);
		SpeedTest(100, 2);
		SpeedTest(1000, 2);
		SpeedTest(10000, 2);
		SpeedTest(100000, 2);
		break;
	}
	case 4: {
		SpeedTest(10, 3);
		SpeedTest(100, 3);
		SpeedTest(1000, 3);
		SpeedTest(10000, 3);
		SpeedTest(100000, 3);
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

	return 0;
}

