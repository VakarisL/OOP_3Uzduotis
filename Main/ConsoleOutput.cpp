#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <numeric>
#include <list>
#include <deque>

#include "../Main/Headers/ConsoleOutput.h"
#include "../Main/Headers/MathFunctions.h"
#include "../Main/Headers/RandomInput.h"




void output(double galBalasVid, double galBalasMed, int *egzaminas, std::vector<int> *ivertinimai, std::string vardas, std::string pavarde) {
	galBalasVid = 0.4 * darbuVidurkis(ivertinimai) + *egzaminas * 0.6;
	galBalasMed = 0.4 * darbuMediana(*ivertinimai) + *egzaminas * 0.6;

	std::cout << "Studento info:" << std::endl;
	std::cout << vardas << " " << pavarde << std::endl;
	int counter = 0;
	for (auto i : *ivertinimai) {
		std::cout << "Namu darbu " << ++counter << " pazymys: " << i << std::endl;
	}
	std::cout << "Egzamino pazymys: " << *egzaminas << std::endl;
	std::cout << "Galutinis balas (naudojant vidurki): " << std::setprecision(2) << std::fixed << galBalasVid << std::endl;
	std::cout << "Galutinis balas (naudojant mediana): " << std::setprecision(2) << std::fixed << galBalasMed << std::endl;
}

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

void test(std::vector <studentaiInfo>& speedTestPass){
	read_data_test(speedTestPass);
	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Average);
	FileWrite(speedTestPass);
}

void test(std::list <studentaiInfo>& speedTestPass){
	read_data_test(speedTestPass);
	speedTestPass.sort(Compare_By_Average);
	FileWrite(speedTestPass);
}

void test(std::deque <studentaiInfo>& speedTestPass){
	read_data_test(speedTestPass);
	std::sort(speedTestPass.begin(), speedTestPass.end(), Compare_By_Average);
	FileWrite(speedTestPass);
}

bool Compare_By_Average(const studentaiInfo &a, const studentaiInfo &b){
	return a.average > b.average;
}

// void SortingFailures(std::vector <studentaiInfo>& speedTestPass, std::vector <studentaiInfo>& speedTestFail){
// 	double tempAvg =0;
// 	for(auto it = speedTestPass.begin(); it != speedTestPass.end();){
// 		tempAvg = 0.4*std::accumulate(it->nDarbai.begin(), it->nDarbai.end(), 0.0)/5 + 0.6*(it->egzaminas);
// 		if(tempAvg < 6){
// 			studentaiInfo temp;
// 			temp.vardas.append(it->vardas);
// 			temp.pavarde.append(it->pavarde);
// 			for(size_t j=0; j<5; j++){
// 				temp.nDarbai.push_back(it->nDarbai[j]);
// 			}
// 			temp.egzaminas = it->egzaminas;
// 			temp.average = tempAvg;
// 			speedTestFail.push_back(temp);
// 			it = speedTestPass.erase(it);
// 		}
// 		else{
// 			it->average = tempAvg;
// 			it++;
// 		}
// 	}
// }

// void FileWrite(std::vector <studentaiInfo>& speedTestPass, std::vector <studentaiInfo>& speedTestFail){
// 	std::ofstream FileOut;
// 	try{
// 		FileOut.open("TestOutput.txt");
// 		if(FileOut.fail()) throw "Nepavyko sukurti failo irasymui";
// 	} catch (const char* e) {
// 		std::cerr << e << std::endl;
// 		std::exit(EXIT_SUCCESS);
// 	}

// 	for(auto i:speedTestPass){
// 		FileOut << i.vardas << " " << i.pavarde << " ";
// 		for(auto j:i.nDarbai){
// 			FileOut << j << " ";
// 		}
// 		FileOut << i.egzaminas << " " << "Vidurkis: " << i.average << std::endl;
// 	}

// 	for(auto i:speedTestFail){
// 		FileOut << i.vardas << " " << i.pavarde << " ";
// 		for(auto j:i.nDarbai){
// 			FileOut << j << " ";
// 		}
// 		FileOut << i.egzaminas << " " << "Vidurkis: " << i.average << std::endl;
// 	}

// 	FileOut.close();

// }

void FileWrite(std::vector <studentaiInfo>& speedTestPass){
	std::ofstream FileOut;
	try{
		FileOut.open("TestOutputV.txt", std::ofstream::out | std::ofstream::trunc);
		if(FileOut.fail()) throw "Nepavyko sukurti failo irasymui";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	for(auto i:speedTestPass){
		FileOut << i.vardas << " " << i.pavarde << " ";
		for(auto j:i.nDarbai){
			FileOut << j << " ";
		}
		FileOut << i.egzaminas << " " << "Vidurkis: " << i.average;
		i.average>=6 ? FileOut << " Pass" << std::endl : FileOut << " Fail" << std::endl;
	}

	FileOut.close();

}

void FileWrite(std::list <studentaiInfo>& speedTestPass){
	std::ofstream FileOut;
	try{
		FileOut.open("TestOutputL.txt", std::ofstream::out | std::ofstream::trunc);
		if(FileOut.fail()) throw "Nepavyko sukurti failo irasymui";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	for(auto i:speedTestPass){
		FileOut << i.vardas << " " << i.pavarde << " ";
		for(auto j:i.nDarbai){
			FileOut << j << " ";
		}
		FileOut << i.egzaminas << " " << "Vidurkis: " << i.average;
		i.average>=6 ? FileOut << " Pass" << std::endl : FileOut << " Fail" << std::endl;
	}

	FileOut.close();

}

void FileWrite(std::deque <studentaiInfo>& speedTestPass){
	std::ofstream FileOut;
	try{
		FileOut.open("TestOutputD.txt", std::ofstream::out | std::ofstream::trunc);
		if(FileOut.fail()) throw "Nepavyko sukurti failo irasymui";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	for(auto i:speedTestPass){
		FileOut << i.vardas << " " << i.pavarde << " ";
		for(auto j:i.nDarbai){
			FileOut << j << " ";
		}
		FileOut << i.egzaminas << " " << "Vidurkis: " << i.average;
		i.average>=6 ? FileOut << " Pass" << std::endl : FileOut << " Fail" << std::endl;
	}

	FileOut.close();

}