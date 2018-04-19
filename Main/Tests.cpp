#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

#include "../Main/Headers/Tests.h"
#include "../Main/Headers/TestFileRead.h"
#include "../Main/Headers/TestFileWrite.h"
#include "../Main/Headers/GenerateTestFile.h"

void SpeedTest(int amount, void (*method)(std::vector<studentaiInfo>&, int)) {
	std::chrono::high_resolution_clock::time_point timeStart, timeEnd;
	std::chrono::duration<double, std::milli> timeTaken;
	generate_speed_test_file(amount);
	timeStart = std::chrono::high_resolution_clock::now();
	std::vector<studentaiInfo> speedTestPassV;
	method(speedTestPassV, amount);
	timeEnd = std::chrono::high_resolution_clock::now();
	timeTaken = timeEnd - timeStart;
	std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'vector' konteinerius (sekundemis): "
	          << (double)timeTaken.count() / 1000 << std::endl;
	speedTestPassV.clear();
}

void test(std::vector <studentaiInfo>& speedTestPass, int amount) {
	read_data_test(speedTestPass, amount);
	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Result);
	FileWrite(speedTestPass);
}

bool Compare_By_Result(const studentaiInfo &a, const studentaiInfo &b) {
	return (a.galBalas() > b.galBalas());
}

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
	std::sort(kieti.begin(), kieti.end(), Compare_By_Result);
	std::sort(vargsai.begin(), vargsai.end(), Compare_By_Result);
	FileWriteUC(kieti, vargsai);
}

void testSingleContainer(std::vector <studentaiInfo>& speedTestPass, int amount) {
	read_data_test(speedTestPass, amount);
	std::vector<studentaiInfo> vargsai;

	remove_copy_if(speedTestPass.begin(), speedTestPass.end(), back_inserter(vargsai), Check_if_Pass);
	speedTestPass.erase(remove_if(speedTestPass.begin(), speedTestPass.end(), Check_if_Fail), speedTestPass.end());

	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Result);
	std::sort(vargsai.begin(), vargsai.end(), Compare_By_Result);
	FileWriteUC(speedTestPass, vargsai);
}

bool Check_if_Fail(studentaiInfo& a) {
	return !Check_if_Pass( a);
}
bool Check_if_Pass(studentaiInfo& a) {
	return bool (a.galBalas() >= 6);
}