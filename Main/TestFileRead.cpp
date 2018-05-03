#include <iostream>
#include <fstream>
#include <vector>

#include "../Main/Headers/TestFileRead.h"
#include "../Main/Headers/StudentaiInfo.h"

/**
 * @brief reads data from Test.txt
 * @details the data in file has to be of form [name] [surname] [grade] [grade] [grade] [grade] [grade] [exam grade]
 * 
 * @param studentai [vector of class objects to read data into]]
 * @param amount [number of data entries in the file]
 */

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