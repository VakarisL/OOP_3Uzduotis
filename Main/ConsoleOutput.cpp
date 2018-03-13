#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <fstream>

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

void SpeedTest(std::vector <studentaiInfoTest>& speedTest, int amount) {
	std::chrono::high_resolution_clock::time_point timeStart, timeEnd;
	std::chrono::duration<double, std::milli> timeTaken;
	timeStart = std::chrono::high_resolution_clock::now();
	generate_speed_test(speedTest, amount);
	std::sort(speedTest.begin(), speedTest.end(), comparePass);
	FileWrite(speedTest);
	timeEnd = std::chrono::high_resolution_clock::now();
	timeTaken = timeEnd - timeStart;
	std::cout << amount << " irasu generavimo, ju palyginimo ir irasymo i faila trukme (sekundemis): "
	          << (double)timeTaken.count() / 1000 << std::endl;

}

void FileWrite(std::vector <studentaiInfoTest>& speedTest){
	std::ofstream FileOut;
	try{
		FileOut.open("Test.txt");
		if(FileOut.fail()) throw "Nepavyko sukurti failo irasymui";
	} catch (const char* e) {
		std::cerr << e << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	for(auto i:speedTest){
		FileOut << i.vardas << " " << i.pavarde << " ";
		for(auto j:i.nDarbai){
			FileOut << j << " ";
		}
		FileOut << i.egzaminas << " " << i.pass << std::endl;
	}

	FileOut.close();

}