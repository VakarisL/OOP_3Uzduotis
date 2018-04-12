#ifndef STUDENTAIINFO_H_
#define	STUDENTAIINFO_H_

#include <string>
#include <vector>

#include "../Headers/MathFunctions.h"


class studentaiInfo {
  private:
	std::string Vardas;
	std::string Pavarde;
	std::vector<int> nDarbai;
	int Egzaminas;
  public:
	//studentaiInfo() : Egzaminas(0) { }
	std::string vardas() const {return Vardas;}
	std::string pavarde() const {return Pavarde;}
	std::vector<int> pazymiai() const {return nDarbai;}
	int egzaminas() const {return Egzaminas;}
	double average() const;
	double median() const;
	double galBalas(double (*)(std::vector<int>) = darbuVidurkis) const;
	void setVardas(std::string& name) {Vardas = name;}
	void setPavarde(std:: string& surname) {Pavarde = surname;}
	void setEgzaminas(int exam) {Egzaminas = exam;}
	void setDarbai(int grade) {nDarbai.push_back(grade);}
};


#endif