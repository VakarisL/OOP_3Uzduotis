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
		SpeedTest(10, test);
		SpeedTest(100, test);
		SpeedTest(1000, test);
		SpeedTest(10000, test);
		SpeedTest(100000, test);
		break;
	}
	case 3: {
		SpeedTest(10, testTwoContainers);
		SpeedTest(100, testTwoContainers);
		SpeedTest(1000, testTwoContainers);
		SpeedTest(10000, testTwoContainers);
		SpeedTest(100000, testTwoContainers);
		break;
	}
	case 4: {
		SpeedTest(10, testSingleContainer);
		SpeedTest(100, testSingleContainer);
		SpeedTest(1000, testSingleContainer);
		SpeedTest(10000, testSingleContainer);
		SpeedTest(100000, testSingleContainer);
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

