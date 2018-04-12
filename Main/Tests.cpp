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

void SpeedTest(int amount, int method) {
	// method -> which implementation of tests are going to be run
	std::chrono::high_resolution_clock::time_point timeStart, timeEnd;
	std::chrono::duration<double, std::milli> timeTaken;
	generate_speed_test_file(amount);

	switch (method) {
	case 1: {
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
		break;
	}
	case 2: {
		timeStart = std::chrono::high_resolution_clock::now();
		std::vector<studentaiInfo> speedTestPassV;
		testTwoContainers(speedTestPassV);
		timeEnd = std::chrono::high_resolution_clock::now();
		timeTaken = timeEnd - timeStart;
		std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'vector' konteinerius (sekundemis): "
		          << (double)timeTaken.count() / 1000 << std::endl;
		speedTestPassV.clear();

		timeStart = std::chrono::high_resolution_clock::now();
		std::list<studentaiInfo> speedTestPassL;
		testTwoContainers(speedTestPassL);
		timeEnd = std::chrono::high_resolution_clock::now();
		timeTaken = timeEnd - timeStart;
		std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'list' konteinerius (sekundemis): "
		          << (double)timeTaken.count() / 1000 << std::endl;
		speedTestPassL.clear();

		timeStart = std::chrono::high_resolution_clock::now();
		std::deque<studentaiInfo> speedTestPassD;
		testTwoContainers(speedTestPassD);
		timeEnd = std::chrono::high_resolution_clock::now();
		timeTaken = timeEnd - timeStart;
		std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'deque' konteinerius (sekundemis): "
		          << (double)timeTaken.count() / 1000 << std::endl;
		speedTestPassD.clear();
		break;
	}
	case 3: {
		timeStart = std::chrono::high_resolution_clock::now();
		std::vector<studentaiInfo> speedTestPassV;
		testSingleContainer(speedTestPassV);
		timeEnd = std::chrono::high_resolution_clock::now();
		timeTaken = timeEnd - timeStart;
		std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'vector' konteinerius (sekundemis): "
		          << (double)timeTaken.count() / 1000 << std::endl;
		speedTestPassV.clear();

		timeStart = std::chrono::high_resolution_clock::now();
		std::list<studentaiInfo> speedTestPassL;
		testSingleContainer(speedTestPassL);
		timeEnd = std::chrono::high_resolution_clock::now();
		timeTaken = timeEnd - timeStart;
		std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'list' konteinerius (sekundemis): "
		          << (double)timeTaken.count() / 1000 << std::endl;
		speedTestPassL.clear();

		timeStart = std::chrono::high_resolution_clock::now();
		std::deque<studentaiInfo> speedTestPassD;
		testSingleContainer(speedTestPassD);
		timeEnd = std::chrono::high_resolution_clock::now();
		timeTaken = timeEnd - timeStart;
		std::cout << amount << " irasu nuskaitymo, rusiavimo ir irasymo i faila trukme naudojant 'deque' konteinerius (sekundemis): "
		          << (double)timeTaken.count() / 1000 << std::endl;
		speedTestPassD.clear();
		break;
	}
	default: {
		std::cerr << "Ivyko switch klaida testavime" << std::endl;
	}
	}
}

void test(std::vector <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Result);
	FileWrite(speedTestPass);
}

void test(std::list <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	speedTestPass.sort(Compare_By_Result);
	FileWrite(speedTestPass);
}

void test(std::deque <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Result);
	FileWrite(speedTestPass);
}

bool Compare_By_Result(const studentaiInfo &a, const studentaiInfo &b) {
	return ((0.4 * a.average() + 0.6 * a.egzaminas()) > (0.4 * b.average() + 0.6 * b.egzaminas()));
}

void testTwoContainers(std::vector <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
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

void testTwoContainers(std::list <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	std::list<studentaiInfo> kieti, vargsai;
	for (auto i : speedTestPass) {
		if (i.galBalas() >= 6) {
			kieti.push_back(i);
		} else {
			vargsai.push_back(i);
		}
	}
	kieti.sort(Compare_By_Result);
	vargsai.sort(Compare_By_Result);
	FileWriteUC(kieti, vargsai);
}

void testTwoContainers(std::deque <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	std::deque<studentaiInfo> kieti, vargsai;
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

void testSingleContainer(std::vector <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	std::vector<studentaiInfo> vargsai;

	remove_copy_if(speedTestPass.begin(), speedTestPass.end(), back_inserter(vargsai), Check_if_Pass);
	speedTestPass.erase(remove_if(speedTestPass.begin(), speedTestPass.end(), Check_if_Fail), speedTestPass.end());

	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Result);
	std::sort(vargsai.begin(), vargsai.end(), Compare_By_Result);
	FileWriteUC(speedTestPass, vargsai);
}

bool Check_if_Fail(studentaiInfo& a){
	return !Check_if_Pass(a);
}
bool Check_if_Pass(studentaiInfo& a){
	return bool (a.galBalas() >= 6);
}

void testSingleContainer(std::list <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	std::list<studentaiInfo> vargsai;

	for(auto it = speedTestPass.begin(); it!= speedTestPass.end();) {
		if (it->galBalas() < 6) {
			vargsai.push_back(*it);
			it = speedTestPass.erase(it);
		} else it++;
	}
	speedTestPass.sort(Compare_By_Result);
	vargsai.sort(Compare_By_Result);
	FileWriteUC(speedTestPass, vargsai);
}

void testSingleContainer(std::deque <studentaiInfo>& speedTestPass) {
	read_data_test(speedTestPass);
	std::deque<studentaiInfo> vargsai;

	remove_copy_if(speedTestPass.begin(), speedTestPass.end(), back_inserter(vargsai), Check_if_Pass);
	speedTestPass.erase(remove_if(speedTestPass.begin(), speedTestPass.end(), Check_if_Fail), speedTestPass.end());
	
	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Result);
	std::sort(vargsai.begin(), vargsai.end(), Compare_By_Result);
	FileWriteUC(speedTestPass, vargsai);
}