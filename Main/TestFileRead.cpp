#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>

#include "../Main/Headers/TestFileRead.h"
#include "../Main/Headers/StudentaiInfo.h"

void read_data_test(std::vector<studentaiInfo>& studentai, int amount) {
	std::ifstream input;

	try {
		input.open("Main/Resources/Test.txt");
		if (input.fail()) throw "Test failas nerastas folderyje";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::terminate();
	}

	for (size_t i; i<amount; i++) {
		studentaiInfo tempStudentas(input);
		studentai.push_back(tempStudentas);
	}
	input.close();
}