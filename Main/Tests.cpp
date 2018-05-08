#include <iostream>
#include <vector>
#include <algorithm>

#include "../Main/Headers/Tests.h"
#include "../Main/Headers/Timer.h"
#include "../Main/Headers/TestFileRead.h"
#include "../Main/Headers/TestFileWrite.h"
#include "../Main/Headers/GenerateTestFile.h"

/**
 * @brief function that times and outputs the duration of (testing)work done
 * @details [long description]
 * 
 * @param amount [number of data entries to test]
 * @param method [function to use for testing (possible values: [test] [testTwoContainers] [testSingleContainer])]
 */

void SpeedTest(int amount, void (*method)(std::vector<studentaiInfo>&, int)) {
	generate_speed_test_file(amount);
	Timer t;
	std::vector<studentaiInfo> speedTestPassV;
	method(speedTestPassV, amount);
	std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'vector' konteinerius (sekundemis): "
	          << t.elapsed() << std::endl;
	speedTestPassV.clear();
}

/**
 * @brief controls the workflow for the test
 * @details reads the data into a vector of class objects, sorts it, outputs to file
 * 
 * @param speedTestPass [vector of class objects to hold the data]
 * @param amount [number of data entries to test]
 */

void test(std::vector <studentaiInfo>& speedTestPass, int amount) {
	read_data_test(speedTestPass, amount);
	std::sort(speedTestPass.rbegin(), speedTestPass.rend());
	FileWrite(speedTestPass);
}

/**
 * @brief controls the workflow for the test
 * @details reads the data, seperates it into two different containers, sorts them, ouputs both to file
 * 
 * @param speedTestPass [vector of class objects to hold the data]
 * @param amount [number of data entries to test]
 */

void testTwoContainers(std::vector <studentaiInfo>& speedTestPass, int amount) {
	read_data_test(speedTestPass, amount);
	std::vector<studentaiInfo> kieti, vargsai;
	for (auto i : speedTestPass) {
		if (i.galBalas() >= 6) {
			kieti.push_back(i);
		} else {
			vargsai.push_back(i);
		}
	}
	std::sort(kieti.rbegin(), kieti.rend());
	std::sort(vargsai.rbegin(), vargsai.rend());
	FileWriteUC(kieti, vargsai);
}

/**
 * @brief controls the workflow for the test
 * @details reads the data, uses algorithms to seperate low scoring data entries to a different container, sorts both, outputs both to file
 * 
 * @param speedTestPass [vector of class objects to hold the data]
 * @param amount [number of data entries to test]
 */

void testSingleContainer(std::vector <studentaiInfo>& speedTestPass, int amount) {
	read_data_test(speedTestPass, amount);
	std::vector<studentaiInfo> vargsai;

	remove_copy_if(speedTestPass.begin(), speedTestPass.end(), back_inserter(vargsai), Check_if_Pass);
	speedTestPass.erase(remove_if(speedTestPass.begin(), speedTestPass.end(), Check_if_Fail), speedTestPass.end());

	std::sort(speedTestPass.rbegin(), speedTestPass.rend());
	std::sort(vargsai.rbegin(), vargsai.rend());
	FileWriteUC(speedTestPass, vargsai);
}

/**
 * @brief predictor functions for remove_if/remove_copy_if
 * @details checks whether the final grade for the class object is >=6
 * 
 * @param a [class object to check]
 * @return [bool value corresponding to the final grade of the object]
 */

bool Check_if_Fail(studentaiInfo& a) {
	return !Check_if_Pass( a);
}
bool Check_if_Pass(studentaiInfo& a) {
	return bool (a.galBalas() >= 6);
}