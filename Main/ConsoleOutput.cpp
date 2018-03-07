#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "../Main/Headers/ConsoleOutput.h"
#include "../Main/Headers/MathFunctions.h"



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