#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

#include "../Main/Headers/Tests.h"
#include "../Main/Headers/TestFileRead.h"
#include "../Main/Headers/TestFileWrite.h"
#include "../Main/Headers/GenerateTestFile.h"

void SpeedTest(int amount) {
	std::chrono::high_resolution_clock::time_point timeStart, timeEnd;
	std::chrono::duration<double, std::milli> timeTaken;
	generate_speed_test_file(amount);

	timeStart = std::chrono::high_resolution_clock::now();
	std::vector<studentaiInfo> speedTestPassV;
	test(speedTestPassV);
	timeEnd = std::chrono::high_resolution_clock::now();
	timeTaken = timeEnd - timeStart;
	std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'vector' konteineri (sekundemis): "
	          << (double)timeTaken.count() / 1000 << std::endl;
	speedTestPassV.clear();

	timeStart = std::chrono::high_resolution_clock::now();
	std::list<studentaiInfo> speedTestPassL;
	test(speedTestPassL);
	timeEnd = std::chrono::high_resolution_clock::now();
	timeTaken = timeEnd - timeStart;
	std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'list' konteineri (sekundemis): "
	          << (double)timeTaken.count() / 1000 << std::endl;
	speedTestPassL.clear();

	timeStart = std::chrono::high_resolution_clock::now();
	std::deque<studentaiInfo> speedTestPassD;
	test(speedTestPassD);
	timeEnd = std::chrono::high_resolution_clock::now();
	timeTaken = timeEnd - timeStart;
	std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'deque' konteineri (sekundemis): "
	          << (double)timeTaken.count() / 1000 << std::endl;
	speedTestPassD.clear();
}

void test(std::vector <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Average);
	FileWrite(speedTestPass);
}

void test(std::list <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	speedTestPass.sort(Compare_By_Average);
	FileWrite(speedTestPass);
}

void test(std::deque <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Average);
	FileWrite(speedTestPass);
}

bool Compare_By_Average(const studentaiInfo &a, const studentaiInfo &b) {
	return a.average > b.average;
}